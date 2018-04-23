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
			Search();
			break;
		case 6:
			Password();
			break;
		default:
			cout << "输入错误" << endl;
			break;

		}
	}
	Save();
	return 0;
}


// //主菜单
int CWorker::Menu()
{
	system("cls");
	int n = 0;
	cout << "\t\t\t\t\t\t员工信息管理系统" << endl << endl;
	cout << "\t\t\t\t\t\t1、浏览员工信息" << endl;
	cout << "\t\t\t\t\t\t2、添加员工信息" << endl;
	cout << "\t\t\t\t\t\t3、删除员工信息" << endl;
	cout << "\t\t\t\t\t\t4、修改员工信息" << endl;
	cout << "\t\t\t\t\t\t5、查找员工信息" << endl;
	cout << "\t\t\t\t\t\t6、修改登录密码" << endl;
	cout << "\t\t\t\t\t\t0、退出管理系统" << endl;
	cout << "请选择：";
	cin >> n;
	return n;
}


// 浏览
void CWorker::Browse()
{
	system("cls");
	int n = 0;
	cout << "你选择了\"浏览员工信息\"" << endl;
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
			cout << "输入错误" << endl;
		}
	}
}

int CWorker::BrowseMenu()
{
	int n = 0;
	cout << "\t\t\t\t\t\t1、按工号浏览" << endl;
	cout << "\t\t\t\t\t\t2、按姓名浏览" << endl;
	cout << "\t\t\t\t\t\t3、按工资浏览" << endl;
	cout << "\t\t\t\t\t\t0、返回主菜单" << endl;
	cout << "请选择：";
	cin >> n;
	return n;
}


void CWorker::PrintAll(SWorker**pp)
{

	if (!pp)
	{
		cout << "系统中无数据记录" << endl;
		return;
	}
	cout << "\t\t\t\t\t\t姓名\t" << "工号\t" << "工资" << endl << endl;
	while (*pp)
	{
		cout<<"\t\t\t\t\t\t" << (*pp)->sName << "\t" << (*pp)->nNumb << "\t" << (*pp)->fSala << endl;
		pp++;
	}
	system("pause");
}


