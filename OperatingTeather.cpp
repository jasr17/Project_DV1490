#include "OperatingTeather.h"



OperatingTeather::OperatingTeather(int openingHours, int openingMinutes,int closingHours,int closingMinutes) {
	this->openingHours = openingHours;
	this->openingMinutes = openingMinutes;
	this->closingHours = closingHours;
	this->closingMinutes = closingMinutes;
}


OperatingTeather::~OperatingTeather() {
}

int OperatingTeather::openingTime() const {
	return (closingHours - openingHours)*60 + (closingMinutes + openingMinutes);
}
