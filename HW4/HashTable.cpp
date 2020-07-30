//
//  HashTable.cpp
//  cs202_hw4
//
//  Created by Ilknur Bas on 7.05.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//
/**
 * Author: İlknur Baş
 * ID: 21601847
 * Section: 2
 * Assignment: 4
 */

#include <stdio.h>
#include "HashTable.h"
#include <string>
#include <iostream>
using namespace std;
#include <cmath>

HashTable::HashTable(){
	
}
HashTable::HashTable(const int tableSize,const CollisionStrategy option ){
	arr_1[tableSize];
	for (int i=0;i<tableSize;i++){
		arr_1[i]=0;
	}
	tablesize =tableSize;
	if (option == LINEAR ) {
		collisonType= "LINEAR";
		
	}else if (option == QUADRATIC ) {
		collisonType= "QUADRATIC";
		
	}else if (option == DOUBLE ) {
		collisonType= "DOUBLE";
	}
}

HashTable::~HashTable(){
	
}

/*
 *First make sure that the inserted item is not in the hash table, then you can insert it
 *
 */
bool HashTable::insert( const int item ){
	bool a=true;

	if (searchForFindingIndex( item ) ==-2 ) {//you can insert, there is no such item.
		if ( collisonType== "LINEAR" ) {
			int index=hash(item);
			int index2=hash(item);
			int i=1;
			while( arr_1[index]!=0 && arr_1[index]!=-1 ) { //keep looking for finding empty spot
				index = (index2 + i) %tablesize;
				i++;
				if (index ==index2){
					a=false;
					break;
				}
			}
			if (a){
				arr_1[index]=item;
				cout <<item << " is inserted to index "<< index <<"."<<endl;
			}else{
				cout<<"Hash is full, "<<item<<" cannot inserted."<<endl;
			}
			return a;
			
		}else if ( collisonType== "QUADRATIC" ) {
			int index=hash(item);
			int index2=hash(item);
			int i=1;
			while( arr_1[index]!=0 && arr_1[index]!=-1 ) { //keep looking to find empty spot
				index = (index2 + (i*i)) %tablesize;
				i++;
				if (index ==index2){ // i == tablesize
					a=false;
					break;
				}
			}
			if (a){
				arr_1[index]=item;
				cout <<item << " is inserted to index "<< index <<"."<<endl;
			}else{
				cout<<""<<item<<" cannot inserted."<<endl; ////full değil yer var belki ama onu insert edemiyoruz
			}
			return a;
			
		}else if ( collisonType== "DOUBLE" ) {
			int index=hash(item);
			int index2=hash(item);
			int i=1;
			while( arr_1[index]!=0 && arr_1[index]!=-1 && hash2(item)!=0) { //keep looking to find empty spot
				index = (index2 + (i*hash2(item)) ) %tablesize;
				i++;
				if (index ==index2){ //Yada table size == i
					a=false;
					break;
				}
			}
			if (a){
				arr_1[index]=item;
				cout <<item << " is inserted to index "<< index <<"."<<endl;
				//display();
			}else{
				cout<<"Hash is full, "<<item<<" cannot inserted."<<endl;
			}
			return a;
		}
		
	}else {
		cout<<"The item "<<item<<" is already in the hash table."<<endl;
		a=false;
		return a;
	}
	
	return false;
}

int HashTable::hash(int key) {
	return key % tablesize;
}

int HashTable::hash2(int key) {
	string s= "";
	while(key>0 ) {
		int lastDigit= key % 10 ;
		key = key /10;
		s= s + to_string(lastDigit) ;
	}
	int reversedNumber =stoi(s);
	return reversedNumber;
}

//-2 is ok
bool HashTable::remove( const int item ){
	bool a=true;
	int index = searchForFindingIndex( item );
	if (index == -2) {
		cout <<item<<" not removed. There is no such item to be removed"<<endl;
		a=false;
	}else{
		arr_1[index] = -1;
		a=true;
		cout <<item <<" removed from index"<<index <<endl;
	}
	return a;
}

