#include"Complex.h"
#include<iostream>
using namespace std;
int main()
{
	CComplex a(1,1);
	CComplex b(1, 1);
	CComplex c = a / b;
	cout << c.m_fReal<< endl;
	cout << c.m_fImag << endl;
	return 0;
}