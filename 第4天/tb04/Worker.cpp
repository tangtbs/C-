#define _CRT_SECURE_NO_WARNINGS
#include "Worker.h"
CWorker::CWorker()
{
	Super.bPower = true;
	strcpy(Super.sName,"root");
	strcpy(Super.sPasword,"root");
	Load();
}


CWorker::~CWorker()
{

}


// ��CWorker�ڵ�Main����
int CWorker::Main()
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
		case 6:
			Password();
			break;
		default:
			cout << "�������" << endl;
			break;

		}
	}
	Save();
	return 0;
}


// //���˵�
int CWorker::Menu()
{
	system("cls");
	int n = 0;
	cout << "\t\t\t\t\t\tԱ����Ϣ����ϵͳ" << endl << endl;
	cout << "\t\t\t\t\t\t1�����Ա����Ϣ" << endl;
	cout << "\t\t\t\t\t\t2�����Ա����Ϣ" << endl;
	cout << "\t\t\t\t\t\t3��ɾ��Ա����Ϣ" << endl;
	cout << "\t\t\t\t\t\t4���޸�Ա����Ϣ" << endl;
	cout << "\t\t\t\t\t\t5������Ա����Ϣ" << endl;
	cout << "\t\t\t\t\t\t6���޸ĵ�¼����" << endl;
	cout << "\t\t\t\t\t\t0���˳�����ϵͳ" << endl;
	cout << "��ѡ��";
	cin >> n;
	return n;
}


// ���
void CWorker::Browse()
{
	system("cls");
	int n = 0;
	cout << "��ѡ����\"���Ա����Ϣ\"" << endl;
	while (n = BrowseMenu())
	{
		switch (n)
		{
		case 1:
		case 2:
		case 3:
			PrintAll(Sort(n));
			break;
		default:
			cout << "�������" << endl;
		}
	}
}

int CWorker::BrowseMenu()
{
	int n = 0;
	cout << "\t\t\t\t\t\t1�����������" << endl;
	cout << "\t\t\t\t\t\t2�����������" << endl;
	cout << "\t\t\t\t\t\t3�����������" << endl;
	cout << "\t\t\t\t\t\t0���������˵�" << endl;
	cout << "��ѡ��";
	cin >> n;
	return n;
}


void CWorker::PrintAll(SWorker**pp)
{

	if (!pp)
	{
		cout << "ϵͳ�������ݼ�¼" << endl;
		return;
	}
	cout << "\t\t\t\t\t\t����\t" << "����\t" << "����" << endl << endl;
	while (*pp)
	{
		cout<<"\t\t\t\t\t\t" << (*pp)->sName << "\t" << (*pp)->nNumb << "\t" << (*pp)->fSala << endl;
		pp++;
	}
	system("pause");
}


//�������
void CWorker::Input()
{
	system("cls");
	if (User.bPower == false)
	{
		cout << "��û�����Ȩ��" << endl;
		system("pause");
		return;
	}
		
	int n = 0;
	cout << "��ѡ����\"���Ա����Ϣ\"" << endl;
	cout << "\t\t\t\t\t\t1����ͷ�����" << endl;
	cout << "\t\t\t\t\t\t2����β�����" << endl;
	cout << "\t\t\t\t\t\t0���������˵�" << endl;
	cout << "��ѡ��";
	cin >> n;
	if (!n)
		return;
	Add(n);
}


void CWorker::Add(int n)
{
	system("cls");
	SWorker data[20];
	int i = 0;
	cout << "����������" << endl;
	cout << "\t\t\t\t\t\t����\t����\t����\tȨ��" << endl << endl;
	do
	{
		cout<<"\t\t\t\t\t\t";
		cin >> data[i].sName >> data[i].nNumb >> data[i].fSala>>data[i].bPower;
		i++;
		cout << "�Ƿ������Y/N��";
	} while (toupper(_getch()) == 'Y');
	cout << "ȷ�����������Ϣ�𣿣�Y/N��"<<endl;
	if (toupper(_getch()) == 'Y')
	{
		if (n == 1)
			for (int j = 0; j < i; j++)
				m_list.AddHead(data[j]);

		if (n == 2)
			for (int j = 0; j < i; j++)
				m_list.AddTail(data[j]);

		cout << "��ӳɹ�" << endl;
	}
	else
		cout << "���ʧ��" << endl;
	return;
}


//ɾ������
void CWorker::Delete()
{
	system("cls");
	if (User.bPower == false)
	{
		cout << "��û��ɾ��Ȩ��" << endl;
		system("pause");
		return;
	}
	int n;
	cout << "��ѡ����\"ɾ������\"" << endl;
	cout << "������Ҫɾ���Ĺ��ţ�" << endl;
	cin >> n;
	POSITION pos = SearchbyNumb(n);
	if (!pos)
	{ 
		cout << "����Ϣ������"<<endl;
		system("pause");
		return;
	}
	SWorker& data = m_list.GetAt(pos);
	Printone(data);
	cout << "ȷ��Ҫɾ������������?(Y/N)" << endl;
	if (toupper(_getch()) == 'Y')
	{
		m_list.RemoveAt(pos);
		cout << "ɾ���ɹ�" << endl;
	}
	else
		cout << "ɾ��ʧ��" << endl;
	system("pause");

}


