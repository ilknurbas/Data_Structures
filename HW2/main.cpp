/**
 * Author: Name Surname * ID: 21601847
 * Section: 2
 * Assignment: 2
 */
//  main.cpp
//  hw2Trees
//
//  Created by Ilknur Bas on 16.03.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#include <iostream>
#include "DecisionTreeNode.h"
#include "DecisionTree.h"

int main(int argc, const char * argv[]) {
    cout << "Program is starting...\n";
    DecisionTree a;

	double predictionRatio;
	a.train("train_data.txt", 498, 21);
	a.numOFFeatures=21;
	predictionRatio =a.test("test_data.txt", 498);
	cout << "Prediction ratio:"<<(double)predictionRatio<<endl;
    return 0;

}



