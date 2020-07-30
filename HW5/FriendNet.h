//
//  FriendNet.h
//  cs202hw5
//
//  Created by Ilknur Bas on 21.05.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#ifndef FriendNet_h
#define FriendNet_h

#include "List.h"
#include <string>
using namespace std;
class FriendNet{
public:
	FriendNet(const string fileName);// constructor
	FriendNet(const FriendNet& aNet);// copy constructor
	~FriendNet();// destructor
	
	void listFriends(const string personName, const int hopNo);
	
	void displayAverageDegrees();
	double displayAverageDegreesHelper(int person);
	
	void displayDiameters();
	int componentFinder(int componentCounter);
	int findShortestLongest(string name);
	 
		
	int personNameToInt(string personName);
	
 
 
private:
	
	List *adjacent;
	string *names;
	int noOfpeople;
	int *hop;
	bool *visitedComponents;
	int noOfComponents;
	bool *visitedEachComponents ;
	string *namesComponents;
	
	bool txtController;
	
	
}; 


#endif /* FriendNet_h */
