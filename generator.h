//
// Created by Michael Vogt on 12.10.22.
//

#ifndef UNTITLED1_GENERATOR_H
#define UNTITLED1_GENERATOR_H


class generator {
public:
    int calcNextmSeq1(int);


    void setRegisterSum();

    int calcNextmSeq2(int mbSeq2);

    int calcNextChipSeqBit(int mbSeq1, int mbSeq2, int registerSum1, int registerSum2);
};


#endif //UNTITLED1_GENERATOR_H
