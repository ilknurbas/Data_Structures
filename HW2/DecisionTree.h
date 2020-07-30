/**
 * Author: Name Surname * ID: 21601847
 * Section: 2
 * Assignment: 2
 */
//  DecisionTree.h
//  hw2Trees
//
//  Created by Ilknur Bas on 16.03.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#ifndef DecisionTree_h
#define DecisionTree_h

#include <iostream>
#include "DecisionTreeNode.h"

using namespace std;

class DecisionTree{

public:
    DecisionTreeNode *root;
    int numOFFeatures;
    
    //calculation
    double calculateEntropy(const int* classCounts, const int numClasses);
    double calculateInformationGain(const bool** data, const int* labels, const int numSamples, const int numFeatures, const bool* usedSamples, const int featureId);
   
    //train data
    bool * calculateleftSample(const bool** data, const int* labels, const int numSamples, const int numFeatures, const bool* usedSamples, const int featureId);
    bool * calculaterightSample(const bool** data, const int* labels, const int numSamples, const int numFeatures, const bool* usedSamples, const int featureId);
    void train(const bool** data, const int* labels, const int numSamples, const int numFeatures,bool *usedSamples,bool *checkLeafFeatureId,DecisionTreeNode *  &root);
    void train(const bool**, const int*, const int, const int);
    void train(const string, const int, const int);
    
    //prediction
	int predict(const bool*);
	int predict(const bool* data,DecisionTreeNode* a);
    int getNoOfFeatures();
    
    //test data
    double test(const bool**, const int*, const int);
    double test(const string, const int);
    
    //print
    void print();
    void printTree(DecisionTreeNode* decisionTreeNode, int height) ;
    
 
};

#endif /* DecisionTree_h */
