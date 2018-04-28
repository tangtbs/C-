#include"String.h"
#include<iostream>
using namespace std;
int main()
{
	CString string1 = "123456123000gg9786123";
	CString string3 = string1;
	cout << string3 << endl;
	cout << string3.Replace("123","ABC")<< endl;
	/*cout<<string3.Replace("123","123")<<endl;*/
	/*if (string3 >="12345678900000")
	cout << "³ÉÁ¢" << endl;*/
	cout << string3;
	return 0;
}