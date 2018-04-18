#pragma once
#include<afxtempl.h>
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
	CList<SWorker>m_list;
public:
	CWorker();
	~CWorker();
	// 类CWorker内的Main函数
	int Main();
private:
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
	void Find();
	void Printone(const SWorker& data);
	// 删除数据
	void Modify();
};
