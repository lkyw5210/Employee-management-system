#include "Employee.h"
Employee::Employee(string workerName,int  workerNumber,string workerPart)
{
	this->m_workerName = workerName;
	this->m_workerNumber = workerNumber;
	this->m_workerPart = workerPart;
};
void Employee::responsibility() 
{
	std:: cout
		<<"����" << this->m_workerName
		<<"���" << this->m_workerNumber
		<< "����" << this->positionName()
		<< std::endl;
}
string Employee::positionName()
{
	return "Ա��"; 
}