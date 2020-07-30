//
//  FriendNet.cpp
//  cs202hw5
//
//  Created by Ilknur Bas on 21.05.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#include <stdio.h>
#include "FriendNet.h"
#include "Queue.h" 
#include <string>
#include <iostream>
using namespace std;
#include <fstream>

FriendNet::~FriendNet()
{
	/*cout<<"destructor"<<endl;
	if (adjacent) {
		delete[] adjacent;
		cout<<"destructor1"<<endl;
	}
	
	if (names){
		cout<<"destructor2"<<endl;
		delete[] names;
	}

	//cout<<"destructor"<<endl;
	if (noOfpeople>0) {
		delete[] adjacent;
		//cout<<"destructor1"<<endl;
	}
	 */
}

FriendNet::FriendNet(const FriendNet& aNet){// copy constructor
	
	noOfpeople = aNet.noOfpeople;
	if ( noOfpeople >= 0){
		cout<<"copy constructor"<<endl;
		adjacent = new List [noOfpeople];
		adjacent =aNet.adjacent;
		for (int i = 0; i<noOfpeople; ++i )
		{
			adjacent[i]=aNet.adjacent[i];
		}
		
		//names
		names=new string [noOfpeople];
		for (int i = 0; i<noOfpeople; ++i )
		{
			names[i]=aNet.names[i];
		}
		txtController=true;
		
		/*NO NEEDdddd
		 //hop
		 hop = new int [noOfpeople];
		 for (int i = 0; i<noOfpeople; ++i )
		 {
		 hop[i]=aNet.hop[i];
		 }
		 
		 //visitedComponents
		 //visitedComponents = new bool [noOfpeople];
		 for (int i = 0; i<noOfpeople; ++i )
		 {
		 visitedComponents[i]=aNet.visitedComponents[i];
		 }
		 //visitedEachComponents
		 visitedEachComponents = new bool [noOfpeople];
		 for (int i = 0; i<noOfpeople; ++i )
		 {
		 visitedEachComponents[i]=aNet.visitedEachComponents[i];
		 }
		 
		 //namesComponents
		 //namesComponents = new string[componentCounter];
		 for (int i = 0; i<noOfpeople; ++i )
		 {
		 namesComponents[i]=aNet.namesComponents[i];
		 }
		 
		 */
		
	}else{
		adjacent=NULL;
		//adjacent = new List [noOfpeople];
		names=NULL;
		hop=NULL;
		visitedComponents=NULL;
		visitedEachComponents=NULL;
		namesComponents=NULL;
	}

}

