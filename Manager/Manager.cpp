#include "Manager.h"


Manager::Manager(string workerName, int  workerNumber, string workerPart)
{
	this->m_workerName = workerName;
	this->m_workerNumber = workerNumber;
	this->m_workerPart = workerPart;
};
void Manager::responsibility()
{
	std::cout
		<< "姓名" << this->m_workerName
		<< "编号" << this->m_workerNumber
		<< "部门" << this->m_workerPart
		<< std::endl;
}
string Manager::positionName()
{
	return "经理";
}