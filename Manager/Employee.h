#pragma once
#include "Worker.h"
class Employee:public Worker
{
public:

	
	Employee(string workerName, int  workerNumber, string workerPart);
	
	virtual void responsibility();
	virtual string positionName();

	


};

