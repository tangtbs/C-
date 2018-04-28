#pragma once
#include<iostream>
class CInput
{
	friend int main();
private:
	CInput& operator >> (int &n);
	CInput& operator >> (short& n);
	CInput& operator >> (long long& ll);
	CInput& operator >> (float &f);
	CInput& operator >> (double &dl);
	CInput& operator >> (char &c);
	CInput& operator >> (char* str);

};