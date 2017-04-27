//
//  main.cpp
//  ass2task1
//
//  Created by Mohamed Asjad Athick on 26/08/2015.
//  Student: 4970612
//  Copyright (c) 2015 Asjad Athick. All rights reserved.
//

#include "hardware.h"
using namespace std;

//prototypes
void printMenu();

int main(int argc, const char * argv[]) {
    fstream chkbinFile;
    fstream binFile;
    //try opening binfile, if it doesnt exist, init, otherwise display menu
    chkbinFile.open(BINARY_FILE_NAME);
    if (!chkbinFile.good()) {
        //file does not exist
        initializeBinaryFile(binFile);
        inputParts(binFile);
    }
    else{
        cout<<"Should the file be initialized (Y or N): ";
        char cmd='\0';
        cin>>cmd;
        if (tolower(cmd)=='y') {
            initializeBinaryFile(binFile);
            inputParts(binFile);
        }
    }
    chkbinFile.close();
    
    int input=0;
    while (input!=5) {
        printMenu();
        cin>>input;
        switch (input) {
            case 1:
                listFile(binFile);
                break;
            case 2:
                updateRecord(binFile);
                break;
            case 3:
                insertRecord(binFile);
                break;
            case 4:
                deleteRecord(binFile);
                break;
            case 5:
                cout<<"Thank you."<<endl;
                break;
                
            default:
                cout<<"Invalid choice."<<endl;
                break;
        }
    }
    return 0;
}

void printMenu(){
    cout<<"1. List all tools."<<endl;
    cout<<"2. Update a record."<<endl;
    cout<<"3. Insert a record."<<endl;
    cout<<"4. Delete a record."<<endl;
    cout<<"5. End Program."<<endl;
    cout<<"? ";
}
