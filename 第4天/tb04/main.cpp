#include<iostream>
#include"Clist.h"
using namespace std;
int main()
{
	int n = 0;
	Clist list;
	do 
	{
		cout << "1、增" << endl;
		cout << "2、删" << endl;
		cout << "3、改" << endl;
		cout << "4、查" << endl;
		cout << "5、浏" << endl;
		cout << "请选择：";
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