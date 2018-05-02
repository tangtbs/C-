#pragma once
#include<iostream>
#include<assert.h>
template<class DATA>
class CArray
{
public:
	class iterator
	{
		/*friend iterator operator +(const int& n, const iterator& it);*/
		DATA* ptr;
	public:
		iterator()
		{
			ptr = NULL;
		}
		iterator(DATA*p)
		{
			ptr = p;
		}
		~iterator()
		{

		}
		iterator& operator =(const iterator& it)
		{
			ptr = it.ptr;
			return *this;
	    }
		iterator& operator=(DATA* pData)
		{
			ptr = pData;
			return *this;
		}
		DATA& operator *()
		{
			return *ptr;
		}
		DATA& operator [](const int& nIndex)
		{
			return ptr[nIndex];
		}
		iterator& operator ++()
		{
			ptr++;
			return *this;
		}
		iterator operator ++(int)
		{
			iterator temp = *this;
			ptr++;
			return temp;
		}
		iterator& operator +=(const int& n)
		{
			ptr=ptr+n;
			return *this;
		}

		iterator operator +(const int& n)
		{
			iterator temp=this;
			temp.ptr = ptr + n;
			return temp;
		}
		
		iterator operator -(const int& n)
		{
			iterator temp = this;
			temp.ptr = ptr - n;
			return temp;
		}
		int operator -(const iterator& it)
		{
			int n = ptr - it.ptr;
			return n;
		}
		iterator& operator --()
		{
			--ptr;
			return *this;
		}
		iterator operator --(int)
		{
			iterator temp = *this;
			ptr--;
			return temp;
		}
		iterator& operator -=(const int& n)
		{
			ptr=ptr-n;
			return *this;
		}
		bool operator ==(const iterator& it);
		bool operator !=(const iterator& it);
		DATA* operator ->()
		{
			return ptr;
		}
	};
	CArray();
	CArray(const CArray& array);
	~CArray();
	iterator begin()const
	{
		return m_pData;
	}
	iterator end()const
	{
		return m_pData + m_nCount;
	}
	void Add(const DATA& data);
	int Append(const CArray& src);
	void Copy(const CArray& src);
	void FreeExtra();
	inline bool IsEmpty()
	{
		return m_nCount != 0;
	}
	inline const DATA& ElementAt(int nIndex)const
	{
		return *(m_pData + nIndex);
	}

	inline DATA& ElementAt(int nIndex)
	{
		return *(m_pData + nIndex);
	}

	inline int GetSize()const
	{
		return m_nMaxSize;
	}

	inline int GetCount()const
	{
		return m_nCount;
	}
	inline DATA& GetAt(int nIndex)
	{
		return m_pData[nIndex];
	}

	inline const DATA& GetAt(int nIndex)const
	{
		return m_pData[nIndex];
	}

	inline int GetUpperBound()
	{
		return m_nCount - 1;
	}
	void InsertAt(int Index, const DATA& data, int nCount = 1);
	void RemoveAt(int Index, int nCount = 1);
	void RemoveAll()
	{
		m_nCount = 0;
	}
	void SetAt(int nIndex, const DATA& newElement);
	void SetAtGrow(int nIndex, const DATA& newElememt);
	void SetSize(int nNewSize);
	const DATA* GetData() const
	{
		return m_pData;
	}
	DATA* GetData()
	{
		return m_pData;
	}

	CArray& operator=(const CArray& array);
	CArray operator+(const CArray& array)const;
	CArray& operator+=(const CArray& array);
	DATA& operator[](int nIndex)
	{
		return m_pData[nIndex];
	}
private:
	int m_nMaxSize;//资源个数
	int m_nCount;//有效个数
	DATA* m_pData;
};



template<class DATA>
CArray<DATA>::CArray(const CArray& array)
{
	m_nCount = 0;
	m_nMaxSize = array.GetSize();
	m_pData = new DATA[m_nMaxSize];
	int nCount = array.GetCount();
	for (int i = 0; i < nCount; i++)
		Add(array.GetAt(i));

}


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
		memcpy(p, m_pData, m_nCount * sizeof(DATA));
		delete[]m_pData;
		p[m_nCount++] = data;
		m_pData = p;
	}
}



template<class DATA>
int CArray<DATA>::Append(const CArray& src)
{
	int nCount = src.GetCount();
	for (int i = 0; i < nCount; i++)
		Add(src.GetAt(i));
	return GetCount() - nCount - 1;
}


template<class DATA>
void CArray<DATA>::Copy(const CArray& src)
{
	RemoveAll();
	int nCount = src.GetCount();
	for (int i = 0; i < nCount; i++)
		Add(src.GetAt(i));
}


template<class DATA>
void CArray<DATA>::FreeExtra()
{
	if (m_nCount == m_nMaxSize)
		return;
	DATA* p = new DATA[m_nCount];
	memcpy(p, m_pData, m_nCount * sizeof(DATA));
	delete[]m_pData;
	m_pData = p;
	m_nMaxSize = m_nCount;
}

