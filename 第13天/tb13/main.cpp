//#include<iostream>
//#include"Array.h"
//using namespace std;
//typedef struct
//{
//	int n;
//}DATA;
//void Print(CArray<DATA> array)
//{
//	CArray<DATA>::iterator it = array.begin();
//
//	while (it!=array.end())
//		cout <<it++->n<<' ';
//}
//int main()
//{
//	CArray<DATA> list1;
//	CArray<DATA>::iterator it;
//	it = list1.GetData();
//	list1.Add({ 1 });
//	list1.Add({ 2 });
//	list1.Add({ 3 });
//	list1.Add({ 4 });
//	list1.Add({ 5 });
//	Print(list1);
//	return 0;
//}
#include"Worker.h"
using namespace std;
int main()
{
	CWorker list1;
	list1.Into();
	return 0;
}