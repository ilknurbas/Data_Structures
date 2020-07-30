//
//  simulator.cpp
//  iteration2_cs202hw3
//
//  Created by Ilknur Bas on 20.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#include <stdio.h>
#include "simulator1.h"
#include <iostream>
#include <fstream>
using namespace std;
 

simulator1::simulator1()
{
	noOfpatients = 0;
	
}


simulator1::~simulator1()
{
}

void simulator1::readFile(string fileName,int maxAverage) {

	ifstream file;
	file.open(fileName);
	
	bool a=true;
	string word;
	string str;
	string deneme="";
	int counter=0;
	int counterForPatient=-1;
	int variables;
	Patient1 patient;
	//int noOfpatients=0;
	if (file.is_open()){
		
		while (getline(file,str,'\n' )) {
			
			if(a){
				noOfpatients = stoi(str);
				a=false;
			}else{
				
				for ( int i=0;i<str.length(); i++ ){
					if (str[i]==' '){
						counter++;
						if ( counter==1){
							variables= stoi(deneme);
							patient.setId(variables);
							deneme ="";
						}else if ( counter==2){
							variables= stoi(deneme);
							patient.setPriority(variables);
							deneme="";
						}else if ( counter==3){
							variables= stoi(deneme);
							patient.setArrivingTime(variables);
							deneme="";
						}
					}
					
					else{
						deneme=deneme+str[i];
					}
					
				}
				//examination
				variables= stoi(deneme);
				patient.setExaminationTime(variables);
				deneme="";
				item2[counterForPatient]=patient;
			
			}
			counter=0;
			counterForPatient++;
		}
		
	}
	
	file.close();
	/*cout<<"PATIENTS --> heap wise"<<endl;
	for(int i=0;!pq.pqIsEmpty();i++){
		pq.returnSpecificPatient(i);
	}
	
	cout<<"PATIENTS --> array wise"<<endl;
	for(int i=0;i<noOfpatients;i++){
		cout<< item2[i].getPatientId() <<" ";
		cout<< item2[i].getPatientPriority()<<" ";
		cout<< item2[i].getPatientArrivingTime()<<" ";
		cout<< item2[i].getPatientExaminationTime()<<" ";
		cout<<endl;
	}*/
	
	if(noOfpatients==0){
		cout<<"NO PATIENT"<<endl;
		return;
	}
	
	doctorAssign( maxAverage,noOfpatients);
	
	cout << "is heap empty= " <<pq.pqIsEmpty()<<endl;
	
	/*cout<<"PATIENTS --> heap wise"<<endl;
	int i=0;
	while ( i != pq.returnSize() ) {
		pq.returnSpecificPatient(i);
		i++;
	}*/

	
}



void simulator1::doctorAssign( const int maxAverage, int noOfpatients){
	
	double maxAverageCalculated =1000000;
	int i=1;
	while ( maxAverageCalculated > maxAverage ) {
		maxAverageCalculated = doctorAssign2(i,noOfpatients);
		cout << "maxAverageCalculated: " << maxAverageCalculated<< "doctor:"<<i<<endl;
		i++;
	}
	cout << "Average waiting time: " << (double)maxAverageCalculated << " minutes"<<" with minimum doctor requires:"<<(--i)<< endl;

}

//THE LINES THAT ARE COMMENTED IS USED WHEN TRACKING EACH STEP
double simulator1::doctorAssign2( const int doctorNo,int noOfpatients){
	double calculation=0;
	int current_time=1;
	Doctor doctors[doctorNo];
	for (int i=0; i<doctorNo; i++) {
		doctors[i].avaliabilityTime=0 ;
	}
	
	double wait = 0;
	int assignEdilenHasta=0;
	
	while ( assignEdilenHasta < noOfpatients) { //until there is no patient left
		for (int i=0;i<noOfpatients;i++){ //bulundugumuz dakikada arrive edenler doktor için bekliyorlar
			if(item2[i].getPatientArrivingTime() == current_time){
				//cout<< item2[i].getPatientId() <<"insert edilecek "<<current_time<<endl;
				pq.pqInsert(item2[i]);
			}
		}

		/*cout<<"In this time: "<< current_time <<"these are in the heap"<<endl;
		int i=0;
		while ( i != pq.returnSize() ) {
			pq.returnSpecificPatient(i);
			i++;
		}*/
		
		int a=0;
		for (int i=0; i<doctorNo; i++) {
			if (  doctors[i].avaliabilityTime == 0 )
				a++; //number of available olan doktors
		}
		
		//does the assignment doctor-patient in that time
		while ( ( ( a != 0 )  ) && (!pq.pqIsEmpty() ) ) {

			//cout<<"---This patient ";
			//pq.returnSpecificPatient(0);
			//cout<<"deleted in :"<<current_time<<endl;
			Patient1 rootItem;
			pq.pqDelete(rootItem);
			/*cout<<"deletion done: root is: ";
			if( !pq.pqIsEmpty() ) {
				pq.returnSpecificPatient(0);
			}else{
				cout<<"no root, heap is empty"<<endl;
			}

			int i=0;
			while ( i != pq.returnSize() ) {
				pq.returnSpecificPatient(i);
				i++;
			}*/
			
			assignEdilenHasta++;
			//find the available doctor with lowest id
			int indexOfDoctor=-1;
			for (int i=0; i<doctorNo; i++) {
				if (  doctors[i].avaliabilityTime == 0  ){
					doctors[i].avaliabilityTime =  rootItem.getPatientExaminationTime();
					indexOfDoctor=i;
					break;
				}
				
			}

			//waiting time of the patient that is assigned
			wait = (current_time - (rootItem.getPatientArrivingTime()) );
			calculation = calculation + wait;
			cout<<"Doctor "<<indexOfDoctor<< "takes patient " << rootItem.getPatientId() << " at minute " <<current_time << "(wait:" << wait <<endl ;

			
			a=0;
			for (int i=0; i<doctorNo; i++) {
				if (  doctors[i].avaliabilityTime ==0 )
					a++; //avaliabile olan doktor sayısı
			}
			//cout <<"available doctor number:"<<a<<endl;
			
		}
		
		//doktorların avaliability timelarından 1 cıkarmak gerekitor -- avaliabilitysi 0 olmayanlardan
		for (int i=0; i<doctorNo; i++) {
			if (  doctors[i].avaliabilityTime !=0 )
				doctors[i].avaliabilityTime--;
		}
		current_time++;
		
		
	}
	calculation = (double)calculation/(double)noOfpatients;
	return calculation;
	
}












