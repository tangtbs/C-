#pragma once
#include<iostream>
#include<conio.h>
using namespace std;
typedef struct
{
	char sNumb[20];
	char sName[20];
	float fMath;
	float fChin;
	float fEngl;
}DATA;
typedef struct _SNode
{
	DATA data;
	struct _SNode* pNext;
}SNode;
class Slist
{
public:
	Slist()
	{
		m_pHead = NULL;
	}
	~Slist()
	{
		RemoveAll();
	}
	SNode* m_pHead;
	int Sortby(SNode*, SNode*, int);
	SNode* Searchbystr(char*);
	void AddHead(DATA*);
	void AddTail(DATA*);
	void Save();
	void Load();
	void Qsort(void*base, size_t num, size_t width, int(*fup)(const void*, const void*));
	void RemoveAll();
	void DeleteData(SNode*);
	void ModifyData(SNode*, DATA*);
	SNode** Sortpoint(int);
	void Printpoint(SNode**);
	SNode** QSortbypoint(int n);
	void Print();
	void Printone(SNode*);
	void Sort(int);
	
};