//
//  priorityQueue.cpp
//  iteration2_cs202hw3
//
//  Created by Ilknur Bas on 23.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#include <stdio.h>
#include "priorityQueue1.h"


bool priorityQueue1::pqIsEmpty() const {
	return h.heapIsEmpty();
}

void priorityQueue1::pqInsert(const Patient1& newItem) throw (PQException){
	try {
		h.heapInsert(newItem);
	}
	catch (exception e) {
		throw PQException("Priority queue is full");
	}
}

void priorityQueue1::pqDelete(Patient1& priorityItem) throw (PQException) {
	try {
		h.heapDelete(priorityItem);
	}
	catch (exception e) {
		throw PQException("Priority queue is empty");
	}
}

void priorityQueue1::returnSpecificPatient(int i){
	h.returnSpecificPatient(i);
}
int  priorityQueue1::returnSize(){
	return h.returnSize();
}


