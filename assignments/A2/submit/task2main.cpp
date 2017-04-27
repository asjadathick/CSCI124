//
//  main.cpp
//  Ass2
//
//  Created by Mohamed Asjad Athick on 5/09/2015.
//  Student 4970512
//  Copyright (c) 2015 Asjad Athick. All rights reserved.
//

#include "sorting.h"
using namespace std;

//prototypes
void listAllRecords(Data record[], int numOfRecords, int offset=0);

int main(int argc, const char * argv[]) {

    ifstream textfile;
    fstream binaryFile;
    Data *records;
    int numRecords=0;
    bool readFromText=false;
    
    binaryFile.open(BIN_FILE_NAME,ios::in|ios::binary);
    if (!binaryFile.good()) {
        binaryFile.close();
        //count records in file
        textfile.open(TEXT_FILE_NAME);
        if (!textfile.good()) {
            cerr<<"Error opening text file for input"<<endl;
            return 0;
        }
        
        //cout num of records
        char tempBuffer[TEXT_LENGTH];
        int numberOfRecords=0;
        textfile.getline(tempBuffer, TEXT_LENGTH,'\n');
        while (strcmp(tempBuffer, "-1")!=0) {
            numberOfRecords++;
            textfile.getline(tempBuffer, TEXT_LENGTH,'\n');
        }
        numberOfRecords/=2; //2 lines per record
        readFromText=true;
        
    }
    else{
        //read from bin file
        binaryFile.close();
        //count records
        binaryFile.open(BIN_FILE_NAME,ios::in);
        if (!binaryFile.good()) {
            cerr<<"Error opening binary file."<<endl;
        }
        
        //figure out num of records
        binaryFile.seekg(ios::end);
        numRecords=(int)binaryFile.tellg()/sizeof(Data);
        
        //seek back
        binaryFile.clear();
        binaryFile.seekg(ios::beg);

    }
    
    //allocate memory
    records=new Data[numRecords+1];
    
    if (readFromText) {
        numRecords=readTxtFile(textfile, records);
        writeBinFile(binaryFile, records, numRecords);
    }
    else{
        numRecords=readBinFile(binaryFile, records);
    }
    
    int cmd;
    do {
        cout<<"Select from the following options:"<<endl;
        cout<<"1. Sort by name"<<endl;
        cout<<"2. Sort by age"<<endl;
        cout<<"3. Sort by balance"<<endl;
        cout<<"4. Quit"<<endl;
        cout<<"Select: "<<endl;
        cin>>cmd;
        //handle invalid input?
        switch (cmd) {
            case 1:
                quicksortData(records, 0, numRecords-1);
                listAllRecords(records, numRecords);
                break;
            case 2:
                insertionSort(records, numRecords);
                listAllRecords(records, numRecords);
                break;
            case 3:
                selectionSort(records, numRecords);
                listAllRecords(records, numRecords);
                break;
            case 4:
                break;
                
            default:
                cout<<"Wrong selection, please choose from 1 to 4."<<endl;
                break;
        }
    }while (cmd!=4);
    
    cout<<"Thank you!"<<endl;
    
    delete []records;
    return 0;
}

void listAllRecords(Data record[], int numOfRecords, int offset){
    for (int i=0+offset; i<numOfRecords+offset; i++) {
        cout<<record[i].name<<'\t'<<record[i].age<<'\t'<<record[i].balance<<'\t'<<endl;
    }
}

