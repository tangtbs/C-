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
	out << "请输入一个字符：" << "字符串：" << "整数：" << "浮点数:"<<'\n';
	in >> c >> s >> n >> f;
	return 0;
}