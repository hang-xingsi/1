#pragma once
#include<iostream>
using namespace std;
#include"ְ��.h"
class Manager:public work
{
public:
	Manager(int id, string name, int did);
	virtual void showId();
	virtual string getworkname();
};