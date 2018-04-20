#include "Worker.h"
CWorker::CWorker()
{

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
		default:
			cout << "�������" << endl;
			break;

		}
	}
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
	SWorker data[20] = { 0 };
	int i = 0;
	cout << "����������" << endl;
	cout << "\t\t\t\t\t\t����\t����\t����" << endl << endl;
	do
	{
		cout<<"\t\t\t\t\t\t";
		cin >> data[i].sName >> data[i].nNumb >> data[i].fSala;
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
	system("pause");
}


// �޸�����
void CWorker::Modify()
{
	system("cls");
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
		cout << "�޸ĳɹ�" << endl;
	}
	else
		cout << "�޸�ʧ��" << endl;
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
