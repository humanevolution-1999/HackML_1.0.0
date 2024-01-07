#ifndef hack_file_h
#define hack_file_h

#include<fstream>
#include<iostream>
#include<string>
#include "coder.h"
#include "symbol_table.h"

class FileHandler {
public:
    std::ifstream inputFile;
    int line_num;

    // Constructor that takes input and output file names and opens the files
    FileHandler(const std::string& inputFileName) {
        openInputFile(inputFileName);
        line_num=0;
        init_coder_instructions();
        init_internal_symbol();

    }

    // Destructor to ensure the files are closed when the object is destroyed
    ~FileHandler() {
        closeInputFile();
    }

    // Member function to open an input file
    void openInputFile(const std::string& fileName) {
        inputFile.open(fileName);
        if (!inputFile.is_open()) {
            std::cerr << "Error opening the input file: " << fileName << std::endl;
            exit(0);
        }
    }

    // Member function to close the input file
    void closeInputFile() {
        if (inputFile.is_open()) {
            inputFile.close();
        }
    }
};

#endif 