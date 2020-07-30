//
//  maxHeap1.cpp
//  iteration2_cs202hw3
//
//  Created by Ilknur Bas on 20.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

/*made changes in insert and rebuild functions. in the case of patients having the same priority,lowest arriving time will be choosen.*/
#include <stdio.h>
#include "maxHeap1.h"
#include <string>
#include <iostream>
using namespace std;
#include <fstream>

maxHeap1::maxHeap1() {
	size = 0;
}

void maxHeap1::heapInsert(const Patient1& newItem) {
	//cout<<"size:"<<size<<endl;
	//cout<<"MAX_HEAP:"<<MAX_HEAP<<endl;
	if (size >= MAX_HEAP){
		throw HeapException("exception: heap full");
		//cout<<"heap full"<<endl;
	}else{
		// Place the new item at the end of the heap
		items[size] = newItem;
		
		// Trickle new item up to its proper position
		int place = size;
		int parent = (place - 1)/2;
		
		
		while ( (place > 0) && (items[place].getPatientPriority() >= items[parent].getPatientPriority() ) ) {
			if (items[place].getPatientPriority() == items[parent].getPatientPriority() ) { //arrive time
				if(items[place].getPatientArrivingTime() < items[parent].getPatientArrivingTime()){
					Patient1 temp = items[parent];
					items[parent] = items[place];
					items[place] = temp;
					
					place = parent;
					parent = (place - 1)/2;
				}
				place = parent;
				parent = (place - 1)/2;
				 
			}else if (items[place].getPatientPriority() > items[parent].getPatientPriority() ){ //highest priority e göre if (items[place].priority > items[parent].priority )
				Patient1 temp = items[parent];
				items[parent] = items[place];
				items[place] = temp;
				
				place = parent;
				parent = (place - 1)/2;
			}
			
		}
		++size;
	}
	
}

bool maxHeap1::heapIsEmpty() const{
	return size==0;
}



void maxHeap1::heapDelete(Patient1& rootItem){
	if (heapIsEmpty()){
		throw HeapException("exception: heap empty");
		//cout<<"Heap empty";
	}
	else {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild(0);
	}
	
}
void maxHeap1::heapRebuild(int root){
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
			
			
			Patient1 temp = items[root];
			items[root] = items[child];
			items[child] = temp;
			
			// transform the new subtree into a heap
			heapRebuild(child);
			
		} //else
		else if ( ( items[root].getPatientPriority() == items[child].getPatientPriority()) && (items[root].getPatientArrivingTime() > items[child].getPatientArrivingTime()) ) {
			Patient1 temp = items[root];
			items[root] = items[child];
			items[child] = temp;
			
			// transform the new subtree into a heap
			heapRebuild(child);
			
		}
		
	}
}


void maxHeap1::returnSpecificPatient(int i){
	
	cout << items[i].getPatientId() <<" "<< items[i].getPatientPriority() <<" "<< items[i].getPatientArrivingTime() <<" "<<items[i].getPatientExaminationTime() <<endl;
	
}

int maxHeap1::returnSize(){
	return size;
}




