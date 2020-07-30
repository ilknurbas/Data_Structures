/**
 * Author: Name Surname * ID: 21601847
 * Section: 2
 * Assignment: 2
 */
 
//  DecisionTree.cpp
//  hw2Trees
//
//  Created by Ilknur Bas on 16.03.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#include "DecisionTree.h"
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
#include <fstream>

double DecisionTree::calculateEntropy(const int* classCounts, const int numClasses){
    double entropy=0;
    //find all
    double all=0;
    for (int i=0; i<numClasses; i++ ){
        all = all +  classCounts[i];
    }
    for (int i=0;i<numClasses;i++ ){
        if ( classCounts[i] != 0){
            entropy = entropy +( (double)(classCounts[i]/all) * (double)log2((double)classCounts[i]/all) ) ;
        }
    }
    entropy = 0-entropy;
    return entropy;
}

double  DecisionTree::calculateInformationGain(const bool** data, const int* labels, const int numSamples, const int numFeatures, const bool* usedSamples, const int featureId){

    double parentEntropy=0;
    double childEntropy;
    double entropyLeft;
    double entropyRight;
    int numClassLeft=0;
    int numClassRight=0;
    int *classCountsLeft =new int [3];
    for(int i=0;i<3;i++){
        classCountsLeft[i]=0;
    }
    int *classCountsRight;
    classCountsRight =new int [3];
    for(int i=0;i<3;i++){
        classCountsRight[i]=0;
    }
	int *classCountsParent =new int [3];
    for(int i=0;i<3;i++){
        classCountsParent[i]=0;
    }
    
    //parent
    for (int i=0; i< numSamples;i++) {
        if (usedSamples [i] == true ){//kullanılacak
            if ( labels[i] == 1 ) //class no
                classCountsParent[0] ++;
            else if(labels[i]  == 2 ) {
                classCountsParent[1] ++;
            }else
                classCountsParent[2] ++;
     	}
    }
    parentEntropy =calculateEntropy(classCountsParent, 3);
  // cout << "parent entropy:"<<parentEntropy<<endl;
    
    //Always use the left branch for the binary value of 0 and the right branch for the binary value of 1
    int x1=1;
    
    //feature i sağlayanın kaç tane olduğu used sample içerisinde-->featureId=1 ise , featureId=0
    for (int i=0; i< numSamples;i++) {
        if (usedSamples [i] == true ){//kullanılacak samplelar
            
           // if(data[i][featureId] == 0 ) { //left 0
            if( x1 != data[i][featureId] ) {
                numClassLeft++;
                if ( labels[i] == 1 ) //class no
                	classCountsLeft[0] ++;
                else if(labels[i]  == 2 ) {
                    classCountsLeft[1] ++;
                }else
                	classCountsLeft[2] ++;
                
                
            }else { //true is  eşitse right 1
                numClassRight++;
                if ( labels[i]  == 1 )
                    classCountsRight[0] ++;
                else if(labels[i]  == 2 ) {
                    classCountsRight[1] ++;
                }else
                    classCountsRight[2] ++;
                
            }
        }
    }
    
    //deneme class count LEFT
 /*   for(int i=0;i<3;i++){
        cout<< classCountsLeft[i];
    }
    cout<< "\n";
    for(int i=0;i<3;i++){
        cout<< classCountsRight[i];
    }
  */
    entropyLeft = calculateEntropy(classCountsLeft, 3);
 	//cout<< "\n"<< "entropy left:"<<entropyLeft<<endl;
    entropyRight = calculateEntropy(classCountsRight, 3);
 	//cout<< "entropy right:"<<entropyRight;
   
 /*   cout<< "numClassLeft :"<<numClassLeft<<endl;
     cout<< "numClassRight :"<<numClassRight<<endl;
    cout<< "numSamples:"<<numSamples<<endl;
 */
    childEntropy= ( (double)numClassLeft/(numClassLeft+numClassRight) ) *entropyLeft+ ( (double)numClassRight/(numClassLeft+numClassRight) ) * entropyRight;
	//cout<<"\n"<< "entropy child:"<<childEntropy;
	//cout<<"\n"<< "info gain:"<<parentEntropy-childEntropy<< endl;
	
    return parentEntropy-childEntropy;
    
}

