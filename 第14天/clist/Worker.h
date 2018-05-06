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
	// //主菜单
	int Menu();
	// //浏览
	void Browse();
	void PrintAll();
	// //添加数据
	void Input();
	void Add(int n);
	// //删除数据
	void Delete();
	// //查找数据
	void Search();
	void Printone(const list<SWorker>::iterator& it);
	// 删除数据
	void Modify();
	int BrowseMenu();
	static bool CWorker::SortbyNumb(SWorker&m1, SWorker&m2);
	static bool CWorker::SortbyName(SWorker&m1, SWorker&m2);
	static bool CWorker::SortbySala(SWorker&m1, SWorker&m2);
	void SearchbyNumb(int numb,list<SWorker>::iterator& it);
	void SearchbyName(char* s,list<SWorker>::iterator& it);
	void Save();
	void Load();
	void Login();
	void CreateUser();
	void Password();
	void RootPassword();
	// 密码输入
	void PasswordInput(char* p);
	/*static bool RemoveIf(const SWorker& data);*/
};

