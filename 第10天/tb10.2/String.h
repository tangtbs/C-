#pragma once
#include<string.h>
#include<assert.h>
CString operator+(const char*, const CString& cstr);
class CString
{
public:
	char* m_pData;
	int m_nCount;
	CString();
	CString(const CString &cstr);
	CString(const char* str);
	CString(char c=0,int nCount=0);
	~CString();
	CString& operator=(const CString& cstr);
	CString &CString::operator=(const char*);
	CString operator+(const CString& cstr);
	CString operator+(const char* str);
	CString& MakeReverse();
	CString& ToUpper();
	CString& ToLower();
	CString& SetData(const char*);
	CString& RemoveData();
	CString& SetAt(int nIndex=0,char ch=0);
	char operator[](int nIndex)const
	{
		assert(nIndex>=0);
		assert(nIndex <=m_nCount);
		return m_pData[nIndex];
	}
	int GetLength()const
	{
		return m_nCount;
	}
};