bool * DecisionTree::calculateleftSample(const bool** data, const int* labels, const int numSamples, const int numFeatures, const bool* usedSamples, const int featureId){

    //You may assume that the features are always binary
    // Always use the left branch for the binary value of 0 and the right branch for the binary value of 1 ??????
    int x1=1;
    bool *leftteOlanSample=new bool[numSamples];
    for(int i=0;i<numSamples;i++){
        leftteOlanSample[i]=0;
    }
    //feature i sağlayanın kaç tane olduğu used sample içerisinde-->featureId=1 ise , featureId=0
    for (int i=0; i< numSamples;i++) {
        if (usedSamples [i] == true ){//kullanılacak
            
            // if(data[i][featureId] == 0 ) { //left??? karışmış olabilir ?no
            if( x1 != data[i][featureId] )
                leftteOlanSample[i]=1; //left use sample
        }
    }
    return leftteOlanSample;
}

bool * DecisionTree::calculaterightSample(const bool** data, const int* labels, const int numSamples, const int numFeatures, const bool* usedSamples, const int featureId){
    
    //You may assume that the features are always binary
    // Always use the left branch for the binary value of 0 and the right branch for the binary value of 1 ??????
    int x1=1;
    bool *rightdaOlanSample=new bool[numSamples];
    for(int i=0;i<numSamples;i++){
        rightdaOlanSample[i]=0;
    }
    
    //feature i sağlayanın kaç tane olduğu used sample içerisinde-->featureId=1 ise , featureId=0
    for (int i=0; i< numSamples;i++) {
        if (usedSamples [i] == true ){//kullanılacak
            // if(data[i][featureId] == 0 ) { //left??? karışmış olabilir toplamı 1 ise?no
            if( x1 == data[i][featureId] )
                rightdaOlanSample[i]=1;      
        }
    }
    return rightdaOlanSample;
}



void DecisionTree::train(const bool** data, const int* labels, const int numSamples, const int numFeatures,bool *usedSamples,bool *checkLeafFeatureId,   DecisionTreeNode* &a){
     cout<<endl;
	
    cout <<"used samples: ";
    for (int i=0;i<numSamples;i++){
        cout <<usedSamples[i];
    }
    cout<<endl;
 
    int b=0;
    for (int i=0;i<numSamples;i++){
        if (usedSamples[i] == true) {
            b++;
        }
    }
    
    //checking the leaf
 //   int *checkLeaf=new int[numSamples];
     int *checkLeaf=new int[b];
    for(int i=0;i<b;i++){
        checkLeaf[i]=0;
    }
    int x=-1;
    
    for (int i=0;i<numSamples;i++){
        if (usedSamples[i] == true) {
            x++;
            checkLeaf[x] = labels[i];
        }
    }
    //deneme amaçlı checkleafin tüm elemanları aynı ise leaf olur
    cout<<"checkLeaf";
    for (int i=0;i<b;i++){
        if (checkLeaf[i]>0 ){
            cout<<checkLeaf[i];
        }
    }
    cout<<endl;
   
    //tüm classlar aynı olursa
    bool isLeafClass =true;
    for (int i = 1; i < b; i++) {
      if (checkLeaf[i] != checkLeaf[0] && checkLeaf[i]!=0  ) {
          // if (checkLeaf[i] != checkLeaf[0] ) {
            isLeafClass = false;
            break;
        }
    }

    
  //   if (isLeafClass | isLeafSample | isLeafFatureId ){ //leaf ise classları bastır
     if (isLeafClass ){
        cout <<"This is leaf node, its classes are:";
        for (int i = 0; i < numSamples; i++) {
            if (checkLeaf[i]>0 &&  checkLeaf[i] <4) { //class no > 0
                //cout <<checkLeaf[i];
                //cout <<" " ;
				//ama samplelar kullanılmıs oluyor
                usedSamples[i]=0;
            }
        }
		 
        a = new DecisionTreeNode;
		a->setLeftChildPtr(NULL);
		a->setRightChildPtr(NULL);
		a->setItem( checkLeaf[0]);
		//cout << "leaf class:"<<a->getItem();
		 cout <<a->getItem();
        return;
		 
    }else {//leaf node değilse feature idsini bastır
        double maxGain;
        double gain;
        int maxGainFeatureId = 0;
        maxGain =-1;
        
        //bir kere feature id kullandıysan bir daha kullanamazsın
        for (int i =0; i< numFeatures; i++){
            gain = calculateInformationGain((const bool**)data,labels, numSamples, numFeatures, (const bool*) usedSamples, i);
            if (gain > maxGain && checkLeafFeatureId[i]==1 ){
           // if (gain > maxGain ){
                maxGain = gain;
                maxGainFeatureId = i; //featureId kacıncı columnda onu söylüyor
            }
        }
      	//left
        checkLeafFeatureId[maxGainFeatureId]=0; //?
        bool* leftFeature = new bool [numFeatures];
        bool* rightFeature = new bool [numFeatures];
        
        for (int i=0;i<numFeatures;i++ ) {
            leftFeature[i]=checkLeafFeatureId[i];
        }
        for (int i=0;i<numFeatures;i++ ) {
            leftFeature[i]=checkLeafFeatureId[i];
        }
        for (int i=0;i<numFeatures;i++ ) {
            rightFeature[i]=checkLeafFeatureId[i];
        }
		
        cout <<"This is not a leaf node, its feature id is: "<< maxGainFeatureId<<endl;
        a=new DecisionTreeNode();
		a->setItem(maxGainFeatureId);
  
        bool* leftSample = new bool [numSamples];
        bool* rightSample = new bool [numSamples];
        
        
        //at that time usedSample in değişmesi gerekiyor
         leftSample =calculateleftSample((const bool**)data, labels, numSamples,numFeatures, usedSamples, maxGainFeatureId);
         rightSample= calculaterightSample((const bool**)data, labels, numSamples,numFeatures, usedSamples, maxGainFeatureId);
		 
		train( (const bool**)data,labels, numSamples,numFeatures,leftSample,checkLeafFeatureId,a->leftChildPtr );
		train((const bool**)data,labels, numSamples,numFeatures,rightSample,checkLeafFeatureId, a->rightChildPtr);

    }
 
}

