#include<iostream>
#include"Clist.h"
using namespace std;
int main()
{
	int n = 0;
	Clist list;
	do 
	{
		cout << "1����" << endl;
		cout << "2��ɾ" << endl;
		cout << "3����" << endl;
		cout << "4����" << endl;
		cout << "5���" << endl;
		cout << "��ѡ��";
		cin >> n;
		switch (n)
		{
		case 1:
			DATA data;
			cin >> data.sName >> data.nNumb >> data.fSala;
			list.AddHead(data);
			break;
		case 2:

		case 3:

		case 4:
			break;
		}
	} while (n);
	return 0;
}