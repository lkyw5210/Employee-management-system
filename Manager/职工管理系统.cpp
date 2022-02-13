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
			std::cout << "退出管理系统" << std::endl;
			wm.exitSystem();
			break;
		case 1:
			std::cout << "增加职工信息" << std::endl;
			break;
		case 2:
			std::cout << "显示职工信息" << std::endl;


			break;
		case 3:
			std::cout << "删除职工信息" << std::endl;
			break;
		case 4:
			std::cout << "修改职工信息" << std::endl;
			break;
		case 5:
			std::cout << "查找职工信息" << std::endl;
			break;
		case 6:
			std::cout << "按照编号编排" << std::endl;
			break;
		case 7:
			std::cout << "清空所有文档" << std::endl;
			break;

		}

		wm.addWorker();

		system("pause");
		return 0;
	}
}