#include <iostream>
#include "ManagerWorker.h"
#include "Employee.h"
#include "Worker.h"
#include "Boss.h"

int main()
{
	ManagerWorker wm;
	int option = 0;
	wm.showMenu();
	std:: cin >> option;
	while (true)
	{
		switch (option)
		{
		case 0:
			std::cout << "�˳�����ϵͳ" << std::endl;
			wm.exitSystem();
			break;
		case 1:
			std::cout << "����ְ����Ϣ" << std::endl;
			break;
		case 2:
			std::cout << "��ʾְ����Ϣ" << std::endl;


			break;
		case 3:
			std::cout << "ɾ��ְ����Ϣ" << std::endl;
			break;
		case 4:
			std::cout << "�޸�ְ����Ϣ" << std::endl;
			break;
		case 5:
			std::cout << "����ְ����Ϣ" << std::endl;
			break;
		case 6:
			std::cout << "���ձ�ű���" << std::endl;
			break;
		case 7:
			std::cout << "��������ĵ�" << std::endl;
			break;

		}

		wm.addWorker();

		system("pause");
		return 0;
	}
}