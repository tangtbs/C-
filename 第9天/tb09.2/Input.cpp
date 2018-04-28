#include "Input.h"

CInput& CInput::operator >> (int& n)
{
	scanf_s("%d",&n);
	return *this;
}

CInput& CInput::operator >> (short& n)
{
	scanf_s("%hd", &n);
	return *this;
}

CInput& CInput::operator >> (long long&ll)
{
	scanf_s("%lld",&ll);
	return *this;
}

CInput& CInput::operator >> (float &f)
{
	scanf_s("%f",&f);
	return *this;
}

CInput& CInput::operator >> (double &dl)
{
	scanf_s("%lf", &dl);
	return *this;
}

CInput& CInput::operator >> (char& c)
{
	c=getchar();
	return *this;
}

CInput& CInput::operator >> (char * str)
{
	scanf_s("%s",str,20);
	return *this;
}
