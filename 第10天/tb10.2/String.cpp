#include "String.h"


CString::CString()
{
	m_pData = new char(0);
	m_nCount = 0;
}

CString::CString(const CString&cstr)
{
	m_nCount = cstr.m_nCount;
	m_pData = new char[m_nCount + 1];
	memcpy(m_pData, cstr.m_pData, m_nCount + 1);
}


CString::CString(const char* str)
{
	m_nCount = strlen(str);
	m_pData = new char[m_nCount + 1];
	memcpy(m_pData,str,m_nCount+1);
}

CString::CString(char c,int nCount)
{
	m_nCount = nCount;
	m_pData = new char[nCount + 1];
	memset(m_pData,c,m_nCount);
	m_pData[m_nCount] = 0;
}

CString::~CString()
{
	delete[]m_pData;
}


CString &CString::operator=(const CString& cstr)
{
	if (m_nCount < cstr.m_nCount)
	{
		delete[]m_pData;
		m_pData = new char[cstr.m_nCount + 1];
	}
	m_nCount = cstr.m_nCount;
	memcpy(m_pData,cstr.m_pData,m_nCount+1);
	return *this;
}

CString &CString::operator=(const char* str)
{
	int length = strlen(str);
	if (m_nCount < length)
	{
		delete m_pData;
		m_pData = new char[length+1];
	}
	m_nCount = length;
	memcpy(m_pData,str,m_nCount+1);
	return *this;
}

CString CString::operator+(const CString& cstr)
{
	CString temp(0,m_nCount+cstr.m_nCount);
	memcpy(temp.m_pData,m_pData,m_nCount);
	memcpy(temp.m_pData+m_nCount,cstr.m_pData,cstr.m_nCount+1);
	return temp;
}

CString CString::operator+(const char* str)
{
	CString temp(0,m_nCount+strlen(str));
	memcpy(temp.m_pData,m_pData,m_nCount);
	memcpy(temp.m_pData + m_nCount, str, strlen(str) + 1);
	return temp;
}


CString operator+(const char*str,const CString& cstr)
{
	CString temp(0,strlen(str)+cstr.m_nCount);
	memcpy(temp.m_pData,str,strlen(str));
	memcpy(temp.m_pData+strlen(str),cstr.m_pData,cstr.m_nCount+1);
	return temp;
}

CString& CString::MakeReverse()
{
	strrev(m_pData);
	return *this;
}

CString& CString::ToUpper()
{
	strupr(m_pData);
	return *this;
}

CString& CString::ToLower()
{
	strlwr(m_pData);
	return *this;
}

CString& CString::SetData(const char*str)
{
	if (m_nCount < strlen(str))
	{
		delete[]m_pData;
		m_pData = new char[strlen(str)+1];
	}
	strcpy(m_pData,str);
	return *this;
}

CString& CString::RemoveData()
{
	strset(m_pData,0);
	return *this;
}

CString& CString::SetAt(int nIndex,char ch)
{
	m_pData[nIndex] = ch;
	return *this;
}

