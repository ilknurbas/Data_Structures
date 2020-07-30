//
//  List.cpp
//  cs202hw5
//
//  Created by Ilknur Bas on 21.05.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#include <stdio.h>
#include "List.h"  //header file


List::List() : size(0){}

bool List::isEmpty() const{
	return size == 0;
}

int List::getLength() const{
	return size;
	
}

int List::translate(int index) const{
	return index - 1;
}
bool List::retrieve(int index,int& dataItem) const{
	bool success = (index >= 1) && (index <= size);
	if (success)
		dataItem = items[translate(index)];
	return success;
}

bool List::insert(int index, int newItem){
	
	bool success = (index >= 1) &&(index <= size + 1) &&(size < MAX_LIST);
	
	if (success){
		for (int pos = size; pos >= index; --pos)
			items[translate(pos+1)] = items[translate(pos)];
		
		items[translate(index)] = newItem;
		++size;
	}
	return success;
}

bool List::remove(int index){
	bool success = (index >= 1) && (index <= size) ;
	
	if (success){
		for (int fromPosition = index+1;
			 fromPosition <= size;
			 ++fromPosition)
			items[translate(fromPosition-1)] =items[translate(fromPosition)];
		
		--size;
	}
	return success;
	
}





