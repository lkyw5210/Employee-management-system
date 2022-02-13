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
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		std::cout << "�ļ�������" << std::endl;
		this->m_existWorkerNum = 0;
		this->m_wokerArr = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//�ļ����ڣ����Ǳ����
	if (ifs.eof()) 
	{
		std::cout << "�ļ�Ϊ�գ�" << std::endl;
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
		std::cout << "�ļ������ڻ��¼Ϊ��" << std::endl;
	}
	else
	{
		//����ְ�����ɾ��
		std::cout << "��������Ҫɾ����ְ����ţ�" << std::endl;
		int id = 0;
		cin >> id;
		int index = this->isExsit(id);
		if (index == -1) 
		{
			std::cout << "�û�������" << std::endl;
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
		std::cout << "�ļ������ڻ��߼�¼Ϊ��"<<std::endl;
	}
	else
	{
		int id ;
		std::cout << "��������Ҫ�޸ĵ�ְ�����" << std::endl;
		std::cin >> id;
		int ret = this->isExsit(id);
		if (ret == -1)
		{
			std::cout << "�û�������" << std::endl;

		}
		else
		{
			delete this->m_wokerArr[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;
			std::cout << "�鵽��" << id << "��Ա������������Ա�����"<<std::endl;
			cin >> newId;
			std::cout << "����������" << std::endl;
			cin >> newName;
			std::cout << "�������λu" << std::endl;
			std::cout << "1����ͨԱ��" << std::endl;
			std::cout << "2������" << std::endl;
			std::cout << "3���ϰ�" << std::endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case1:
				worker = new Employee(newName,newId,"Ա��");
				break;
			case2:
				worker = new Manager(newName, newId, "����");
				break;
			case3:
				worker = new Boss(newName, newId, "�ϰ�");
				break;
			}
			//�������ݵ�������
			this->m_wokerArr[ret] = worker;
			std::cout << "�޸ĳɹ�" << std::endl;
			//����
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
	cout << "��ѡ������ʽ��" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	
	int selet = 0;
	cin >> selet;
	for (int i = 0; i < m_getEmpNum;i++) 
	{
		int minOrMax = i;
		
		for (int j = i + 1; j < this->m_getEmpNum; j++) 
		{
			if (selet == 1)//����
			{
				if (this->m_wokerArr[minOrMax]->m_workerNumber > this->m_wokerArr[j]->m_workerNumber) 
				{
					minOrMax = j;
				}
			}
			else  //����
			{
				if (this->m_wokerArr[minOrMax]->m_workerNumber < this->m_wokerArr[j]->m_workerNumber)
				{
					minOrMax = j;
				}
			}
		}
		//�ж�һ��ʼ�϶���Сֵ�ǲ��Ǽ������Сֵ�����ֵ��������ǽ�������
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
	cout << "ȷ�������" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select ==1) 
	{
		//ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		
		if (this->m_wokerArr != NULL) 
		{
			//ɾ��������ÿһ������
			for (int i = 0; i < this->m_getEmpNum; i++) 
			{
				delete this->m_wokerArr[i];
				this->m_wokerArr[i] = NULL;
			}
			//ɾ����������ָ��
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
		std::cout << "�ļ�������" << std::endl;
	}
	else
	{
		std::cout << "��������ҷ�ʽ" << std::endl;
		std::cout << "1������ְ����Ž��в���" << std::endl;
		std::cout << "2������ְ����������" << std::endl;
		int slect = 0;
		cin >> slect;
		switch (slect)
		{
		case1:
			int id;
			std::cout << "��������Ҫ���ҵ�Ա����ţ�" << endl;
			cin >> id;

			int ret = isExsit(id);
			if (ret != -1) 
			{
				this->m_wokerArr[ret]->responsibility();
			}
			else
			{
				cout << "����ʧ��" << endl;
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
	std::cout << "*******��ӭʹ��ְ������ϵͳ******" << std::endl;
	std::cout << "*******0.�˳�����ϵͳ************" << std::endl;
	std::cout << "*******1.����ְ����Ϣ***********" << std::endl;
	std::cout << "*******2.��ʾְ����Ϣ************" << std::endl;
	std::cout << "*******3.ɾ����ְְ��************" << std::endl;
	std::cout << "*******4.�޸�ְ����Ϣ************" << std::endl;
	std::cout << "*******5.����ְ����Ϣ************" << std::endl;
	std::cout << "*******6.���ձ�ű���************" << std::endl;
	std::cout << "*******7.��������ĵ�************" << std::endl;
	std::cout << "*********************************" << std::endl;
}
void ManagerWorker::exitSystem() 
{
	std::cout << "��ӭ�´�ʹ��" << std::endl;
	system("pause");
	exit(0);
}
void ManagerWorker::save() 
{
	
	ofstream  ofs;
	ofs.open(FILENAME, ios::out);
	std::cout << "�޸�1��" << this->m_existWorkerNum << std::endl;
	for (int i = 0; i < this->m_existWorkerNum; i++) 
	{
		std::cout <<"�޸�2��" << this->m_wokerArr[i]->m_workerName << std::endl;
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
	std::cout << "��������Ҫ��ӵ�����" << std::endl;
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
			

			std::cout << "������Ҫ��ӵ�Ա��������" << std::endl;
			std::cin >> name;
		
			std::cout << "������Ҫ��ӵ�Ա����ţ�" << std::endl;
			std::cin >> id;
		
			std::cout << "��ѡ��Ҫ��ӵ�ְ������" << std::endl;
			std::cout << "1.��ְͨ��" << std::endl;
			std::cout << "2.����" << std::endl;
			std::cout << "3.�ϰ�" << std::endl;
			std::cin >> select;
			
			Worker* newWorker = NULL;

			switch (select)
			{
			case 1:

				newWorker = new Employee(name, id, "��ְͨ��");
				newSpace[this->m_existWorkerNum + i] = newWorker;
				break;

			case 2:
				newWorker = new Employee(name, id, "����");
				newSpace[this->m_existWorkerNum + i] = newWorker;
				break;
			case 3:
				newWorker = new Employee(name, id, "�ϰ�");
				newSpace[this->m_existWorkerNum + i] = newWorker;
				break;
			}


			
		}
		delete[] this->m_wokerArr;
		this->m_wokerArr = newSpace;
		this->m_existWorkerNum = addWorkNumber;
		std::cout << "����" << this->m_existWorkerNum << std::endl;
		this->save();
		this->m_FileIsEmpty = false;
		std::cout << "��ӳɹ�" << std::endl;
	}
	else
	{
		std::cout << "���ʧ��" << std::endl;
	}

	


	system("pause");
	system("cls");
}

