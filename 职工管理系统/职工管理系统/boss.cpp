#include"boss.h"
Boss::Boss(int id, string name, int did)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_workId = did;
}
void Boss::showId()
{
	cout << "职工编号：" << this->w_Id
		<< "\t职工姓名：" << this->w_Name
		<< "\t岗位：" << this->getworkname()
		<< "\t岗位职责:管理公司所有事物" << endl;
}
string Boss::getworkname()
{
	return string("总裁");
}
