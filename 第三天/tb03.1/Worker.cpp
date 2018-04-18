#include "Worker.h"



CWorker::CWorker()
{
}


CWorker::~CWorker()
{
}


// 类CWorker内的Main函数
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
			cout << "输入错误"<<endl;
			break;

		}
	}
	return 0;
}


// //主菜单
int CWorker::Menu()
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


// 浏览
void CWorker::Browse()
{
	cout << "你选择了\"浏览员工信息\"" << endl;
	PrintAll();
}


void CWorker::PrintAll()
{

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
		SWorker data=m_list.GetNext(pos);
		cout << data.sName << "\t" << data.nNumb << "\t" << data.fSala << endl;
	}
		
		
	system("pause");
}


//添加数据
void CWorker::Input()
{
	int n = 0;
	cout << "你选择了\"添加员工信息\"" << endl;
	cout << "1、从头部添加" << endl;
	cout << "2、从尾部添加" << endl;
	cout << "0、返回主菜单" << endl;
	cout << "请选择：";
	cin >> n;
	if (!n)
		return;
	Add(n);
}


void CWorker::Add(int n)
{
	SWorker data[20] = { 0 };
	int i = 0;
	cout << "请依次输入"<< endl;
	cout << "姓名\t" << "工号\t" << "工资" << endl << endl;
	do 
	{
		cin >> data[i].sName >> data[i].nNumb >> data[i].fSala;
		i++;
		cout << "是否继续（Y/N）"<<endl;
	} while (toupper(_getch()) == 'Y');
	cout << "确定添加以上信息吗？（Y/N）" << endl;
	if (toupper(_getch()) == 'Y')
	{
		if(n==1)
		   for (int j = 0; j < i; j++ )
			    m_list.AddHead(data[j]);
				
		if (n == 2)
			for (int j = 0; j < i; j++)
				m_list.AddTail(data[j]);
				
		cout << "添加成功" << endl;
	}
	else
		cout << "添加失败" << endl;
	return;
}


 //删除数据
void CWorker::Delete()
{
	int n;
	cout << "你选择了\"删除数据\"" << endl;
	cout << "请输入要删除的工号：" << endl;
	cin >> n;
	POSITION pos = m_list.FindIndex(n - 10000);
	SWorker data = m_list.GetAt(pos);
	Printone(data);
	cout << "确定要删除这条数据吗?(Y/N)" << endl;
	if (toupper(_getch()) == 'Y')
	{
		m_list.RemoveAt(pos);
		cout << "删除成功" << endl;
	}
	else
		cout << "删除失败" << endl;

}


//查找数据
void CWorker::Find()
{
	SWorker data = { 0 };
	cout << "你选择了\"查找数据\"" << endl;
	cout << "请输入工号：";
	cin >> data.nNumb;
	data=m_list.GetAt(m_list.FindIndex(data.nNumb-10000));
	Printone(data);
	return;
}


void CWorker::Printone(const SWorker& data)
{
	cout << "姓名\t" << "工号\t" << "工资" << endl << endl;
	cout << data.sName << "\t" << data.nNumb << "\t" << data.fSala << endl;
}


// 修改数据
void CWorker::Modify()
{
	int numb = 0;
	cout << "你选择了\"修改数据\"" << endl;
	cout << "请输入一个工号：" << endl;
	POSITION pos = m_list.FindIndex(numb-10000);
	SWorker data=m_list.GetAt(pos);
	Printone(data);
	cout << "确定修改以上信息吗？(Y/N)";
	if (toupper(_getch()) == 'Y')
	{
		cout << "请输入新的工号";
		cin >> data.nNumb;
		cout << "请输入新的姓名";
		cin >> data.sName;
		cout << "请输入新的薪资";
		cin >> data.fSala;
		m_list.SetAt(pos, data);
		cout << "修改成功" << endl;
	}
	else
		cout << "修改失败" << endl;

}
