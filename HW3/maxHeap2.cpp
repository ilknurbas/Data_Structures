//
//  maxHeap2.cpp
//  CS202HW3QUESTION2iteration2
//
//  Created by Ilknur Bas on 23.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//


#include <stdio.h>
#include "maxHeap2.h"
#include <string>
#include <iostream>
using namespace std;
#include <fstream>

//some commentted parts are used for tracking purposes.
maxHeap2::maxHeap2() {
	max_heap=10;
	size = 0;
	items = new Patient2[max_heap];
}

maxHeap2::~maxHeap2() {
	/*if (items != NULL) {
	 delete items;
	 items = NULL;
	 }*/

	//if (size != 0){
	//if (items){
		delete[]items;
	//}
	
}

void maxHeap2::heapInsert(const Patient2& newItem) {
	//cout<<"size:"<<size<<endl;
	//cout<<"max_heap:"<<max_heap<<endl;
	if (size == 0){ //her başta insert edeceğiz
		cout<<"heap size is 0"<<endl;
		delete[] items;
		max_heap=10;
		items = new Patient2[max_heap];
	
	}
	else if (size >= max_heap){
		cout<<"heap full-double"<<endl;
		Patient2 *temp= items;
		items= new Patient2[max_heap*2];
		for (int i=0;i<max_heap;i++){
			items[i]=temp[i];
		}
		delete []temp;
		//cout<<"size after doubling size:"<<size<<endl;
		max_heap=max_heap*2;
		//cout<<"max_heap after doubling size:"<<max_heap<<endl;
		
	}
	
	// Place the new item at the end of the heap
	items[size] = newItem;
	
	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
	
	
	while ( (place > 0) && (items[place].getPatientPriority() >= items[parent].getPatientPriority() ) ) {
		if (items[place].getPatientPriority() == items[parent].getPatientPriority() ) { //arrive time
			if(items[place].getPatientArrivingTime() < items[parent].getPatientArrivingTime()){
				Patient2 temp = items[parent];
				items[parent] = items[place];
				items[place] = temp;
				
				place = parent;
				parent = (place - 1)/2;
			}
			place = parent;
			parent = (place - 1)/2;
			//else dont swap right position
		}else if (items[place].getPatientPriority() > items[parent].getPatientPriority() ){ //highest priority e göre if (items[place].priority > items[parent].priority )
			Patient2 temp = items[parent];
			items[parent] = items[place];
			items[place] = temp;
			
			place = parent;
			parent = (place - 1)/2;
		}
		
	}
	++size;

}

bool maxHeap2::heapIsEmpty() const{
	return size==0;
}

void maxHeap2::heapDelete(Patient2& rootItem){
	if (heapIsEmpty())
		cout<<"Heap empty";
		
	else {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild(0);
		//after deletion
		if (size <= max_heap/2){ //shrink the heap
			
			Patient2 *temp= items;
			items= new Patient2[max_heap/2];
			for (int i=0;i<max_heap/2;i++){
				items[i]=temp[i];
			}
			delete []temp;
		//	cout<<"size after shrink size(aynı kalması lazım):"<<size<<endl; //
			max_heap=max_heap/2;
			//cout<<"max_heap after shrink size: "<<max_heap<<endl;
			
		}
	}
	
}
void maxHeap2::heapRebuild(int root){
	int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < size ) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < size) &&(items[rightChild].getPatientPriority() > items[child].getPatientPriority() ) ) {
			child = rightChild; 	// index of larger child
		}
		
		if ( (rightChild < size) &&(items[rightChild].getPatientPriority() == items[child].getPatientPriority() ) && (items[rightChild].getPatientArrivingTime() < items[child].getPatientArrivingTime() ) ) {
			child = rightChild;
		}
		
		
		// If root’s item is smaller than larger child, swap values
		if ( items[root].getPatientPriority() < items[child].getPatientPriority() ) {
			
			
			Patient2 temp = items[root];
			items[root] = items[child];
			items[child] = temp;
			
			// transform the new subtree into a heap
			heapRebuild(child);
			
		} //else
		else if ( ( items[root].getPatientPriority() == items[child].getPatientPriority()) && (items[root].getPatientArrivingTime() > items[child].getPatientArrivingTime()) ) {
			Patient2 temp = items[root];
			items[root] = items[child];
			items[child] = temp;
			
			// transform the new subtree into a heap
			heapRebuild(child);
			
		}
		
	}
}


void maxHeap2::returnSpecificPatient(int i){
	
	cout << items[i].getPatientId() <<" "<< items[i].getPatientPriority() <<" "<< items[i].getPatientArrivingTime() <<" "<<items[i].getPatientExaminationTime() <<endl;
	
}

int maxHeap2::returnSize(){
	return size;
}




