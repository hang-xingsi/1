#include<iostream>
#include"�˵�.h"
#include"ְ��.h"
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
		cout << "���������ѡ��" << endl;
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
			cout << "��������Ҫɾ��ְ���ı��"<<endl;
			cin >> id;
			w.Del_Emp(id);
		}
			break;
		case 4:
		{
			int id;
			cout << "��������Ҫ�޸�ְ���ı��" << endl;
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
			cout << "�������" << endl;
			break;
		}
	}
	system("cle");
	system("pause");
	return 0;
}
