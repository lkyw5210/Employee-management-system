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
		<< "����" << this->m_workerName
		<< "���" << this->m_workerNumber
		<< "����" << this->m_workerPart
		<< std::endl;
}
string Manager::positionName()
{
	return "����";
}