//
//  simulator.h
//  CS202HW3QUESTION2iteration2
//
//  Created by Ilknur Bas on 23.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//


#ifndef simulator_h
#define simulator_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include "priorityQueue2.h"


struct Doctor
{
	int avaliabilityTime;
};


class simulator2{
public:
	simulator2();
	~simulator2();
	void readFile(string fileName, int maxAverage);
	void doctorAssign( const int maxAverage,int noOfpatients);
	double doctorAssign2( const int doctorNo,int noOfpatients);
	
private:
	int noOfpatients ;
	//Patient item2[MAX_HEAP];	//array of patients used when extracting data from txt
	Patient2* item2; //in order to store all patients when extracting data from txt file
	priorityQueue2 pq ;
	
};




#endif /* simulator_h */


