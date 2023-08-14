#include<iostream>
#include"菜单.h"
#include"职工.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;
int main()
{
	worker w;
	int choice;
	while (1)
	{
		w.show_mune();
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			w.exit_system();
			break;
		case 1:
			w.Add_Emp();
			break;
		case 2:
			w.Show_Emp();
			break;
		case 3:
		{
			int id;
			cout << "请输入你要删除职工的编号"<<endl;
			cin >> id;
			w.Del_Emp(id);
		}
			break;
		case 4:
		{
			int id;
			cout << "请输入你要修改职工的编号" << endl;
			cin >> id;
			w.Mod_Emp(id);
		}
			break;
		case 5:
			w.Find_Emp();
			break;
		case 6:
			w.Sort_Emp();
			break;
		case 7:
			w.Clean_Emp();
			break;
		default:
			cout << "输入错误" << endl;
			break;
		}
	}
	system("cle");
	system("pause");
	return 0;
}
