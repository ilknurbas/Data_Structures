//
//  Patient.cpp
//  CS202HW3QUESTION2iteration2
//
//  Created by Ilknur Bas on 23.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//


#include <stdio.h>
#include "Patient2.h"
#include <iostream>

using namespace std;

Patient2::Patient2()
{
}

Patient2::Patient2(const Patient2& toCopy)
{
	this->idP = toCopy.idP;
	this->priority = toCopy.priority;
	this->arrivingTime = toCopy.arrivingTime;
	this->examinationTime = toCopy.examinationTime;
}

int Patient2::getPatientId()
{
	return idP;
}

int Patient2::getPatientPriority()
{
	return priority;
}

int Patient2::getPatientArrivingTime()
{
	return arrivingTime;
}

int Patient2::getPatientExaminationTime()
{
	return examinationTime;
}

void Patient2::setId(const int a){
	idP=a;
}
void Patient2::setPriority(const int a){
	priority=a;
}
void Patient2::setArrivingTime(const int a){
	arrivingTime=a;
}
void Patient2::setExaminationTime(const int a){
	examinationTime=a;
}

void Patient2::operator=(const Patient2& a)
{
	idP = a.idP;
	priority = a.priority;
	arrivingTime = a.arrivingTime;
	examinationTime = a.examinationTime;
}






