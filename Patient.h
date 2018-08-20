#ifndef PATIENT_H
#define PATIENT_H
#include<string>

class Patient {
private:
	//int ID;
	int operationMinutes;
	std::string name;
	std::string operation;
public:
	Patient();
	virtual ~Patient();
};

#endif // !PATIENT_H
