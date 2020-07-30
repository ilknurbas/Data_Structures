//
//  maxHeap2.h
//  CS202HW3QUESTION2iteration2
//
//  Created by Ilknur Bas on 23.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#ifndef maxHeap2_h
#define maxHeap2_h


#include <string>
#include <iostream>
using namespace std;

#include "Patient2.h"


class maxHeap2 {
	
public:
	maxHeap2();
	~maxHeap2();
	void heapInsert(const Patient2& newItem) ;
	bool heapIsEmpty() const;
	void heapDelete(Patient2& rootItem);
	
	void returnSpecificPatient(int i);
	int returnSize();
	
protected:
	void heapRebuild(int root);
	
private:
	//int MAX_HEAP = 10 ;
	int max_heap;
	Patient2* items;	// array of heap items
	int          size;    // number of heap items
	
/*	Patient items[MAX_HEAP];	// array of heap items
	int          size;            	// number of heap items*/
	
};



#endif /* maxHeap2_h */







