#include<stdio.h>
#define max(c1,c2) c1>c2?c1:c2
int main()
{
	float c1,c2;
	puts("������2��������");
	scanf_s("%f%f", &c1, &c2);
	printf("%.2f\n", max(c1, c2));
	return 0;
}





//Դ
//inline float max(float c1, float c2)
//{
//	return c1>c2 ? c1 : c2;
//}
//
//void main()
//{
//	cout << "������2����������"
//		float c1, float c2;
//	cin >> c1 >> c2;
//	cout << max(c1, c2) << endl;
//}
