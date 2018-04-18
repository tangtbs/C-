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
			Find();
			break;
		default:
			cout << "�������"<<endl;
			break;

		}
	}
	return 0;
}


// //���˵�
int CWorker::Menu()
{
	int n = 0;
	cout << "1�����Ա����Ϣ" << endl;
	cout << "2�����Ա����Ϣ" << endl;
	cout << "3��ɾ��Ա����Ϣ" << endl;
	cout << "4���޸�Ա����Ϣ" << endl;
	cout << "5������Ա����Ϣ" << endl;
	cout << "0���˳�����ϵͳ" << endl;
	cout << "��ѡ��";
	cin >> n;
	return n;
}


// ���
void CWorker::Browse()
{
	cout << "��ѡ����\"���Ա����Ϣ\"" << endl;
	PrintAll();
}


void CWorker::PrintAll()
{

	if (!m_list.GetCount())
	{
		cout << "ϵͳ�������ݼ�¼" << endl;
		return;
	}
	POSITION pos = m_list.GetHeadPosition();
	cout << "����\t" << "����\t" << "����" << endl << endl;
	cout << m_list.GetHead().sName << "\t" << m_list.GetHead().nNumb << "\t" << m_list.GetHead().fSala << endl;
	for (int i = 1; i < m_list.GetCount(); i++)
	{ 
		SWorker data=m_list.GetNext(pos);
		cout << data.sName << "\t" << data.nNumb << "\t" << data.fSala << endl;
	}
		
		
	system("pause");
}


//�������
void CWorker::Input()
{
	int n = 0;
	cout << "��ѡ����\"���Ա����Ϣ\"" << endl;
	cout << "1����ͷ�����" << endl;
	cout << "2����β�����" << endl;
	cout << "0���������˵�" << endl;
	cout << "��ѡ��";
	cin >> n;
	if (!n)
		return;
	Add(n);
}


void CWorker::Add(int n)
{
	SWorker data[20] = { 0 };
	int i = 0;
	cout << "����������"<< endl;
	cout << "����\t" << "����\t" << "����" << endl << endl;
	do 
	{
		cin >> data[i].sName >> data[i].nNumb >> data[i].fSala;
		i++;
		cout << "�Ƿ������Y/N��"<<endl;
	} while (toupper(_getch()) == 'Y');
	cout << "ȷ�����������Ϣ�𣿣�Y/N��" << endl;
	if (toupper(_getch()) == 'Y')
	{
		if(n==1)
		   for (int j = 0; j < i; j++ )
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
	int n;
	cout << "��ѡ����\"ɾ������\"" << endl;
	cout << "������Ҫɾ���Ĺ��ţ�" << endl;
	cin >> n;
	POSITION pos = m_list.FindIndex(n - 10000);
	SWorker data = m_list.GetAt(pos);
	Printone(data);
	cout << "ȷ��Ҫɾ������������?(Y/N)" << endl;
	if (toupper(_getch()) == 'Y')
	{
		m_list.RemoveAt(pos);
		cout << "ɾ���ɹ�" << endl;
	}
	else
		cout << "ɾ��ʧ��" << endl;

}


//��������
void CWorker::Find()
{
	SWorker data = { 0 };
	cout << "��ѡ����\"��������\"" << endl;
	cout << "�����빤�ţ�";
	cin >> data.nNumb;
	data=m_list.GetAt(m_list.FindIndex(data.nNumb-10000));
	Printone(data);
	return;
}


void CWorker::Printone(const SWorker& data)
{
	cout << "����\t" << "����\t" << "����" << endl << endl;
	cout << data.sName << "\t" << data.nNumb << "\t" << data.fSala << endl;
}


// �޸�����
void CWorker::Modify()
{
	int numb = 0;
	cout << "��ѡ����\"�޸�����\"" << endl;
	cout << "������һ�����ţ�" << endl;
	POSITION pos = m_list.FindIndex(numb-10000);
	SWorker data=m_list.GetAt(pos);
	Printone(data);
	cout << "ȷ���޸�������Ϣ��(Y/N)";
	if (toupper(_getch()) == 'Y')
	{
		cout << "�������µĹ���";
		cin >> data.nNumb;
		cout << "�������µ�����";
		cin >> data.sName;
		cout << "�������µ�н��";
		cin >> data.fSala;
		m_list.SetAt(pos, data);
		cout << "�޸ĳɹ�" << endl;
	}
	else
		cout << "�޸�ʧ��" << endl;

}