//build decision tree
void DecisionTree::train(const bool** data, const int* labels, const int numSamples, const int numFeatures){
    
    //en başta root gibi düşün
    bool *usedSamples = new bool[numSamples];
    for ( int i =0; i<numSamples; i++ ){
        usedSamples[i]=1;
    }
    
    //featureId i checki kullancabileceklerin 1
    bool *checkLeafFeatureId=new bool[numFeatures];
    for(int i=0;i<numFeatures;i++){
        checkLeafFeatureId[i]=1;
    }

    train( (const bool**)data,labels,numSamples, numFeatures,usedSamples,checkLeafFeatureId,root);
    
    cout <<"\nPRINTING TREE!!"<<endl;
    print();
    
}

void DecisionTree::train(const string fileName, const int numSamples, const int numFeatures){

    //numSamples ia the row number, numFeatures+1 is column?
    bool **traindata ;
    traindata = new bool*[numSamples];
    for(int i = 0; i < numSamples ; i++){
        traindata[i] = new bool[numFeatures];
    }

	ifstream file;
	file.open(fileName);
    
    bool a;
    string str;
    int i=0;
    cout <<""<<endl;
    if (file.is_open())
    {
        while (getline(file,str,'\n' )) {
            //cout <<"satıra gec"<<i<<":"<< str[0]<<";";
            //cout <<str[0]<<endl;
            for (int j=0; j<(numFeatures)*2 ;j=j+2 ){
                if ( str[j] == '1'){
                    a=true;
                }else if( str[j] == '0')  {
                    a=false;
                }
                j = j/2;
                traindata[i][j]=a;
                j = j*2;
            }
            i++;
        }
    }
    file.close();
    
    int *labels;
    labels = new int [numSamples];
    for (int i = 0; i < numSamples ; i++){
        labels[i]=0;
    }
    
    //son column
    i=0;

    file.open(fileName);
    if (file.is_open())
    {
        while (getline(file,str,'\n' )) {
            if (str [(numFeatures)*2] == '1' ){
                labels[i] =1;
            }else if ( str [(numFeatures)*2] == '2' ) {
                labels[i] =2;
            }else{
                labels[i] =3;
            }
        	i++;
        }
    }
    file.close();
  
    //after parsing call prev function
    train( (const bool**)traindata,labels, numSamples, numFeatures);
	
}

