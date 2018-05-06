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
		p->nType == 1? delete (SArt*)p:delete (SScie*)p;
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
	cout<<"\t\t********************************"<<endl;
	cout<<"\t\t*\t1�����������Ϣ        *"<<endl;
	cout<<"\t\t*\t2�������Ϣ            *"<<endl;
	cout<<"\t\t*\t3��ɾ����Ϣ            *"<<endl;
    cout<<"\t\t*\t4���޸���Ϣ            *"<<endl;
	cout<<"\t\t*\t5��������Ϣ            *"<<endl;
	cout<<"\t\t*\t0���˳�                *"<<endl;
	cout<<"\t\t********************************"<<endl;
	cout<<"\t\t��ѡ��";
	int i = 0;
	cin >> i;
	return i;
}


void CStudent::Printone(const POSITION pos)
	{
	using namespace std;
	SStud* p=m_list.GetAt(pos);

	if (p->nType == 1)
	{
		SArt* p1 = (SArt*)p;
		cout << "����\t�Ա�\tѧ��\t��ѧ\tӢ��\t��ʷ\t����\t����" << endl << endl;
		cout<< p1->sName << "\t" <<p1->sSex << "\t" <<p1->nNumb << "\t" <<p1->fMath << "\t" <<p1->fEngl << "\t" 
			<< p1->fHist << "\t" <<p1->fGeog << "\t" << p1->fPoli<<endl;
	}
	else
	{
		SScie* p1 = (SScie*)p;
		cout << "����\t�Ա�\tѧ��\t��ѧ\t����\t��ѧ\t����" << endl << endl;
		cout << p1->sName<<"\t" << p1->sSex <<"\t"<< p1->nNumb<<"\t" << p1->fMath<<"\t" << p1->fPhys<<"\t" << p1->fChem<<"\t" << p1->fBiol << endl;
	}
		
}

void CStudent::Input()
{
	using namespace std;
	int i = 0;
	system("cls");
	std::cout << "��ѡ����\"�������\"" << std::endl;
	cout << "\t\t\t\t1����ͷ�����" << endl;
	cout << "\t\t\t\t2����β�����" << endl;
	cout << "\t\t\t\t3���������˵�" << endl;
	cout << "��ѡ��" << endl;
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
	cout << "1������Ŀ�" << endl;
	cout << "2��������" << endl;
	cout << "0�������ϼ��˵�" << endl;
	cout << "��ѡ�����ͣ�";
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
	cout << "����������" << endl;
	cout << "����\t�Ա�\tѧ��\t��ѧ\tӢ��\t��ʷ\t����\t����" << endl << endl;
	do
	{
		if (i)
			getchar();
		cin >> data[i].sName >> data[i].sSex>>data[i].nNumb >> data[i].fMath >> data[i].fEngl>>data[i].fHist>>data[i].fGeog>>data[i].fPoli;
		data[i].nType = 1;
		i++;
		cout << "�Ƿ������Y/N��" << endl;
	} while (toupper(_getch()) == 'Y');
	cout << "ȷ�����������Ϣ�𣿣�Y/N��" << endl;
	if (toupper(_getch()) == 'Y')
	{
		SArt temp;
		if (n == 1)
			for (int j = 0; j < i; j++)
				m_list.AddHead(temp.Input(data[j]));
				

		if (n == 2)
			for (int j = 0; j < i; j++)
				m_list.AddTail(temp.Input(data[j]));

		cout << "��ӳɹ�" << endl;
	}
	else
		cout << "���ʧ��" << endl;
}

void CStudent::AddScie(int n)
{
	using namespace std;
	system("cls");
	SScie data[20];
	int i = 0;
	cout << "����������" << endl;
	cout << "����\t�Ա�\tѧ��\t��ѧ\t����\t��ѧ\t����" << endl << endl;
	do
	{
		if (i)
			getchar();
		cin >> data[i].sName >> data[i].sSex >> data[i].nNumb >> data[i].fMath >> data[i].fPhys >> data[i].fChem >> data[i].fBiol;
		data[i].nType = 2;
		i++;
		cout << "�Ƿ������Y/N��" << endl;
	} while (toupper(_getch()) == 'Y');
	cout << "ȷ�����������Ϣ�𣿣�Y/N��" << endl;
	if (toupper(_getch()) == 'Y')
	{
		SScie temp;
		if (n == 1)
			for (int j = 0; j < i; j++)
				m_list.AddHead(temp.Input(data[j]));


		if (n == 2)
			for (int j = 0; j < i; j++)
				m_list.AddTail(temp.Input(data[j]));

		cout << "��ӳɹ�" << endl;
	}
	else
		cout << "���ʧ��" << endl;
}

