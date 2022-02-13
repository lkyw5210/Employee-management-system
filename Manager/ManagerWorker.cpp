#include <iostream>
#include <fstream>
#include "ManagerWorker.h"
#include "Employee.h"
#include "Manager.h"
#include "Worker.h"
#include "Boss.h"
#define FILENAME "worker.txt"

ManagerWorker::ManagerWorker()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		std::cout << "文件不存在" << std::endl;
		this->m_existWorkerNum = 0;
		this->m_wokerArr = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//文件存在，但是被清空
	if (ifs.eof()) 
	{
		std::cout << "文件为空！" << std::endl;
		this->m_existWorkerNum = 0;
		this->m_wokerArr = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	int num = this->getEmpNum();
	this->m_getEmpNum = num;

}
ManagerWorker::~ManagerWorker()
{
	if (this->m_wokerArr != NULL) 
	{
		delete[] this->m_wokerArr;
		this->m_existWorkerNum = NULL;
	}
}

void ManagerWorker::delWorker() 
{
	if (this->m_FileIsEmpty) 
	{
		std::cout << "文件不存在或记录为空" << std::endl;
	}
	else
	{
		//按照职工编号删除
		std::cout << "请输入想要删除的职工编号：" << std::endl;
		int id = 0;
		cin >> id;
		int index = this->isExsit(id);
		if (index == -1) 
		{
			std::cout << "用户不存在" << std::endl;
		}
		else 
		{
			for (int i = index; i < this->m_getEmpNum - 1; i++) 
			{
				this->m_wokerArr[i] = this->m_wokerArr[i + 1];
			}
			this->m_getEmpNum--;

		}

	}


};
void ManagerWorker::modWorker() 
{
	if (this->m_FileIsEmpty) 
	{
		std::cout << "文件不存在或者记录为空"<<std::endl;
	}
	else
	{
		int id ;
		std::cout << "请输入需要修改的职工编号" << std::endl;
		std::cin >> id;
		int ret = this->isExsit(id);
		if (ret == -1)
		{
			std::cout << "用户不存在" << std::endl;

		}
		else
		{
			delete this->m_wokerArr[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;
			std::cout << "查到第" << id << "号员工，请输入新员工编号"<<std::endl;
			cin >> newId;
			std::cout << "请输入姓名" << std::endl;
			cin >> newName;
			std::cout << "请输入岗位u" << std::endl;
			std::cout << "1：普通员工" << std::endl;
			std::cout << "2：经理" << std::endl;
			std::cout << "3：老板" << std::endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case1:
				worker = new Employee(newName,newId,"员工");
				break;
			case2:
				worker = new Manager(newName, newId, "经理");
				break;
			case3:
				worker = new Boss(newName, newId, "老板");
				break;
			}
			//更新数据到数组中
			this->m_wokerArr[ret] = worker;
			std::cout << "修改成功" << std::endl;
			//保存
			this->save();
		}
	}
	
}