//��������
void CWorker::Search()
{
	system("cls");
	int numb = 0;
	cout << "��ѡ����\"��������\"" << endl;
	cout << "�����빤�ţ�";
	cin >> numb;
	POSITION pos = SearchbyNumb(numb);
	if (!pos)
	{
		cout << "����Ϣ������" << endl;
		system("pause");
		return;
	}
	SWorker& data = m_list.GetAt(pos);
	Printone(data);
	return;
}


void CWorker::Printone(const SWorker& data)
{
	cout << "\t\t\t\t\t\t����\t����\t����" << endl << endl;
	cout <<"\t\t\t\t\t\t"<< data.sName << "\t" << data.nNumb << "\t" << data.fSala << endl;
}


// �޸�����
void CWorker::Modify()
{
	system("cls");
	if (User.bPower==false)
	{
		cout << "��û���޸�Ȩ��" << endl;
		system("pause");
		return;
	}
	int numb = 0;
	cout << "��ѡ����\"�޸�����\"" << endl;
	cout << "������һ�����ţ�" << endl;
	cin >> numb;
	POSITION pos = SearchbyNumb(numb);
	if (!pos)
	{
		cout << "����Ϣ������" << endl;
		system("pause");
		return;
	}
	SWorker& data = m_list.GetAt(pos);
	Printone(data);
	cout << "ȷ���޸�������Ϣ��(Y/N)";
	if (toupper(_getch()) == 'Y')
	{
		cout << endl;
		cout << "�������µĹ���:";
		cin >> data.nNumb;
		cout << "�������µ�����:";
		cin >> data.sName;
		cout << "�������µ�н��:";
		cin >> data.fSala;
		cout << "�Ƿ�Ϊ���û���ӹ���ԱȨ�ޣ�Y/N����";
		toupper(_getch()) == 'Y' ? data.bPower = true : false;
		cout<<endl<< "�޸ĳɹ�" << endl;
	}
	else
		cout <<endl<< "�޸�ʧ��" << endl;
	system("pause");

}

//�޸�����
void CWorker::Password()
{
	system("cls");
	int n = 5;
	Clist<SWorker>::SNode*p = (Clist<SWorker>::SNode*)SearchbyName(User.sName);
	if (!p)
	{
		cout << "root�û����벻���ڴ��޸�" << endl;
		system("pause");
		return;
	}
	cout << "��ѡ�����޸�����" << endl;
	cout << "������ԭʼ����:";
	do
	{
		char s[20] = { 0 };
		int i = 0;
		for (; (s[i] = _getch()) != '\r'; i++)
			putchar('*');
		s[i] = 0;
		if (!strcmp(p->data.sPasword, s))
			break;
		cout << endl<<"����������������룺";
	} while (n--);
	if(n<0)
	{
		cout << "�޸�ʧ��" << endl;
		system("pause");
		return;
	}
	while(1)
	{
		char s1[20] = { 0 };
		char s2[20] = { 0 };
	    cout << endl<<"�������µ�����:";
		int i = 0;
		for (; (s1[i] = _getch()) != '\r'; i++)
			putchar('*');
		s1[i] = 0;
	    cout << endl<<"���ٴ���������:" ;
		int j = 0;
		for (; (s2[j] = _getch()) != '\r'; j++)
			putchar('*');
		s2[j] = 0;
		if (!strcmp(s1, s2))
		{
			strcpy(p->data.sPasword, s1);
			break;
		}
		cout <<endl<< "������������벻һ��" << endl;
	}
	cout << "�޸ĳɹ�" << endl;
	system("pause");
}

SWorker** CWorker::Sort(int n)
{
	SWorker** pp = new SWorker*[m_list.GetCount() + 1];
	SWorker**pp1 = pp;
	POSITION pos = m_list.GetHeadPosition();
	if (!pos)
		return NULL;
	for (int i = 0; i < m_list.GetCount(); i++)
	{
		*pp1++ = &m_list.GetAt(pos);
		m_list.GetNext(pos);
	}
	*pp1 = NULL;
	pp1 = pp;
	while (*pp1)
	{
		SWorker**mp = pp1;
		SWorker**pp2 = pp1 + 1;
		while (*pp2)
		{
			if (Sortby(**pp2, **mp, n)<0)
				mp = pp2;
			pp2++;
		}
		if (mp != pp1)
		{
			SWorker*temp = *mp;
			*mp = *pp1;
			*pp1 = temp;
		}
		pp1++;
	}
	return pp;
}
int CWorker::Sortby(SWorker&m1, SWorker&m2, int n)
{
	switch (n)
	{
	case 1:
		return m1.nNumb - m2.nNumb;
	case 2:
		return strcmp(m1.sName, m2.sName);
	case 3:
		return m1.fSala - m2.fSala < 0 ? 1 : -1;

	}
}


