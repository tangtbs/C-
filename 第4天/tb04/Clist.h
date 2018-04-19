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
	SNode* pPrev;
	SNode* pNext;
	DATA data;
};
typedef void* POSITION;
class Clist
{
public:
	Clist();
	~Clist();
	SNode* m_pHead;
	SNode* m_pTail;
	//ͷ���
	void AddHead(const DATA& data);
	//β���
	void AddTail(const DATA& data);
	// ɾ��
	int RemoveAt(SNode& p);
	//�����Ų���
	POSITION FindbyNumb(int numb);
	//����������
	POSITION FindbyName(char* name);
	//�޸�
	int Set(SNode& node,const DATA& data);
	//��������
	void Insert(const DATA& data, POSITION pos);
	//ɾ����������
	int RemoveAll();
	DATA& GetAt(POSITION pos)
	{
		return ((SNode*)pos)->data;
	}
	DATA& GetNext(POSITION pos)
	{
		pos = ((SNode*)pos)->pNext;
		return ((SNode*)pos)->pPrev->data;
	}
	DATA& GetPrev(POSITION pos)
	{
		pos = ((SNode*)pos)->pPrev;
		return ((SNode*)pos)->pNext->data;
	}
	DATA& GetHead()
	{
		return m_pHead->data;
	}
	POSITION GetHeadPosition()
	{
		return (POSITION)m_pHead;
	}
	DATA& GetTail()
	{
		return m_pTail->data;
	 }

	POSITION GetTailPosition()
	{
		return (POSITION)m_pTail;
	}
};