//This function is used in remove and insert functions
int HashTable::searchForFindingIndex( const int item ){
	bool a=true;
	if ( collisonType== "LINEAR" ){

		int index=hash(item);
		//cout <<"index"<<index<<endl ;
		int index2=hash(item);
		int i=1;

		if( arr_1[index]!=0) {
			while ( arr_1[index]!=item ) {
				index = (index2 + i) %tablesize;
				i++;
				if (arr_1[index]==0 || index ==index2 ){ //i=tablesize also works
					a=false;
					break;
				}
			}
		}else{
			a=false;
		}
		
		if (a) {
			return index;
		}else{
			return -2;
		}
		
	}else if ( collisonType== "QUADRATIC" ){
		
		int index=hash(item);
		int index2=hash(item);
		int i=1;
		
		if( arr_1[index]!=0) {
			while ( arr_1[index]!=item ) {
				index = (index2 + (i*i) ) %tablesize;
				i++;
				if (arr_1[index]==0 || index ==index2 ){ //i=tablesize also works
					a=false;
					break;
				}
			}
		}else{
			a=false;
		}
		
		if (a) {
			return index;
		}else{
			return -2;
		}
	}else if ( collisonType== "DOUBLE" ){
		
		int index=hash(item);
		int index2=hash(item);
		int i=1;
		
		if( arr_1[index]!=0) {
			while ( arr_1[index]!=item && hash2(item)!=0) {
				index = (index2 + (i*hash2(item) ) ) %tablesize;
				i++;
				if (arr_1[index]==0 || index ==index2 ){
					a=false;
					break;
				}
			}
		}else{
			a=false;
		}
		
		if (a) {
			return index;
		}else{
			return -2;
		}
	}
	return -2;
}
	

bool HashTable::search( const int item, int& numProbes ){
	bool a=true;
	if ( collisonType== "LINEAR" ){

		int index=hash(item);
		int index2=hash(item);
		int i=1;
		numProbes=1;
		
		if( arr_1[index]!=0) {
			while ( arr_1[index]!=item ) {
				index = (index2 + i) %tablesize;
				i++;
				numProbes++;
				if (arr_1[index]==0 || index ==index2 ){
					a=false;
					break;
				}
			}
		}else{
			a=false;
		}
		
		
		if (a) {
			cout <<"Searched item "<< item<<" is found in index "<<index<<"";
		}else{
			cout <<"Searched item "<< item<<" is not found"<<"" ;
		}
		return a;
		
	}else if ( collisonType== "QUADRATIC" ){

		int index=hash(item);
		int index2=hash(item);
		int i=1;
		numProbes=1;
		
		
		if( arr_1[index]!=0) {
			while ( arr_1[index]!=item ) {
				index = (index2 + (i*i)) %tablesize;
				i++;
				numProbes++;
				if (arr_1[index]==0 || index ==index2 ){
					a=false;
					break;
				}
			}
		}else{
			a=false;
		}
		
		if (a) {
			cout <<"Searched item "<< item<<" is found in index "<<index<<"";
		}else{
			cout <<"Searched item "<< item<<"is not found"<<"" ;
		}
		return a;
	}else if ( collisonType== "DOUBLE" ){

		int index=hash(item);
		int index2=hash(item);
		int i=1;
		numProbes=1;
		
		if( arr_1[index]!=0) {
			while ( arr_1[index]!=item && hash2(item)!=0) {
				index = (index2 + (i*hash2(item))) %tablesize;
				i++;
				numProbes++;
				if (arr_1[index]==0 || index ==index2 ){
					a=false;
					break;
				}
			}
		}else{
			a=false;
		}
		
		if (a) {
			cout <<"Searched item "<< item<<" is found in index "<<index<<"";
		}else{
			cout <<"Searched item "<< item<<"is not found"<<"" ;
		}
		return a;
	}
	

	return a;
}

void HashTable::display(){
	cout <<"DISPLAY"<<endl;
	for (int i=0;i<tablesize;i++){
		if (arr_1[i]==-1 || arr_1[i]==0) {
			cout <<i <<":"<<""<<endl;
			//cout <<i <<":"<<arr_1[i] <<""<<endl; //in order to track indexes with deleted items
		}else{
			cout <<i <<":"<<arr_1[i] <<""<<endl;
		}
	}
}



