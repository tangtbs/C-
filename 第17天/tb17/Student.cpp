#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include<iostream>
#include<conio.h>
CStudent::CStudent()
{
	Load();
}

CStudent::~CStudent()
{
	POSITION pos = m_list.GetHeadPosition();
	int count = m_list.GetCount();
	while (count--)
	{
		SStud* p = m_list.GetAt(pos);
		delete p;
		m_list.GetNext(pos);
	}
}

int CStudent::Main()
{
	int n = 0;
	while (n = Menu())
	{
		switch (n)
		{
		case 1:
			Browse();
			break;
		case 2:
			Input();
			break;
		case 3:
			Delete();
			break;
		case 4:
			Modify();
			break;
		case 5:
			Search();
			break;
		}
	}
	Save();
	return 0;
}

int CStudent::Menu()
{
	using namespace std;
	system("cls");
	cout << endl << endl;
	cout << "\t\t********************************" << endl;
	cout << "\t\t*\t1、浏览所有信息        *" << endl;
	cout << "\t\t*\t2、添加信息            *" << endl;
	cout << "\t\t*\t3、删除信息            *" << endl;
	cout << "\t\t*\t4、修改信息            *" << endl;
	cout << "\t\t*\t5、查找信息            *" << endl;
	cout << "\t\t*\t0、退出                *" << endl;
	cout << "\t\t********************************" << endl;
	cout << "\t\t请选择：";
	int i = 0;
	cin >> i;
	return i;
}


void CStudent::Printone(SStud* p)
{
	using namespace std;
	if (p->Type())
	{
		std::cout << "姓名\t性别\t学号\t数学\t物理\t化学\t生物" << std::endl << std::endl;
	}
	else
	{
		std::cout << "姓名\t性别\t学号\t数学\t英语\t历史\t地理\t政治" << std::endl << std::endl;
	}
	p->Print();
		
}

void CStudent::Input()
{
	using namespace std;
	int i = 0;
	system("cls");
	std::cout << "你选择了\"添加数据\"" << std::endl;
	cout << "\t\t\t\t1、从头部添加" << endl;
	cout << "\t\t\t\t2、从尾部添加" << endl;
	cout << "\t\t\t\t3、返回主菜单" << endl;
	cout << "请选择：" << endl;
	cin >> i;
	switch (i)
	{
	case 1:
	case 2:
		Add(i);
		break;
	default:
		return;
	}

}

void CStudent::Add(int i)
{
	using namespace std;
	int n = 0;
	system("cls");
	cout << "1、添加文科" << endl;
	cout << "2、添加理科" << endl;
	cout << "0、返回上级菜单" << endl;
	cout << "请选择类型：";
	cin >> n;
	switch (n)
	{
	case 1:
		AddArt(n);
		break;
	case 2:
		AddScie(n);
		break;
	case 0:
		return;

	}
}

void CStudent::AddArt(int n)
{
	using namespace std;
	system("cls");
	SArt data[20];
	int i = 0;
	cout << "请依次输入" << endl;
	cout << "姓名\t性别\t学号\t数学\t英语\t历史\t地理\t政治" << endl << endl;
	do
	{
		if (i)
			getchar();
		cin >> data[i].sName >> data[i].sSex >> data[i].nNumb >> data[i].fMath
			>>data[i].fEngl >> data[i].fHist >> data[i].fGeog >> data[i].fPoli;
		data[i].nType = 0;
		i++;
		cout << "是否继续（Y/N）" << endl;
	} while (toupper(_getch()) == 'Y');
	cout << "确定添加以上信息吗？（Y/N）" << endl;
	if (toupper(_getch()) == 'Y')
	{
		
		if (n == 1)
			for (int j = 0; j < i; j++)
			{
				SStud* p;
				p= new SArt;
				p->Input(data[j]);
				m_list.AddHead(p);
			}
				

		else
			for (int j = 0; j < i; j++)
			{
				SStud* p;
				p= new SArt;
				p->Input(data[j]);
				m_list.AddTail(p);
			}
				

		cout << "添加成功" << endl;
	}
	else
		cout << "添加失败" << endl;
}

