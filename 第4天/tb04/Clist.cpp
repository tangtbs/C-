#include "Clist.h"



Clist::Clist()
{
	m_pHead = NULL;
	m_pTail = NULL;
}


Clist::~Clist()
{
	RemoveAll();
}


//ͷ���
void Clist::AddHead(DATA& data)
{
	SNode* p = new SNode;
	p->pNext = m_pHead;
	p->pRevi = NULL;
	p->data = data;
	m_pHead = p;
}


//β���
void Clist::AddTail(DATA& data)
{
	SNode*p = new SNode;
	if (!m_pHead)
	{
		p->pNext = NULL;
		p->pRevi = NULL;
		m_pHead = m_pTail = p;
		p->data = data;
	}
	p->pNext = NULL;
	p->pRevi = m_pTail;
	m_pTail = p;
	p->data = data;
	
}


// ɾ��
int Clist::Removeone(SNode& p)
{
	if (!p.data.nNumb)
		return 1;
	if (!m_pHead->pNext)
	{
		delete &p;
		m_pHead = NULL;
		return 0;
	}
	if (p.data.nNumb == m_pHead->data.nNumb)
	{
		m_pHead = p.pNext;
		p.pNext->pRevi = NULL;
		delete &p;
		return 0;
	}
	if (p.data.nNumb == m_pTail->data.nNumb)
	{
		p.pRevi->pNext = NULL;
		m_pTail = p.pRevi;
		delete &p;
		return 0;
	}
	p.pRevi->pNext = p.pNext;
	p.pNext->pRevi = p.pRevi;
	delete &p;
	return 0;
}


// //�����Ų���
SNode& Clist::FindbyNumb(int numb)
{
	SNode* pH = m_pHead;
	if (!pH)
	{
		pH = new SNode{ 0 };
		return *pH;
	}
	while (pH)
	{
		if (pH->data.nNumb == numb)
			return *pH;
		pH = pH->pNext;
	}
	pH = new SNode{ 0 };
	return *pH;
}


// //����������
SNode& Clist::FindbyName(char* name)
{
	SNode* pH = m_pHead;
	if (!pH)
	{
		pH = new SNode{ 0 };
		return *pH;
	}
	while (pH)
	{
		if (!strcmp(pH->data.sName,name))
			return *pH;
		pH = pH->pNext;
	}
	pH = new SNode{ 0 };
	return *pH;
}


//�޸�
int Clist::Set(SNode& node,DATA& data)
{
	if (node.data.nNumb == 0)
		return 1;
	node.data = data;
	return 0;
}


//��������
void Clist::Insert(DATA& data, SNode& node)
{
	if (&node == m_pHead)
	{ 
		AddHead(data);
		return;
	}
	else if (&node == m_pTail)
	{
		AddTail(data);
		return;
	}
		
	else
	{
		SNode* p = new SNode;
		p->pRevi = &node;
		p->pNext = node.pNext;
		node.pNext = p;
		node.pNext->pRevi = p;
		p->data = data;
	}
}

 //ɾ����������
int Clist::RemoveAll()
{
	SNode*p = m_pHead;
	if (!m_pHead)
		return 1;
	while (p)
	{
		m_pHead = p->pNext;
		delete p;
		p = m_pHead;
	}
	return 0;
}