FriendNet::FriendNet(const string fileName){
	
	ifstream file;
	file.open(fileName);
	
	
	bool a=true;
	string str;
	
	string word;
	string deneme="";
	int bosluk=0;
	
	int id;
	string name="";
	int degree=0;
	int ekleme;
	noOfpeople=0;
	int counter=-1;
	
	int degree2 =-6;
	
	
	if (file.is_open()){
		
		while (getline(file,str,'\n' )) {
			
			if(a){ //get the number of people
				noOfpeople = stoi(str);
				cout<<"Number of people: "<<noOfpeople<<endl;
				adjacent = new List [noOfpeople];
				a=false;
				names= new string [noOfpeople];
				
			}else{
				for (int i=0;i<str.length();i++){
					//cout<<"str[i]"<<str[i]<<endl;
					if (str[i]==' '){
						bosluk++;
						if (bosluk==1){//id
							id = stoi(deneme);
							//cout<< "id:"<<id;
							deneme="";
							
						}else if (bosluk==2){//name
							name=deneme;
							//cout<< " name:"<<name;
							deneme="";
							names[counter]=name;
							
						}else if (bosluk==3){//degree
							degree2=-5;
							degree = stoi(deneme);
							//cout<< " degree:"<<degree<<endl;
							deneme="";
							
						}else{
							ekleme = stoi(deneme);
							//cout<< "	added: "<<ekleme<<endl;
							adjacent[counter].insert(adjacent[counter].getLength()+1, ekleme);
							//adjacent[counter].insert(1, ekleme);
							deneme="";
						}
						
					}else{
						 deneme=deneme+str[i];
						
						if(i==str.length()-1  && degree2 ==-5 ){
							ekleme = stoi(deneme);
							//cout<< "	added2: "<<ekleme<<endl;
							adjacent[counter].insert(adjacent[counter].getLength()+1, ekleme);
							//adjacent[counter].insert(1, ekleme);
							
							int dataitem;
							adjacent[counter].retrieve(adjacent[counter].getLength()-1, dataitem);
							//cout<< "		list lenght: "<<adjacent[counter].getLength()<< endl;
							deneme="";
						}
						if(degree2 !=-5 && i==str.length()-1) {
							degree = 0;
							//cout<< " degree:"<<degree<<endl;
							//cout<< "		list lenght: "<<adjacent[counter].getLength()<< endl;
							deneme="";
							
							
						}
						
						
					}
					
					
				}
			
				
			}
			degree2 =-6;
			counter++;
			bosluk=0;
			//cout << endl;
		}
		file.close();
		txtController=true;
	}else{
		txtController=false;
	}
	//file.close();
	//txtController=true;
	
	//Note that, if the input file fileName does not exist, then the default constructor creates an empty friendship network.
	//if (fileName=="" ) {
	if (!txtController) {
		cout<<"There is no txt file, empty friendship network created."<<endl;
		noOfpeople=0;
		adjacent = new List [noOfpeople];
		names= new string [noOfpeople];
		//adjacent=NULL;
		//names=NULL;
		
		txtController=false;
	}
	if (noOfpeople==0 && txtController){
		cout<<"There is no people in the txt file."<<endl;
	}else {
		//print --- is it true
		cout << "----------ADJACENCY LIST----------"<<endl;
		for (int i=0;i<noOfpeople;i++){
			int lenght= adjacent[i].getLength();
			cout<< "list "<<i<<" size:" <<adjacent[i].getLength()<<" ";
			cout<< "----";
			int dataitem;
			for(int j=1; j<=lenght;j++){
				adjacent[i].retrieve(j, dataitem);
				cout<<dataitem<<" ";
			}
			cout << endl;
		}
		cout << "----------Names----------"<<endl;
		for (int i=0;i<noOfpeople;i++){
			cout << names[i]<<" ";
		}
		cout << endl;
	}
	
	
}

//This function finds the index of the given personName
int FriendNet::personNameToInt(string personName){
	for (int i=0;i<noOfpeople ;i++){
		if (names[i]== personName) {
			return i;
		}
	}
	return -1;
}

//This function uses iterative version of breadth-first strategy
void FriendNet::listFriends(const string personName, const int hopNo){
	/*if (!txtController) {
		cout<<"There is no text file."<<endl;
	}else */
		if (noOfpeople<=0) {
		cout<<"There is no people in the text file."<<endl;
	}else{
		if (hopNo<=0){
			//cout<<"hopNo is negative"<<endl;
			cout<<"People accessible from "<<personName<<" within "<<hopNo <<" hops: NOBODY"<<endl;
		}else if ( personNameToInt(personName)== -1 ){
			cout<<personName<<" does not exist in the network."<<endl;
		}else{ //degressi 0 olanlar
			if (adjacent[ personNameToInt(personName)].getLength()==0 ) {
				cout<<"People accessible from "<<personName<<" within "<<hopNo <<" hops: NOBODY"<<endl;
			}else{
				cout<<"People accessible from "<<personName<<" within "<<hopNo <<" hops: ";
				Queue q;
				bool *visited = new bool [noOfpeople];
				for (int i = 0; i < noOfpeople; i++)
					visited[i] = false;
				visited[personNameToInt(personName)] = true;
				q.enqueue(personNameToInt(personName));
				//hop yap
				hop = new int [noOfpeople];
				for (int i = 0; i < noOfpeople; i++)
					hop[i] = -1;
				hop[personNameToInt(personName)] = hopNo;
				//int hopNo2=hopNo;
				int counter=0;
				while (!q.isEmpty()) {
					//while (counter!=hopNo && !q.isEmpty() ) {
					counter++;
					//cout<<"counter"<<counter<<endl;
					int front;
					q.dequeue(front); //w
					
					for ( int i = 1; i <= adjacent[front].getLength(); i++){
						int adjacentNode;
						adjacent[front].retrieve(i, adjacentNode);
						if (!visited[adjacentNode]){
							//q.enqueue(adjacentNode);
							//S.push(adjacentNode);
							//hop-1
							
							//if (counter==hopNo ) {
							//if (hop[adjacentNode]==1 ) {
							if (hop[front]==1 ) {
								
							}else{
								//hopNo2=hopNo2-1;
								//hop[adjacentNode] = hopNo2-1;
								hop[adjacentNode]=hop[front]-1;
								q.enqueue(adjacentNode);

							}
							//q.enqueue(adjacentNode);
							//cout << "	adjacentNode:"<<adjacentNode<<","<<names[adjacentNode]<< endl;
							cout <<names[adjacentNode]<<",";
							visited[adjacentNode] = true;
						}
						
					}
					
				}
				
				delete [] visited;
				delete [] hop;
				
			}
			
			
		}
		cout <<endl;
		
	}

}



