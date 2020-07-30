/**
 * Author: Name Surname * ID: 21601847
 * Section: 2
 * Assignment: 2
 */
//  DecisionTreeNode.cpp
//  hw2Trees
//
//  Created by Ilknur Bas on 16.03.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#include <stdio.h>
#include "DecisionTreeNode.h"

DecisionTreeNode::DecisionTreeNode(){}

DecisionTreeNode::DecisionTreeNode(const int& anItem):featureId(anItem){
    rightChildPtr = NULL;
    leftChildPtr = NULL;
}

DecisionTreeNode::DecisionTreeNode(const int& anItem, DecisionTreeNode* leftPtr, DecisionTreeNode* rightPtr)
:featureId(anItem),leftChildPtr(leftPtr),rightChildPtr(rightPtr){}

void DecisionTreeNode::setItem( const int& anItem){
    featureId = anItem;
}

int DecisionTreeNode::getItem() const{
    return featureId;
}

DecisionTreeNode* DecisionTreeNode::getLeftChildPtr() const {
    return leftChildPtr;
}

DecisionTreeNode* DecisionTreeNode::getRightChildPtr() const {
    return rightChildPtr;
}

void DecisionTreeNode::setLeftChildPtr(DecisionTreeNode* leftPtr){
    leftChildPtr = leftPtr;
}

void DecisionTreeNode::setRightChildPtr(DecisionTreeNode* rightPtr){
    rightChildPtr = rightPtr;
}

bool DecisionTreeNode::isLeaf() const{
    if (rightChildPtr == NULL && leftChildPtr == NULL)
        return true;
    return false;
}


