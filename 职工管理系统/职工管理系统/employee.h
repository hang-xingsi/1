#pragma once
#include<iostream>
using namespace std;
#include"ְ��.h"

class Employee :public work
{
public:
	Employee(int id,string name,int did);
	virtual void showId();
	virtual string getworkname();
};