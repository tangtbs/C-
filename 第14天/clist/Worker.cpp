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
	cout << "\t\t\t\t\t\t当前用户【" << User.sName << "】" << endl;
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
	bool(*pFun[3])(SWorker&, SWorker&) = {SortbyNumb,SortbyName,SortbySala};
	cout << "你选择了\"浏览员工信息\"" << endl;
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


void CWorker::PrintAll( )
{
	int size = m_list.size();
	list<SWorker>::iterator it = m_list.begin();
	if (!size)
	{
		cout << "系统中无数据记录" << endl;
		return;
	}
	cout << "\t\t\t\t\t\t姓名\t" << "工号\t" << "工资" << endl << endl;
	while (size--)
	{
		cout << "\t\t\t\t\t\t" << it->sName << "\t" << it->nNumb << "\t" << it->fSala << endl;
		it++;
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
		if (i)
			getchar();
		cout << "\t\t\t\t\t\t";
		cin >> data[i].sName >> data[i].nNumb >> data[i].fSala >> data[i].bPower;
		i++;
		cout << "是否继续（Y/N）" << endl;
	} while (toupper(_getch()) == 'Y');
	cout << "确定添加以上信息吗？（Y/N）" << endl;
	if (toupper(_getch()) == 'Y')
	{
		if (n == 1)
			for (int j = 0; j < i; j++)
				m_list.push_front(data[j]);

		if (n == 2)
			for (int j = 0; j < i; j++)
				m_list.push_back(data[j]);

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
	list<SWorker>::iterator it;
    SearchbyNumb(n,it);
	if (it==m_list.end())
	{
		cout << "该信息不存在" << endl;
		system("pause");
		return;
	}
	Printone(it);
	cout << "确定要删除这条数据吗?(Y/N)" << endl;
	if (toupper(_getch()) == 'Y')
	{
		m_list.erase(it);
		cout << "删除成功" << endl;
	}
	else
		cout << "删除失败" << endl;
	system("pause");

}

//bool CWorker::RemoveIf(const SWorker& data)
//{
//	/*int numb = 0;
//	cout << "请输入要删除的工号:";
//	cin >> numb;*/
//	return data.nNumb == 1001;
//}


//查找数据
void CWorker::Search()
{
	system("cls");
	int numb = 0;
	cout << "你选择了\"查找数据\"" << endl;
	cout << "请输入工号：";
	cin >> numb;
	list<SWorker>::iterator it;
	SearchbyNumb(numb,it);
	if (it==m_list.end())
	{
		cout << "该信息不存在" << endl;
		system("pause");
		return;
	}
	Printone(it);
	system("pause");
	return;
}


void CWorker::Printone(const list<SWorker>::iterator& it)
{
	cout << "\t\t\t\t\t\t姓名\t工号\t工资" << endl << endl;
	cout << "\t\t\t\t\t\t" << it->sName << "\t" << it->nNumb << "\t" << it->fSala << endl;
}


// 修改数据
void CWorker::Modify()
{
	system("cls");
	if (User.bPower == false)
	{
		cout << "你没有修改权限" << endl;
		system("pause");
		return;
	}
	int numb = 0;
	cout << "你选择了\"修改数据\"" << endl;
	cout << "请输入一个工号：" << endl;
	cin >> numb;
	list<SWorker>::iterator it;
	SearchbyNumb(numb,it);
	if (it==m_list.end())
	{
		cout << "该信息不存在" << endl;
		system("pause");
		return;
	}
	Printone(it);
	cout << "确定修改以上信息吗？(Y/N)";
	if (toupper(_getch()) == 'Y')
	{
		getchar();
		cout << endl;
		cout << "请输入新的工号:";
		cin >> it->nNumb;
		cout << "请输入新的姓名:";
		cin >> it->sName;
		cout << "请输入新的薪资:";
		cin >> it->fSala;
		cout << "是否为该用户添加管理员权限（Y/N）？";
		toupper(_getch()) == 'Y' ? it->bPower = true : false;
		cout << endl << "修改成功" << endl;
	}
	else
		cout << endl << "修改失败" << endl;
	system("pause");

}

//修改密码
void CWorker::Password()
{
	system("cls");
	int n = 5;
	cout << "你选择了修改密码" << endl;
	cout << "请输入原始密码:";
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
		cout << endl << "密码错误，请重新输入：";
	} while (n--);
	if (n<0)
	{
		cout << "修改失败" << endl;
		system("pause");
		return;
	}
	while (1)
	{
		char s1[20] = { 0 };
		char s2[20] = { 0 };
		cout << endl << "请输入新的密码:";
		PasswordInput(s1);
		cout << endl << "请再次输入密码:";
		PasswordInput(s2);
		if (!strcmp(s1, s2))
		{
			strcpy(it->sPasword, s1);
			break;
		}
		cout << endl << "两次输入的密码不一致" << endl;
	}
	cout << endl << "修改成功" << endl;
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

// 保存
void CWorker::Save()
{
	FILE* fp = fopen("Worker.tb", "w");
	if (!fp)
	{
		cout << "保存文件失败" << endl;
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

//加载
void CWorker::Load()
{
	FILE* fp = fopen("Worker.tb", "r");
	if (!fp)
	{
		cout << "加载文件失败" << endl;
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

//登入
void CWorker::Login()
{
	int n = 3;
	char name[20] = { 0 };
	char password[20] = { 0 };
	list<SWorker>::iterator it = m_list.begin();
	cout << "你选择了\"登入系统\"" << endl;
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
			cout << endl << "登入成功" << endl;
			system("pause");
			Main();
			return;
		}
		if (--n>0)
			cout << endl << "用户名或密码错误," << "您还有" << n << "次输入机会" << endl;
	} while (n);
	cout << endl << "登入系统失败" << endl;
	system("pause");
}
void CWorker::Into()
{
	int i = 0;
	cout << "\t\t\t\t\t\t1、用户注册" << endl;
	cout << "\t\t\t\t\t\t2、登入系统" << endl;
	cout << "\t\t\t\t\t\t0、退出" << endl;
	cout << "请选择：";
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
	cout << "你选择了\"用户注册\"" << endl;
	while (1)
	{
		SWorker data;
		char*s = data.sPasword;
		char temp[20] = { 0 };
		cout << "请输入用户名：";
		cin >> data.sName;
		SearchbyName(data.sName, it);
		if (it!=m_list.end()|| !strcmp(data.sName, Super.sName))
		{
			cout << "用户名已存在,请重新输入" << endl;
			continue;
		}
		cout << "请输入密码:";
		PasswordInput(s);
		cout << endl << "请再次输入密码：";
		PasswordInput(temp);
		if (!strcmp(temp, data.sPasword))
		{
			data.nNumb = 1000 + m_list.size() + 1;
			m_list.push_back(data);
			cout << endl << "注册成功" << endl;
			system("pause");
			User = data;
			Main();
			break;
		}
		cout << endl << "两次输入的密码不同" << endl;
	}
}

// 密码输入
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
		cout << endl << "密码错误，请重新输入：";
	} while (n--);
	if (n<0)
	{
		cout << "修改失败" << endl;
		system("pause");
		return;
	}
	while (1)
	{
		char s1[20] = { 0 };
		char s2[20] = { 0 };
		cout << endl << "请输入新的密码:";
		PasswordInput(s1);
		cout << endl << "请再次输入密码:";
		PasswordInput(s2);
		if (!strcmp(s1, s2))
		{
			strcpy(Super.sPasword, s1);
			break;
		}
		cout << endl << "两次输入的密码不一致" << endl;
	}
	cout << endl << "修改成功" << endl;
	system("pause");
}