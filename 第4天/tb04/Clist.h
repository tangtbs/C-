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
	//头添加
	void AddHead(const DATA& data);
	//尾添加
	void AddTail(const DATA& data);
	// 删除
	int RemoveAt(SNode& p);
	//按工号查找
	POSITION FindbyNumb(int numb);
	//按姓名查找
	POSITION FindbyName(char* name);
	//修改
	int Set(SNode& node,const DATA& data);
	//插入数据
	void Insert(const DATA& data, POSITION pos);
	//删除所有数据
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

