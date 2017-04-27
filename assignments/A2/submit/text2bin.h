//
//  text2bin.h
//  Ass2
//
//  Created by Mohamed Asjad Athick on 5/09/2015.
//  Student 4970512
//  Copyright (c) 2015 Asjad Athick. All rights reserved.
//

#include <fstream>
#include <iostream>

struct Data{
    char name[30];
    int age;
    float balance;
};

//constants
const char TEXT_FILE_NAME[]="textdata.txt";
const char BIN_FILE_NAME[]="data.dat";
const char TEXT_LENGTH=100;

int readTxtFile(std::ifstream &inputFile, Data records[]);
void writeBinFile(std::fstream &binaryFile, const Data records[],int size);
int readBinFile(std::fstream &binaryFile, Data records[]);