void CStudent::Browse()
{
	using namespace std;
	int n = 0;
	system("cls");
	cout << "��ѡ����\"�������\"" << endl;
	cout << "\t\t\t\t\t 1�����������" << endl;
	cout << "\t\t\t\t\t 2����ѧ�����" << endl;
	cout << "\t\t\t\t\t 3������ѧ�ɼ����" << endl;
	cout << "\t\t\t\t\t 4����Ӣ��ɼ����" << endl;
	cout << "\t\t\t\t\t 5�������γɼ����" << endl;
	cout << "\t\t\t\t\t 6��������ɼ����" << endl;
	cout << "\t\t\t\t\t 7������ʷ�ɼ����" << endl;
	cout << "\t\t\t\t\t 8��������ɼ����" << endl;
	cout << "\t\t\t\t\t 9������ѧ�ɼ����" << endl;
	cout << "\t\t\t\t\t10��������ɼ����" << endl;
	cout << "\t\t\t\t\t 0���������˵�" << endl;
	cout << "��ѡ��";
	cin >> n;
	while (n < 0 || n>10)
	{
		cout << "�������,����������";
		cin >> n;
	}
	if (n == 0)
		return;
	SStud** pp=Sort(n);
	PrintAll(pp,n);

}


void CStudent::Delete()
{
	using namespace std;
	system("cls");
	int n;
	cout << "��ѡ����\"ɾ������\"" << endl;
	cout << "������Ҫɾ����ѧ�ţ�" << endl;
	cin >> n;
	POSITION pos;
	SearchbyNumb(n, pos);
	if (!pos)
	{
		cout << "����Ϣ������" << endl;
		system("pause");
		return;
	}
	Printone(pos);
	cout << "ȷ��Ҫɾ������������?(Y/N)" << endl;
	if (toupper(_getch()) == 'Y')
	{
		SStud* p = m_list.GetAt(pos);
		m_list.RemoveAt(pos);
		p->nType == 1 ? delete[](SArt*)p : delete[](SScie*)p;
		cout << "ɾ���ɹ�" << endl;
	}
	else
		cout << "ɾ��ʧ��" << endl;
	system("pause");


}

void CStudent::Modify()
{
	using namespace std;
	int numb = 0;
	cout << "��ѡ����\"�޸�����\"" << endl;
	cout << "������һ��ѧ�ţ�" << endl;
	cin >> numb;
	POSITION pos;
	SearchbyNumb(numb, pos);
	if (!pos)
	{
		cout << "����Ϣ������" << endl;
		system("pause");
		return;
	}
	Printone(pos);
	cout << "ȷ���޸�������Ϣ��(Y/N)";
	if (toupper(_getch()) == 'Y')
	{
		getchar();
		cout << endl<<"����������" << endl;
		SStud* p = m_list.GetAt(pos);
		if (p->nType == 1)
		{
			SArt* p1 = (SArt*)p;
			cout << "����\t�Ա�\tѧ��\t��ѧ\tӢ��\t��ʷ\t����\t����" << endl << endl;
			cin >> p1->sName >> p1->sSex >> p1->nNumb >> p1->fMath >> p1->fEngl >> p1->fHist >> p1->fGeog >> p1->fPoli;
		}
		else
		{
			SScie* p1 = (SScie*)p;
			cout << "����\t�Ա�\tѧ��\t��ѧ\t����\t��ѧ\t����" << endl << endl;
			cin >> p1->sName >> p1->sSex >> p1->nNumb >> p1->fMath >> p1->fPhys >> p1->fChem >> p1->fBiol;
		}
		cout << endl << "�޸ĳɹ�" << endl;
	}
	else
		cout << endl << "�޸�ʧ��" << endl;
	system("pause");

}

