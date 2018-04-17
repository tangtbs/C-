#define _CRT_SECURE_NO_WARNINGS
#include"Slist.h"
void Slist::Sort(int n)
{
	if (!m_pHead)
		return;
	SNode*p = m_pHead;
	while (p->pNext)
	{
		SNode*p1 = p->pNext;
		SNode*min = p;
		while (p1)
		{
			if (Sortby(min, p1, n)>0)
				min = p1;
			p1 = p1->pNext;
		}

		if (min != p)
		{
			DATA temp = min->data;
			min->data = p->data;
			p->data = temp;
		}
		p = p->pNext;
	}
}
int pSortbyNumb(const void*p, const void*p1)
{
	return strcmp((*(SNode**)p)->data.sNumb, (*(SNode**)p1)->data.sNumb)>0 ? -1 : 0;
}

int pSortbyName(const void*p, const void*p1)
{
	return strcmp((*(SNode**)p)->data.sName, (*(SNode**)p1)->data.sName)>0 ? -1 : 0;
}

int pSortbyMath(const void*p, const void*p1)
{
	return (*(SNode**)p)->data.fMath - (*(SNode**)p1)->data.fMath;
}

int pSortbyChin(const void*p, const void*p1)
{
	return(*(SNode**)p)->data.fChin - (*(SNode**)p1)->data.fChin;
}

