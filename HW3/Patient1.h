//
//  Patient.h
//  iteration2_cs202hw3
//
//  Created by Ilknur Bas on 23.04.2020.
//  Copyright © 2020 Ilknur Bas. All rights reserved.
//

#ifndef Patient1_h
#define Patient1_h

class Patient1
{
public:
	Patient1();
	Patient1(const Patient1& toCopy);
	int getPatientId();
	int getPatientPriority();
	int getPatientArrivingTime();
	int getPatientExaminationTime();
	void operator=(const Patient1&);
	
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


#endif /* Patient1_h */

