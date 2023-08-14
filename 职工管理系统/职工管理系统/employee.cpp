#include"employee.h"

Employee::Employee(int id, string name, int did)
{
	this->w_Id=id;
	this->w_Name = name;
	this->w_workId = did;
}
void Employee::showId()
{
	cout << "职工编号：" << this->w_Id
		<< "\t职工姓名：" << this->w_Name
		<< "\t岗位：" << this->getworkname()
		<< "\t岗位职责:完成经理交给的任务" << endl;
}
string Employee::getworkname()
{
	return string("员工");
}