void FriendNet::displayAverageDegrees(){
	/*if (!txtController) {
		cout<<"There is no text file."<<endl;
	}else */
	if (noOfpeople<=0) {
		cout<<"There is no people in the text file."<<endl;
	}else {
		visitedComponents = new bool [noOfpeople];
		for (int i = 0; i < noOfpeople; i++)
			visitedComponents[i] = false;
		noOfComponents=0;
		for ( int i=0;i<noOfpeople;i++) {
			if (!visitedComponents[i]) {
				cout<<"For component "<<noOfComponents<<": "<<endl;
				displayAverageDegreesHelper(i); //vertex
				cout << endl;
				noOfComponents++;
				//Visitedcomponents
				
			}
			
		}
		delete [] visitedComponents;
	}
	
}

double FriendNet::displayAverageDegreesHelper(int person){

	Queue q;
	visitedComponents[person] = true;
	//newly addded
	
	//visitedEachComponents[person] = true; //?????
	
	q.enqueue(person);
	double counterForNoOfPeople=1;
	double sum=0;
	while (!q.isEmpty()) {
		int front;
		q.dequeue(front); //w
		
		sum+=adjacent[front].getLength();
		//cout<<"adjacent[front].getLength()"<< front<<endl;
		for ( int i = 1; i <= adjacent[front].getLength(); i++){
			int adjacentNode;
			adjacent[front].retrieve(i, adjacentNode);
			if (!visitedComponents[adjacentNode]){
				q.enqueue(adjacentNode);
				//cout << "adjacentNode:"<<adjacentNode << endl;
				visitedComponents[adjacentNode] = true;
				
				//visitedEachComponents[adjacentNode] = true; //?????
				counterForNoOfPeople++;
			}
		}
	}
	
	double average=0;
	average = sum/counterForNoOfPeople;
	cout<<"		sum: "<<sum<<endl;
	cout<<"		no of people: "<<counterForNoOfPeople<<endl;
	cout<<"		average: "<<average<<endl;

	return average;
	
}


