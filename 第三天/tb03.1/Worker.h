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
	// ��CWorker�ڵ�Main����
	int Main();
private:
	// //���˵�
	int Menu();
	// //���
	void Browse();
	void PrintAll();
	// //�������
	void Input();
	void Add(int n);
	// //ɾ������
	void Delete();
	// //��������
	void Find();
	void Printone(const SWorker& data);
	// ɾ������
	void Modify();
};
