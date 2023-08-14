#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"职工.h"
#include<fstream>
class worker
{
public:
	worker();
	void show_mune();
	void exit_system();
	//职工数组指针
	work** w_EmpArray;
	//添加职工
	void Add_Emp();
	//显示职工
	void Show_Emp();
	//删除职工
	void Del_Emp(int id);
	//修改职工
	void Mod_Emp(int id);
	//查找员工
	void Find_Emp();
	//按员工编号排序
	void Sort_Emp();
	//清理文件
	void Clean_Emp();
	//判断职工是否存在
	int Search_Emp(int id);
	//保存数据
	void save();
	//统计人数
	int get_numble();
	//初始化数组
	void init_Emp();
	//
	~worker();
public:
	//原有人数
	int numble;
	//文件是否为空或不存在
	bool w_wenjian;
};