int DecisionTree::predict(const bool* data){
    DecisionTreeNode *a = root;
    return predict( (const bool*)data, a);
}

int DecisionTree::predict(const bool* data,DecisionTreeNode* a){
    
      int prediction;
      if ( a->isLeaf() ) {
		  prediction=a->getItem();
      }else{
		  //cout <<"feature "<<a->getItem();
		  if ( data[a->getItem()]==false ) { //false ise
              prediction= predict((const bool*)data,a->getLeftChildPtr());
          }else{
              prediction =predict((const bool*)data,a->getRightChildPtr());
          }
      }
	return prediction;
}


double DecisionTree::test(const bool** data, const int* labels, const int numSamples){
    bool *dataEachSample;
   /* bool *dataEachSample = new bool [getNoOfFeatures()];
    for (int i =0;i<getNoOfFeatures();i++){
        dataEachSample[i]=0;
    }*/
    int truePrediction=0;
    double predictionRatio=0;
    
    for (int i=0;i<numSamples;i++) {
        dataEachSample = new bool [getNoOfFeatures()];
        for (int j=0; j<getNoOfFeatures();j++){
             dataEachSample[j] = data[i][j];
            // cout<<data[i][j]<<"again";
           // dataEachSample[j] = data[i][j];
        }

        int prediction = predict((const bool*)dataEachSample);
        delete[]dataEachSample;
        // cout<<"prediction TEST:"<<prediction <<endl;
        if ( prediction == labels [i] ){
            truePrediction ++;
            //cout<<"TRUE"<<truePrediction;
        }
        
    }
    cout<<"truePrediction:"<<truePrediction<<endl;
    cout<<"samp no:"<<numSamples<<endl;
    predictionRatio = (double)truePrediction/(double)numSamples;
    return predictionRatio;
}

int DecisionTree::getNoOfFeatures(){
    return numOFFeatures;
}
double DecisionTree::test(const string fileName, const int numSamples){
 
    int numOFFeatures = getNoOfFeatures();
    bool **data ;
    data = new bool*[numSamples];
    for(int i = 0; i < numSamples ; i++){
        data[i] = new bool[numOFFeatures];
    }
    int* labels = new int [numSamples];
    for (int i=0;i<numSamples;i++) {
        labels[i]=0;
    }

    ifstream file;
    file.open(fileName);
    
    bool a;
    string str;
    int i=0;
    cout <<""<<endl;
    if (file.is_open())
    {
        while (getline(file,str,'\n' )) {
            for (int j=0; j<(numOFFeatures)*2 ;j=j+2 ){
                if ( str[j] == '1'){
                    a=true;
                }else if( str[j] == '0')  {
                    a=false;
                }
                j = j/2;
                data[i][j]=a;
                j = j*2;
            }
            i++;
        }
    }
    file.close();
    
    //son column
    i=0;
	file.open(fileName);
    if (file.is_open())
    {
        while (getline(file,str,'\n' )) {
            if (str [(numOFFeatures)*2] == '1' ){
                labels[i] =1;
            }else if ( str [(numOFFeatures)*2] == '2' ) {
                labels[i] =2;
            }else{
                labels[i] =3;
            }
            i++;
        }
    }
    file.close();
    return test( (const bool**)data, labels, numSamples);
   
}

void DecisionTree::print() {
    int height = 0;
    printTree(root, height);
}

void DecisionTree::printTree(DecisionTreeNode* decisionTreeNode, int height) {
    if (decisionTreeNode == NULL){
        return;
    }else {
        for (int i = 0; i < height; i++){
            cout << '\t';	
        }
        if ( decisionTreeNode->getRightChildPtr() == NULL && decisionTreeNode->getLeftChildPtr() == NULL ){
            cout << "class= "<<decisionTreeNode->getItem() << endl;
        }else {
            cout << decisionTreeNode->getItem() << endl;
            printTree(decisionTreeNode->getLeftChildPtr(), height + 1);
            printTree(decisionTreeNode->getRightChildPtr(), height + 1);
        }
    }
}