POSITION CWorker::SearchbyNumb(int numb)
{
	POSITION pos = m_list.GetHeadPosition();
	if (!pos)
		return NULL;
	for (int i = 0; i < m_list.GetCount(); i++)
	{
		if (m_list.GetAt(pos).nNumb == numb)
			return pos;
		m_list.GetNext(pos);
	}
	return NULL;
}

POSITION CWorker::SearchbyName(char * s)
{

	POSITION pos = m_list.GetHeadPosition();
	if (!pos)
		return NULL;
	for (int i = 0; i < m_list.GetCount(); i++)
	{
		if (!strcmp(m_list.GetAt(pos).sName,s))
			return pos;
		m_list.GetNext(pos);
	}
	return NULL;
}

// ����
void CWorker::Save()
{
	FILE* fp =fopen("Worker.tb","w");
	if (!fp)
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	Clist<SWorker>::SNode* p = m_list.m_pHead;
	while (p)
	{
		fwrite(&p->data,sizeof(SWorker),1,fp);
		p = p->pNext;
	}
	fclose(fp);
}

//����
void CWorker::Load()
{
	FILE* fp = fopen("Worker.tb","r");
	if (!fp)
		return;
	Clist<SWorker>::SNode* p =new Clist<SWorker>::SNode;
	Clist<SWorker>::SNode* Tail = NULL;
	while (fread(&p->data,sizeof(SWorker),1,fp)==1)
	{
		if (!Tail)
			m_list.m_pHead = p;
		Tail = p;
		Tail->pPrev=m_list.m_pTail;
		m_list.m_pTail = Tail;
		p = new  Clist<SWorker>::SNode;
		Tail->pNext = p;
		m_list.m_nCount++;
	}
	if(Tail)
	Tail->pNext = NULL;
	delete p;
}

//����
void CWorker::Login()
{
	int n = 3;
	char name[20] = { 0 };
	char password[20] = { 0 };
	Clist<SWorker>::SNode*p;
	cout << "��ѡ����\"����ϵͳ\"" << endl;
	do{
		
	cout << "User:";
	cin >>name;
	cout << "password:";
	int i = 0;
	for (; (password[i] = _getch()) != '\r'; i++)
		putchar('*');
	password[i] = 0;
	p=(Clist<SWorker>::SNode*)SearchbyName(name);
	if (p &&!strcmp(p->data.sPasword, password)||!strcmp(name,Super.sName)&&!strcmp(password,Super.sPasword))
	{		
		if (p)
			User = p->data;
		else
			User = Super;
		cout<<endl << "����ɹ�" << endl;
		system("pause");
		Main();
		return;
	}
	if(--n>0)
		cout <<endl<< "�û������������,"<< "������" << n << "���������" << endl;
	} while (n);
	cout <<endl<< "����ϵͳʧ��" << endl;
	system("pause");
}
void CWorker::Into()
{
	int i = 0;
	cout << "\t\t\t\t\t\t1���û�ע��" << endl;
	cout << "\t\t\t\t\t\t2������ϵͳ" << endl;
	cout << "\t\t\t\t\t\t0���˳�" << endl;
	cout << "��ѡ��";
	cin  >>i;
	switch (i)
	{
	case 1:
		CreateUser();
		break;
	case 2:
		Login();
		return;
	case 0:
		return;
	}
}
void CWorker::CreateUser()
{
	system("cls");
	
	cout << "��ѡ����\"�û�ע��\"" << endl;
	while (1)
	{
		SWorker data;
		char*s = data.sPasword;
		char temp[20] = { 0 };
		cout << "�������û�����";
		cin >> data.sName;
		if (SearchbyName(data.sName)||!strcmp(data.sName,Super.sName))
		{
			cout << "�û����Ѵ���,����������"<<endl;
			continue;
		}
		cout << "����������:";
		while (( *s= _getch()) != '\r')
		{			putchar('*');
			s++;
		}
		*s = 0;
		cout <<endl<< "���ٴ��������룺";
		int i = 0;
		for (; (temp[i] = _getch()) != '\r'; i++)
			putchar('*');
		temp[i] = 0;
		if (!strcmp(temp,data.sPasword))
		{
			data.nNumb = 1000 + m_list.m_nCount + 1;
			m_list.AddTail(data);
			cout<<endl << "ע��ɹ�"<<endl;
			system("pause");
			User = data;
			Main();
			break;
		}
		cout << endl<<"������������벻ͬ" << endl;
	}
}