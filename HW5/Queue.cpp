//
//  Queue.cpp
//  cs202hw5
//
//  Created by Ilknur Bas on 21.05.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#include <stdio.h>
#include "Queue.h"


Queue::Queue():front(0), back(MAX_QUEUE-1), count(0){
	
}
bool Queue::isEmpty() const {
	
	return (count == 0);
	
}
bool Queue::enqueue(int newItem) {
	
	if (count == MAX_QUEUE)
		return false;
	
	else{
		// queue is not full; insert item
		back = (back+1) % MAX_QUEUE;
		items[back] = newItem;
		++count;
		
		return true;
	}
	
}
bool Queue::dequeue(){
	
	if (isEmpty())
		return false;
	
	else {
		// queue is not empty; remove front
		front = (front+1) % MAX_QUEUE;
		--count;
		
		return true;
	}
	
}
bool Queue::dequeue(int& queueFront) {
	
	if (isEmpty())
		return false;
	
	else{
		// queue is not empty;
		// retrieve and remove front
		queueFront = items[front];
		front = (front+1) % MAX_QUEUE;
		--count;
		
		return true;
	}
	
}
bool Queue::getFront(int& queueFront)const {
	
	if (isEmpty())
		return false;
	
	else{
		// queue is not empty; retrieve front
		queueFront = items[front];
		
		return true;
	}
	
}
