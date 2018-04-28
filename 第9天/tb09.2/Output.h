#pragma once
#include<iostream>
class COutput
{
	friend int main();
private:
	COutput& operator<<(int n);
	COutput& operator<<(float f);
	COutput& operator<<(char c);
	COutput& operator<<(char* str);
	COutput& COutput::operator<<(double dl);

};
