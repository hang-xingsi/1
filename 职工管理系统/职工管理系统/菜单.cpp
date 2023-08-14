#include"菜单.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<cstdlib>
worker::worker()
{
	ifstream ifs;
	ifs.open("empfile.txt", ios::in);
	if (!ifs.is_open())
	{
		this->numble = 0;
		this->w_EmpArray = NULL;
		this->w_wenjian = true;
		ifs.close();
		return;
	}
	else
	{
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			this->numble = 0;
			this->w_EmpArray = NULL;
			this->w_wenjian = true;
			ifs.close();
			return;
		}
	}

	this->numble = this->get_numble();
	this->w_EmpArray = new work * [this->numble];
	this->init_Emp();

}
void worker::show_mune()
{
	cout << "**********************************" << endl;
    cout << "******欢迎使用职工管理系统!*******" << endl;
	cout << "**********0.退出管理系统**********" << endl;
	cout << "**********1.增加职工信息**********" << endl;
	cout << "**********2.显示职工信息**********" << endl;
	cout << "**********3.删除职工信息**********" << endl;
	cout << "**********4.修改职工信息**********" << endl;
	cout << "**********5.查找职工信息**********" << endl;
	cout << "**********6.按照编号排序**********" << endl;
	cout << "**********7.清空所有文档**********" << endl;
	cout << "**********************************" << endl;
	cout << endl;
}
void worker::exit_system()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void worker::Add_Emp()
{
	int add_numble;
	cout << "你要增加职工的人数:"<<endl;
	cin >> add_numble;
	if (add_numble > 0)
	{
		int w_size = numble + add_numble;
		work** new_EmpArray = new work * [w_size];
		if (this->w_EmpArray != NULL)
		{
			for (int i = 0; i < numble; i++)
			{
				new_EmpArray[i] = w_EmpArray[i];
			}
		}
		for (int i = 0; i < add_numble; i++)
		{
			work* new_w = NULL;
			int id;
			string name;
			int did;
			cout << "请输入第" << numble + i + 1 << "个职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << numble + i + 1 << "个职工的名字" << endl;
			cin >> name;
			cout << "请输入第" << numble + i + 1 << "个职工的职位对应编号" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> did;
			while (1)        //防止岗位输入错误，创建不了worker数据，写文件时出错
			{
				if (did == 1 || did == 2 || did == 3)
				{
					switch (did)
					{
					case 1:
						new_w = new Employee(id, name, did);
						break;
					case 2:
						new_w = new Manager(id, name, did);
						break;
					case 3:
						new_w = new Boss(id, name, did);
						break;
					default:
						break;
					}
					
					break;
				}
				else
				{
					cout << "岗位输入错误，请重新输入" << endl;
					cin >> did;
				}
			}
			new_EmpArray[this->numble+i] = new_w;
		}
		
			delete[]this->w_EmpArray;
			numble = w_size;
			this->w_EmpArray = new_EmpArray;
			save();
			this->w_wenjian = false;
			cout << "已成功添加：" << add_numble << "职工" << endl;
	}
	else
	{
		cout << "输入错误" << endl;
	}
	system("pause");
	system("cls");
}
void worker::Show_Emp()
{
	if (this->w_wenjian == true)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->numble; i++)
		{
		    this->w_EmpArray[i]->showId();
		}
	}
	system("pause");
	system("cls");
}
void worker::Del_Emp(int id)
{
	if (this->w_wenjian ==true)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		if (this->Search_Emp(id)==-1)
		{
			cout << "无法查找到此用户" << endl;
		}
		else
		{
			for (int i = this->Search_Emp(id); i < this->numble-1; i++)
			{
				this->w_EmpArray[i] = this->w_EmpArray[i + 1];
			}
			this->numble--;
		}
	}
	this->save();
	system("pause");
	system("cls");
}
void worker::Mod_Emp(int id)
{
	if (this->w_wenjian == true)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		if (this->Search_Emp(id)==-1)
		{
			cout << "无法查找到此用户" << endl;
		}
		else
		{
			int i = this->Search_Emp(id);
			delete this->w_EmpArray[i];
			int new_id;
			string new_name;
			int new_did;
			cout << "请重新输入职工编号" << endl;
			cin >> new_id;
			cout << "请重新输入职工名字" << endl;
			cin >> new_name;
			cout << "请输入职工职位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> new_did;
			work * new_p=NULL;
			while (1)        //防止岗位输入错误，创建不了worker数据，写文件时出错
			{
				if (new_did == 1 || new_did == 2 || new_did == 3)
				{
					switch (new_did)
					{
					case 1:
						new_p = new Employee(new_id, new_name, new_did);
						break;
					case 2:
						new_p = new Manager(new_id, new_name, new_did);
						break;
					case 3:
						new_p = new Boss(new_id, new_name, new_did);
						break;
					default:
						break;
					}

					break;
				}
				else
				{
					cout << "岗位输入错误，请重新输入" << endl;
					cin >> new_did;
				}
			}
			this->w_EmpArray[i] = new_p;
		}
	}
	this->save();
	system("pause");
	system("cls");
}
void worker::Find_Emp()
{
	while (1)
	{
		if (this->w_wenjian == true)
		{
			cout << "文件不存在或记录为空" << endl;
			break;
		}
		else
		{
			int j;
			cout << "请输入你想要查找的方式" << endl;
			cout << "1.职工编号" << endl;
			cout << "2.职工姓名" << endl;
			cin >> j;
			if (j == 1)
			{
				int w_id;
				cout << "请输入查找职工的编号" << endl;
				cin >> w_id;
				int index = this->Search_Emp(w_id);
				if (index == -1)
				{
					cout << "未查找到该职工" << endl;
				}
				else
				{
					cout << "查找到该职工,信息如下" << endl;
					this->w_EmpArray[index]->showId();
				}
				break;
			}
			else if (j == 2)
			{
				string w_name;
				cout << "请输入查找职工的姓名" << endl;
				cin >> w_name;
				int index2 = -1;
				for (int i = 0; i < this->numble; i++)
				{
					if (this->w_EmpArray[i]->w_Name == w_name)
					{
						index2 = i;
						break;
					}
				}
				if (index2 == -1)
				{
					cout << "未查找到该职工" << endl;
				}
				else
				{
					cout << "查找到该职工,信息如下" << endl;
					this->w_EmpArray[index2]->showId();
				}
				break;
			}
			else
			{
				cout << "输入错误,请重新输入" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
void worker::Sort_Emp()
{
	while (1)
	{
		if (this->w_wenjian == true)
		{
			cout << "文件不存在或记录为空" << endl;
			break;
		}
		else
		{
			int j;
			cout << "请输入你想要排序的方式" << endl;
			cout << "1.按职工编号进行升序" << endl;
			cout << "2.按职工编号进行降序" << endl;
			cin >> j;
			if (j == 1)
			{
				for (int m = 0; m < this->numble; m++)
				{
					for (int n = m + 1; n < this->numble; n++)
					{
						work* new_w = NULL;
						if (this->w_EmpArray[m]->w_Id >this->w_EmpArray[n]->w_Id)
						{
							new_w = this->w_EmpArray[m];
							this->w_EmpArray[m] = this->w_EmpArray[n];
							this->w_EmpArray[n] = new_w;
						}
						new_w = NULL;
					}
					
				}
				break;
			}
			else if (j == 2)
			{
				for (int m = 0; m < this->numble; m++)
				{
					for (int n = m + 1; n < this->numble; n++)
					{
						work* new_w = NULL;
						if (this->w_EmpArray[m]->w_Id < this->w_EmpArray[n]->w_Id)
						{
							new_w = this->w_EmpArray[m];
							this->w_EmpArray[m] = this->w_EmpArray[n];
							this->w_EmpArray[n] = new_w;
						}
						new_w = NULL;
					}

				}
				break;
			}
			else
			{
				cout << "输入错误,请重新输入" << endl;
			}
		}
	}
	this->save();
	system("pause");
	system("cls");
}
void worker::Clean_Emp()
{
	cout << "确定清空" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int s;
	cin >> s;
	if (s == 1)
	{
		ofstream ofs;
		ofs.open("empfile.txt", ios::trunc);
			if (this->w_EmpArray != NULL)
			{
				for (int i = 0; i < this->numble; i++)
				{
					if (this->w_EmpArray[i] != NULL)
					{
						delete this->w_EmpArray[i];
					}
				}
				delete[]this->w_EmpArray;
				this->w_EmpArray = NULL;
				this->numble = 0;
				this->w_wenjian = true;
			}
			cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
int  worker::Search_Emp(int id)
{
	int index=-1;
	for (int i = 0; i < this->numble; i++)
	{
		if (this->w_EmpArray[i]->w_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void worker::save()
{
	ofstream ofs;
	ofs.open("empfile.txt", ios::out);
		for (int i = 0; i < this->numble; i++)
		{
			ofs << this->w_EmpArray[i]->w_Id << " "
				<< this->w_EmpArray[i]->w_Name << " " 
				<< this->w_EmpArray[i]->w_workId << endl;
		}
	ofs.close();
}
int worker::get_numble()
{
	ifstream ifs;
	int id;
	string name;
	int did;
	int num=0;
	ifs.open("empfile.txt", ios::in);
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}
void worker::init_Emp()
{
	ifstream ifs;
	ifs.open("empfile.txt", ios::in);
	int id;
	string name;
	int did;
	int index=0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		work* new_m=NULL;
		switch (did)
		{
		case 1:
			new_m = new Employee(id, name, did);
			break;
		case 2:
			new_m = new Manager(id, name, did);
			break;
		case 3:
			new_m = new Boss(id, name, did);
			break;
		default:
			break;
		}
		this->w_EmpArray[index] = new_m;
		index++;
	}
}
worker::~worker()
{
	if (this->w_EmpArray != NULL)
	{
		for (int i = 0; i < this->numble; i++)
		{
			if (this->w_EmpArray[i] != NULL)
			{
				delete this->w_EmpArray[i];
			}
		}
		delete[]this->w_EmpArray;
		this->w_EmpArray = NULL;
		this->numble = 0;
	}
}