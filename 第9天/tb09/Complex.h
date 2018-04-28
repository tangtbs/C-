#pragma once
class CComplex
{
public:
	double m_fReal;//ʵ��
	double m_fImag;//�鲿
	CComplex(double fReal,double fImag);
	~CComplex();
	friend int main();
private:
	CComplex operator +(const CComplex& right)
	{
		return CComplex(m_fReal + right.m_fReal, m_fImag + right.m_fImag);
	}
	/*CComplex& test()
	{
		return *this;
	}*/
	CComplex operator -(const CComplex& right)
	{
		return CComplex(m_fReal-right.m_fReal,m_fImag-right.m_fImag);
	}
	CComplex operator *(const CComplex& right);
	CComplex operator /(const CComplex& right);
};
