#pragma once
#include<iostream>
using namespace std;
#include<string>
class work
{
public:
	//��ʾ������Ϣ
	virtual void showId() = 0;
	//��ȡ��λ����
	virtual string getworkname() = 0;
public:
	int w_Id;
	string w_Name;
	int w_workId;
};