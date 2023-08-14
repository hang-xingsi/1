#pragma once
#include<iostream>
using namespace std;
#include"Ö°¹¤.h"
class Boss:public work
{
public:
	Boss(int id, string name, int did);
	virtual void showId();
	virtual string getworkname();
};