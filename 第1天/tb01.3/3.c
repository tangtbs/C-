#include<stdio.h>
#define Pi 3.141592654
float Area(struct Circle*p);
float Circumference(struct Circle* p);
struct Circle
{
	float radius;
};
int main()
{
	float radius;
	printf("��������Ӿ�ذ뾶:");
	scanf_s("%f", &radius);
	struct Circle Pool = {radius};
	struct Circle PoolRim = {radius+3};
	printf("դ�����ȣ�%0.2fm\n", Circumference(&Pool));
	printf("�������%0.2fm*m\n", Area(&PoolRim) - Area(&Pool));
	return 0;
}

float Circumference(struct Circle*p)
{
	return p->radius*2*Pi;
}

float Area(struct Circle*p)
{
	return p->radius*p->radius*Pi;
}
//#include <iostream>
//using namespace std;
//const float PI = 3.14159f;
//
//struct Circle
//{
//	float   radius;
//
//	float Circumference()  //Բ�ܳ�
//	{
//		return 2 * PI * radius;
//	}
//	float Area()  //Բ���
//	{
//		return PI * radius * radius;
//	}
//};
//void main()
//{
//	float radius;
//
//	cout << "��������Ӿ�صİ뾶: ";
//	cin >> radius;
//
//	// ���� Circle ����
//	Circle Pool = { radius };
//	Circle PoolRim = { radius + 3 };
//	//����դ������
//	cout << "դ�������ǣ�" << PoolRim.Circumference() << endl;
//
//	cout << "��������ǣ�" << PoolRim.Area() - Pool.Area() << endl;
//
//}