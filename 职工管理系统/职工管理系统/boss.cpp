#include"boss.h"
Boss::Boss(int id, string name, int did)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_workId = did;
}
void Boss::showId()
{
	cout << "ְ����ţ�" << this->w_Id
		<< "\tְ��������" << this->w_Name
		<< "\t��λ��" << this->getworkname()
		<< "\t��λְ��:����˾��������" << endl;
}
string Boss::getworkname()
{
	return string("�ܲ�");
}
