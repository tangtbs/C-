#include<iostream>
using namespace std;
class CBase
{
public:
	int m_i;
	void RealFunc() //ÆÕÍ¨º¯Êý
	{
		cout << "CBase::RealFunc()" << endl;
		m_i = 0;
	}
	virtual void VirtualFunc() //ÐéÄâº¯Êý
	{
		m_i = 1;
		cout << "CBase::VirtualFunc()" << endl;
	}
};
class CDerived :public CBase
{
public:
	void RealFunc()
	{
		m_i = 2;
		cout << "CDerived::RealFunc()" << endl;
	}
	void VirtualFunc()
	{
		m_i = 3;
		cout << "CDerived::VirtualFunc()" << endl;
	}
};
void TestByObj(CBase b)
{
	b.VirtualFunc();
	CBase *pb = &b;
	pb->VirtualFunc();
}
void TestByPointer(CBase *pb)
{
	pb->VirtualFunc();
}

void TestByRef(CBase &bRef)
{
	bRef.VirtualFunc();
	CBase *pb = &bRef;
	pb->VirtualFunc();
}

int main()
{
	CBase b, *pb;
	CDerived d;
	int iSize = sizeof(b);
	b.RealFunc();
	b.VirtualFunc();

	d.RealFunc();
	d.VirtualFunc();

	pb = &b;
	pb->RealFunc();
	pb->VirtualFunc();

	pb = &d;
	pb->RealFunc();

	pb->VirtualFunc();


	CBase &b1 = b;
	b1.RealFunc();
	b1.VirtualFunc();

	CBase &b2 = d;
	b2.RealFunc();
	b2.VirtualFunc();

	TestByObj(d);
	TestByPointer(&d);
	TestByRef(d);

	memcpy(&b, &d, sizeof(b));
	b.VirtualFunc();
	return 0;
}