#include"manager.h"
Manager::Manager(int id, string name, int did)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_workId = did;
}
void Manager::showId()
{
	cout << "ְ����ţ�" << this->w_Id
		<< "\tְ��������" << this->w_Name
		<< "\t��λ��" << this->getworkname()
		<< "\t��λְ��:����ϰ彻��������" << endl;
}
string Manager::getworkname()
{
	return string("����");
}
