#pragma once
#include<iostream>
struct DATA
{
	int nNumb;
	char sName[20];
	float fSala;
};
struct SNode
{
	SNode* pRevi;
	SNode* pNext;
	DATA data;
};
class Clist
{
public:
	Clist();
	~Clist();
	SNode* m_pHead;
	SNode* m_pTail;
	//头添加
	void AddHead(DATA& data);
	//尾添加
	void AddTail(DATA& data);
	// 删除
	int Removeone(SNode& p);
	//按工号查找
	SNode& FindbyNumb(int numb);
	//按姓名查找
	SNode& FindbyName(char* name);
	//修改
	int Set(SNode& node,DATA& data);
	//插入数据
	void Insert(DATA& data, SNode& node);
	//删除所有数据
	int RemoveAll();
};

