#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;
class Boss:public Worker
{
public:


	Boss(string workerName, int  workerNumber, string workerPart);

	virtual void responsibility();
	virtual string positionName();

};

