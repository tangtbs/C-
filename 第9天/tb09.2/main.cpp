#include"Output.h"
#include"Input.h"
COutput out;
CInput in;
int main()
{
	float f;
	char s[20];
	char c;
	int n = 10;
	out << "������һ���ַ���" << "�ַ�����" << "������" << "������:"<<'\n';
	in >> c >> s >> n >> f;
	return 0;
}