--bag.h--

#include <iostream>
#ifndef _BAG_

const int INCREMENT=10;
#define _BAG_
class Bag{
private:
	int *array;
	int arraySize;
	int capacity;
public:
	Bag();
	Bag(const Bag);
	~Bag();
	void putIn(int);
	bool takeOut(int);
	void print(std::iostream &) const;
};
#endif

--bag.cpp--

#include "bag.h"
Bag::Bag(){
	arraySize=0;
	capacity=INCREMENT;
	array=new int[capacity];
}

Bag::~Bag(){
	if(array!=NULL)
		delete [] array;
	data=NULL;
}

void Bag::putIn(int d){
	if(size>=capacity){
		//mem full
		capacity+=INCREMENT;
		int *tmp=new int[capacity];
		//copy old
		for(int i=0;i<size;i++){
			tmp[i]=array[i];
		}
		tmp[size]=d;
		delete [] data;
		data=tmp;
		size++;
	}
	else
	{
		array[size]=d;

	}
}

bool:Bag::takeOut(int d){
	//find element
	int i;
	bool foundFlag=false;
	for (i = 0; i < arraySize && !foundFlag; ++i)
	{
		if (array[i]==d)
		{
			foundFlag=true;
		}
	}
	if (foundFlag)
	{
		for(;i<size-1;i++){
			array[i]=array[i+1];
		}
		size--;
	}

	return foundFlag;

}

void Bag::print(std::ostream &out) const{
	for(int i=0;i<size;i++){
		out<<array[i]<<" ";
	}
	out<<std::endl;
}

--main.cpp--

#include "bag.h"
using namespace std;

int main(){
	Bag store;
	int tmp;
	while(cin>>tmp){
		store.putIn(tmp);
	}
	cout<<"Which data do you want to remove?";
	cin>>tmp;
	if(store.takeOut(tmp)){
		cout<<"Data removed: "<<tmp<<endl;
	}
	else
		cout<<"Data doesn't exist"<<endl;

	store.print(cout);
}


