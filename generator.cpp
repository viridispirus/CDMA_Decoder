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
