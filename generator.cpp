//
// Created by Michael Vogt on 12.10.22.
//

#include <iostream>
#include "generator.h"

int generator::calcNextmSeq1(int mbSeq1) {
    int thirdBit = (mbSeq1>>7)&1;
    std::cout << "thirdBit ";
    std::cout << thirdBit << std::endl;
    int nextBit = !(mbSeq1&1) != !thirdBit;
    std::cout << "nextBit ";
    std::cout << nextBit << std::endl;
    return (nextBit<<9) | (mbSeq1>>1);
}

int generator::calcNextmSeq2(int mbSeq2) {
    int secondBit = (mbSeq2>>8)&1;
    std::cout << "secondBit ";
    std::cout << secondBit << std::endl;
    int thirdBit = (mbSeq2>>7)&1;
    std::cout << "thirdBit ";
    std::cout << thirdBit << std::endl;
    int sixthBit = (mbSeq2>>4)&1;
    std::cout << "sixthBit ";
    std::cout << sixthBit << std::endl;
    int eighthBit = (mbSeq2>>2)&1;
    std::cout << "eighthBit ";
    std::cout << eighthBit << std::endl;
    int ninthBit = (mbSeq2>>1)&1;
    std::cout << "ninthBit ";
    std::cout << ninthBit << std::endl;
    int tenthBit = mbSeq2&1;
    std::cout << "tenthBit ";
    std::cout << tenthBit << std::endl;


    int nextBit = !(mbSeq2&1) != !secondBit != !thirdBit != !sixthBit != !eighthBit != !ninthBit != !tenthBit;
    std::cout << "nextBit ";
    std::cout << nextBit << std::endl;
    return (nextBit<<9) | (mbSeq2>>1);
}
