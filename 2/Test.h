#pragma once
#include<iostream>
using namespace std;
#include"Clist.h"
class CTest
{
public:
	CTest();
	~CTest();

private:
	Clist m_list1, m_list2;


public:
	// //����������
	int Main();
private:
	// //���˵�
	int Menu();
	// //���
	void Browse();
	void PrintAll();
	// //ѡ���ĸ�����
	Clist& Select();
};

