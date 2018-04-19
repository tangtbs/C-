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
	DATA data;
	SNode* pNext;
};
class Clist
{
public:
	Clist();
	~Clist();

private:
	// Õ∑÷∏’Î
	SNode* m_pHead;
	void AddHead(DATA& data);
	void AddTail(DATA& data);
	int Remove(DATA& data);
	
	int RemoveAll();
	int SetData(SNode& node,DATA& data);
	SNode* SearchbyName(char* name);
	SNode* SearchbyNumb(int numb);
};

