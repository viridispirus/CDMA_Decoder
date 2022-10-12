#include <iostream>
#include <fstream>
#include <string>
#include "generator.h"

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;
    if (argc != 2) {
        std::cout << "Invalid input!" << std::endl;
        return 1;
    }
    std::cout << argv[1] << std::endl;

    std::ifstream inputFile; inputFile.open("/Users/micha/CLionProjects/untitled1/embeddedSequenzCDMA.txt");
    std::string inputString;
    int signal[1024];
    int index = 0;
    if ( inputFile.is_open() ) { // always check whether the file is open
        while (inputFile) {
            inputFile >> inputString; // pipe file's content into streams
            signal[index] = stoi(inputString);
            std::cout << signal[index] << std::endl; // pipe stream's content to standard output
            index++;
        }
    }
    std::cout << inputString << std::endl;

    struct rSum{
        int rSum1;
        int rSum2;
    };

    rSum registerSum[24];
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

    int mbSeq1 = 0b1111111111;
    int mbSeq2 = 0b1111111111;
    int nextChip;

    generator gen = *new generator();

    for (int i = 0; i < 10; i++) {
        mbSeq1 = gen.calcNextmSeq1(mbSeq1);
    //    std::cout << "calcNextmSeq1 = " << std::bitset<10>(mbSeq1) << std::endl;
        mbSeq2 = gen.calcNextmSeq2(mbSeq2);
        std::cout << "calcNextmSeq2 = " << std::bitset<10>(mbSeq2) << std::endl;
        nextChip = gen.calcNextChipSeqBit(mbSeq1, mbSeq2, registerSum[0].rSum1, registerSum[0].rSum2);
     //   std::cout << "calcNextChip = " << std::bitset<10>(nextChip) << std::endl;
    }

    return 0;
}

