//
//  Queue.h
//  cs202hw5
//
//  Created by Ilknur Bas on 21.05.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

const int MAX_QUEUE = 100;


class Queue{
public:
	Queue();
	bool isEmpty() const;
	bool enqueue( int newItem);
	bool dequeue();
	bool dequeue( int& queueFront);
	bool getFront( int& queueFront) const;
	
private:
	
	int items[MAX_QUEUE];
	int           front;
	int           back;
	int           count;
	
};


#endif  