int pSortbyEngl(const void*p, const void*p1)
{
	return (*(SNode**)p)->data.fEngl - (*(SNode**)p1)->data.fEngl;
}
void Slist::Qsort(void*base, size_t num, size_t width, int(*fup)(const void*, const void*))
{
	char*t = new char[width];
	char*b = (char*)base;
	int i = 0;
	while (b + i*width < (char*)base + (num - 1)*width)
	{
		char *s = b + i*width;
		int j = 0;
		char*s1 = s + width;
		while (s1 + j*width<(char*)base + num*width)
		{
			if (fup(s, s1 + j*width) <0)
				s = s1 + j*width;
			j++;
		}
		if (s != b + i*width)
		{
			memcpy(t, b + i*width, width);
			memcpy(b + i*width, s, width);
			memcpy(s, t, width);
		}
		i++;
	}
}
SNode** Slist::QSortbypoint(int n)
{
	int(*pfunction[5])(const void*, const void*) = { pSortbyNumb ,pSortbyName ,pSortbyMath,pSortbyChin,pSortbyEngl };
	SNode*p = m_pHead;
	int sum = 0;
	if (!p)
		return NULL;
	while (p)
	{
		sum++;
		p = p->pNext;
	}
	SNode**pp = (SNode**)malloc(sizeof(SNode*)*(sum + 1));
	SNode**pp1 = pp;
	p = m_pHead;
	while (p)
	{
		*pp1++ = p;
		p = p->pNext;
	}
	*pp1 = NULL;
	Qsort(pp, sum, sizeof(SNode*), pfunction[n - 1]);
	return pp;
}
int Slist::Sortby(SNode*p, SNode*p1, int n)
{
	switch (n)
	{
	case 1:
		return strcmp(p->data.sNumb, p1->data.sNumb)>0 ? 1 : 0;
	case 2:
		return strcmp(p->data.sName, p1->data.sName)>0 ? 1 : 0;
	case 3:
		return p->data.fMath - p1->data.fMath<0 ? 1 : 0;
	case 4:
		return p->data.fChin, -p1->data.fChin<0 ? 1 : 0;
	case 5:
		return p->data.fEngl - p1->data.fEngl<0 ? 1 : 0;

	}
}
void Slist::Print()
{
	if (!m_pHead)
	{
		cout<<"系统中无数据记录"<<endl;
		system("pause");
		return;
	}
	SNode*p = m_pHead;
	cout<<"\t\t\t\t\t\t";
	cout << "姓名\t学号\t数学\t语文\t英语" << endl << endl;
	while (p)
	{
		cout<<"\t\t\t\t\t\t";
		cout << p->data.sName<<"\t"<< p->data.sNumb<<"\t"<< p->data.fMath<<"\t"<< p->data.fChin<<"\t"<< p->data.fEngl << endl << endl;
		p = p->pNext;
	}
	cout<<"\t\t\t\t\t\t\t\t按任意键继续...";
	_getch();

}
void Slist::Printone(SNode*p)
{
	cout<<"\t\t\t\t\t\t";
	cout << "姓名\t学号\t数学\t语文\t英语" << endl << endl;
	cout<<"\t\t\t\t\t\t";
	cout<< p->data.sName<<p->data.sNumb<< p->data.fMath<< p->data.fChin<< p->data.fEngl<<endl;
}
SNode* Slist::Searchbystr(char*s)
{
	SNode*p = m_pHead;
	if (strpbrk(s, "1234567890"))
	{
		while (p)
		{
			if (strcmp(p->data.sNumb, s) == 0)
				return p;
			p = p->pNext;
		}
		return NULL;
	}
	while (p)
	{
		if (strcmp(p->data.sName, s) == 0)
			return p;
		p = p->pNext;
	}
	return NULL;
}
void Slist::AddTail(DATA*data)
{
	SNode*tail = new SNode;
	if (!m_pHead)
	{
		m_pHead = tail;
		tail->data = *data;
		tail->pNext = NULL;
	}

	SNode*p = m_pHead;
	while (p->pNext)
		p = p->pNext;
	p->pNext = tail;
	tail->data = *data;
	tail->pNext = NULL;
}
void Slist::AddHead(DATA*data)
{
	SNode*head = new SNode;
	head->pNext = m_pHead;
	m_pHead = head;
	head->data = *data;
}
void Slist::DeleteData(SNode*p)
{
	if (p == m_pHead)
	{
		m_pHead = p->pNext;
		delete(p);
		return;
	}
	SNode*p1 = m_pHead;
	while (p1->pNext)
	{
		if (p1->pNext == p)
			break;
		p1 = p1->pNext;
	}
	p1->pNext = p->pNext;
	delete(p);
}
void Slist::ModifyData(SNode*p, DATA*data)
{
	p->data = *data;
}
SNode** Slist::Sortpoint(int n)
{
	SNode*p = m_pHead;
	int sum = 0;
	if (!p)
		return NULL;
	while (p)
	{
		sum++;
		p = p->pNext;
	}
	SNode**pp = new SNode*[sum + 1];
	SNode**pp1 = pp;
	p = m_pHead;
	while (p)
	{
		*pp1++ = p;
		p = p->pNext;
	}
	*pp1 = NULL;//结尾
	pp1 = pp;//回到起始位置;
	while (*pp1)
	{
		SNode**min = pp1;
		SNode**pp2 = pp1 + 1;
		while (*pp2)
		{
			if (Sortby(*min, *pp2, n)>0)
				min = pp2;
			pp2++;
		}
		if (min != pp2)
		{
			SNode*temp = *min;
			*min = *pp1;
			*pp1 = temp;
		}
		pp1++;
	}
	return pp;
}
void Slist::Printpoint(SNode**p)
{
	SNode**p1 = p;
	if (!p)
	{
		cout<<"系统中无数据记录"<<endl;
		system("pause");
		return;
	}
	cout<<"\t\t\t\t\t\t";
	cout<<"姓名\t学号\t数学\t语文\t英语"<<endl<<endl;
	while (*p)
	{
		cout<<"\t\t\t\t\t\t";
		cout<< (*p)->data.sName<< (*p)->data.sNumb<< (*p)->data.fMath<< (*p)->data.fChin<< (*p)->data.fEngl<<endl<<endl;
		p++;
	}
	delete(p1);
	cout<<"\t\t\t\t\t\t\t\t按任意键继续...";
	_getch();

}
void Slist::RemoveAll()
{
	SNode*p = m_pHead;
	while (p)
	{
		m_pHead = p->pNext;
		free(p);
		p = m_pHead;
	}
}
void Slist::Save()
{
	SNode*p =m_pHead;
	FILE*pf = fopen("Student.tb", "wb");
	if (!pf)
	{
		puts("保存失败");
		exit(-1);
	}
	while (p)
	{
		fwrite(p, sizeof(DATA), 1, pf);
		p = p->pNext;
	}
	fclose(pf);
	RemoveAll();
}
void Slist::Load()
{
	FILE*pf = fopen("Student.tb", "rb");
	if (!pf)
	{
		puts("加载失败");
		system("pause");
		return;
	}
	m_pHead = new SNode;
	SNode*p = m_pHead;
	*p = { 0 };
	SNode*p1 = m_pHead;
	while (fread(p, sizeof(DATA), 1, pf) == 1)
	{
		p->pNext = new SNode;
		p1 = p;
		p = p->pNext;
	}
	if (p->data.fChin == 0)
		m_pHead = NULL;
	p1->pNext = NULL;
	free(p);
	fclose(pf);
}