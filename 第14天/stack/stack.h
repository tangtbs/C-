#pragma once
#include<iostream>
template<typename DATA>
class CStack
{
public:
	CStack();
	CStack(const size_t maxsize);
	~CStack();
	DATA* push(size_t size, const DATA& data = {0});
	DATA* pop(size_t size);
	bool empty();
	DATA* top();
	size_t size();
private:
	size_t m_nMaxSize;
	DATA* m_pTop;
	DATA* m_pBottom;
	size_t m_nSize;

};

template<typename DATA>
CStack<DATA>::CStack()
{
	m_nMaxSize = 1000;
	m_pBottom = m_pTop = new DATA[m_nMaxSize];
	m_nSize = 0;

}

template<typename DATA>
CStack<DATA>::CStack(const size_t maxsize)
{
	m_nMaxSize = maxsize;
	m_pBottom = m_pTop = new [m_nMaxSize];
	m_nSize = 0;

}

template<typename DATA>
CStack<DATA>::~CStack()
{
	delete[]m_pBottom;
}

template<typename DATA>
DATA* CStack<DATA>::push(size_t size, const DATA& data )
{
	if (m_nSize + size >= m_nMaxSize)
	{
		stderr;
		return m_pTop;
	}
	m_nSize += size;
	m_pTop+= size;
	return m_pTop;
}
template<typename DATA>
DATA* CStack<DATA>::pop(size_t size)
{
	if (m_nSize == 0)
	{
		stderr;
		return m_pTop;
	}
	if (m_nSize <= size)
	{
		m_pTop = m_pBottom;
		return m_pTop;
	}
	m_nSize -= size;
	m_pTop-= size;
	return m_pTop;
}

template<typename DATA>
bool CStack<DATA>::empty()
{

	return m_nSize == 0;
}

template<typename DATA>
DATA* CStack<DATA>::top()
{
	return m_pTop;
}

template<typename DATA>
size_t CStack<DATA>::size()
{
	return m_nSize;
}