void CStudent::AddScie(int n)
{
	using namespace std;
	system("cls");
	SScie data[20];
	int i = 0;
	cout << "请依次输入" << endl;
	cout << "姓名\t性别\t学号\t数学\t物理\t化学\t生物" << endl << endl;
	do
	{
		if (i)
			getchar();
		cin >> data[i].sName >> data[i].sSex >> data[i].nNumb >> data[i].fMath >> data[i].fPhys >> data[i].fChem >> data[i].fBiol;
		data[i].nType = 1;
		i++;
		cout << "是否继续（Y/N）" << endl;
	} while (toupper(_getch()) == 'Y');
	cout << "确定添加以上信息吗？（Y/N）" << endl;
	if (toupper(_getch()) == 'Y')
	{
		if (n == 1)
			for (int j = 0; j < i; j++)
			{
				SStud* p = new SScie;
				p->Input(data[j]);
				m_list.AddHead(p);
			}
				


		else
			for (int j = 0; j < i; j++)
			{
				SStud* p = new SScie;
				p->Input(data[j]);
				m_list.AddTail(p);
			}
				

		cout << "添加成功" << endl;
	}
	else
		cout << "添加失败" << endl;
}

void CStudent::Browse()
{
	using namespace std;
	int n = 0;
	system("cls");
	cout << "你选择了\"浏览数据\"" << endl;
	cout << "\t\t\t\t\t 1、按姓名浏览" << endl;
	cout << "\t\t\t\t\t 2、按学号浏览" << endl;
	cout << "\t\t\t\t\t 3、按数学成绩浏览" << endl;
	cout << "\t\t\t\t\t 4、按英语成绩浏览" << endl;
	cout << "\t\t\t\t\t 5、按政治成绩浏览" << endl;
	cout << "\t\t\t\t\t 6、按地理成绩浏览" << endl;
	cout << "\t\t\t\t\t 7、按历史成绩浏览" << endl;
	cout << "\t\t\t\t\t 8、按物理成绩浏览" << endl;
	cout << "\t\t\t\t\t 9、按化学成绩浏览" << endl;
	cout << "\t\t\t\t\t10、按生物成绩浏览" << endl;
	cout << "\t\t\t\t\t 0、返回主菜单" << endl;
	cout << "请选择：";
	cin >> n;
	while (n < 0 || n>10)
	{
		cout << "输入错误,请重新输入";
		cin >> n;
	}
	if (n == 0)
		return;
	SStud** pp = Sort(n);
	PrintAll(pp, n);
}


void CStudent::Delete()
{
	using namespace std;
	system("cls");
	int n;
	cout << "你选择了\"删除数据\"" << endl;
	cout << "请输入要删除的学号：" << endl;
	cin >> n;
	POSITION pos;
	SearchbyNumb(n, pos);
	if (!pos)
	{
		cout << "该信息不存在" << endl;
		system("pause");
		return;
	}
	SStud* p = m_list.GetAt(pos);
	Printone(p);
	cout << "确定要删除这条数据吗?(Y/N)" << endl;
	if (toupper(_getch()) == 'Y')
	{
		m_list.RemoveAt(pos);
		delete p;
		cout << "删除成功" << endl;
	}
	else
		cout << "删除失败" << endl;
	system("pause");


}

void CStudent::Modify()
{
	using namespace std;
	int numb = 0;
	cout << "你选择了\"修改数据\"" << endl;
	cout << "请输入一个学号：" << endl;
	cin >> numb;
	POSITION pos;
	SearchbyNumb(numb, pos);
	if (!pos)
	{
		cout << "该信息不存在" << endl;
		system("pause");
		return;
	}
	SStud* p = m_list.GetAt(pos);
	Printone(p);
	cout << "确定修改以上信息吗？(Y/N)";
	if (toupper(_getch()) == 'Y')
	{
		getchar();
		cout << endl << "请依次输入" << endl;
		p->Modify();
		cout << endl << "修改成功" << endl;
	}
	else
		cout << endl << "修改失败" << endl;
	system("pause");

}

void CStudent::Search()
{
	using namespace std;
	int n = 0;
	system("cls");
	cout << "你选择了\"查找数据\"" << endl;
	cout << "请输入一个学号：";
	cin >> n;
	POSITION pos;
	SearchbyNumb(n, pos);
	if (!pos)
	{
		cout << "该信息不存在" << endl;
		system("pause");
		return;
	}
	Printone(m_list.GetAt(pos));
	system("pause");
}

void  CStudent::SearchbyNumb(int numb, POSITION& pos)
{
	pos = m_list.GetHeadPosition();
	if (!pos)
		return;
	POSITION pos_end = m_list.GetTailPosition();
	if (m_list.GetAt(pos_end)->nNumb == numb)
	{
		pos = pos_end;
		return;
	}

	while (pos != pos_end)
	{
		if (m_list.GetAt(pos)->nNumb == numb)
			return;
		m_list.GetNext(pos);
	}
	pos = NULL;
}


