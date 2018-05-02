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
	void PrintAll(SWorker**);
	// //添加数据
	void Input();
	void Add(int n);
	// //删除数据
	void Delete();
	// //查找数据
	void Search();
	void Printone(const SWorker& data);
	// 删除数据
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
	// 密码输入
	void PasswordInput(char* p);
};

