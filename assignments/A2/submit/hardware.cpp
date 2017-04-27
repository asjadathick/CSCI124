//
//  hardware.cpp
//  ass2task1
//
//  Created by Mohamed Asjad Athick on 26/08/2015.
//  Student: 4970612
//  Copyright (c) 2015 Asjad Athick. All rights reserved.
//

#include "hardware.h"
#include <iomanip>

using namespace std;


void initializeBinaryFile(fstream &binaryFile){
    Hardware data[100];
    //init
    for (int i=0; i<MAX_RECORDS; i++) {
        data[i].partNumber=-1; //-1 = empty record
        data[i].toolName[0]='\0';
        data[i].quantityInStock=0;
        data[i].unitPrice=0;
    }
    binaryFile.clear();
    binaryFile.open(BINARY_FILE_NAME, ios::out|ios::binary);
    if (!binaryFile.good()){
        cout<<"Error opening binary file for init."<<endl;
        return;
    }
    
    binaryFile.write(reinterpret_cast<char*>(data), sizeof(Hardware)*100);
    binaryFile.close();
}

void inputParts(fstream &binaryFile){
    binaryFile.open(BINARY_FILE_NAME, ios::out|ios::app|ios::binary);
    if (!binaryFile.good()){
        cout<<"Error opening binary file for input."<<endl;
        return;
    }

    Hardware inputData;
    do{
        cout<<"Enter the part number (0-99, -1 to end the input): ";
        cin>>inputData.partNumber;
        if (!(inputData.partNumber<0)) {
            cout<<"Enter the tool name: ";
            cin.ignore();
            cin.getline(inputData.toolName, PART_NAME_SIZE,'\n');
            cout<<"Enter the quantity ";
            cin>>inputData.quantityInStock;
            cout<<"Enter the price: ";
            cin>>inputData.unitPrice;
            
            binaryFile.write(reinterpret_cast<char*>(&inputData), sizeof(Hardware));
        }
        
    }while (inputData.partNumber>0);
    
    binaryFile.close();
}

void listFile(fstream &binaryFile){
    binaryFile.open(BINARY_FILE_NAME);
    if (!binaryFile.good()){
        cout<<"Error opening binary file for listing."<<endl;
        return;
    }
    cout<<left<<setw(7)<<"Part#"<<setw(30)<<"Tool Name"<<setw(15)<<"Quantity"<<setw(7)<<"Price"<<endl;
    while (!binaryFile.eof()) {
        Hardware temp;
        binaryFile.read(reinterpret_cast<char*>(&temp), sizeof(Hardware));
        if (!binaryFile.eof()){
            if (temp.partNumber!=-1)
                cout<<setw(7)<<temp.partNumber<<setw(30)<<temp.toolName<<setw(15)<<temp.quantityInStock<<setw(7)<<temp.unitPrice<<endl;
        }
    }
    binaryFile.close();
}

void updateRecord(fstream &binaryFile){
    binaryFile.open(BINARY_FILE_NAME);
    if (!binaryFile.good()) {
        cout<<"Error opening file for update."<<endl;
        return;
    }
    cout<<"Enter a part number for update: "<<endl;
    int searchPart=0;
    cin>>searchPart;
    
    bool found=false;
    //seek part
    while (!binaryFile.eof()) {
        Hardware temp;
        Hardware inputData;
        binaryFile.read(reinterpret_cast<char*>(&temp), sizeof(Hardware));
        if (!binaryFile.eof()) {
            if (temp.partNumber==searchPart) {
                //part found
                //get new details, seek back and update
                inputData.partNumber=searchPart;
                cout<<"Enter the tool name: ";
                cin.ignore();
                cin.getline(inputData.toolName, PART_NAME_SIZE,'\n');
                cout<<"Enter the quantity ";
                cin>>inputData.quantityInStock;
                cout<<"Enter the price: ";
                cin>>inputData.unitPrice;
                
                binaryFile.seekg(-sizeof(Hardware), ios::cur);
                binaryFile.write(reinterpret_cast<char*>(&inputData), sizeof(Hardware));
                found=true;
                cout<<"Record updated."<<endl;
                break;
            }
        }
    }
    if (!found) {
        cout<<"The record does not exist"<<endl;
    }
    binaryFile.close();
}

void deleteRecord(fstream &binaryFile){
    binaryFile.open(BINARY_FILE_NAME);
    if (!binaryFile.good()) {
        cout<<"Error opening file for delete"<<endl;
        return;
    }
    cout<<"Enter a part number to delete: ";
    int deletePart;
    cin>>deletePart;
    
    Hardware temp;
    bool recordFound=false;
    //search through the file for part
    while (!binaryFile.eof()) {
        binaryFile.read(reinterpret_cast<char*>(&temp), sizeof(Hardware));
        if (temp.partNumber==deletePart) {
            recordFound=true;
            temp.partNumber=-1;
            binaryFile.seekg(-sizeof(Hardware),ios::cur);
            binaryFile.write(reinterpret_cast<char*>(&temp), sizeof(Hardware));
            cout<<"Record deleted."<<endl;
            break;
        }
    }
    
    if (!recordFound) {
        cout<<"Record not found for delete"<<endl;
    }
    binaryFile.close();
}

void insertRecord(fstream &binaryFile){
    binaryFile.open(BINARY_FILE_NAME,ios::in|ios::out|ios::binary);
    if (!binaryFile.good()) {
        cout<<"Error opening binary file for insert"<<endl;
        return;
    }
    
    //get part number
    cout<<"Enter part number for insertion: "<<endl;
    Hardware inputData;
    cin>>inputData.partNumber;
    
    Hardware temp;
    //go through file and see if record exists
    while (!binaryFile.eof()) {
        binaryFile.read(reinterpret_cast<char*>(&temp), sizeof(Hardware));
        if (!binaryFile.eof()) {
            if (temp.partNumber==inputData.partNumber) {
                //part already exists
                cout<<"The record already exists."<<endl;
                binaryFile.close();
                return;
            }
            
        }
    }
    
    //find place to insert
    binaryFile.clear();
    binaryFile.seekg(ios::beg);
    
    int emptyRecordFound=false;
    
    
    while (!binaryFile.eof()) {
        binaryFile.read(reinterpret_cast<char*>(&temp), sizeof(Hardware));
        if (!binaryFile.eof()) {
            if (temp.partNumber==-1) {
                emptyRecordFound=true;
                break;
            }
        }
    }
    
    if (emptyRecordFound) {
        binaryFile.seekg(-sizeof(Hardware),ios::cur);
        
        //get other details
        cout<<"Enter the tool name: ";
        cin.ignore();
        cin.getline(inputData.toolName, PART_NAME_SIZE,'\n');
        cout<<"Enter the quantity ";
        cin>>inputData.quantityInStock;
        cout<<"Enter the price: ";
        cin>>inputData.unitPrice;
        
        binaryFile.write(reinterpret_cast<char*>(&inputData), sizeof(Hardware));
    }
    else
    {
        cout<<"Binary file is full"<<endl;
    }
    
    binaryFile.close();
    
}



