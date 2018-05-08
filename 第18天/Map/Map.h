#pragma once
template<typename KEY,typename VALUE>
class CMap
{
	struct SNode
	{
		KEY key;
		VALUE value;
		SNode* pNext;
	};
	SNode** m_pData;
	int m_nHash;
public:
	CMap(int nHash=5);
	~CMap();
	VALUE& operator[](const KEY& key);
	inline SetAt(const KEY& key,const VALUE &value)
	{
		(*this)[key] = value;
	}
	bool RemoveKey(const KEY&key);
	bool Lookup(const KEY& KEY, VALUE& value)const;
	void RemoveAll();


};
template<typename KEY,typename VALUE>
CMap<KEY,VALUE>::CMap(int nHash)
{
	m_nHash = nHash;
	m_pData = new SNode*[m_nHash] {0};
}

template<typename KEY,typename VALUE>
CMap<KEY,VALUE>::~CMap()
{

}

template<typename KEY,typename VALUE>
VALUE& CMap<KEY,VALUE>::operator[](const KEY& key)
{
	SNode** pp = &m_pData[key%m_nHash];
	while (*pp)
	{
		if ((*pp)->key == key)
			return (*pp)->value;
		pp = &(*pp)->pNext;
	}
	SNode* pTail = new SNode{0};
	(*pp) = pTail;
	pTail->key = key;
	return pTail->value;
}

template<typename KEY,typename VALUE>
bool CMap<KEY, VALUE>::RemoveKey(const KEY& key)
{
	SNode** pp = &m_pData[key%m_nHash];
	while (*pp)
	{
		if ((*pp)->key == key)
		{
			SNode* temp = *pp;
			*pp = (*pp)->pNext;
			delete temp;
			return true;
		}
		pp = &(*pp)->pNext;
	}
	return false;
}

template<typename KEY,typename VALUE>
bool CMap<KEY, VALUE>::Lookup(const KEY& key, VALUE& value)const
{
	SNode* p = m_pData[key%m_nHash];
	while (p)
	{
		if (p->key == key)
		{
			value = p->value;
			return true;
		}
		p = p->pNext;
	}
	return false;
}

template<typename KEY,typename VALUE>
void CMap<KEY, VALUE>::RemoveAll()
{
	for (int i = 0; i < m_nHash; i++)
	{
		SNode* p = m_pData[i];
		SNode* temp = 0;
		while (p)
		{
			temp = p->pNext;
			delete p;
			p = temp;
		}
		m_pData[i] = 0;
	}
}