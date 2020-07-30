//
//  HashTable.h
//  cs202_hw4
//
//  Created by Ilknur Bas on 7.05.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//
/**
 * Author: İlknur Baş
 * ID: 21601847
 * Section: 2
 * Assignment: 4
 */

#ifndef HashTable_h
#define HashTable_h

#include <iostream>
using namespace std;

enum CollisionStrategy { LINEAR, QUADRATIC, DOUBLE };
const int MAX_SIZE=100;
class HashTable{
	
public:
	HashTable();
	HashTable(const int tableSize,const CollisionStrategy option );
	~HashTable();
	bool insert( const int item );
	bool remove( const int item );
	bool search( const int item, int& numProbes );
	void display();
	void analyze( double& numSuccProbes, double& numUnsuccProbes );
	int hash(int key);
	int hash2(int key);
	int searchForFindingIndex( const int item );
	void analyzeTheoretical();
		
private:
	
	int arr_1[MAX_SIZE];
	string collisonType ;
	int tablesize;
};




#endif /* HashTable_h */
