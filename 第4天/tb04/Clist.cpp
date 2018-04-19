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


//头添加
void Clist::AddHead(const DATA& data)
{
	SNode* p = new SNode;
	p->pNext = m_pHead;
	p->pPrev = NULL;
	p->data = data;
	m_pHead = p;
}


//尾添加
void Clist::AddTail(const DATA& data)
{
	SNode*p = new SNode;
	if (!m_pHead)
	{
		p->pNext = NULL;
		p->pPrev = NULL;
		m_pHead = m_pTail = p;
		p->data = data;
	}
	p->pNext = NULL;
	p->pPrev = m_pTail;
	m_pTail = p;
	p->data = data;
	
}


// 删除
int Clist::RemoveAt(SNode& p)
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
		p.pNext->pPrev = NULL;
		delete &p;
		return 0;
	}
	if (p.data.nNumb == m_pTail->data.nNumb)
	{
		p.pPrev->pNext = NULL;
		m_pTail = p.pPrev;
		delete &p;
		return 0;
	}
	p.pPrev->pNext = p.pNext;
	p.pNext->pPrev = p.pPrev;
	delete &p;
	return 0;
}


// //按工号查找
POSITION Clist::FindbyNumb(int numb)
{
	SNode* pH = m_pHead;
	if (!pH)
	{
		pH = new SNode{ 0 };
		return (POSITION)pH;
	}
	while (pH)
	{
		if (pH->data.nNumb == numb)
			return (POSITION)pH;
		pH = pH->pNext;
	}
	pH = new SNode{ 0 };
	return (POSITION)pH;
}


// //按姓名查找
POSITION Clist::FindbyName(char* name)
{
	SNode* pH = m_pHead;
	if (!pH)
	{
		pH = new SNode{ 0 };
		return (POSITION)pH;
	}
	while (pH)
	{
		if (!strcmp(pH->data.sName,name))
			return (POSITION)pH;
		pH = pH->pNext;
	}
	pH = new SNode{ 0 };
	return (POSITION)pH;
}


//修改
int Clist::Set(SNode& node,const DATA& data)
{
	if (node.data.nNumb == 0)
		return 1;
	node.data = data;
	return 0;
}


//插入数据
void Clist::Insert(const DATA& data, POSITION pos)
{
	SNode& node = *(SNode*)pos;
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
		p->pPrev = &node;
		p->pNext = node.pNext;
		node.pNext = p;
		node.pNext->pPrev = p;
		p->data = data;
	}
}

 //删除所有数据
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
