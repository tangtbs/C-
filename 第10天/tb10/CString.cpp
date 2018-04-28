#define _CRT_SECURE_NO_WARNINGS
#include "CString.h"
CString::CString()
{
	m_pData = new char(0);
}
//¿½±´¹¹Ôì
CString::CString(const CString & stringSrc)
{
	m_pData = new char[stringSrc.GetLength()+1];
	strcpy(m_pData,stringSrc.m_pData);
}



CString::CString(int nCount)
{
	m_pData = new char[nCount + 1];
}


CString::CString(char ch, int nRepeat)
{
	m_pData = new char[nRepeat + 1];
	m_pData[nRepeat] = 0;
	_strset(m_pData,ch);
}


CString::CString(const char* str,int nLength)
{
	m_pData = new char[nLength + 1];
	if (nLength > (int)strlen(str))
		nLength = strlen(str);
	memcpy(m_pData,str,nLength);
	m_pData[nLength + 1] = 0;
}


CString::CString(const char* str)
{
	m_pData = new char[strlen(str) + 1];
	strcpy(m_pData,str);
}

CString::~CString()
{
	delete[]m_pData;
}

CString & CString::MakeReverse()
{
	_strrev(m_pData);
	return *this;
}

void CString::RemoveStringData()
{
	char*p = m_pData;
	while (*p)
		*p++ = 0;
}

int CString::Delete(int iIndex, int nCount)
{
	int length = GetLength();
	if (nCount > length - iIndex)
		m_pData[iIndex] = 0;
	else
	memmove(m_pData+iIndex,m_pData+iIndex+nCount,length-nCount-iIndex+1);
	return GetLength();
}

int CString::Insert(int nIndex, char c)
{
	int length = GetLength();
	if (nIndex >= length)
		nIndex = length - 1;
	char* p = new char[length + 2];
	memcpy(p, m_pData, nIndex);
	p[nIndex] = c;
	memcpy(p + nIndex + 1, m_pData + nIndex, length - nIndex+1);
	delete[]m_pData;
	m_pData = p;
	return length+1;
}

int CString::Insert(int nIndex, const char * substr)
{
	int sublength = (int)strlen(substr);
	int length = GetLength();
	if (nIndex >= length)
		nIndex = length - 1;
	char* p = new char[length+sublength+1];
	memcpy(p,m_pData,nIndex);
	memcpy(p + nIndex, substr, sublength);
	memcpy(p+nIndex+sublength,m_pData+nIndex,length-nIndex+1);
	delete[]m_pData;
	m_pData = p;
	return length + sublength;
}

int CString::Find(char ch, int iStart) const
{
	char* pos=strchr(m_pData+iStart,ch);
	return  pos ? pos - m_pData : -1;
}

int CString::Find(const char * szSub, int iStart) const
{
	char* pos=strstr(m_pData+iStart,szSub);
	return pos ? pos - m_pData : -1;
}

int CString::ReverseFind(char ch)
{
	char* pos = strrchr(m_pData,ch);
	return pos?pos-m_pData:-1;
}

CString & CString::MakeLower()
{
	_strlwr(m_pData);
	return *this;
}

CString & CString::MakeUpper()
{
	_strupr(m_pData);
	return *this;
}

int CString::Replace(const char * szOld, const char * szNew)
{
	int Size =1;
	int *num = new int[Size]{ -1 };
	int i = 0;
	int length = GetLength();
	char* p = m_pData;
	while(p=strstr(p, szOld))
	{
		num[i++] = p - m_pData;

		if (i ==Size)
		{
			Size *= 2;
			int *p = new int[Size];
			memcpy(p,num,(Size/2)*sizeof(int));
			delete[]num;
			num = p;
		}
		p = p + strlen(szOld);
	}
	if (num[0]==-1)
		return 0;
	char*pN = new char[length-i*strlen(szOld)+i*strlen(szNew)+1];
	char* pt = m_pData;
	p = pN;
	for (int j = 0; j <i; j++)
	{
		if (j == 0)
		{
			memcpy(p, pt, num[j]);
			memcpy(p+num[j],szNew,strlen(szNew));
			p = pN + num[j] + strlen(szNew);
		}
			
		else
		{
			memcpy(p, pt, num[j] - num[j - 1] - strlen(szOld));
			memcpy(p + num[j] - num[j - 1] - strlen(szOld), szNew, strlen(szNew));
			p = p + num[j] - num[j - 1] - strlen(szOld) + strlen(szNew);
		}
		
		pt = m_pData + num[j] + strlen(szOld);
	}
	/*if (*pt)*/
		memcpy(p, pt, length + 1 - num[i - 1] - strlen(szOld));
	/*else
		*p = 0;*/
	delete[]num;
	delete[]m_pData;
	m_pData = pN;
	return i;
}

