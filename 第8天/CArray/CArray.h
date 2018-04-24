#pragma once
#include<iostream>
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
	void InsertAt(int Index,const DATA& data);
	void RemoveAt(int Index);
	void RemoveAll()
	{
		m_nCount = 0;
	}
	void SetAt(int nIndex,const DATA& newElement);
	void SetSize(int nNewSize);
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
	if (!newSize)
	{
		m_nCount= 0;
		return;
	}
	if (newSize <= m_nCount)
	{
		m_nCount = newSize;
		return;
	}
	m_nMaxSize = newSize;
	DATA* p = new DATA[newSize];
	memcpy(p,m_pData,m_nCount*sizeof(DATA));
	m_pData = p;
}


template<class DATA>
void CArray<DATA>::InsertAt(int Index,const DATA& data)
{
	if (m_nCount == m_nMaxSize)
	{
		memcpy(m_pData + Index, m_pData + Index + 1; (m_nCount - Index-1)*sizeof(DATA));
		m_pData[Index] = data;
		m_nCount++;
	}
	memcpy(m_pData + Index, m_pData + Index + 1;(m_nCount-Index)*sizeof(DATA));
	m_pData[Index] = data;
	m_nCount++;
}


template<class DATA>
void CArray<DATA>::RemoveAt(int Index)
{
	memcpy(m_pData+Index,m_pData+Index+1,(m_nCount-Index-1)*sizeof(DATA));
	m_nCount--;

}