#include"�˵�.h"
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
    cout << "******��ӭʹ��ְ������ϵͳ!*******" << endl;
	cout << "**********0.�˳�����ϵͳ**********" << endl;
	cout << "**********1.����ְ����Ϣ**********" << endl;
	cout << "**********2.��ʾְ����Ϣ**********" << endl;
	cout << "**********3.ɾ��ְ����Ϣ**********" << endl;
	cout << "**********4.�޸�ְ����Ϣ**********" << endl;
	cout << "**********5.����ְ����Ϣ**********" << endl;
	cout << "**********6.���ձ������**********" << endl;
	cout << "**********7.��������ĵ�**********" << endl;
	cout << "**********************************" << endl;
	cout << endl;
}
void worker::exit_system()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void worker::Add_Emp()
{
	int add_numble;
	cout << "��Ҫ����ְ��������:"<<endl;
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
			cout << "�������" << numble + i + 1 << "��ְ���ı��" << endl;
			cin >> id;
			cout << "�������" << numble + i + 1 << "��ְ��������" << endl;
			cin >> name;
			cout << "�������" << numble + i + 1 << "��ְ����ְλ��Ӧ���" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
			cin >> did;
			while (1)        //��ֹ��λ������󣬴�������worker���ݣ�д�ļ�ʱ����
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
					cout << "��λ�����������������" << endl;
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
			cout << "�ѳɹ���ӣ�" << add_numble << "ְ��" << endl;
	}
	else
	{
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");
}
void worker::Show_Emp()
{
	if (this->w_wenjian == true)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		if (this->Search_Emp(id)==-1)
		{
			cout << "�޷����ҵ����û�" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		if (this->Search_Emp(id)==-1)
		{
			cout << "�޷����ҵ����û�" << endl;
		}
		else
		{
			int i = this->Search_Emp(id);
			delete this->w_EmpArray[i];
			int new_id;
			string new_name;
			int new_did;
			cout << "����������ְ�����" << endl;
			cin >> new_id;
			cout << "����������ְ������" << endl;
			cin >> new_name;
			cout << "������ְ��ְλ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
			cin >> new_did;
			work * new_p=NULL;
			while (1)        //��ֹ��λ������󣬴�������worker���ݣ�д�ļ�ʱ����
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
					cout << "��λ�����������������" << endl;
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
			cout << "�ļ������ڻ��¼Ϊ��" << endl;
			break;
		}
		else
		{
			int j;
			cout << "����������Ҫ���ҵķ�ʽ" << endl;
			cout << "1.ְ�����" << endl;
			cout << "2.ְ������" << endl;
			cin >> j;
			if (j == 1)
			{
				int w_id;
				cout << "���������ְ���ı��" << endl;
				cin >> w_id;
				int index = this->Search_Emp(w_id);
				if (index == -1)
				{
					cout << "δ���ҵ���ְ��" << endl;
				}
				else
				{
					cout << "���ҵ���ְ��,��Ϣ����" << endl;
					this->w_EmpArray[index]->showId();
				}
				break;
			}
			else if (j == 2)
			{
				string w_name;
				cout << "���������ְ��������" << endl;
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
					cout << "δ���ҵ���ְ��" << endl;
				}
				else
				{
					cout << "���ҵ���ְ��,��Ϣ����" << endl;
					this->w_EmpArray[index2]->showId();
				}
				break;
			}
			else
			{
				cout << "�������,����������" << endl;
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
			cout << "�ļ������ڻ��¼Ϊ��" << endl;
			break;
		}
		else
		{
			int j;
			cout << "����������Ҫ����ķ�ʽ" << endl;
			cout << "1.��ְ����Ž�������" << endl;
			cout << "2.��ְ����Ž��н���" << endl;
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
				cout << "�������,����������" << endl;
			}
		}
	}
	this->save();
	system("pause");
	system("cls");
}
void worker::Clean_Emp()
{
	cout << "ȷ�����" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
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
			cout << "��ճɹ�" << endl;
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