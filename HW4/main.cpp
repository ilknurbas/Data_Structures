

//
//  main.cpp
//  cs202_hw4
//
//  Created by Ilknur Bas on 7.05.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//
/**
 * Author: İlknur Baş
 * ID: 21601847
 * Section: 2
 * Assignment: 4
 */

#include <iostream>
#include "HashTable.h"
#include <fstream>

int main(int argc, const char * argv[]) {
	
	int numProbes;
	double numSuccProbes;
	double numUnsuccProbes;
	
	
	string fileName = "30_of_occupied.txt";
	/*UNCOMMENT WHEN NECESSARY!!!!!*/
	//string fileName = "15_of_occupied.txt";
	//string fileName = "25_of_occupied.txt";
	//string fileName = "30_of_occupied.txt";
	
	ifstream file;
	file.open(fileName);
	string str="";
	string str2="";
	int itemFromTxt;
	
	
	HashTable h = HashTable (31,LINEAR);
	cout<<"-----------------------LINEAR----------------------"<<endl;
	int v=1;
	for( v=1;v<=3;v++){
		if (file.is_open()){
			
			while (getline(file,str,'\n' )) {
				char a = str[0];
				//itemi bul.
				for (int i =2; i<str.length(); i++) {
					str2 = str2+str[i];
				}
				itemFromTxt = stoi(str2);
				
				if (a == 'I') {
					h.insert(itemFromTxt);
					
				}else if (a == 'S') {
					h.search(itemFromTxt, numProbes);
					cout <<",number of probes:"<<numProbes<<endl;
					
				}else if (a == 'R') {
					h.remove(itemFromTxt);
				}
				str2="";
			}
			
		}
		file.close();
		cout<<""<<endl;
		h.display();
		cout<<""<<endl;
		cout<<"Analyzation starts..."<<endl;
		h.analyze(numSuccProbes, numUnsuccProbes);
		cout<<""<<endl;
		cout<<"Experimental successful :"<<numSuccProbes<<endl;
		cout<<"Experimental unsuccessful :"<<numUnsuccProbes<<endl;
		h.analyzeTheoretical();
		
		if(v==1){
			cout<<""<<endl;
			cout<<"-----------------------QUADRATIC-----------------------"<<endl;
			h = HashTable (31,QUADRATIC);
			file.open(fileName);
		}else if(v==2){
			cout<<""<<endl;
			cout<<"------------------DOUBLE---------------------------"<<endl;
			h = HashTable(31,DOUBLE);
			file.open(fileName);
		}
	}
	
	
	return 0;
}

