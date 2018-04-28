#include "Output.h"

COutput& COutput::operator<<(double dl)
{
	printf("%lf", dl);
	return *this;
}
COutput& COutput::operator<<(int n)
{
	printf("%d",n);
	return *this;
}

COutput& COutput::operator<<(float f)
{
	printf("%f", f);
	return *this;
}

COutput& COutput::operator<<(char c)
{
	printf("%c", c);
	return *this;
}

COutput& COutput::operator<<(char * str)
{
	printf(str);
	return *this;
}
