//
//  Patient.h
//  CS202HW3QUESTION2iteration2
//
//  Created by Ilknur Bas on 23.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#ifndef Patient2_h
#define Patient2_h

class Patient2
{
public:
	Patient2();
	Patient2(const Patient2& toCopy);
	int getPatientId();
	int getPatientPriority();
	int getPatientArrivingTime();
	int getPatientExaminationTime();
	void operator=(const Patient2&);
	
	void setId(const int a);
	void setPriority(const int a);
	void setArrivingTime(const int a);
	void setExaminationTime(const int a);
	
	
	
private:
	int idP;
	int priority;
	int arrivingTime;
	int examinationTime;
};

#endif /* Patient2_h */



