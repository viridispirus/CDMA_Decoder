#include <iostream>
#include <fstream>
#include <string>
#include "generator.h"

int main(int argc, char *argv[]) {
 //   std::cout << "Hello, World!" << std::endl;
    if (argc != 2) {
     //   std::cout << "Invalid input!" << std::endl;
        return 1;
    }
    //std::cout << argv[1] << std::endl;

    std::ifstream inputFile; inputFile.open("/Users/micha/CLionProjects/untitled1/embeddedSequenzCDMA.txt");
    std::string inputString;
    int signal[1024];
    int index = 0;
    if ( inputFile.is_open() ) { // always check whether the file is open
        while (inputFile) {
            inputFile >> inputString; // pipe file's content into streams
            signal[index] = stoi(inputString);
    //        std::cout << signal[index] << std::endl; // pipe stream's content to standard output
            index++;
        }
    }
  //  std::cout << inputString << std::endl;


    int mbSeq1 = 0b1111111111;
    int mbSeq2 = 0b1111111111;

   // std::cout << "stepMotherSequence1 = " << std::bitset<10>(mbSeq1) << std::endl;
   // std::cout << "stepMotherSequence2 = " << std::bitset<10>(mbSeq2) << std::endl;

    generator gen = *new generator();
    gen.initRegisterSum();
    int test[4] = {5,8,11,22};

    for(int testid = 0; testid <= 3; testid++) {
        int delta = 0;
        bool* goldSeq = gen.calcGoldSequence(test[testid], mbSeq1, mbSeq2);
       // std::cout << "satellitedID = " << test[testid] << std::endl;
        int result = gen.matchingGoldSeqWithSignal(goldSeq, signal, &delta);
        if (result != 0) {
            std::cout << "Satellite " << test[testid] << " has sent bit ";
            if (result > 500) {
                std::cout << "1";
            }
            if (result < -500) {
                std::cout << "0";
            }
            std::cout <<  " (delta = " << delta << ")" << std::endl;
        }

    }
    return 0;
}

