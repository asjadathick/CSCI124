//
//  text2bin.cpp
//  Ass2
//
//  Created by Mohamed Asjad Athick on 5/09/2015.
//  Student 4970512
//  Copyright (c) 2015 Asjad Athick. All rights reserved.
//

#include "text2bin.h"
using namespace std;

int readTxtFile(ifstream &inputFile, Data records[]){
    int recordsLoaded=0;
    char tempBuffer[TEXT_LENGTH];
    
    //seek back to beg
    inputFile.clear();
    inputFile.seekg(ios::beg);
    
    //assign records
    inputFile.getline(tempBuffer, TEXT_LENGTH, '\n');
    while (strcmp(tempBuffer, "-1")!=0) {
        strcpy(records[recordsLoaded].name,tempBuffer);
        inputFile.getline(tempBuffer, TEXT_LENGTH,' ');
        records[recordsLoaded].age=atoi(tempBuffer);
        inputFile.getline(tempBuffer, TEXT_LENGTH,'\n');
        records[recordsLoaded].balance=atof(tempBuffer);
        //record loaded
        recordsLoaded++;
        //next rec
        inputFile.getline(tempBuffer, TEXT_LENGTH, '\n');
    }
    inputFile.close();
    return recordsLoaded;
}

void writeBinFile(fstream &binaryFile, const Data records[],int size){
    binaryFile.open(BIN_FILE_NAME,ios::out|ios::binary);
    if(!binaryFile.good()){
        cerr<<"Error creating the binary file"<<endl;
        return;
    }
    
    Data temp;
    for (int i=0; i<size; i++) {
        strcpy(temp.name,records[i].name);
        temp.age=records[i].age;
        temp.balance=records[i].balance;
        binaryFile.write(reinterpret_cast<char*>(&temp), sizeof(Data));
    }
    binaryFile.close();
}

int readBinFile(fstream &binaryFile, Data records[]){
    
    int recordsLoaded=0;
    
    Data temp;
    while (!binaryFile.eof()) {
        binaryFile.read(reinterpret_cast<char*>(&temp), sizeof(Data));
        if (!binaryFile.eof()) {
            records[recordsLoaded]=temp;
            recordsLoaded++;
        }
    }
    return recordsLoaded;
}