void FriendNet::displayDiameters(){
	/*if (!txtController) {
		cout<<"There is no text file."<<endl;
	}else*/
	if (noOfpeople<=0) {
		cout<<"There is no people in the text file."<<endl;
	}else {
		visitedComponents = new bool [noOfpeople];
		for (int i = 0; i < noOfpeople; i++)
			visitedComponents[i] = false;
		noOfComponents=0;
		
		visitedEachComponents = new bool [noOfpeople];
		for (int i = 0; i < noOfpeople; i++){
			visitedEachComponents[i] = false;
		}
		
		
		for ( int i=0;i<noOfpeople;i++) {
			if (!visitedComponents[i]) {
				cout<<"For component "<<noOfComponents<<": "<<endl;
				Queue q;
				visitedComponents[i] = true;
				//newly addded
				visitedEachComponents[i] = true;
				
				q.enqueue(i);
				double counterForNoOfPeople=1;
				double sum=0;
				while (!q.isEmpty()) {
					int front;
					q.dequeue(front); //w
					
					sum+=adjacent[front].getLength();
					for ( int i = 1; i <= adjacent[front].getLength(); i++){
						int adjacentNode;
						adjacent[front].retrieve(i, adjacentNode);
						if (!visitedComponents[adjacentNode]){
							q.enqueue(adjacentNode);
							//cout << "adjacentNode:"<<adjacentNode << endl;
							visitedComponents[adjacentNode] = true;  ////////Karışabilrirrr
							//not sure
							visitedEachComponents[adjacentNode] = true;
							counterForNoOfPeople++;
						}
					}
				}
				
				
				noOfComponents++;
				//Visitedcomponents
				int componentCounter=0;
				
				//shortest içn
				for (int i=0;i<noOfpeople;i++) {
					if (visitedEachComponents[i]==1) {
						componentCounter++;
					}
				}
				
				//componenti dogru mu almıs diye check etmek istersen componenti kullanabilirsin yoksa gereksiz
				List* component = new List [componentCounter];
				namesComponents = new string[componentCounter];
				int index=-1;
				for (int i=0;i<noOfpeople;i++) {
					if (visitedEachComponents[i]==1) {
						index++;
						component[index]=adjacent[i];
						namesComponents[index]=names[i];
					}else{
						
					}
				}
				//şimdi component içinde o componentta bulunan köseler var
				//deneme
				/*	for (int i=0;i<componentCounter;i++){
				 int lenght= component[i].getLength();
				 cout<< "list "<<i<<" size:" <<component[i].getLength()<<" ";
				 cout<< "----";
				 int dataitem;
				 for(int j=1; j<=lenght;j++){
				 component[i].retrieve(j, dataitem);
				 cout<<dataitem<<" ";
				 }
				 cout << endl;
				 }
				 */
				///
				
				
				//at this point you have found 1 component
				cout<<"		Longest Shortest path is: ";
				int found = componentFinder(componentCounter);
				cout << found<< endl;
				cout << endl;
				
				
				delete []component;
			}
			for (int i = 0; i < noOfpeople; i++){ //Doğru yapıyorsun
				visitedEachComponents[i] = false;
			}
			
		}
		delete [] visitedComponents;
		
		
		
		
	}
	
	
}



int FriendNet::componentFinder(int componentCounter){
	double largest=-2;
	//just one component
	for (int i=0;i<componentCounter;i++) {
		//Starting pointi i olanların shortestini buluyor sonra onların arasında longest döndür
		double deneme = findShortestLongest(namesComponents[i]);
		if(largest <deneme)
			largest=deneme;
		
		//cout <<"largest "<<largest<<endl;
	}
	
	return largest;
}


int FriendNet::findShortestLongest(string name){
	//Starting pointi verilen A-b a-c a-d....
	//distance arrayının içinde shortest olacak onların largestin sececeksin
	
	//int *distance = new int[componentCounter]; //yoksa zaten 0
	int *distance = new int[noOfpeople];
	for (int i = 0; i < noOfpeople; i++)
		distance[i] = 0;
	
	//bfs
	
	bool *visited2 = new bool [noOfpeople];
	for (int i = 0; i < noOfpeople; i++)
		visited2[i] = true;
	for (int i=0;i<noOfpeople;i++) {
		if (visitedEachComponents[i]==1)
			visited2[i] = false;
	}
	
	
	Queue q;
	/*bool *visited = new bool [noOfpeople];
	for (int i = 0; i < noOfpeople; i++)
		visited[i] = false;*/
	visited2[personNameToInt(name)] = true;
	q.enqueue(personNameToInt(name));

	int counter=0;
	
	while (!q.isEmpty()) {
		counter++;

		int front;
		q.dequeue(front); //w

		for ( int i = 1; i <= adjacent[front].getLength(); i++){
			int adjacentNode;
			adjacent[front].retrieve(i, adjacentNode);
			if (!visited2[adjacentNode]){
				q.enqueue(adjacentNode);
				//cout << "adjacentNode:"<<adjacentNode << endl;
				visited2[adjacentNode] = true;
				distance[adjacentNode] = distance[front]+1;
			}
		}
	}
		
		
	/*
	//arrayin için bak
	cout<<"ARRAY for "<<name<<endl;
	for (int i = 0; i < noOfpeople; i++)
		cout <<distance[i]<<" " ;
	cout<<endl;
	*/
	int largest = distance[0];
	for(int i = 1;i < noOfpeople; i++) {
		if(largest < distance[i])
			largest = distance[i];
	}
	
	///////////
	delete []distance;
	delete [] visited2;
	return largest;
	
	
}




 

