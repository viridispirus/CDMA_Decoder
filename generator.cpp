//
// Created by Michael Vogt on 12.10.22.
//

#include <iostream>
#include "generator.h"

struct rSum{
    int rSum1;
    int rSum2;
};
    rSum registerSum[24];

void generator::initRegisterSum() {
    registerSum[0] = {2,6};
    registerSum[1] = {3,7};
    registerSum[2] = {4,8};
    registerSum[3] = {5,9};
    registerSum[4] = {1,9};
    registerSum[5] = {2,10};
    registerSum[6] = {1,8};
    registerSum[7] = {2,9};
    registerSum[8] = {3,10};
    registerSum[9] = {2,3};
    registerSum[10] = {3,4};
    registerSum[11] = {5,6};
    registerSum[12] = {6,7};
    registerSum[13] = {7,8};
    registerSum[14] = {8,9};
    registerSum[15] = {9,10};
    registerSum[16] = {1,4};
    registerSum[17] = {2,5};
    registerSum[18] = {3,6};
    registerSum[19] = {4,7};
    registerSum[20] = {5,8};
    registerSum[21] = {6,9};
    registerSum[22] = {1,3};
    registerSum[23] = {4,6};
}

    /**
     * Calculate next bit for the first motherSequence
     * which is shifted into the sequence.
     * @param mbSeq1
     * @return
     */
int generator::stepMotherSequence1(int mbSeq1) {
    bool thirdBit = (mbSeq1>>7)&1;
//    std::cout << "thirdBit ";
//    std::cout << thirdBit << std::endl;
        bool nextBit = !(mbSeq1&1) != !thirdBit;
//    std::cout << "nextBit ";
//    std::cout << nextBit << std::endl;
    return (nextBit<<9) | (mbSeq1>>1);
}

/**
 * Calculate next bit for the second motherSequence
 * which is shifted into the sequence.
 * @param mbSeq1
 * @return
 */
int generator::stepMotherSequence2(int mbSeq2) {
    bool secondBit = (mbSeq2>>8)&1;
//    std::cout << "secondBit ";
//    std::cout << secondBit << std::endl;
    bool thirdBit = (mbSeq2>>7)&1;
//    std::cout << "thirdBit ";
//    std::cout << thirdBit << std::endl;
    bool sixthBit = (mbSeq2>>4)&1;
//    std::cout << "sixthBit ";
//    std::cout << sixthBit << std::endl;
    bool eighthBit = (mbSeq2>>2)&1;
//    std::cout << "eighthBit ";
//    std::cout << eighthBit << std::endl;
    bool ninthBit = (mbSeq2>>1)&1;
//    std::cout << "ninthBit ";
//    std::cout << ninthBit << std::endl;
    bool tenthBit = mbSeq2&1;
//    std::cout << "tenthBit ";
//    std::cout << tenthBit << std::endl;


    bool nextBit = secondBit ^ thirdBit ^ sixthBit ^ eighthBit ^ ninthBit ^ tenthBit;
    //std::cout << "nextBit ";
    //std::cout << nextBit << std::endl;
    return (nextBit<<9) | (mbSeq2>>1);
}

bool generator::calcNextChipSeqBit(int mbSeq1, int mbSeq2, int registerSum1, int registerSum2) {
    bool mbSeq1Bit = mbSeq1&1;
      //std::cout << "motherSequence1AfterStep ";
      //std::cout << mbSeq1Bit << std::endl;
    //std::cout << "rSum1Bit ";
    //std::cout << (mbSeq2>>(10-registerSum1)&1) << std::endl;
    bool mbSeq2Bit = ((mbSeq2 >> ( 10 - registerSum1)) &1) ^ ((mbSeq2 >> ( 10 - registerSum2)) &1);
    //std::cout << "rSum2Bit ";
    //std::cout << (mbSeq2>>(10-registerSum2)&1) << std::endl;
    //std::cout << "motherSequence2AfterStep ";
    //std::cout << mbSeq2Bit << std::endl;
    //std::cout << "nextChipBit ";
    //std::cout << (mbSeq1Bit ^ mbSeq2Bit) << std::endl;
    return (mbSeq1Bit ^ mbSeq2Bit);
}



  bool* generator::calcGoldSequence(int satelliteId, int mbSeq1, int mbSeq2) {
    int numberOfBits = 1023;
    int nextGoldCodeBit;
    static bool chipSeq[1023];
    for (int i = 0; i < numberOfBits; i++) {
        nextGoldCodeBit = calcNextChipSeqBit(mbSeq1, mbSeq2, registerSum[satelliteId-1].rSum1, registerSum[satelliteId-1].rSum2);
        chipSeq[i] = nextGoldCodeBit;
        // std::cout << "nextGoldCodeBit = " << std::bitset<12>(chipSeq) << std::endl;
        mbSeq1 = stepMotherSequence1(mbSeq1);
        //   std::cout << "stepMotherSequence1 = " << std::bitset<10>(mbSeq1) << std::endl;
        mbSeq2 = stepMotherSequence2(mbSeq2);
        //   std::cout << "stepMotherSequence2 = " << std::bitset<10>(mbSeq2) << std::endl;


    }
    return chipSeq;
}

    int generator::matchingGoldSeqWithSignal(bool* goldSeq, int signal[]) {

        for (int delta = 0; delta < 1023; delta++) {
            int result = 0;
            for (int j = 0; j < 1023; j++) {
                short vector = goldSeq[j] ? 1 : -1 ;
                result += vector * signal[(delta + j) % 1023];
            }
            if (result < -500 || result > 500) {
               // std::cout << "result = " << result << std::endl;
                return result;
            }
        }

    return 0;
}
