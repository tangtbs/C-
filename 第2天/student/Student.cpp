#include"Student.h"
int Student::Menu()
{
	system("cls");
	int i = 0;
	cout << endl;
	cout<<"\t\t\t\t\t\t学生信息管理系统"<<endl<<endl;
	cout<<"\t\t\t\t\t\t1、浏览学生信息"<<endl;
	cout<<"\t\t\t\t\t\t2、添加学生信息"<<endl;
	cout<<"\t\t\t\t\t\t3、删除学生信息"<<endl;
	cout<<"\t\t\t\t\t\t4、修改学生信息"<<endl;
	cout<<"\t\t\t\t\t\t5、查找学生信息"<<endl;
	cout<<"\t\t\t\t\t\t0、退出管理系统"<<endl;
	cout<<"请选择：";
	cin>>i;
	return i;
}
void Student::Browse()
{
	system("cls");
	SNode**p = NULL;
	int n = 0;
	cout<<"你选择了\"浏览学生信息\""<<endl;
	cout<<"请选择浏览方式"<<endl;
	while (n = BrowseMenu())
	{
		switch (n)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			/*p=Sortpoint(n);
			Printpoint(p);*/
			p = (*pl).QSortbypoint(n);
			(*pl).Printpoint(p);
			return;
		case 6:
			(*pl).Print();
			return;
		default:
			cout<<"输入错误"<<endl;
		}
	}
}
int Student::BrowseMenu()
{
	int i = 0;
	cout<<"\t\t\t\t\t\t1、按学号浏览"<<endl;
	cout<<"\t\t\t\t\t\t2、按姓名浏览"<<endl;
	cout<<"\t\t\t\t\t\t3、按数学成绩浏览"<<endl;
	cout<<"\t\t\t\t\t\t4、按语文成绩浏览"<<endl;
	cout<<"\t\t\t\t\t\t5、按英语成绩浏览"<<endl;
	cout<<"\t\t\t\t\t\t6、按默认顺序浏览"<<endl;
	cout<<"\t\t\t\t\t\t0、返回主菜单"<<endl;
	cin >> i;
	return i;
}
void Student::Add()
{
	system("cls");
	DATA t[20] = { 0 };
	DATA*temp = t;
	cout<<"你选择了添加数据"<<endl;
	cout<<"请选择添加方式"<<endl;
	int l = AddMenu();
	if (!l)
		return;
	cout<<"请输入";
	cout<<"\t\t\t\t\t\t";
	cout<<"姓名\t学号\t数学\t语文\t英语"<<endl<<endl;
	do
	{
		cout<<"\t\t\t\t\t\t";
		cin>>temp->sName>>temp->sNumb>>temp->fMath>>temp->fChin>>temp->fEngl;
		if ((*pl).Searchbystr(temp->sNumb))
			puts("该数据中的学号已存在，此条输入无效");
		temp++;
		cout<<"是否继续?(y/n)";
	} while (tolower(_getch()) == 'y');
	system("cls");
	cout<<"\t\t\t\t\t姓名\t学号\t数学\t语文\t英语\n"<<endl;
	int i = 0;
	while (*t[i].sNumb)
	{
		cout<<"\t\t\t\t\t"<< t[i].sName<<t[i].sNumb<<t[i].fMath<<t[i].fChin<<t[i].fEngl<<endl;
		i++;
	}
	cout<<endl<<endl<<"确定添加以上数据吗？（按'y'确认添加，其他键取消添加）"<<endl;
	if (toupper(_getch()) == 'Y')
	{
		if (l == 1)
		{
			while (i--)
				(*pl).AddHead(&t[i]);
			cout<<"添加成功"<<endl;
		}
		else
		{
			while (i--)
				(*pl).AddTail(&t[i]);
			cout<<"添加成功"<<endl;
		}
	}

	else
		cout<<"添加失败"<<endl;
	cout<<"按任意键继续";
	_getch();
}
int Student::AddMenu()
{
	int i = 0;
	cout<<"1、从头部添加"<<endl;
	cout << "2、从尾部添加" << endl;
	cout << "0、返回主菜单" << endl;
	cout<<"请选择：";
	cin >> i;
	while (i < 0 || i>2)
	{
		cout<<"无效输入，请重新选择:";
		cin >> i;
	}
	return i;
}
void Student::Delete()
{
	int n = DeleteMenu();
	switch (n)
	{
	case 1:
		DeleteAll();
		return;
	case 2:
		Deletesome();
		return;
	case 0:
		return;
	}

}
int Student::DeleteMenu()
{
	int n = 0;
	cout<<"你选择了\"删除数据\""<<endl;
	cout << "1、清除所有数据" << endl;
	cout << "2、删除部分数据" << endl;
	cout << "0、返回主菜单" << endl;
	cout << "请选择：";
	cin>>n;
	while (n > 2 || n < 0)
	{
		cout<<"无效输入，请重新选择：";
		cin>>n;
	}
	return n;
}
void Student::Deletesome()
{
	char s[20] = { 0 };
	cout<<"请输入要删除数据的学号或姓名"<<endl;
	cin >> s;
	SNode*p = (*pl).Searchbystr(s);
	if (!p)
	{
		cout<<"该数据不存在"<<endl;
		system("pause");
		return;
	}
	(*pl).Printone(p);
	cout<<endl<<"确定删除以上信息吗(按'y'确认删除，其他键取消删除)"<<endl;
	if (tolower(_getch()) == 'y')
	{
		(*pl).DeleteData(p);
		cout<<"删除成功"<<endl;
		system("pause");
		return;
	}
	cout<<"删除失败"<<endl;
	system("pause");
}
void Student::DeleteAll()
{
	cout<<"确定清除所有数据吗？(按'y'确认，按其他键取消)"<<endl;
	if (toupper(_getch()) == 'Y')
		(*pl).RemoveAll();
	cout<<"所有数据已被清除"<<endl;
	system("pause");
}
void Student::Modify()
{
	system("cls");
	DATA s = { 0 };
	cout<<"你选择了\"修改数据\""<<endl;
	cout<<"请输入要修改数据的姓名或学号"<<endl;
	cin>>s.sName;
	SNode* p = (*pl).Searchbystr(s.sName);
	if (!p)
	{
		cout<<"该数据不存在"<<endl;
		return;
	}
	cout<<"以下是要修改数据的详细信息"<<endl;
	cout<<"请依次输入数据"<<endl;
	(*pl).Printone(p);
	cout<<"\t\t\t\t\t\t";
	cin>>s.sName>>s.sNumb>>s.fMath>>s.fChin>>s.fEngl;
	cout<<endl<<"确定修改以上信息吗？（按'y'确认修改，其他键取消修改）"<<endl;
	if (tolower(_getch()) == 'y')
	{
		(*pl).ModifyData(p, &s);
		cout<<"修改成功"<<endl;
		system("pause");
		return;
	}
	cout<<"修改失败"<<endl;
	system("pause");
	return;
}
void Student::Find()
{
	int flag = 0;
	system("cls");
	cout<<"你选择了\"查找数据\""<<endl;
	int i = FindMenu();
	if (i == 1)
	{
		char t[20] = { 0 };
		SNode*p = (*pl).m_pHead;
		cout<<"请输入学号"<<endl;
		cin>>t;
		cout<<"\t\t\t\t\t\t";
		cout<<"姓名\t学号\t数学\t语文\t英语"<<endl;
		while (p)
		{
			if (strstr(p->data.sNumb, t))
			{
				flag = 1;
				cout<<"\t\t\t\t\t\t";
				cout<<p->data.sName<<p->data.sNumb<<p->data.fMath<<p->data.fChin<<p->data.fEngl<<endl;
			}
			p = p->pNext;
		}
	}
	else if (i == 2)
	{
		SNode*p = (*pl).m_pHead;
		char t[20] = { 0 };
		cout<<"请输入姓名"<<endl;
		cin >> t;
		cout<<"\t\t\t\t\t\t";
		cout<<"姓名\t学号\t数学\t语文\t英语"<<endl;
		while (p)
		{
			if (strstr(p->data.sName, t))
			{
				flag = 1;
				cout<<"\t\t\t\t\t\t";
				cout<< p->data.sName<<p->data.sNumb<<p->data.fMath<< p->data.fChin<< p->data.fEngl<<endl;
			}
			p = p->pNext;
		}
	}
	else if (i == 3)
	{
		SNode*p = (*pl).m_pHead;
		float f1 = 0, f2 = 0;
		cout<<"请输入数学成绩段"<<endl;
		cin >> f1 >> f2;
		while (p)
		{
			if (p->data.fMath >= f1&&p->data.fMath <= f2)
			{
				flag = 1;
				cout<<"\t\t\t\t\t\t";
				cout<< p->data.sName<< p->data.sNumb<< p->data.fMath<< p->data.fChin<< p->data.fEngl<<endl;
			}
			p = p->pNext;
		}

	}
	else if (i == 4)
	{
		SNode*p = (*pl).m_pHead;
		float f1 = 0, f2 = 0;
		cout<<"请输入语文成绩段"<<endl;
		cin >> f1 >> f2;
		while (p)
		{
			if (p->data.fChin >= f1&&p->data.fChin <= f2)
			{
				flag = 1;
				cout<<"\t\t\t\t\t\t";
				cout<< p->data.sName<< p->data.sNumb<< p->data.fMath<< p->data.fChin<< p->data.fEngl<<endl;
			}
			p = p->pNext;
		}

	}
	else if (i == 5)
	{
		SNode*p = (*pl). m_pHead;
		float f1 = 0, f2 = 0;
		cout<<"请输入英语成绩段"<<endl;
		cin >> f1 >> f2;
		while (p)
		{
			if (p->data.fEngl >= f1&&p->data.fEngl <= f2)
			{
				flag = 1;
				cout<<"\t\t\t\t\t\t";
				cout<< p->data.sName<< p->data.sNumb<< p->data.fMath<< p->data.fChin<<p->data.fEngl<<endl;
			}
			p = p->pNext;
		}

	}
	else
		return;
	if (flag == 0)
		cout<<"系统中无符合条件的数据"<<endl;
	cout<<"\t\t\t\t\t\t按任意键继续...";
	_getch();
}
int Student::FindMenu()
{
	int n = 0;
	cout<<"\t\t\t\t\t\t1、按学号查找"<<endl;
	cout<<"\t\t\t\t\t\t2、按姓名查找"<<endl;
	cout<<"\t\t\t\t\t\t3、按数学成绩查找"<<endl;
	cout<<"\t\t\t\t\t\t4、按语文成绩查找"<<endl;
	cout<<"\t\t\t\t\t\t5、按英语成绩查找"<<endl;
	cout<<"\t\t\t\t\t\t0、返回主菜单"<<endl;
	cout<<"请选择：";
	cin >> n;
	while (n>5 || n<0)
	{
		cout<<"无效输入，请重新选择";
		cin >> n;
	}
	return n;
}
int Student::Main()
{
	if(!(pl = Select()))
		return 0;
	(*pl).Load();
	int n = 0;
	while (n = Menu())
	{
		switch (n)
		{
		case 1:
			Browse();
			break;
		case 2:
			Add();
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
			cout<<"无效输入"<<endl;
		}
	}
	(*pl).Save();
	return 0;
}
Slist*Student::Select()
{
	int i = 0;
	cout << "1、操作链表L1中的数据" << endl;
	cout << "2、操作链表L2中的数据" << endl;
	cout << "0、退出" << endl;
	cout << "请选择：";
	cin >> i;
	switch (i)
	{
	case 1:
		return &L1;
	case 2:
		return &L2;
	case 0:
		return NULL;
	}
}