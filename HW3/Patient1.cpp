//
//  Patient.cpp
//  iteration2_cs202hw3
//
//  Created by Ilknur Bas on 23.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#include <stdio.h>
#include "Patient1.h"
#include <iostream>

using namespace std;

Patient1::Patient1()
{
}

Patient1::Patient1(const Patient1& toCopy)
{
	this->idP = toCopy.idP;
	this->priority = toCopy.priority;
	this->arrivingTime = toCopy.arrivingTime;
	this->examinationTime = toCopy.examinationTime;
}

int Patient1::getPatientId()
{
	return idP;
}

int Patient1::getPatientPriority()
{
	return priority;
}

int Patient1::getPatientArrivingTime()
{
	return arrivingTime;
}

int Patient1::getPatientExaminationTime()
{
	return examinationTime;
}

void Patient1::setId(const int a){
	idP=a;
}
void Patient1::setPriority(const int a){
	priority=a;
}
void Patient1::setArrivingTime(const int a){
	arrivingTime=a;
}
void Patient1::setExaminationTime(const int a){
	examinationTime=a;
}

void Patient1::operator=(const Patient1& a)
{
	idP = a.idP;
	priority = a.priority;
	arrivingTime = a.arrivingTime;
	examinationTime = a.examinationTime;
}






