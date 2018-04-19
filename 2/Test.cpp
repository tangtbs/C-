#include "Test.h"



CTest::CTest()
{
}


CTest::~CTest()
{
}


 //类内主函数
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
			cout << "输入错误" << endl;
			break;

		}
	}
	return 0;
}


// //主菜单
int CTest::Menu()
{
	int n = 0;
	cout << "1、浏览员工信息" << endl;
	cout << "2、添加员工信息" << endl;
	cout << "3、删除员工信息" << endl;
	cout << "4、修改员工信息" << endl;
	cout << "5、查找员工信息" << endl;
	cout << "0、退出管理系统" << endl;
	cout << "请选择：";
	cin >> n;
	return n;
}


// //浏览
void CTest::Browse()
{
	cout << "你选择了\"浏览员工信息\"" << endl;
	PrintAll();
}


void CTest::PrintAll()
{
	Clist& list = Select();
	if (!m_list.GetCount())
	{
		cout << "系统中无数据记录" << endl;
		return;
	}
	POSITION pos = m_list.GetHeadPosition();
	cout << "姓名\t" << "工号\t" << "工资" << endl << endl;
	cout << m_list.GetHead().sName << "\t" << m_list.GetHead().nNumb << "\t" << m_list.GetHead().fSala << endl;
	for (int i = 1; i < m_list.GetCount(); i++)
	{
		SWorker data = m_list.GetNext(pos);
		cout << data.sName << "\t" << data.nNumb << "\t" << data.fSala << endl;
	}


	system("pause");
}


// //选择哪个链表
Clist& CTest::Select()
{
	int n = 0;
	cout << "1、对m_list1操作" << endl;
	cout << "2、对m_list2操作" << endl;
	cout << "0、放弃本次操作" << endl;
	cout << "请选择：";
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