int ManagerWorker::isExsit(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_existWorkerNum; i++)
	{
		if (this->m_wokerArr[i]->m_workerNumber == id)
		{
			index = i;
			break;
		}

	}
	return index;
}
void ManagerWorker::sortWorNum()
{
	cout << "请选择排序方式：" << endl;
	cout << "1、升序" << endl;
	cout << "2、降序" << endl;
	
	int selet = 0;
	cin >> selet;
	for (int i = 0; i < m_getEmpNum;i++) 
	{
		int minOrMax = i;
		
		for (int j = i + 1; j < this->m_getEmpNum; j++) 
		{
			if (selet == 1)//升序
			{
				if (this->m_wokerArr[minOrMax]->m_workerNumber > this->m_wokerArr[j]->m_workerNumber) 
				{
					minOrMax = j;
				}
			}
			else  //降序
			{
				if (this->m_wokerArr[minOrMax]->m_workerNumber < this->m_wokerArr[j]->m_workerNumber)
				{
					minOrMax = j;
				}
			}
		}
		//判断一开始认定最小值是不是计算的最小值或最大值，如果不是交换数据
		if (i != minOrMax) 
		{
			Worker* temp = this->m_wokerArr[i];
			this->m_wokerArr[i] = this->m_wokerArr[minOrMax];
			this->m_wokerArr[minOrMax] = temp;
		}
	}
}
void ManagerWorker::cleanFile() 
{
	cout << "确定清空吗？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select ==1) 
	{
		//删除文件后重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		
		if (this->m_wokerArr != NULL) 
		{
			//删除数组中每一个对象
			for (int i = 0; i < this->m_getEmpNum; i++) 
			{
				delete this->m_wokerArr[i];
				this->m_wokerArr[i] = NULL;
			}
			//删除堆区数组指针
			delete[] this->m_wokerArr;
			this->m_wokerArr = NULL;
			this->m_getEmpNum = 0;
			this->m_FileIsEmpty = true;
		}
	}
	else
	{

	}
}
void ManagerWorker::findWorker() 
{
	if (this->m_FileIsEmpty) 
	{
		std::cout << "文件不存在" << std::endl;
	}
	else
	{
		std::cout << "请输入查找方式" << std::endl;
		std::cout << "1、按照职工编号进行查找" << std::endl;
		std::cout << "2、按照职工姓名查找" << std::endl;
		int slect = 0;
		cin >> slect;
		switch (slect)
		{
		case1:
			int id;
			std::cout << "请输入需要查找的员工编号：" << endl;
			cin >> id;

			int ret = isExsit(id);
			if (ret != -1) 
			{
				this->m_wokerArr[ret]->responsibility();
			}
			else
			{
				cout << "查找失败" << endl;
			}
			break;
		case2:
			break;
		}

	}


}
void ManagerWorker::showMenu() 
{
	std::cout << "*********************************" << std::endl;
	std::cout << "*******欢迎使用职工管理系统******" << std::endl;
	std::cout << "*******0.退出管理系统************" << std::endl;
	std::cout << "*******1.增加职工信息***********" << std::endl;
	std::cout << "*******2.显示职工信息************" << std::endl;
	std::cout << "*******3.删除离职职工************" << std::endl;
	std::cout << "*******4.修改职工信息************" << std::endl;
	std::cout << "*******5.查找职工信息************" << std::endl;
	std::cout << "*******6.按照编号编排************" << std::endl;
	std::cout << "*******7.清空所有文档************" << std::endl;
	std::cout << "*********************************" << std::endl;
}
void ManagerWorker::exitSystem() 
{
	std::cout << "欢迎下次使用" << std::endl;
	system("pause");
	exit(0);
}
void ManagerWorker::save() 
{
	
	ofstream  ofs;
	ofs.open(FILENAME, ios::out);
	std::cout << "修改1：" << this->m_existWorkerNum << std::endl;
	for (int i = 0; i < this->m_existWorkerNum; i++) 
	{
		std::cout <<"修改2：" << this->m_wokerArr[i]->m_workerName << std::endl;
		ofs << this->m_wokerArr[i]->m_workerName << ' '
			<< this->m_wokerArr[i]->m_workerNumber << endl;
	}
	ofs.close();
}
int ManagerWorker::getEmpNum() 
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string name;
	int id;
	int num = 0;
	while (ifs>>name&&ifs>>id)
	{
		num++;
	}
	return num;

}
void ManagerWorker::addWorker()
{
	std::cout << "请输入需要添加的人数" << std::endl;
	int addWorkNumber = 0;
	std::cin >> addWorkNumber;
	
	if (addWorkNumber > 0)
	{
		int newSize = this->m_existWorkerNum + addWorkNumber;
		Worker** newSpace = new Worker*[newSize ];

		//for (int i = 0; i < this->m_existWorkerNum; i++) 
		if(this->m_wokerArr !=NULL)
		{
			for (int i = 0; i < this->m_existWorkerNum; i++) 
			{
				newSpace[i] = this->m_wokerArr[i];
			}
			
		}
		
		
		for (int i = 0; i < addWorkNumber; i++) 
		{
			int id;
			std::string name;
			int select;
			

			std::cout << "请输入要添加的员工姓名：" << std::endl;
			std::cin >> name;
		
			std::cout << "请输入要添加的员工编号：" << std::endl;
			std::cin >> id;
		
			std::cout << "请选择要添加的职工类型" << std::endl;
			std::cout << "1.普通职工" << std::endl;
			std::cout << "2.经理" << std::endl;
			std::cout << "3.老板" << std::endl;
			std::cin >> select;
			
			Worker* newWorker = NULL;

			switch (select)
			{
			case 1:

				newWorker = new Employee(name, id, "普通职工");
				newSpace[this->m_existWorkerNum + i] = newWorker;
				break;

			case 2:
				newWorker = new Employee(name, id, "经理");
				newSpace[this->m_existWorkerNum + i] = newWorker;
				break;
			case 3:
				newWorker = new Employee(name, id, "老板");
				newSpace[this->m_existWorkerNum + i] = newWorker;
				break;
			}


			
		}
		delete[] this->m_wokerArr;
		this->m_wokerArr = newSpace;
		this->m_existWorkerNum = addWorkNumber;
		std::cout << "人数" << this->m_existWorkerNum << std::endl;
		this->save();
		this->m_FileIsEmpty = false;
		std::cout << "添加成功" << std::endl;
	}
	else
	{
		std::cout << "添加失败" << std::endl;
	}

	


	system("pause");
	system("cls");
}

