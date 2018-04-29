#pragma once
#include<afxtempl.h>
#include<iostream>
#include<conio.h>
using namespace std;
struct SWorker
{
	int nNumb;
	char sName[20];
	char sPasword[20] = "000000";
	float fSala = 0;
	bool bPower = false;
};
class CWorker
{
public:
	CWorker();
	~CWorker();
	void Into();
	CArray<SWorker>m_list;
private:
	
	SWorker Super;
	SWorker User;
	int Main();
	// //主菜单
	int Menu();
	// //浏览
	void Browse();
	// //添加数据
	void Input();
	void Add();
	// //删除数据
	void Delete();
	// //查找数据
	void Search();
	void Printone(int Index);
	// 删除数据
	void Modify();
	int BrowseMenu();
	void PrintAll(const SWorker * p);
	SWorker* Sort(int n);
	int Sortby(SWorker&, SWorker&, int n);
	int SearchbyNumb(int numb);
	int SearchbyName(char* s);
	void Save();
	void Load();
	void Login();
	void CreateUser();
	void Password();
	void PasswordInput(char* password);
	void RootPassword();
};