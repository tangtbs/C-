#include"Student.h"
int Student::Menu()
{
	system("cls");
	int i = 0;
	cout << endl;
	cout<<"\t\t\t\t\t\tѧ����Ϣ����ϵͳ"<<endl<<endl;
	cout<<"\t\t\t\t\t\t1�����ѧ����Ϣ"<<endl;
	cout<<"\t\t\t\t\t\t2�����ѧ����Ϣ"<<endl;
	cout<<"\t\t\t\t\t\t3��ɾ��ѧ����Ϣ"<<endl;
	cout<<"\t\t\t\t\t\t4���޸�ѧ����Ϣ"<<endl;
	cout<<"\t\t\t\t\t\t5������ѧ����Ϣ"<<endl;
	cout<<"\t\t\t\t\t\t0���˳�����ϵͳ"<<endl;
	cout<<"��ѡ��";
	cin>>i;
	return i;
}
void Student::Browse()
{
	system("cls");
	SNode**p = NULL;
	int n = 0;
	cout<<"��ѡ����\"���ѧ����Ϣ\""<<endl;
	cout<<"��ѡ�������ʽ"<<endl;
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
			cout<<"�������"<<endl;
		}
	}
}
int Student::BrowseMenu()
{
	int i = 0;
	cout<<"\t\t\t\t\t\t1����ѧ�����"<<endl;
	cout<<"\t\t\t\t\t\t2�����������"<<endl;
	cout<<"\t\t\t\t\t\t3������ѧ�ɼ����"<<endl;
	cout<<"\t\t\t\t\t\t4�������ĳɼ����"<<endl;
	cout<<"\t\t\t\t\t\t5����Ӣ��ɼ����"<<endl;
	cout<<"\t\t\t\t\t\t6����Ĭ��˳�����"<<endl;
	cout<<"\t\t\t\t\t\t0���������˵�"<<endl;
	cin >> i;
	return i;
}
void Student::Add()
{
	system("cls");
	DATA t[20] = { 0 };
	DATA*temp = t;
	cout<<"��ѡ�����������"<<endl;
	cout<<"��ѡ����ӷ�ʽ"<<endl;
	int l = AddMenu();
	if (!l)
		return;
	cout<<"������";
	cout<<"\t\t\t\t\t\t";
	cout<<"����\tѧ��\t��ѧ\t����\tӢ��"<<endl<<endl;
	do
	{
		cout<<"\t\t\t\t\t\t";
		cin>>temp->sName>>temp->sNumb>>temp->fMath>>temp->fChin>>temp->fEngl;
		if ((*pl).Searchbystr(temp->sNumb))
			puts("�������е�ѧ���Ѵ��ڣ�����������Ч");
		temp++;
		cout<<"�Ƿ����?(y/n)";
	} while (tolower(_getch()) == 'y');
	system("cls");
	cout<<"\t\t\t\t\t����\tѧ��\t��ѧ\t����\tӢ��\n"<<endl;
	int i = 0;
	while (*t[i].sNumb)
	{
		cout<<"\t\t\t\t\t"<< t[i].sName<<t[i].sNumb<<t[i].fMath<<t[i].fChin<<t[i].fEngl<<endl;
		i++;
	}
	cout<<endl<<endl<<"ȷ��������������𣿣���'y'ȷ����ӣ�������ȡ����ӣ�"<<endl;
	if (toupper(_getch()) == 'Y')
	{
		if (l == 1)
		{
			while (i--)
				(*pl).AddHead(&t[i]);
			cout<<"��ӳɹ�"<<endl;
		}
		else
		{
			while (i--)
				(*pl).AddTail(&t[i]);
			cout<<"��ӳɹ�"<<endl;
		}
	}

	else
		cout<<"���ʧ��"<<endl;
	cout<<"�����������";
	_getch();
}
int Student::AddMenu()
{
	int i = 0;
	cout<<"1����ͷ�����"<<endl;
	cout << "2����β�����" << endl;
	cout << "0���������˵�" << endl;
	cout<<"��ѡ��";
	cin >> i;
	while (i < 0 || i>2)
	{
		cout<<"��Ч���룬������ѡ��:";
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
	cout<<"��ѡ����\"ɾ������\""<<endl;
	cout << "1�������������" << endl;
	cout << "2��ɾ����������" << endl;
	cout << "0���������˵�" << endl;
	cout << "��ѡ��";
	cin>>n;
	while (n > 2 || n < 0)
	{
		cout<<"��Ч���룬������ѡ��";
		cin>>n;
	}
	return n;
}
void Student::Deletesome()
{
	char s[20] = { 0 };
	cout<<"������Ҫɾ�����ݵ�ѧ�Ż�����"<<endl;
	cin >> s;
	SNode*p = (*pl).Searchbystr(s);
	if (!p)
	{
		cout<<"�����ݲ�����"<<endl;
		system("pause");
		return;
	}
	(*pl).Printone(p);
	cout<<endl<<"ȷ��ɾ��������Ϣ��(��'y'ȷ��ɾ����������ȡ��ɾ��)"<<endl;
	if (tolower(_getch()) == 'y')
	{
		(*pl).DeleteData(p);
		cout<<"ɾ���ɹ�"<<endl;
		system("pause");
		return;
	}
	cout<<"ɾ��ʧ��"<<endl;
	system("pause");
}
void Student::DeleteAll()
{
	cout<<"ȷ���������������(��'y'ȷ�ϣ���������ȡ��)"<<endl;
	if (toupper(_getch()) == 'Y')
		(*pl).RemoveAll();
	cout<<"���������ѱ����"<<endl;
	system("pause");
}
void Student::Modify()
{
	system("cls");
	DATA s = { 0 };
	cout<<"��ѡ����\"�޸�����\""<<endl;
	cout<<"������Ҫ�޸����ݵ�������ѧ��"<<endl;
	cin>>s.sName;
	SNode* p = (*pl).Searchbystr(s.sName);
	if (!p)
	{
		cout<<"�����ݲ�����"<<endl;
		return;
	}
	cout<<"������Ҫ�޸����ݵ���ϸ��Ϣ"<<endl;
	cout<<"��������������"<<endl;
	(*pl).Printone(p);
	cout<<"\t\t\t\t\t\t";
	cin>>s.sName>>s.sNumb>>s.fMath>>s.fChin>>s.fEngl;
	cout<<endl<<"ȷ���޸�������Ϣ�𣿣���'y'ȷ���޸ģ�������ȡ���޸ģ�"<<endl;
	if (tolower(_getch()) == 'y')
	{
		(*pl).ModifyData(p, &s);
		cout<<"�޸ĳɹ�"<<endl;
		system("pause");
		return;
	}
	cout<<"�޸�ʧ��"<<endl;
	system("pause");
	return;
}
void Student::Find()
{
	int flag = 0;
	system("cls");
	cout<<"��ѡ����\"��������\""<<endl;
	int i = FindMenu();
	if (i == 1)
	{
		char t[20] = { 0 };
		SNode*p = (*pl).m_pHead;
		cout<<"������ѧ��"<<endl;
		cin>>t;
		cout<<"\t\t\t\t\t\t";
		cout<<"����\tѧ��\t��ѧ\t����\tӢ��"<<endl;
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
		cout<<"����������"<<endl;
		cin >> t;
		cout<<"\t\t\t\t\t\t";
		cout<<"����\tѧ��\t��ѧ\t����\tӢ��"<<endl;
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
		cout<<"��������ѧ�ɼ���"<<endl;
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
		cout<<"���������ĳɼ���"<<endl;
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
		cout<<"������Ӣ��ɼ���"<<endl;
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
		cout<<"ϵͳ���޷�������������"<<endl;
	cout<<"\t\t\t\t\t\t�����������...";
	_getch();
}
int Student::FindMenu()
{
	int n = 0;
	cout<<"\t\t\t\t\t\t1����ѧ�Ų���"<<endl;
	cout<<"\t\t\t\t\t\t2������������"<<endl;
	cout<<"\t\t\t\t\t\t3������ѧ�ɼ�����"<<endl;
	cout<<"\t\t\t\t\t\t4�������ĳɼ�����"<<endl;
	cout<<"\t\t\t\t\t\t5����Ӣ��ɼ�����"<<endl;
	cout<<"\t\t\t\t\t\t0���������˵�"<<endl;
	cout<<"��ѡ��";
	cin >> n;
	while (n>5 || n<0)
	{
		cout<<"��Ч���룬������ѡ��";
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
			cout<<"��Ч����"<<endl;
		}
	}
	(*pl).Save();
	return 0;
}
Slist*Student::Select()
{
	int i = 0;
	cout << "1����������L1�е�����" << endl;
	cout << "2����������L2�е�����" << endl;
	cout << "0���˳�" << endl;
	cout << "��ѡ��";
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