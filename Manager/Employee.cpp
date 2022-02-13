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
		<<"姓名" << this->m_workerName
		<<"编号" << this->m_workerNumber
		<< "部门" << this->positionName()
		<< std::endl;
}
string Employee::positionName()
{
	return "员工"; 
}