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
	SNode* pRevi;
	SNode* pNext;
	DATA data;
};
class Clist
{
public:
	Clist();
	~Clist();
	SNode* m_pHead;
	SNode* m_pTail;
	//ͷ���
	void AddHead(DATA& data);
	//β���
	void AddTail(DATA& data);
	// ɾ��
	int Removeone(SNode& p);
	//�����Ų���
	SNode& FindbyNumb(int numb);
	//����������
	SNode& FindbyName(char* name);
	//�޸�
	int Set(SNode& node,DATA& data);
	//��������
	void Insert(DATA& data, SNode& node);
	//ɾ����������
	int RemoveAll();
};