void HashTable::analyzeTheoretical(){
	double currentItems=0;
	for (int i=0;i<tablesize;i++) {
		if (arr_1[i]!=0 && arr_1[i]!=-1  ) {
			currentItems++;
		}
	}
	double successful;
	double unsuccessful;
	
	double a = (double)currentItems/(double)tablesize;
	if ( collisonType== "LINEAR" ){
		//successful
		successful= ( 1+ (1/(1-a) ) ) /2;
		cout<<"LINEAR, Theoretical , successful :"<<successful<<endl;
		//unsuccessful
		
		unsuccessful= (1+ (1/((1-a)*(1-a)) ) ) /2;
		cout<<"LINEAR, Theoretical , unsuccessful :"<<unsuccessful<<endl;
		currentItems=0;
		
	}else if ( collisonType== "QUADRATIC" ){
		//successful
		successful= - ( (log(1-a)) / a);
		cout<<"QUADRATIC, Theoretical , successful :"<<successful<<endl;
		//unsuccessful
		unsuccessful= 1/(1-a);
		cout<<"QUADRATIC, Theoretical , unsuccessful :"<<unsuccessful<<endl;
		 currentItems=0;
		
	}else if ( collisonType== "DOUBLE" ){
		//successful
		successful= - ( (log(1-a)) / a);
		cout<<"DOUBLE, Theoretical , successful :"<<successful<<endl;
		//unsuccessful
		unsuccessful= 1/(1-a);
		cout<<"DOUBLE, Theoretical , unsuccessful :"<<unsuccessful<<endl;
		currentItems=0;
	}
	
	
}
 
void HashTable::analyze( double& numSuccProbes, double& numUnsuccProbes ){
	
	double currentItems=0;
	for (int i=0;i<tablesize;i++) {
		if (arr_1[i]!=0 && arr_1[i]!=-1  ) {
			currentItems++;
		}
	}
	
	int oneprobe;
	if ( collisonType== "LINEAR" ){
		//successful
		numSuccProbes=0;
		for (int i=0;i<tablesize;i++) {
			if (arr_1[i]!=0 && arr_1[i]!=-1)  {
				search(arr_1[i], oneprobe);
				cout <<" probe:"<<oneprobe<<endl;
				numSuccProbes=numSuccProbes+oneprobe;
			}
		}
		numSuccProbes=numSuccProbes/currentItems;
		
		//unsuccessful bir indexten basla boş bulana kadar
		int i=1;
		int count=0;
		int counter=0;
		
		for (int j=0;j<tablesize;j++) {
			int index=j;
			int index2=j;
			int index3=-5;
			while( arr_1[index]!=0  && index!=index3 ){
				index3=j;
				index = (index2 + i) %tablesize;
				i++;
				count++;
			}
			i=1;
			count++;
			counter =counter+count;
			//cout<<"COUNT:"<<count<<endl;
			count=0;
		}
		//cout<<"counter:"<<counter<<endl;
		numUnsuccProbes=(double)counter/tablesize;
		
	}else if ( collisonType== "QUADRATIC" ){
		//successful
		numSuccProbes=0;
		for (int i=0;i<tablesize;i++) {
			if (arr_1[i]!=0 && arr_1[i]!=-1)  {
				search(arr_1[i], oneprobe);
				cout <<" probe:"<<oneprobe<<endl;
				numSuccProbes=numSuccProbes+oneprobe;
			}
		}
		numSuccProbes=numSuccProbes/currentItems;
		
		//unsuccessful bir indexten basla boş bulana kadar
		int i=1;
		int count=0;
		int counter=0;
		
		for (int j=0;j<tablesize;j++) {
			int index=j;
			int index2=j;
			int index3=-5;
			//while( arr_1[index]!=0  && index!=index3 ){
			int x =-5;
			while( arr_1[index]!=0  && i!=tablesize ){
				index3=j;
				index = (index2 + (i*i)) %tablesize;
				i++;
				x=i;
				
				count++;
			}
			i=1;
			count++;
			counter =counter+count;
			//cout<<"COUNT:"<<count<<endl;
			count=0;
		}
		//cout<<"counter:"<<counter<<endl;
		numUnsuccProbes=(double)counter/tablesize;
		
		
	}else if ( collisonType== "DOUBLE" ){
		//successful
		numSuccProbes=0;
		for (int i=0;i<tablesize;i++) {
			if (arr_1[i]!=0 && arr_1[i]!=-1)  { 
				search(arr_1[i], oneprobe);
				cout <<" probe:"<<oneprobe<<endl;
				numSuccProbes=numSuccProbes+oneprobe;
			}
		}
		numSuccProbes=numSuccProbes/currentItems;
		
		//unsuccessful
		numUnsuccProbes=-1;
		

	}
	
	
}


