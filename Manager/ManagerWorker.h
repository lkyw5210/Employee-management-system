#pragma once
#include <iostream>
#include "Worker.h"
class ManagerWorker
{
public :
	int m_option;

	ManagerWorker();
	~ManagerWorker();

	void showMenu();
	void exitSystem();
	void addWorker();
	void save();
	int getEmpNum();



	int m_existWorkerNum;
	Worker **m_wokerArr;
	bool m_FileIsEmpty;
	int m_getEmpNum;
	


};

