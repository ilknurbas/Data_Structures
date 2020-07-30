//
//  priorityQueue.h
//  iteration2_cs202hw3
//
//  Created by Ilknur Bas on 23.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#ifndef priorityQueue1_h
#define priorityQueue1_h
#include "Patient1.h"
#include "maxHeap1.h"

class PQException : public exception {
	
private:
	string msg;
	
public:
	virtual const char* what() const throw()
	{
		return msg.c_str();
	}
	PQException(const string& message = "") :
	exception(), msg(message) {};
	~PQException() throw() {};
	
}; // end TreeException


class priorityQueue1 {
public:
	// default constructor, copy constructor, and destructor
	// are supplied by the compiler
	
	// priority-queue operations:
	bool pqIsEmpty() const;
	void pqInsert(const Patient1& newItem) throw (PQException);
	void pqDelete(Patient1& priorityItem) throw (PQException);
	void returnSpecificPatient(int i);
	int returnSize();
	
private:
	maxHeap1 h;
};





#endif /* priorityQueue1_h */
