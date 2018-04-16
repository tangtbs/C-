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
	printf("请输入游泳池半径:");
	scanf_s("%f", &radius);
	struct Circle Pool = {radius};
	struct Circle PoolRim = {radius+3};
	printf("栅栏长度：%0.2fm\n", Circumference(&Pool));
	printf("甬道面积：%0.2fm*m\n", Area(&PoolRim) - Area(&Pool));
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
//	float Circumference()  //圆周长
//	{
//		return 2 * PI * radius;
//	}
//	float Area()  //圆面积
//	{
//		return PI * radius * radius;
//	}
//};
//void main()
//{
//	float radius;
//
//	cout << "请输入游泳池的半径: ";
//	cin >> radius;
//
//	// 声明 Circle 对象
//	Circle Pool = { radius };
//	Circle PoolRim = { radius + 3 };
//	//计算栅栏长度
//	cout << "栅栏长度是：" << PoolRim.Circumference() << endl;
//
//	cout << "甬道的面积是：" << PoolRim.Area() - Pool.Area() << endl;
//
//}