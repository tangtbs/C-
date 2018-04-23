#pragma once
#include"Clist.h"
#include<iostream>
#include<conio.h>
using namespace std;
struct SWorker
{
	int nNumb;
	char sName[20];
	char sPasword[20]="000000";
	float fSala=0;
	bool bPower=false;
};
class CWorker
{
	Clist<SWorker>m_list;
public:
	CWorker();
	~CWorker();
	void Into();
private:
	SWorker Super;
	SWorker User;
	int Main();
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
	POSITION SearchbyName(char* s);
	void Save();
	void Load();
	void Login();
	void CreateUser();
	void Password();
	
};

