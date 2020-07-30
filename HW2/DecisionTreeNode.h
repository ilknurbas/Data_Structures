/**
 * Author: Name Surname * ID: 21601847
 * Section: 2
 * Assignment: 2
 */
//  DecisionTreeNode.h
//  hw2Trees
//
//  Created by Ilknur Bas on 16.03.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//  .h file of DecisionTreeNode

#ifndef DecisionTreeNode_h
#define DecisionTreeNode_h

#include <iostream>
using namespace std;

class DecisionTreeNode{
	
private:
	int featureId;
		
public:
	DecisionTreeNode* leftChildPtr;
	DecisionTreeNode* rightChildPtr;
    bool isLeaf() const;
    
    DecisionTreeNode();
    DecisionTreeNode(const int& anItem);
    DecisionTreeNode(const int& anItem, DecisionTreeNode* leftPtr, DecisionTreeNode* rightPtr);
    
    void setItem( const int& anItem);
    int getItem() const ;
    
    DecisionTreeNode* getLeftChildPtr() const ;
    DecisionTreeNode* getRightChildPtr() const ;
    void setLeftChildPtr(DecisionTreeNode* leftPtr);
    void setRightChildPtr(DecisionTreeNode* rightPtr);
 
};


#endif /* DecisionTreeNode_h */
