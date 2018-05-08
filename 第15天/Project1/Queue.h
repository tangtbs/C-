#pragma once
template<typename DATA>
class Queue
{
	friend int main();
public:
	Queue(int nCount =100);
	~Queue()
	{
		delete []m_pData;
	};

	bool empty()const
	{
		return m_nHead ==-1;
	}
	bool full()const
	{
		return m_nHead-m_nTail==1||m_nTail-m_nHead==3;
	}
	bool push(const DATA& data);
	bool pop();
	size_t count()const
	{
		return m_nCount;
	}
private:
	DATA* m_pData;
	size_t m_nHead;
	size_t m_nTail;
	size_t m_nCount;
	size_t m_nSize;
	
};

template<typename DATA>
Queue<DATA>::Queue(int nCount)
{
	m_nSize=nCount;
	m_nCount = 0;
	m_pData = new DATA[m_nSize];
	m_nHead = m_nTail = -1;
}

template<typename DATA>
bool Queue<DATA>::push(const DATA& data)
{
	if (full())
		return false;
	if (empty())
		m_nTail++, m_nHead++;
	else
	++m_nTail %= m_nSize;
	m_pData[m_nTail] = data;
	m_nCount++;
	return true;
}

template<typename DATA>
bool Queue<DATA>::pop()
{
	if (empty())
		return false;
	if (m_nHead == m_nTail)
	{
		m_nHead = -1;
		m_nTail = -1;
	}
		 
	else
	++m_nHead%=m_nSize;
	m_nCount--;
	return true;
}