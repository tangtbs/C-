#include "Test.h"



CTest::CTest()
{
}


CTest::~CTest()
{
}


 //����������
int CTest::Main()
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
			cout << "�������" << endl;
			break;

		}
	}
	return 0;
}


// //���˵�
int CTest::Menu()
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


// //���
void CTest::Browse()
{
	cout << "��ѡ����\"���Ա����Ϣ\"" << endl;
	PrintAll();
}


void CTest::PrintAll()
{
	Clist& list = Select();
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
		SWorker data = m_list.GetNext(pos);
		cout << data.sName << "\t" << data.nNumb << "\t" << data.fSala << endl;
	}


	system("pause");
}


// //ѡ���ĸ�����
Clist& CTest::Select()
{
	int n = 0;
	cout << "1����m_list1����" << endl;
	cout << "2����m_list2����" << endl;
	cout << "0���������β���" << endl;
	cout << "��ѡ��";
	switch (n)
	{
	case 1:
		return m_list1;
	case 2:
		return m_list2;
	case 0:
		return ;
	}
}
