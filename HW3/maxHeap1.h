//
//  maxHeap1.h
//  iteration2_cs202hw3
//
//  Created by Ilknur Bas on 20.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//



#ifndef maxHeap1_h
#define maxHeap1_h

#include <string>
#include <iostream>
using namespace std;

#include "Patient1.h"

class HeapException : public exception {
	
private:
	string msg;
	
public:
	virtual const char* what() const throw()
	{
		return msg.c_str();
	}
	HeapException(const string& message = "") :
	exception(), msg(message) {};
	~HeapException() throw() {};
	
};

const int MAX_HEAP = 2000 ;
class maxHeap1 {
	
public:
	maxHeap1();
	
	void heapInsert(const Patient1& newItem) ;
	bool heapIsEmpty() const;
	void heapDelete(Patient1& rootItem);

	void returnSpecificPatient(int i);
	int returnSize();
	
protected:
	void heapRebuild(int root);
	
private:
	Patient1 items[MAX_HEAP];	// array of heap items
	int          size;            	// number of heap items
	
};






#endif /* maxHeap1_h */
