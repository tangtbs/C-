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
	// //类内主函数
	int Main();
private:
	// //主菜单
	int Menu();
	// //浏览
	void Browse();
	void PrintAll();
	// //选择哪个链表
	Clist& Select();
};

