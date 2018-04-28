#pragma once
#include<string.h>
#include<assert.h>
class CString
{
	friend bool operator!=(const char* str, const CString&cstr);
	friend bool operator==(const char*, const CString&cstr);
	friend bool operator<(const char*str, const CString&cstr);
	friend bool operator>(const char*str, const CString&cstr);
	friend bool operator<=(const char* str, const CString&cstr);
	friend bool operator>=(const char* str, const CString& cstr);
	friend int main();
	friend CString operator+(const char* str1, const CString cstr2);
public:
	CString();
	CString(int nCount);
	CString(const CString&stringSrc);//拷贝构造
	CString(char ch,int nRepeat=1);//字符串内有n个ch字符
	CString(const char* str, int nLength);
	CString(const char* str);
	~CString();
	CString& MakeReverse();
	CString& operator=(const CString&str);
	CString& operator=(const char* str);
	CString operator+(const CString&str);
	CString operator+(const char*str);
	CString& operator+=(const char*);
	CString& operator+=(const CString& cstr);
	bool operator!=(const CString& cstr);
	bool operator!=(const char*);
	bool operator==(const CString& cstr);
	bool operator==(const char* str);
	bool operator<(const CString&cstr);
	bool operator<(const char*str);
	bool operator>(const CString&cstr);
	bool operator>(const char* str);
	bool operator<=(const CString&cstr);
	bool operator<=(const char* str);
	bool operator>=(const char* str2);
    bool operator>=(const CString& cstr);
	operator const char*() { return m_pData; };
	char operator[](int nIndex)const
	{
		return m_pData[nIndex];
	}
	char&operator[](int nIndex)
	{
		return m_pData[nIndex];
	}
	CString Mid(int iFirst,int nCount);
	inline CString Left(int nCount)
	{
		return Mid(0,nCount);
	}
	inline CString Right(int nCount)
	{
		return Mid(GetLength()-nCount,nCount);
	}
	int GetLength()const;
	int GetLength();
	void RemoveStringData();
	int Delete(int iIndex, int nCount = 1);
	int Insert(int nIndex, char c);
	int Insert(int nIndex, const char*substr);
	int Find(char ch, int iStart = 0) const;//strchr //charactor
	int Find(const char* szSub, int iStart = 0)  const;//strstr (sz：string zero )
	int ReverseFind(char ch);//strrch
	CString& MakeLower();
	CString& MakeUpper();
	int Replace(const char *szOld, const char * szNew);
	int Replace(char chOld, char chNew);
private:
	char*m_pData;


};
