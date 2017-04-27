//
//  sorting.cpp
//  Ass2
//
//  Created by Mohamed Asjad Athick on 5/09/2015.
//  Student 4970512
//  Copyright (c) 2015 Asjad Athick. All rights reserved.
//

#include "sorting.h"

void quicksortData(Data records[], int p, int q)
{
    int r=0;
    if (p<q)
    {
        r= partition(records, p, q);
        quicksortData(records, p, r-1);
        quicksortData(records, r+1, q);
    }
}

int partition(Data records[], int p, int q) //p is the starting index, q is the number of elements
{
    Data temp;
    Data x;
    strcpy(x.name, records[p].name);
    
    int i=p;
    for (int j=p+1; j<=q; j++)
    {
        if (strcmp(records[j].name, x.name)<=0)
        {
            i++;
            temp=records[i];
            records[i]=records[j];
            records[j]=temp;
        }
    }
    temp=records[p];
    records[p]=records[i];
    records[i]=temp;
    return i;
}

void insertionSort(Data data[], int numRecords){
    int i, j;
    Data next;
    for (i = 1; i < numRecords; i++){
        next = data[i];
        j = i;
        while (j > 0 && (next.age > data[j-1].age)) {
            data[j] = data[j-1];
            j--;
        }
        data[j] = next;
    }
}

void selectionSort(Data data[], int numRecords){
    int i, j, index_of_largest;
    Data largest;
    if (numRecords == 0) return;
    for(i = numRecords-1; i > 0; --i) {
        largest = data[0];
        index_of_largest = 0;
        for (j=1; j <= i; j++)
            if (data[j].balance < largest.balance) {
                largest = data[j];
                index_of_largest = j;
            }
        Data temp = data[i]; // swap
        data[i] = data[index_of_largest];
        data[index_of_largest] = temp;
    }

}