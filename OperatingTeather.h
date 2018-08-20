#ifndef OPERATINGTHEATHER_H
#define OPERATINGTHEATER_H
#include "Queue.h"
#include "Patient.h"


class OperatingTeather {
private:
	//int minutesOpen;
	int openingHours, openingMinutes;
	int closingHours, closingMinutes;
	Queue<Patient> patients;


public:
	OperatingTeather(int openingHours = 8, int openingMinutes = 0, int closingHours = 19, int closingMinutes = 0);
	virtual ~OperatingTeather();
	int openingTime()const;
	int patientsInWaitinglist()const;
	bool addPatient(int ID, std::string name, std::string operation);
	Patient removePatient();
};

#endif // !OPERATINGTHEATHER
