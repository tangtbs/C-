#pragma once
#include<iostream>
typedef void* POSITION;
template<class DATA>
class Clist
{

	struct SNode
	{
		SNode* pPrev;
		SNode* pNext;
		DATA data;
	};
	
	SNode* m_pHead;
	SNode* m_pTail;
	size_t m_nCount;
public:
	Clist()
	{
		m_pHead = NULL;
		m_pTail = NULL;
		m_nCount = 0;
	}
	Clist(const Clist&);

	~Clist()
	{
		RemoveAll();
	}
	//ͷ���
	void AddHead(const DATA& data);
	//β���
	void AddTail(const DATA& data);
	//��������
	void Insert(const DATA& data, POSITION pos);
	// ɾ��
	int RemoveAt(POSITION pos);
	//ɾ����������
	int RemoveAll();
	////�����Ų���
	//POSITION FindbyNumb(int numb);
	////����������
	//POSITION FindbyName(char* name);
	//�޸�

	// ����
	POSITION Find(const DATA& data);
	//�޸�
	int Set(SNode& node, const DATA& data);
	DATA& GetAt(POSITION pos)
	{
		return ((SNode*)pos)->data;
	}
	DATA& GetNext(POSITION &pos)
	{
		SNode* p = (SNode*)pos;
		pos = ((SNode*)pos)->pNext;//�ȶ�ȡ���ݣ���������
		return p->data;
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
	int GetCount()
	{
		return m_nCount;
	}

	Clist& operator=(const Clist&list);
};


//ͷ���
template<class DATA>
void Clist<DATA>::AddHead(const DATA& data)
{
	SNode* p = new SNode;
	if (!m_pHead)
	{
		m_pHead = m_pTail = p;
		p->pNext = p->pPrev = NULL;
		p->data = data;
	}
	else
	{
		p->pNext = m_pHead;
		p->pPrev = NULL;
		p->pNext->pPrev = p;
		p->data = data;
		m_pHead = p;
	}
	m_nCount++;
	return;
}


//β���
template<class DATA>
void Clist<DATA>::AddTail(const DATA& data)
{
	SNode*p = new SNode;
	if (!m_pHead)
	{
		p->pNext = NULL;
		p->pPrev = NULL;
		m_pHead = m_pTail = p;
		p->data = data;
	}
	else
	{
		p->pNext = NULL;
		p->pPrev = m_pTail;
		p->pPrev->pNext = p;
		m_pTail = p;
		p->data = data;
	}
	m_nCount++;
	return;
}


//��������
template<class DATA>
void Clist<DATA>::Insert(const DATA& data, POSITION pos)
{
	SNode& node = *(SNode*)pos;
	if (&node == m_pHead)
		AddHead(data);
	else if (&node == m_pTail)
		AddTail(data);

	else
	{
		SNode* p = new SNode;
		p->pPrev = &node;
		p->pNext = node.pNext;
		node.pNext = p;
		node.pNext->pPrev = p;
		p->data = data;
	}
	m_nCount++;
	return;
}


// ɾ��
template<class DATA>
int Clist<DATA>::RemoveAt(POSITION pos)
{
	SNode*p = (SNode*)pos;
	if (!p)
		return 1;
	if (p == m_pHead)
		m_pHead = p->pNext;
	else
		p->pPrev->pNext = p->pNext;

	if (p == m_pTail)
		m_pTail = p->pNext;
	else
		p->pNext->pPrev = p->pPrev;
	delete p;
	m_nCount--;
	return 0;
}

//ɾ����������
template<class DATA>
int Clist<DATA>::RemoveAll()
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
	m_pTail = NULL;
	m_nCount = 0;
	return 0;
}

//����
template<class DATA>
POSITION Clist<DATA>::Find(const DATA& data)
{
	SNode* p = m_pHead;
	if (!p)
		return NULL;
	while (p)
	{
		if (p->data.nNumb == data.nNumb&&p->data.fSala == data.fSala && !strcmp(p->data.sName, data.sName))
			return m_pHead;
		p = p->pNext;
	}
	return NULL;
}

//�޸�
template<class DATA>
int Clist<DATA>::Set(SNode& node, const DATA& data)
{
	if (node.data.nNumb == 0)
		return 1;
	node.data = data;
	return 0;
}

template<class DATA>
void Clist<DATA>::operator=(const Clist&list)
{
	RemoveAll();
	SNode* p= list.m_pHead;
	while (p)
	{
		AddTail(p->data);
		p = p->pNext;
	}
}

template<class DATA>
Clist<DATA>::Clist(const Clist& list)  //���
{
	SNode* p = list.m_pHead;
	while (p)
	{
		AddTail(p->data);
		p = p->pNext;
	}
}