void CStudent::Search()
{
	using namespace std;
	int n = 0;
	system("cls");
	cout << "��ѡ����\"��������\"" << endl;
	cout << "������һ��ѧ�ţ�";
	cin >> n;
	POSITION pos;
	SearchbyNumb(n, pos);
	if (!pos)
	{
		cout << "����Ϣ������" << endl;
		system("pause");
		return;
	}
	Printone(pos);
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
		if (m_list.GetAt(pos)->nNumb== numb)
			return;
		m_list.GetNext(pos);
	}
	pos = NULL;
}


SStud ** CStudent::Sort(int n)
{
	int size = m_list.GetCount();

	if (!size)
		return NULL;
	SStud** pp = new SStud*[size+1]{NULL};
	POSITION pos = m_list.GetHeadPosition();
	if (n == 1 || n == 2)
	{
		bool(*pFunction[])(SStud*, SStud*) = {SortbyName,SortbyNumb};
		SStud** pp1 = pp;
		int i = size;
		while (i--)
		{
			*pp1++ = m_list.GetAt(pos);
			m_list.GetNext(pos);
		}
		std::sort(pp,pp+size,pFunction[n-1]);
	}
	else if (n ==3)
	{
		SScie** pp1 = (SScie**)pp;
		int i = size;
		while (i--)
		{
			*pp1++ =(SScie*)m_list.GetAt(pos);
			m_list.GetNext(pos);
		}
		std::sort((SScie**)pp, (SScie**)pp + size,SortbyMath);
	}
	else if (n == 4 || n == 5 || n == 6||n==7)
	{
		bool (*pFunction[])(SArt*, SArt*) = {SortbyEngl,SortbyPoli,SortbyGeog,SortbyHist};
		SArt** p1 =(SArt**)pp;
		int i = size,nCount=0;
		while (i--)
		{
			SStud* temp = m_list.GetAt(pos);
			if (temp->nType == 1)
			{
				*p1++ = (SArt*)temp;
				nCount++;
			}
				
			m_list.GetNext(pos);
		}
		std::sort((SArt**)pp,(SArt**)pp+nCount,pFunction[n-4]);
	}
	else
	{
		bool(*pFunction[])(SScie*, SScie*) = {SortbyPhys,SortbyChem,SortbyBiol};
		SScie** p1 = (SScie**)pp;
		int i = size, nCount = 0;
		while (i--)
		{
			SStud* temp = m_list.GetAt(pos);
			if (temp->nType == 2)
			{
				*p1++ = (SScie*)temp;
				nCount++;
			}

			m_list.GetNext(pos);
		}
		std::sort((SScie**)pp, (SScie**)pp + nCount, pFunction[n - 8]);
	}
	return pp;
}

void CStudent::PrintAll(SStud **pp, int n)
{
	using namespace std;
	if (!pp)
	{
		cout << "ϵͳ��������" << endl;
		system("pause");
		return;
	}
	if (!*pp)
	{
		cout << "ϵͳ���޴�������" << endl;
		system("pause");
		return;
	}
	if (n==1||n==2)
	{
		SScie** temp = (SScie**)pp;
		cout << "����\t�Ա�\tѧ��" << endl << endl;
		while (*temp)
		{
			cout << (*temp)->sName << "\t" << (*temp)->sSex << "\t" << (*temp)->nNumb << endl;
			temp++;
		}
	}
	else if (n == 3)
	{
		SScie** temp = (SScie**)pp;
		cout << "����\t�Ա�\tѧ��\t��ѧ" << endl << endl;
		while (*temp)
		{
			cout << (*temp)->sName<<"\t" << (*temp)->sSex<<"\t" << (*temp)->nNumb<<"\t" <<(*temp)->fMath<< endl;
			temp++;
		}
	}
	else if (n == 4 || n == 5 || n == 6||n==7)
	{
		SArt** temp = (SArt**)pp;
		cout << "����\t�Ա�\tѧ��\t��ѧ\tӢ��\t��ʷ\t����\t����" << endl << endl;
		while (*temp)
		{
			cout << (*temp)->sName << "\t" << (*temp)->sSex << "\t" << (*temp)->nNumb << "\t" << (*temp)->fMath << "\t"
				<<(*temp)->fEngl<<"\t"<<(*temp)->fHist<<"\t"<<(*temp)->fGeog<<"\t"<<(*temp)->fPoli<<endl;
			temp++;
		}
	}
	else
	{
		SScie** temp = (SScie**)pp;
		cout << "����\t�Ա�\tѧ��\t��ѧ\t����\t��ѧ\t����" << endl << endl;
		while (*temp)
		{
			cout << (*temp)->sName << "\t" << (*temp)->sSex << "\t" << (*temp)->nNumb << "\t" << (*temp)->fMath << "\t"
				<< (*temp)->fPhys<< "\t" << (*temp)->fChem << "\t" << (*temp)->fBiol<< endl;
			temp++;
		}
	}
	system("pause");
}