SStud ** CStudent::Sort(int n)
{
	int size = m_list.GetCount();
	bool(*pFunction[])(SStud*, SStud*) = { SortbyName,SortbyNumb ,SortbyMath ,SortbyEngl ,SortbyPoli ,SortbyGeog ,
		SortbyHist , SortbyPhys ,SortbyChem,SortbyBiol };
	if (!size)
		return NULL;
	SStud** pp = new SStud*[size + 1]{ NULL };
	POSITION pos = m_list.GetHeadPosition();
	if (n == 1 || n == 2||n==3)
	{
		
		SStud** pp1 = pp;
		int i = size;
		while (i--)
		{
			*pp1++ = m_list.GetAt(pos);
			m_list.GetNext(pos);
		}
		std::sort(pp, pp + size, pFunction[n - 1]);
	}

	else if (n == 4 || n == 5 || n == 6 || n == 7)
	{
		SArt** p1 = (SArt**)pp;
		int i = size, nCount = 0;
		while (i--)
		{
			SStud* temp = m_list.GetAt(pos);
			if (!temp->Type())
			{
				*p1++ = (SArt*)temp;
				nCount++;
			}

			m_list.GetNext(pos);
		}
		std::sort((SArt**)pp, (SArt**)pp + nCount, pFunction[n - 1]);
	}
	else
	{
		SScie** p1 = (SScie**)pp;
		int i = size, nCount = 0;
		while (i--)
		{
			SStud* temp = m_list.GetAt(pos);
			if (temp->Type())
			{
				*p1++ = (SScie*)temp;
				nCount++;
			}

			m_list.GetNext(pos);
		}
		std::sort((SScie**)pp, (SScie**)pp + nCount, pFunction[n - 1]);
	}
	return pp;
}

void CStudent::PrintAll(SStud **pp, int n)
{
	using namespace std;
	if (!pp)
	{
		cout << "系统中无数据" << endl;
		system("pause");
		return;
	}
	if (!*pp)
	{
		cout << "系统中无此类数据" << endl;
		system("pause");
		return;
	}
	if (n == 1 || n == 2)
	{
		cout << "姓名\t性别\t学号" << endl << endl;
		while (*pp)
		{
			cout << (*pp)->sName << "\t" << (*pp)->sSex << "\t" << (*pp)->nNumb << endl;
			pp++;
		}
	}
	else if (n == 3)
	{
		cout << "姓名\t性别\t学号\t数学" << endl << endl;
		while (*pp)
		{
			cout << (*pp)->sName << "\t" << (*pp)->sSex << "\t" << (*pp)->nNumb << "\t" << ((SArt*)(*pp))->fMath << endl;
			pp++;
		}
	}
	else if (n == 4 || n == 5 || n == 6 || n == 7)
		cout << "姓名\t性别\t学号\t数学\t英语\t历史\t地理\t政治" << endl << endl;
	else
		cout << "姓名\t性别\t学号\t数学\t物理\t化学\t生物" << endl << endl;

	while (*pp)
		(*pp++)->Print();
	system("pause");
}

bool CStudent::SortbyName(SStud *p1, SStud *p2)
{
  return p1->SortbyName(p2);
}

bool CStudent::SortbyNumb(SStud *p1, SStud *p2)
{
	return p1->SortbyNumb(p2);
}

bool CStudent::SortbyMath(SStud *p1, SStud *p2)
{
	return p1->SortbyMath(p2);
}

bool CStudent::SortbyPhys(SStud *p1, SStud *p2)
{
	return p1->SortbyPhys(p2);
}

bool CStudent::SortbyChem(SStud *p1, SStud *p2)
{
	return p1->SortbyChem(p2);
}

bool CStudent::SortbyBiol(SStud *p1, SStud *p2)
{
	return p1->SortbyBiol(p2);
}

bool CStudent::SortbyEngl(SStud*p1, SStud *p2)
{
	return p1->SortbyEngl(p2);
}

bool CStudent::SortbyGeog(SStud *p1, SStud *p2)
{
	return p1->SortbyGeog(p2);
}

bool CStudent::SortbyHist(SStud *p1, SStud *p2)
{
	return p1->SortbyHist(p2);
}

bool CStudent::SortbyPoli(SStud *p1, SStud *p2)
{
	return p1->SortbyPoli(p2);
}


