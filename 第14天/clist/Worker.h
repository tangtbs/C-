#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<list>
#include<iostream>
#include<conio.h>
using namespace std;
struct SWorker
{
	int nNumb;
	char sName[20];
	char sPasword[20];
	float fSala;
	bool bPower;
	SWorker()
	{
	    strcpy(sPasword,"000000");
		fSala = 0;
	    bPower = false;
	}
	
	bool operator==(SWorker worker)
	{
		return nNumb == worker.nNumb ? true : false;
	}
};
class CWorker
{
	list<SWorker>m_list;
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
	SWorker SearchbyNumb(int numb);
	SWorker SearchbyName(char* s);
	void Save();
	void Load();
	void Login();
	void CreateUser();
	void Password();
	void RootPassword();
	// ��������
	void PasswordInput(char* p);
};

