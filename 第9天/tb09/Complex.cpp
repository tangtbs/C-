#include"Complex.h"
CComplex::CComplex(double fReal,double fImag=0)
{
	m_fReal = fReal;
	m_fImag = fImag;
}

CComplex::~CComplex()
{

}

CComplex CComplex::operator *(const CComplex& right)
{
	return CComplex(m_fReal*right.m_fReal-m_fImag*right.m_fImag,m_fReal*right.m_fImag+m_fImag*right.m_fReal);
}

CComplex CComplex::operator/(const CComplex & right)
{
	CComplex Rright(right.m_fReal,-right.m_fImag);
	double f = right.m_fReal*right.m_fReal + right.m_fImag*right.m_fImag;
	return CComplex((*this*Rright).m_fReal/f,(*this*Rright).m_fImag/f);
}
