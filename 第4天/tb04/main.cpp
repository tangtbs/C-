#include<iostream>
#include"Worker.h"
#include"Clist.h"

int main()
{
	Clist<int> list1;
	list1.AddHead(1);
	list1.AddTail(2);
	list1.AddTail(3);
	list1.AddTail(4);
	int Count = list1.GetCount();
	POSITION pos = list1.GetHeadPosition();
	for (int i=0;i<Count;i++)
	{

		cout << list1.GetAt(pos) << ' ';
		list1.GetNext(pos);
	}
	cout << endl;
	Clist<int> list2 = list1;
	list2.AddTail(5);
	list2.AddTail(6);
	POSITION pos2 = list2.GetHeadPosition();
	for (int i = 0; i < list2.GetCount(); i++)
	{
		cout << list2.GetAt(pos2) << ' ';
		list2.GetNext(pos2);
	}
	cout << endl;
	Clist<int>list3 = list1 + list2;
	list3 += list1 + list2;
	POSITION pos3 = list3.GetHeadPosition();
	for (int i = 0; i < list3.GetCount(); i++)
	{
		cout << list3.GetAt(pos3) << ' ';
		list2.GetNext(pos3);
	}
	/*CWorker list1;
	list1.Into();*/
	return 0;
}