bool CStudent::SortbyName(SStud *p1, SStud *p2)
{
	return strcmp(p1->sName,p2->sName)<0;
}

bool CStudent::SortbyNumb(SStud *p1, SStud *p2)
{
	return p1->nNumb-p2->nNumb<0;
}

bool CStudent::SortbyMath(SScie *p1, SScie *p2)
{
	return p1->fMath-p2->fMath>0;
}

bool CStudent::SortbyPhys(SScie *p1, SScie *p2)
{
	return p1->fPhys-p1->fPhys>0;
}

bool CStudent::SortbyChem(SScie *p1, SScie *p2)
{
	return p1->fChem-p2->fChem>0;
}

bool CStudent::SortbyBiol(SScie *p1, SScie *p2)
{
	return p1->fBiol-p2->fBiol>0;
}

bool CStudent::SortbyEngl(SArt *p1, SArt *p2)
{
	return p1->fEngl-p2->fEngl>0;
}

bool CStudent::SortbyGeog(SArt *p1, SArt *p2)
{
	return p1->fGeog-p2->fGeog>0;
}

bool CStudent::SortbyHist(SArt *p1, SArt *p2)
{
	return p1->fHist-p2->fHist>0;
}

bool CStudent::SortbyPoli(SArt *p1, SArt *p2)
{
	return p1->fPoli-p2->fPoli>0;
}


void CStudent::Save()
{
	FILE* fp;
	fp=fopen("Student.tb", "w");
	int size = m_list.GetCount();
	POSITION pos = m_list.GetHeadPosition();
	while (size--)
	{
		SStud* p = m_list.GetAt(pos);
		if (p->nType == 1)
			fwrite((SArt*)p, sizeof(SArt), 1, fp);
		else
			fwrite((SScie*)p,sizeof(SScie),1,fp);
		m_list.GetNext(pos);
	}
	fclose(fp);
}

void CStudent::Load()
{
	FILE*fp=fopen("Student.tb", "r");
	if (!fp)
	{
		std::cout << "���ļ�ʧ��" << std::endl;
		system("pause");
		return;
	}
	SStud temp;
	while (fread(&temp, sizeof(SStud), 1, fp) == 1)
	{
		if (temp.nType == 1)
		{
			SArt* tArt = new SArt;
			memcpy(tArt,&temp,sizeof(SStud));
			fread(&tArt->fMath,sizeof(SArt)-sizeof(SStud),1,fp);
			m_list.AddTail(tArt);
		}
		else
		{
			SScie* tSScie = new SScie;
			memcpy(tSScie, &temp, sizeof(SStud));
			fread(&tSScie->fMath, sizeof(SScie) - sizeof(SStud), 1, fp);
			m_list.AddTail(tSScie);
		}
	}

}

SStud* SStud::InputInfo(const SStud& data)
{
	SStud* p = new SStud{data};
	return p;
}

SStud* SScie::Input(const SScie& data)
{
	SScie* p = new SScie{data};
	return p;
}

SStud* SArt::Input(const SArt & data)
{
	SArt* p = new SArt{data};
	return p;
}
