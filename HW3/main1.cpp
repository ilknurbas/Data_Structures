//
//  main.cpp
//  iteration2_cs202hw3
//
//  Created by Ilknur Bas on 20.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
#include "simulator1.h"

int main (int argc, const char * argv[]) {
	std::cout << "Program is starting...\n";
	
	int maxAverageTime;
	string fileName;
	if (argc > 1) {
		fileName = argv[1];
		maxAverageTime = atoi(argv[2]);
		cout << "read from command line argument" << maxAverageTime << endl;
		
	}else {
		maxAverageTime =10;
		fileName = "sample.txt";
		cout << "not read from command line, fixed file name will be used" << endl;
	}
	
	simulator1 s;
	s.readFile(fileName,maxAverageTime);
	cout << "END OF THE QUESTION 1" << endl;
	
	return 0;
} 
