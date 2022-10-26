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


    int mbSeq1 = 0b1111111111;
    int mbSeq2 = 0b1111111111;

   // std::cout << "stepMotherSequence1 = " << std::bitset<10>(mbSeq1) << std::endl;
   // std::cout << "stepMotherSequence2 = " << std::bitset<10>(mbSeq2) << std::endl;

    int satelliteId = 1;
    generator gen = *new generator();
    gen.initRegisterSum();
    while (satelliteId <= 24) {
        bool* goldSeq = gen.calcGoldSequence(satelliteId, mbSeq1, mbSeq2);
        satelliteId++;
    }

    return 0;
}