int CString::Replace(char chOld, char chNew)
{
	int numb = 0;
	char*p=m_pData;
	while (*p)
	{
		if (*p == chOld)
		{
			*p = chNew;
			numb++;
		}
		p++;
	}
	return numb;
}

CString CString::Mid(int iFirst, int nCount)
{
	int length = GetLength();
	if (nCount > length - iFirst)
		nCount = length - iFirst;
	CString temp(nCount);
	memcpy(temp.m_pData,m_pData+iFirst,nCount);
	temp[nCount] = 0;
	return temp;
}

int CString::GetLength()const
{
	const char* p = m_pData;
	int n = 0;
	while (*p++)
		n++;
	return n;
}
int CString::GetLength()
{
	char* p = m_pData;
	int n = 0;
	while (*p++)
		n++;
	return n;
}


CString & CString::operator=(const CString & str)
{
	RemoveStringData();
	if (GetLength() < str.GetLength())
	{
		delete[]m_pData;
		m_pData = new char[str.GetLength()+1];
	}
	strcpy(m_pData, str.m_pData);
	return *this;
}


CString& CString::operator=(const char* str)
{
	RemoveStringData();
	int length = strlen(str);
	if (GetLength() < length)
	{
		delete[]m_pData;
		m_pData = new char[length + 1];
	}
	strcpy(m_pData, str);
	return *this;
}

CString CString::operator +(const CString& str)
{
	int length = GetLength() + str.GetLength();
	CString temp('\0', length);
	strcat(temp.m_pData, this->m_pData);
	strcat(temp.m_pData, str.m_pData);
	return temp;
}
CString CString::operator +(const char* str)
{
	int length = GetLength() + strlen(str);
	CString temp('\0', length);
	strcat(temp.m_pData, this->m_pData);
	strcat(temp.m_pData, str);
	return temp;
}

CString & CString::operator+=(const char* str)
{
	CString temp =*this+str;
	*this = temp;
	return *this;
}

CString & CString::operator+=(const CString & cstr)
{
	CString temp = *this + cstr;
	*this = temp;
	return *this;
}

bool CString::operator!=(const CString & cstr)
{
	return strcmp(m_pData,cstr.m_pData)!=0;
}

bool CString::operator!=(const char *str)
{
	return strcmp(m_pData,str)!=0;
}

bool CString::operator==(const CString & cstr)
{

	return strcmp(m_pData,cstr.m_pData)!=0;
}

bool CString::operator==(const char * str)
{
	return strcmp(m_pData,str)!=0;
}

bool CString::operator<(const CString & cstr)
{
	return strcmp(m_pData,cstr.m_pData)<0;
}

bool CString::operator<(const char * str)
{
	return strcmp(m_pData,str)<0;
}

bool CString::operator>(const CString & cstr)
{
	return strcmp(m_pData,cstr.m_pData)>0;
}

bool CString::operator>(const char * str)
{
	return strcmp(m_pData,str)>0;
}

bool CString::operator<=(const CString & cstr)
{
	return strcmp(m_pData,cstr.m_pData)<=0;
}

bool CString::operator<=(const char * str)
{
	return strcmp(m_pData,str)<=0;
}

bool operator>=(const char * str, const CString & cstr)
{
	return strcmp(str,cstr.m_pData)>=0;
}

bool CString::operator>=(const char * str)
{
	return strcmp(m_pData,str)>=0;
}

bool CString::operator>=(const CString & cstr)
{
	return strcmp(m_pData,cstr.m_pData)>=0;
}

bool operator<=(const char * str, const CString & cstr)
{
	return strcmp(str,cstr.m_pData)<=0;
}

bool operator>(const char * str, const CString & cstr)
{
	return strcmp(str,cstr.m_pData)>0;
}


bool operator<(const char*str, const CString&cstr)
{
	return strcmp(str,cstr.m_pData)<0;
}


bool operator==(const char*str, const CString&cstr)
{
	return !strcmp(str,cstr.m_pData);

}


bool operator!=(const char* str, const CString&cstr)
{
	return !strcmp(str,cstr.m_pData);
}


CString operator+(const char* str1,const CString cstr2)
{
	int length = strlen(str1) + cstr2.GetLength();
	CString temp('\0',length);
	strcat(temp.m_pData,str1);
	strcat(temp.m_pData, cstr2.m_pData);
	return temp;
}

