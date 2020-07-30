//
//  priorityQueue.h
//  CS202HW3QUESTION2iteration2
//
//  Created by Ilknur Bas on 23.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#ifndef priorityQueue2_h
#define priorityQueue2_h

#include "Patient2.h"
#include "maxHeap2.h"


class priorityQueue2 {
public:
	// default constructor, copy constructor, and destructor
	// are supplied by the compiler
	
	// priority-queue operations:
	bool pqIsEmpty() const;
	void pqInsert(const Patient2& newItem) ;
	void pqDelete(Patient2& priorityItem) ;
	void returnSpecificPatient(int i);
	int returnSize();
	
private:
	maxHeap2 h;
};



#endif /* priorityQueue2_h */
