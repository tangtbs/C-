#define _CRT_SECURE_NO_WARNINGS
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
	cout << "��ѡ����\"���Ա����Ϣ\"" << endl;
	while (n = BrowseMenu())
	{
		system("cls");
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


void CWorker::PrintAll(const SWorker *p)
{

	if (!p)
	{
		cout << "ϵͳ�������ݼ�¼" << endl;
		system("pause");
		return;
	}
	cout << "\t\t\t\t\t\t����\t" << "����\t" << "����" << endl << endl;
	for (int i = 0; i<(int)m_list.size(); i++)
	{
		cout << "\t\t\t\t\t\t" << p[i].sName << "\t" << p[i].nNumb << "\t" << p[i].fSala << endl;
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
	cout << "��ѡ����\"���Ա����Ϣ\"" << endl;
	Add();
}


void CWorker::Add()
{
	SWorker data[20];
	int i = 0;
	cout << "����������" << endl;
	cout << "\t\t\t\t\t\t����\t����\t����\tȨ��" << endl << endl;
	do
	{
		cout << "\t\t\t\t\t\t";
		/*cin >> data[i].sName >> data[i].nNumb >> data[i].fSala >> data[i].bPower;*/
		scanf_s("%s%d%f%d", data[i].sName, 20, &data[i].nNumb, &data[i].fSala, &data[i].bPower);
		i++;
		cout << endl << "�Ƿ������Y/N��";
		cout << endl;
	} while (toupper(_getch()) == 'Y');
	cout << "ȷ�����������Ϣ�𣿣�Y/N��" << endl;
	if (toupper(_getch()) == 'Y')
	{
		for (int j = 0; j < i; j++)
			m_list.emplace_back(data[j]);
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
	int Index = SearchbyNumb(n);
	if (Index == -1)
	{
		cout << "����Ϣ������" << endl;
		system("pause");
		return;
	}
	Printone(Index);
	cout << "ȷ��Ҫɾ������������?(Y/N)" << endl;
	if (toupper(_getch()) == 'Y')
	{
		m_list.erase(m_list.begin()+Index);
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
	int Index = SearchbyNumb(numb);
	if (Index == -1)
	{
		cout << "����Ϣ������" << endl;
		system("pause");
		return;
	}
	Printone(Index);
	system("pause");
	return;
}


void CWorker::Printone(int Index)
{
	SWorker& data = m_list.at(Index);
	cout << "\t\t\t\t\t\t����\t����\t����" << endl << endl;
	cout << "\t\t\t\t\t\t" << data.sName << "\t" << data.nNumb << "\t" << data.fSala << endl;
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
	int Index = SearchbyNumb(numb);
	if (Index == -1)
	{
		cout << "����Ϣ������" << endl;
		system("pause");
		return;
	}
	SWorker& data = m_list.at(Index);
	Printone(Index);
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
	cout << "��ѡ�����޸�����" << endl;
	cout << "������ԭʼ����:";
	if (!strcmp(User.sName, "root"))
	{
		RootPassword();
		return;
	}
	int n = 5;
	int  Index = SearchbyName(User.sName);
	do
	{
		char s[20] = { 0 };
		PasswordInput(s);
		if (!strcmp(m_list.at(Index).sPasword, s))
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
			strcpy(m_list.at(Index).sPasword, s1);
			break;
		}
		cout << endl << "������������벻һ��" << endl;
	}
	cout << endl << "�޸ĳɹ�" << endl;
	system("pause");
}

SWorker* CWorker::Sort(int n)
{
	if (m_list.size() == 0)
		return NULL;

	SWorker* p = new SWorker[m_list.size()];
	for (int i = 0; i <(int)m_list.size(); i++)
		p[i] = m_list.at(i);
	for (int i = 0; i<(int)m_list.size() - 1; i++)
		for (int j = 0; j <(int)m_list.size() - i - 1; j++)
			if (Sortby(p[j], p[j + 1], n)> 0)
			{
				SWorker temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
	return p;
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


int CWorker::SearchbyNumb(int numb)
{
	for (int i = 0; i < (int)m_list.size(); i++)
		if (m_list.at(i).nNumb == numb)
			return i;
	return -1;
}

int CWorker::SearchbyName(char * s)
{

	for (int i = 0; i < (int)m_list.size(); i++)
		if (!strcmp(m_list.at(i).sName, s))
			return i;
	return -1;
}

// ����
void CWorker::Save()
{
	FILE* fp = fopen("Worker.tb", "w");
	if (!fp)
	{
		cout << "���ļ�ʧ��" << endl;
		system("pause");
		return;
	}
	for (int i = 0; i<(int)m_list.size(); i++)
		fwrite(&m_list.at(i), sizeof(SWorker), 1, fp);
	fclose(fp);
	FILE* fp1 = fopen("su.r", "w");
	if (!fp1)
	{
		cout << "���ļ�\"su.r\"ʧ��" << endl;
		system("pause");
		return;
	}
	fwrite(Super.sPasword, 20, 1, fp1);
	fclose(fp1);
}

//����
void CWorker::Load()
{
	FILE*fp1 = fopen("su.r", "r");
	if (!fp1)
	{
		cout << "��ȡ�ļ�ʧ��" << endl;
		system("pause");
		return;
	}
	fread(Super.sPasword, 20, 1, fp1);
	fclose(fp1);
	FILE* fp = fopen("Worker.tb", "r");
	if (!fp)
		return;
	int MAX = 100;
	SWorker*p = new SWorker[MAX];
	int i = 0;
	for (; fread(&p[i], sizeof(SWorker), 1, fp) == 1; i++)
		if (i == MAX - 1)
		{
			SWorker* pN = new SWorker[2 * MAX];
			memcpy(pN, p, MAX);
			p = pN;
			MAX = 2 * MAX;
		}
	for (int j = 0; j < i; j++)
		m_list.emplace_back(p[j]);
	fclose(fp);
}

//����
void CWorker::Login()
{
	int n = 3;
	char name[20] = { 0 };
	char password[20] = { 0 };
	int Index;
	cout << "��ѡ����\"����ϵͳ\"" << endl;
	do {

		cout << "User:";
		cin >> name;
		cout << "password:";
		PasswordInput(password);
		Index = SearchbyName(name);
		if (Index != -1 && !strcmp(m_list.at(Index).sPasword, password) || !strcmp(name, Super.sName) && !strcmp(password, Super.sPasword))
		{
			if (Index != -1)
				User = m_list.at(Index);
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

	cout << "��ѡ����\"�û�ע��\"" << endl;
	while (1)
	{
		SWorker data;
		char*s = data.sPasword;
		char temp[20] = { 0 };
		cout << "�������û�����";
		cin >> data.sName;
		if (SearchbyName(data.sName) != -1 || !strcmp(data.sName, Super.sName))
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
			m_list.emplace_back(data);
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