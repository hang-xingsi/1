#pragma once
#include<iostream>
using namespace std;
#include<string>
class work
{
public:
	//显示个人信息
	virtual void showId() = 0;
	//获取岗位名称
	virtual string getworkname() = 0;
public:
	int w_Id;
	string w_Name;
	int w_workId;
};