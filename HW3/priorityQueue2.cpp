//
//  priorityQueue.cpp
//  CS202HW3QUESTION2iteration2
//
//  Created by Ilknur Bas on 23.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//


#include <stdio.h>
#include "priorityQueue2.h"


bool priorityQueue2::pqIsEmpty() const {
	return h.heapIsEmpty();
}

void priorityQueue2::pqInsert(const Patient2& newItem) {
		h.heapInsert(newItem);
}

void priorityQueue2::pqDelete(Patient2& priorityItem)  {
		h.heapDelete(priorityItem);

}

void priorityQueue2::returnSpecificPatient(int i){
	h.returnSpecificPatient(i);
}
int  priorityQueue2::returnSize(){
	return h.returnSize();
}


