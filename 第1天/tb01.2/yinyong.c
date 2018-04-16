#include<stdio.h>
void swap(int*i,int*j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}
int main()
{
	int i = 10, j = 20;
	swap(&i,&j);
	printf("i=%d,j=%d", i, j);
	return 0;
}
//
//void swap(int& i, int& j)
//{
//	int tmp = i;
//	i = j;
//	j = tmp;
//}
//
//void main()
//{
//	int i = 10;
//	int j = 20;
//	swap(i, j);
//}