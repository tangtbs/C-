#include "Worker.h"
CWorker::CWorker()
{
	Super.bPower = true;
	strcpy(Super.sName, "root");
	strcpy(Super.sPasword, "root");
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
	cout << "\t\t\t\t\t\t��ǰ�û���" << User.sName << "��" << endl;
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
	bool(*pFun[3])(SWorker&, SWorker&) = {SortbyNumb,SortbyName,SortbySala};
	cout << "��ѡ����\"���Ա����Ϣ\"" << endl;
	while (n = BrowseMenu())
	{
		switch (n)
		{
		case 1:
		case 2:
		case 3:
			m_list.sort(pFun[n - 1]);
			PrintAll();
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


void CWorker::PrintAll( )
{
	int size = m_list.size();
	list<SWorker>::iterator it = m_list.begin();
	if (!size)
	{
		cout << "ϵͳ�������ݼ�¼" << endl;
		return;
	}
	cout << "\t\t\t\t\t\t����\t" << "����\t" << "����" << endl << endl;
	while (size--)
	{
		cout << "\t\t\t\t\t\t" << it->sName << "\t" << it->nNumb << "\t" << it->fSala << endl;
		it++;
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
		if (i)
			getchar();
		cout << "\t\t\t\t\t\t";
		cin >> data[i].sName >> data[i].nNumb >> data[i].fSala >> data[i].bPower;
		i++;
		cout << "�Ƿ������Y/N��" << endl;
	} while (toupper(_getch()) == 'Y');
	cout << "ȷ�����������Ϣ�𣿣�Y/N��" << endl;
	if (toupper(_getch()) == 'Y')
	{
		if (n == 1)
			for (int j = 0; j < i; j++)
				m_list.push_front(data[j]);

		if (n == 2)
			for (int j = 0; j < i; j++)
				m_list.push_back(data[j]);

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
	list<SWorker>::iterator it;
    SearchbyNumb(n,it);
	if (it==m_list.end())
	{
		cout << "����Ϣ������" << endl;
		system("pause");
		return;
	}
	Printone(it);
	cout << "ȷ��Ҫɾ������������?(Y/N)" << endl;
	if (toupper(_getch()) == 'Y')
	{
		m_list.erase(it);
		cout << "ɾ���ɹ�" << endl;
	}
	else
		cout << "ɾ��ʧ��" << endl;
	system("pause");

}

//bool CWorker::RemoveIf(const SWorker& data)
//{
//	/*int numb = 0;
//	cout << "������Ҫɾ���Ĺ���:";
//	cin >> numb;*/
//	return data.nNumb == 1001;
//}


//��������
void CWorker::Search()
{
	system("cls");
	int numb = 0;
	cout << "��ѡ����\"��������\"" << endl;
	cout << "�����빤�ţ�";
	cin >> numb;
	list<SWorker>::iterator it;
	SearchbyNumb(numb,it);
	if (it==m_list.end())
	{
		cout << "����Ϣ������" << endl;
		system("pause");
		return;
	}
	Printone(it);
	system("pause");
	return;
}


void CWorker::Printone(const list<SWorker>::iterator& it)
{
	cout << "\t\t\t\t\t\t����\t����\t����" << endl << endl;
	cout << "\t\t\t\t\t\t" << it->sName << "\t" << it->nNumb << "\t" << it->fSala << endl;
}


// �޸�����
void CWorker::Modify()
{
	system("cls");
	if (User.bPower == false)
	{
		cout << "��û���޸�Ȩ��" << endl;
		system("pause");
		return;
	}
	int numb = 0;
	cout << "��ѡ����\"�޸�����\"" << endl;
	cout << "������һ�����ţ�" << endl;
	cin >> numb;
	list<SWorker>::iterator it;
	SearchbyNumb(numb,it);
	if (it==m_list.end())
	{
		cout << "����Ϣ������" << endl;
		system("pause");
		return;
	}
	Printone(it);
	cout << "ȷ���޸�������Ϣ��(Y/N)";
	if (toupper(_getch()) == 'Y')
	{
		getchar();
		cout << endl;
		cout << "�������µĹ���:";
		cin >> it->nNumb;
		cout << "�������µ�����:";
		cin >> it->sName;
		cout << "�������µ�н��:";
		cin >> it->fSala;
		cout << "�Ƿ�Ϊ���û���ӹ���ԱȨ�ޣ�Y/N����";
		toupper(_getch()) == 'Y' ? it->bPower = true : false;
		cout << endl << "�޸ĳɹ�" << endl;
	}
	else
		cout << endl << "�޸�ʧ��" << endl;
	system("pause");

}

//�޸�����
void CWorker::Password()
{
	system("cls");
	int n = 5;
	cout << "��ѡ�����޸�����" << endl;
	cout << "������ԭʼ����:";
	if (!strcmp(User.sName, "root"))
	{
		RootPassword();
		return;
	}
	list<SWorker>::iterator it;
	SearchbyName(User.sName,it);
	do
	{
		
		char s[20] = { 0 };
		PasswordInput(s);
		if (!strcmp(it->sPasword, s))
			break;
		cout << endl << "����������������룺";
	} while (n--);
	if (n<0)
	{
		cout << "�޸�ʧ��" << endl;
		system("pause");
		return;
	}
	while (1)
	{
		char s1[20] = { 0 };
		char s2[20] = { 0 };
		cout << endl << "�������µ�����:";
		PasswordInput(s1);
		cout << endl << "���ٴ���������:";
		PasswordInput(s2);
		if (!strcmp(s1, s2))
		{
			strcpy(it->sPasword, s1);
			break;
		}
		cout << endl << "������������벻һ��" << endl;
	}
	cout << endl << "�޸ĳɹ�" << endl;
	system("pause");
}


bool CWorker::SortbyNumb(SWorker&m1, SWorker&m2)
{
	return m1.nNumb - m2.nNumb<=0;
}

bool CWorker::SortbyName(SWorker&m1, SWorker&m2)
{
	
	return strcmp(m1.sName, m2.sName)<=0;
}

bool CWorker::SortbySala(SWorker&m1, SWorker&m2)
{
	return m1.fSala - m2.fSala >0;
}

void  CWorker::SearchbyNumb(int numb,list<SWorker>::iterator& it)
{
     it = m_list.begin();
	list<SWorker>::iterator it_end = m_list.end();
	while(it!=it_end)
	{
		if (it->nNumb == numb)
			return;
		it++;
	}
}

void CWorker::SearchbyName(char * s, list<SWorker>::iterator& it)
{

	it = m_list.begin();
	list<SWorker>::iterator it_end = m_list.end();
	while(it!=it_end)
	{
		if (!strcmp(it->sName, s))
			return ;
		it++;
	}
}

// ����
void CWorker::Save()
{
	FILE* fp = fopen("Worker.tb", "w");
	if (!fp)
	{
		cout << "�����ļ�ʧ��" << endl;
		system("pause");
		return;
	}
	fwrite(Super.sPasword,20,1,fp);
	list<SWorker>::iterator it_end = m_list.end();
	list<SWorker>::iterator it = m_list.begin();
	while (it!=it_end)
		fwrite(&*it++,sizeof(SWorker),1,fp);
	fclose(fp);
}

//����
void CWorker::Load()
{
	FILE* fp = fopen("Worker.tb", "r");
	if (!fp)
	{
		cout << "�����ļ�ʧ��" << endl;
		system("pause");		
		return;
	}
	fread(Super.sPasword, 20, 1, fp);
	fseek(fp,0L,SEEK_END);
	int size = (ftell(fp)-20) / sizeof(SWorker);
	fseek(fp,20L,SEEK_SET);
	m_list.resize(size);
	list<SWorker>::iterator it = m_list.begin();
	while(size--)
	fread(&*it++,sizeof(SWorker),1,fp);
	fclose(fp);
}

//����
void CWorker::Login()
{
	int n = 3;
	char name[20] = { 0 };
	char password[20] = { 0 };
	list<SWorker>::iterator it = m_list.begin();
	cout << "��ѡ����\"����ϵͳ\"" << endl;
	do {

		cout << "User:";
		cin >> name;
		cout << "password:";
		PasswordInput(password);
		SearchbyName(name,it);
		if (it!=m_list.end() && !strcmp(it->sPasword, password) || !strcmp(name, Super.sName) && !strcmp(password, Super.sPasword))
		{
			if (it != m_list.end())
				User = *it;
			else
				User = Super;
			cout << endl << "����ɹ�" << endl;
			system("pause");
			Main();
			return;
		}
		if (--n>0)
			cout << endl << "�û������������," << "������" << n << "���������" << endl;
	} while (n);
	cout << endl << "����ϵͳʧ��" << endl;
	system("pause");
}
void CWorker::Into()
{
	int i = 0;
	cout << "\t\t\t\t\t\t1���û�ע��" << endl;
	cout << "\t\t\t\t\t\t2������ϵͳ" << endl;
	cout << "\t\t\t\t\t\t0���˳�" << endl;
	cout << "��ѡ��";
	cin >> i;
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
	list<SWorker>::iterator it;
	cout << "��ѡ����\"�û�ע��\"" << endl;
	while (1)
	{
		SWorker data;
		char*s = data.sPasword;
		char temp[20] = { 0 };
		cout << "�������û�����";
		cin >> data.sName;
		SearchbyName(data.sName, it);
		if (it!=m_list.end()|| !strcmp(data.sName, Super.sName))
		{
			cout << "�û����Ѵ���,����������" << endl;
			continue;
		}
		cout << "����������:";
		PasswordInput(s);
		cout << endl << "���ٴ��������룺";
		PasswordInput(temp);
		if (!strcmp(temp, data.sPasword))
		{
			data.nNumb = 1000 + m_list.size() + 1;
			m_list.push_back(data);
			cout << endl << "ע��ɹ�" << endl;
			system("pause");
			User = data;
			Main();
			break;
		}
		cout << endl << "������������벻ͬ" << endl;
	}
}

// ��������
void CWorker::PasswordInput(char* password)
{
	int i = 0;
	char c;
	while ((c = _getch()) != '\r')
	{
		if (c == '\b')
		{
			putchar('\b');
			putchar(' ');
			putchar('\b');
			i--;
			continue;
		}
		putchar('*');
		password[i++] = c;
	}
	password[i] = 0;
}


void CWorker::RootPassword()
{
	int n = 5;
	do
	{
		char s[20] = { 0 };
		PasswordInput(s);
		if (!strcmp(User.sPasword, s))
			break;
		cout << endl << "����������������룺";
	} while (n--);
	if (n<0)
	{
		cout << "�޸�ʧ��" << endl;
		system("pause");
		return;
	}
	while (1)
	{
		char s1[20] = { 0 };
		char s2[20] = { 0 };
		cout << endl << "�������µ�����:";
		PasswordInput(s1);
		cout << endl << "���ٴ���������:";
		PasswordInput(s2);
		if (!strcmp(s1, s2))
		{
			strcpy(Super.sPasword, s1);
			break;
		}
		cout << endl << "������������벻һ��" << endl;
	}
	cout << endl << "�޸ĳɹ�" << endl;
	system("pause");
}