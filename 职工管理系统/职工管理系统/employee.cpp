#include"employee.h"

Employee::Employee(int id, string name, int did)
{
	this->w_Id=id;
	this->w_Name = name;
	this->w_workId = did;
}
void Employee::showId()
{
	cout << "ְ����ţ�" << this->w_Id
		<< "\tְ��������" << this->w_Name
		<< "\t��λ��" << this->getworkname()
		<< "\t��λְ��:��ɾ�����������" << endl;
}
string Employee::getworkname()
{
	return string("Ա��");
}