#include"Queue.h"
#include<iostream>
using namespace std;
int main()
{
	Queue<int> qu(4);
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	qu.push(5);
	qu.pop();
	qu.pop();
	qu.push(3);
	qu.push(4);
	return 0;
}