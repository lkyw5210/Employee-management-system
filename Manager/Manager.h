#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;
class Manager:public Worker
{
public:


	Manager(string workerName, int  workerNumber, string workerPart);

	virtual void responsibility();
	virtual string positionName();


};

