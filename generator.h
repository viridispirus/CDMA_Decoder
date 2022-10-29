//
// Created by Michael Vogt on 12.10.22.
//

#ifndef UNTITLED1_GENERATOR_H
#define UNTITLED1_GENERATOR_H


class generator {
public:
    int stepMotherSequence1(int);


    void initRegisterSum();

    int stepMotherSequence2(int mbSeq2);
    bool calcNextChipSeqBit(int mbSeq1, int mbSeq2, int registerSum1, int registerSum2);

    bool* calcGoldSequence(int satelliteId, int mbSeq1, int mbSeq2);

    int matchingGoldSeqWithSignal(bool *goldSeq, int *signal);
};


#endif //UNTITLED1_GENERATOR_H
