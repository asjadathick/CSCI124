//
//  hardware.h
//  ass2task1
//
//  Created by Mohamed Asjad Athick on 26/08/2015.
//  Student: 4970612
//  Copyright (c) 2015 Asjad Athick. All rights reserved.
//

#include <iostream>
#include <fstream>

const int PART_NAME_SIZE=31;
const char BINARY_FILE_NAME[]="hardware.dat";
const int MAX_RECORDS=100;


struct Hardware{
    int partNumber;
    char toolName[PART_NAME_SIZE];
    int quantityInStock;
    float unitPrice;
};

//method prototypes
void initializeBinaryFile(std::fstream &binaryFile);
void inputParts(std::fstream &binaryFile);
void listFile(std::fstream &binaryFile);
void updateRecord(std::fstream &binaryFile);
void insertRecord(std::fstream &binaryFile);
void deleteRecord(std::fstream &binaryFile);