void CStudent::Save()
{
	FILE* fp;
	fopen_s(&fp,"Student.tb", "w");
	int size = m_list.GetCount();
	POSITION pos = m_list.GetHeadPosition();
	while (size--)
	{
		SStud* p = m_list.GetAt(pos);
		p->Save(fp);
		m_list.GetNext(pos);
	}
	fclose(fp);
}

void CStudent::Load()
{
	FILE*fp = fopen("Student.tb", "r");
	if (!fp)
	{
		std::cout << "打开文件失败" << std::endl;
		system("pause");
		return;
	}
	int type;
	while (fread(&type, sizeof(int), 1, fp) == 1)
	{
		void* p;
		type ? (p=new SScie) : (p=new SArt);
		size_t size = type ? sizeof(SScie) : sizeof(SArt);
		memcpy((char*)p+sizeof(void*),&type,sizeof(int));
		void* temp = (char*)p + sizeof(int)+sizeof(void*);
		fread(temp, size - sizeof(int)-sizeof(void*), 1, fp);
		m_list.AddTail((SStud*)p);
	}
	fclose(fp);
}



SStud::~SStud()
{
}

void SStud::Modify()
{
}

void SScie::Input(const SStud& data)
{
	const SScie* p = (SScie*)&data;
	nNumb =p->nNumb;
	strcpy(sName,p->sName);
	strcpy(sSex, p->sSex);
	fMath = p->fMath;
	fPhys = p->fPhys;
	fChem = p->fChem;
	fBiol = p->fBiol;
	nType = 1;
}

void SScie::Modify()
{
	std::cin >>sName >>sSex >>nNumb >>fMath >>fPhys >>fChem >>fBiol;
}

void SScie::Print()
{
	std::cout << sName << "\t" << sSex << "\t" << nNumb << "\t" << fMath << "\t" << fPhys
		<< "\t" << fChem << "\t" << fBiol << std::endl;

}

bool SScie::SortbyNumb(SStud *pData)
{
	SScie* p = (SScie*)pData;
	return nNumb-p->nNumb<0;
}

bool SScie::SortbyName(SStud *pData)
{
	SScie* p = (SScie*)pData;
	return strcmp(sName,p->sName)<0;
}

bool SScie::SortbyMath(SStud *pData)
{
	SScie* p = (SScie*)pData;
	return fMath-p->fMath>0;
}

bool SScie::SortbyChem(SStud * pData)
{
	SScie* p = (SScie*)pData;
	return fChem-p->fChem>0;
}

bool SScie::SortbyPhys(SStud *pData)
{
	SScie* p = (SScie*)pData;
	return fPhys-p->fPhys>0;
}

bool SScie::SortbyBiol(SStud *pData)
{
	SScie* p = (SScie*)pData;
	return fBiol-p->fBiol>0;
}

void SArt::Input(const SStud& data)
{
	const SArt* p = (SArt*)&data;
	nNumb = p->nNumb;
	strcpy(sName, p->sName);
	strcpy(sSex, p->sSex);
	fMath = p->fMath;
	fEngl = p->fEngl;
	fGeog = p->fGeog;
	fHist = p->fHist;
	fPoli = p->fPoli;
	nType = 0;
}

void SArt::Delete()
{
	delete this;
}

void SArt::Modify()
{

	std::cin >>sName >>sSex >> nNumb >> fMath >> fEngl >> fHist >> fGeog >> fPoli;
}

void SArt::Print()
{
	std::cout << sName << "\t" << sSex << "\t" << nNumb << "\t" << fMath << "\t" << fEngl
		<< "\t" << fHist << "\t"<< fGeog << "\t" << fPoli << std::endl;
}

bool SArt::SortbyNumb(SStud *pData)
{
	SArt* p = (SArt*)pData;
	return nNumb-p->nNumb<0;
}

bool SArt::SortbyName(SStud *pData)
{
	SArt*p = (SArt*)pData;
	return strcmp(sName,p->sName)<0;
}

bool SArt::SortbyMath(SStud *pData)
{
	SArt* p = (SArt*)pData;
	return fMath-p->fMath>0;
}

bool SArt::SortbyEngl(SStud *pData)
{
	SArt* p = (SArt*)pData;
	return fEngl - p->fEngl > 0;
}

bool SArt::SortbyHist(SStud *pData)
{
	SArt* p = (SArt*)pData;
	return fHist-p->fHist>0;
}

bool SArt::SortbyGeog(SStud *pData)
{
	SArt* p = (SArt*)pData;
	return fGeog-p->fGeog>0;
}

bool SArt::SortbyPoli(SStud *pData)
{
	SArt* p = (SArt*)pData;
	return fPoli-p->fPoli>0;
}
