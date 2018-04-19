#include "Clist.h"



Clist::Clist()
	: m_pHead(NULL)
{
}


Clist::~Clist()
{
	RemoveAll();
}


void Clist::AddHead(DATA& data)
{
	SNode* p= new SNode;
	p->pNext = m_pHead;
	m_pHead = p;
	p->data = data;
}


void Clist::AddTail(DATA& data)
{
	SNode* p = new SNode;
	if (!m_pHead)
	{
		p->pNext = NULL;
		m_pHead = p;
		p->data = data;
	}
	SNode*pH = m_pHead;
	while (pH->pNext)
		pH = pH->pNext;
	pH->pNext = p;
	p->pNext = NULL;
	p->data = data;
}


int Clist::Remove(DATA& data)
{
	SNode*pH = m_pHead;
	if (!pH)
		return 1;
	SNode*p = NULL;
	while (pH)
	{

		if (pH->data.nNumb == data.nNumb)
		{
			if (!p)
			{
				delete[]pH;
				m_pHead = NULL;
			}
			else 
			{
			p->pNext = pH->pNext;
			delete []pH;
			}
			return 0;
		}
		p = pH;
		pH = pH->pNext;
	}
	return -1;
}



int Clist::RemoveAll()
{
	SNode* pH = m_pHead;
	if (!pH)
		return -1;
	while (pH)
	{
		pH = pH->pNext;
		delete []m_pHead;
		m_pHead = pH;
	}
	return 0;
}


int Clist::SetData(SNode& node,DATA& data)
{
	node.data = data;
	return 0;
}


SNode* Clist::SearchbyName(char* name)
{
	SNode*pH = m_pHead;
	while (pH)
	{
		if (!strcmp(pH->data.sName, name))
			return pH;
		pH = pH->pNext;
	}
	return NULL;
}


SNode* Clist::SearchbyNumb(int numb)
{
	SNode*pH = m_pHead;
	while (pH)
	{
		if (pH->data.nNumb == numb)
			return pH;
		pH = pH->pNext;
	}
	return nullptr;
}
