#include"stack.h"
#include<iostream>
using namespace std;
int main()
{
	CStack<int> stack;
	stack.push(100*sizeof(int));
	stack.pop(10 * sizeof(int));
	cout<<stack.size();
	return 0;
}