template<class DATA>
void CArray<DATA>::SetAt(int nIndex, const DATA& newElement)
{
	if (nIndex > m_nCount - 1 || nIndex < 0)
		return;
	m_pData[nIndex] = newElement;
}

template<class DATA>
void CArray<DATA>::SetAtGrow(int nIndex, const DATA& newElement)
{
	if (nIndex < m_nMaxSize)
	{
		if (nIndex >= m_nCount)
		{
			for (int i = 0; i < nIndex - m_nCount; i++)
				m_pData[m_nCount + i] = 0;
			m_nCount = nIndex + 1;
		}
		m_pData[nIndex] = newElement;
	}
	else
	{
		m_nMaxSize = nIndex + 1;
		DATA* p = new DATA[m_nMaxSize]{ 0 };
		memcpy(p, m_pData, m_nCount);
		p[nIndex] = newElement;
		m_nCount = nIndex + 1;
		delete[]m_pData;
		m_pData = p;
	}

}


template<class DATA>
void CArray<DATA>::SetSize(int newSize)
{
	if (newSize <= m_nCount)
		m_nCount = newSize;
	else
	{
		m_nMaxSize = newSize;
		DATA* p = new DATA[m_nMaxSize]{ 0 };
		memcpy(p, m_pData, m_nCount * sizeof(DATA));
		m_nCount = m_nMaxSize;
		delete[]m_pData;
		m_pData = p;
	}
}


template<class DATA>
void CArray<DATA>::InsertAt(int Index, const DATA& data, int nCount)
{
	if (Index < m_nCount)
	{
		if (m_nCount + nCount <= m_nMaxSize)
		{
			memmove(m_pData + Index + nCount, m_pData + Index, (m_nCount - Index) * sizeof(DATA));
			for (int i = 0; i < nCount; i++)
				m_pData[Index + i] = data;

		}
		else
		{
			m_nMaxSize = m_nCount + nCount;
			DATA* p = new DATA[m_nMaxSize];
			memcpy(p, m_pData, Index * sizeof(DATA));
			for (int i = 0; i < nCount; i++)
				p[Index + i] = data;
			memcpy(p + Index + nCount, m_pData + Index, (m_nCount - Index) * sizeof(DATA));
			delete[]m_pData;
			m_pData = p;
		}
		m_nCount += nCount;
	}
	else
	{
		if (Index + nCount <= m_nMaxSize)
		{
			for (int i = 0; i < Index - m_nCount; i++)
				m_pData[m_nCount + i] = { 0 };
			for (int i = 0; i < nCount; i++)
				m_pData[Index + i] = data;

		}
		else
		{
			m_nMaxSize = Index + nCount;
			DATA* p = new DATA[m_nMaxSize];
			memcpy(p, m_pData, m_nCount * sizeof(DATA));
			for (int i = 0; i < Index - m_nCount; i++)
				p[m_nCount + i] = 0;
			for (int i = 0; i < nCount; i++)
				p[Index + i] = data;
			delete[]m_pData;
			m_pData = p;
		}
		m_nCount = Index + nCount;
	}
}


template<class DATA>
void CArray<DATA>::RemoveAt(int Index, int nCount = 1)
{
	assert(Index >= 0);
	assert(Index<m_nMaxSize);
	if (Index >= m_nCount)
		return;
	if (Index + nCount < m_nCount)
	{
		memcpy(m_pData + Index, m_pData + Index + nCount, (m_nCount - Index - nCount) * sizeof(DATA));
		m_nCount -= nCount;
	}
	else
		m_nCount = Index;
}

template<class DATA>
CArray<DATA>& CArray<DATA>::operator=(const CArray<DATA>& array)
{
	RemoveAll();
	int nCount = array.GetCount();
	for (int i = 0; i<nCount; i++)
		Add(array.GetAt(i));
	return *this;
}

template<class DATA>
CArray<DATA> CArray<DATA>::operator+(const CArray<DATA>& array)const
{
	CArray temp = *this;
	int nCount = array.GetCount();
	for (int i = 0; i < nCount; i++)
		temp.Add(array.GetAt(i));
	return temp;
}

template<class DATA>
CArray<DATA>& CArray<DATA>::operator+=(const CArray<DATA>& array)
{
	int nCount = array.GetCount();
	for (int i = 0; i < nCount; i++)
		Add(array.GetAt(i));
	return *this;
}


template<class DATA>
bool CArray<DATA>::iterator::operator ==(const iterator& it )
{
	return ptr == it.ptr;
}

template<class DATA>
bool CArray<DATA>::iterator::operator != (const iterator& it)
{
	return ptr != it.ptr;
}

//template<class DATA>
//CArray<DATA>::iterator operator +(const int& n, const CArray<DATA>::iterator& it)
//{
//	class iterator temp = it;
//	temp.ptr = temp.ptr + n;
//	return temp;
//}


