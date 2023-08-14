#include"manager.h"
Manager::Manager(int id, string name, int did)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_workId = did;
}
void Manager::showId()
{
	cout << "职工编号：" << this->w_Id
		<< "\t职工姓名：" << this->w_Name
		<< "\t岗位：" << this->getworkname()
		<< "\t岗位职责:完成老板交给的任务" << endl;
}
string Manager::getworkname()
{
	return string("经理");
}
