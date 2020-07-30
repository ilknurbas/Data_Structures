//
//  List.h
//  cs202hw5
//
//  Created by Ilknur Bas on 21.05.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#ifndef List_h
#define List_h

const int MAX_LIST = 100;

class List{

public:
	List();
	bool isEmpty() const;
	int getLength() const;
	bool retrieve(int index,int& dataItem) const;
	bool insert(int index,int newItem);
	bool remove(int index);
	
private:
	int items[MAX_LIST];
	// array of list items
	
	int size;// number of items in list
	
	int translate(int index) const;
	
}; 
	
	
	

#endif /* List_h */
