#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"ְ��.h"
#include<fstream>
class worker
{
public:
	worker();
	void show_mune();
	void exit_system();
	//ְ������ָ��
	work** w_EmpArray;
	//���ְ��
	void Add_Emp();
	//��ʾְ��
	void Show_Emp();
	//ɾ��ְ��
	void Del_Emp(int id);
	//�޸�ְ��
	void Mod_Emp(int id);
	//����Ա��
	void Find_Emp();
	//��Ա���������
	void Sort_Emp();
	//�����ļ�
	void Clean_Emp();
	//�ж�ְ���Ƿ����
	int Search_Emp(int id);
	//��������
	void save();
	//ͳ������
	int get_numble();
	//��ʼ������
	void init_Emp();
	//
	~worker();
public:
	//ԭ������
	int numble;
	//�ļ��Ƿ�Ϊ�ջ򲻴���
	bool w_wenjian;
};