//添加数据
void CWorker::Input()
{
	system("cls");
	if (User.bPower == false)
	{
		cout << "你没有添加权限" << endl;
		system("pause");
		return;
	}
		
	int n = 0;
	cout << "你选择了\"添加员工信息\"" << endl;
	cout << "\t\t\t\t\t\t1、从头部添加" << endl;
	cout << "\t\t\t\t\t\t2、从尾部添加" << endl;
	cout << "\t\t\t\t\t\t0、返回主菜单" << endl;
	cout << "请选择：";
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
	cout << "请依次输入" << endl;
	cout << "\t\t\t\t\t\t姓名\t工号\t工资\t权限" << endl << endl;
	do
	{
		cout<<"\t\t\t\t\t\t";
		cin >> data[i].sName >> data[i].nNumb >> data[i].fSala>>data[i].bPower;
		i++;
		cout << "是否继续（Y/N）";
	} while (toupper(_getch()) == 'Y');
	cout << "确定添加以上信息吗？（Y/N）"<<endl;
	if (toupper(_getch()) == 'Y')
	{
		if (n == 1)
			for (int j = 0; j < i; j++)
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
	system("cls");
	if (User.bPower == false)
	{
		cout << "你没有删除权限" << endl;
		system("pause");
		return;
	}
	int n;
	cout << "你选择了\"删除数据\"" << endl;
	cout << "请输入要删除的工号：" << endl;
	cin >> n;
	POSITION pos = SearchbyNumb(n);
	if (!pos)
	{ 
		cout << "该信息不存在"<<endl;
		system("pause");
		return;
	}
	SWorker& data = m_list.GetAt(pos);
	Printone(data);
	cout << "确定要删除这条数据吗?(Y/N)" << endl;
	if (toupper(_getch()) == 'Y')
	{
		m_list.RemoveAt(pos);
		cout << "删除成功" << endl;
	}
	else
		cout << "删除失败" << endl;
	system("pause");

}


//查找数据
void CWorker::Search()
{
	system("cls");
	int numb = 0;
	cout << "你选择了\"查找数据\"" << endl;
	cout << "请输入工号：";
	cin >> numb;
	POSITION pos = SearchbyNumb(numb);
	if (!pos)
	{
		cout << "该信息不存在" << endl;
		system("pause");
		return;
	}
	SWorker& data = m_list.GetAt(pos);
	Printone(data);
	return;
}


void CWorker::Printone(const SWorker& data)
{
	cout << "\t\t\t\t\t\t姓名\t工号\t工资" << endl << endl;
	cout <<"\t\t\t\t\t\t"<< data.sName << "\t" << data.nNumb << "\t" << data.fSala << endl;
}


// 修改数据
void CWorker::Modify()
{
	system("cls");
	if (User.bPower==false)
	{
		cout << "你没有修改权限" << endl;
		system("pause");
		return;
	}
	int numb = 0;
	cout << "你选择了\"修改数据\"" << endl;
	cout << "请输入一个工号：" << endl;
	cin >> numb;
	POSITION pos = SearchbyNumb(numb);
	if (!pos)
	{
		cout << "该信息不存在" << endl;
		system("pause");
		return;
	}
	SWorker& data = m_list.GetAt(pos);
	Printone(data);
	cout << "确定修改以上信息吗？(Y/N)";
	if (toupper(_getch()) == 'Y')
	{
		cout << endl;
		cout << "请输入新的工号:";
		cin >> data.nNumb;
		cout << "请输入新的姓名:";
		cin >> data.sName;
		cout << "请输入新的薪资:";
		cin >> data.fSala;
		cout << "是否为该用户添加管理员权限（Y/N）？";
		toupper(_getch()) == 'Y' ? data.bPower = true : false;
		cout<<endl<< "修改成功" << endl;
	}
	else
		cout <<endl<< "修改失败" << endl;
	system("pause");

}

//修改密码
void CWorker::Password()
{
	system("cls");
	int n = 5;
	Clist<SWorker>::SNode*p = (Clist<SWorker>::SNode*)SearchbyName(User.sName);
	if (!p)
	{
		cout << "root用户密码不能在此修改" << endl;
		system("pause");
		return;
	}
	cout << "你选择了修改密码" << endl;
	cout << "请输入原始密码:";
	do
	{
		char s[20] = { 0 };
		int i = 0;
		for (; (s[i] = _getch()) != '\r'; i++)
			putchar('*');
		s[i] = 0;
		if (!strcmp(p->data.sPasword, s))
			break;
		cout << endl<<"密码错误，请重新输入：";
	} while (n--);
	if(n<0)
	{
		cout << "修改失败" << endl;
		system("pause");
		return;
	}
	while(1)
	{
		char s1[20] = { 0 };
		char s2[20] = { 0 };
	    cout << endl<<"请输入新的密码:";
		int i = 0;
		for (; (s1[i] = _getch()) != '\r'; i++)
			putchar('*');
		s1[i] = 0;
	    cout << endl<<"请再次输入密码:" ;
		int j = 0;
		for (; (s2[j] = _getch()) != '\r'; j++)
			putchar('*');
		s2[j] = 0;
		if (!strcmp(s1, s2))
		{
			strcpy(p->data.sPasword, s1);
			break;
		}
		cout <<endl<< "两次输入的密码不一致" << endl;
	}
	cout << "修改成功" << endl;
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

// 保存
void CWorker::Save()
{
	FILE* fp =fopen("Worker.tb","w");
	if (!fp)
	{
		cout << "打开文件失败" << endl;
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

//加载
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

//登入
void CWorker::Login()
{
	int n = 3;
	char name[20] = { 0 };
	char password[20] = { 0 };
	Clist<SWorker>::SNode*p;
	cout << "你选择了\"登入系统\"" << endl;
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
		cout<<endl << "登入成功" << endl;
		system("pause");
		Main();
		return;
	}
	if(--n>0)
		cout <<endl<< "用户名或密码错误,"<< "您还有" << n << "次输入机会" << endl;
	} while (n);
	cout <<endl<< "登入系统失败" << endl;
	system("pause");
}
void CWorker::Into()
{
	int i = 0;
	cout << "\t\t\t\t\t\t1、用户注册" << endl;
	cout << "\t\t\t\t\t\t2、登入系统" << endl;
	cout << "\t\t\t\t\t\t0、退出" << endl;
	cout << "请选择：";
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
	
	cout << "你选择了\"用户注册\"" << endl;
	while (1)
	{
		SWorker data;
		char*s = data.sPasword;
		char temp[20] = { 0 };
		cout << "请输入用户名：";
		cin >> data.sName;
		if (SearchbyName(data.sName)||!strcmp(data.sName,Super.sName))
		{
			cout << "用户名已存在,请重新输入"<<endl;
			continue;
		}
		cout << "请输入密码:";
		while (( *s= _getch()) != '\r')
		{			putchar('*');
			s++;
		}
		*s = 0;
		cout <<endl<< "请再次输入密码：";
		int i = 0;
		for (; (temp[i] = _getch()) != '\r'; i++)
			putchar('*');
		temp[i] = 0;
		if (!strcmp(temp,data.sPasword))
		{
			data.nNumb = 1000 + m_list.m_nCount + 1;
			m_list.AddTail(data);
			cout<<endl << "注册成功"<<endl;
			system("pause");
			User = data;
			Main();
			break;
		}
		cout << endl<<"两次输入的密码不同" << endl;
	}
}