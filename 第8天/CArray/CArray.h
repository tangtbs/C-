#pragma once
#include<iostream>
#include<assert.h>
template<class DATA>
class CArray
{
public:
	CArray();
	~CArray();
	void Add(const DATA& data);
	/*Append();
	Copy();*/
	bool IsEmpty()
	{
		return m_nCount == 0;
	}
	const DATA& ElementAt(int nIndex)
	{
		return *(m_pData + nIndex);
	}
	DATA& GetAt(int nIndex)
	{
		return m_pData[nIndex];
	}
	int GetCount()
	{
		return m_nCount;
	}
	int GetUpperBound()
	{
		return m_nCount - 1;
	}
	/*void InsertAt(int Index,const DATA& data);*/
	void RemoveAt(int Index,int nCount=1);
	void RemoveAll()
	{
		m_nCount = 0;
	}
	void SetAt(int nIndex,const DATA& newElement);
	void SetSize(int nNewSize);
	const DATA* GetData() const
	{
		return m_pData;
	}
	DATA* GetData()
	{
		return m_pData;
	}
private:
	int m_nMaxSize;//资源个数
	int m_nCount;//有效个数
	DATA* m_pData;
};

template<class DATA>
CArray<DATA>::CArray()
{
	m_pData = new DATA[2];
	m_nCount = 0;
	m_nMaxSize = 2;
}


template<class DATA>
CArray<DATA>::~CArray()
{
	delete[]m_pData;
}


template<class DATA>
void CArray<DATA>::Add(const DATA& data)
{
	if (m_nCount < m_nMaxSize)
		m_pData[m_nCount++] = data;
	else
	{
		DATA* p = new DATA[2 * m_nMaxSize];
		m_nMaxSize = 2 * m_nMaxSize;
		memcpy(p,m_pData,m_nCount*sizeof(DATA));
		p[m_nCount++] = data;
		m_pData = p;
	}	
}


template<class DATA>
void CArray<DATA>::SetAt(int nIndex,const DATA& newElement)
{
	if (nIndex > m_nCount - 1 || nIndex < 0)
		return;
	m_pData[nIndex] = newElement;
}


template<class DATA>
void CArray<DATA>::SetSize(int newSize)
{
	if (newSize <= m_nCount)
		m_nCount = newSize;
	else
	{
	m_nMaxSize = newSize;
	DATA* p = new DATA[newSize];
	memcpy(p,m_pData,m_nCount*sizeof(DATA));
	delete []m_pData;
	m_pData = p;
    }
}


//template<class DATA>
//void CArray<DATA>::InsertAt(int Index,const DATA& data,int nCount)
//{
//	if (Index < m_nCount)
//	{
//		if (m_nCount + nCount <= m_nMaxSize)
//			memmove(m_pData+Index+nCount,m_pData+Index,(m_nCount-Index)*sizeof(DATA));
//		else
//		{
//			m_nMaxSize = (m_nCount + nCount) * 2
//			DATA* p = new DATA[m_nMaxSize];
//			memcpy(p,m_pData,Index*sizeof(DATA));
//			memcpy(p+Index+nCount,m_pData+Index,(m_nCount-Index)*sizeof(DATA));
//			m_pData = p;
//		}
//		while (nCount--)
//			m_pData[Index+nCount] = data;
//	}
//	else
//	{
//
//
//	}
//
//}


template<class DATA>
void CArray<DATA>::RemoveAt(int Index,int nCount=1)
{
	assert(Index >= 0);
	assert(Index<m_nMaxSize);
	if (Index >= m_nCount)
		return;
	if (Index + nCount < m_nCount)
	{
		memcpy(m_pData + Index, m_pData + Index + nCount, (m_nCount - Index - nCount) * sizeof(DATA));
		m_nCount = -nCount;
	}
	else
		m_nCount = Index;
}
