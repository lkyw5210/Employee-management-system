#pragma once
#include <iostream>
using namespace std;
//ְ���������
class Worker
{
public :
	virtual void responsibility()=0;
	virtual string positionName() =0;

	string m_workerName;
	int m_workerNumber;
	string m_workerPart;
	

};

