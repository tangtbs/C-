#pragma once
#include"Clist.h"
#include<iostream>
#include<conio.h>
using namespace std;
struct SWorker
{
	int nNumb;
	char sName[20];
	float fSala;
};
class CWorker
{
	Clist<SWorker>m_list;
public:
	CWorker();
	~CWorker();
	// ��CWorker�ڵ�Main����
	int Main();
private:
	// //���˵�
	int Menu();
	// //���
	void Browse();
	void PrintAll(SWorker**);
	// //�������
	void Input();
	void Add(int n);
	// //ɾ������
	void Delete();
	// //��������
	void Search();
	void Printone(const SWorker& data);
	// ɾ������
	void Modify();
	int BrowseMenu();
	SWorker** Sort(int n);
	int Sortby(SWorker&, SWorker&, int n);
	POSITION SearchbyNumb(int numb);
};


