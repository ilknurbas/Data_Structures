//
//  simulator.h
//  iteration2_cs202hw3
//
//  Created by Ilknur Bas on 20.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#ifndef simulator1_h
#define simulator1_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include "priorityQueue1.h"


struct Doctor 
{
	int avaliabilityTime;
};


class simulator1{
public:
	simulator1();
	~simulator1();
	void readFile(string fileName, int maxAverage);
	void doctorAssign( const int maxAverage,int noOfpatients);
	double doctorAssign2( const int doctorNo,int noOfpatients);

private:
	int noOfpatients ;
	Patient1 item2[MAX_HEAP];	//array of patients used when extracting data from txt
	priorityQueue1 pq ;

};


#endif /* simulator1_h */


