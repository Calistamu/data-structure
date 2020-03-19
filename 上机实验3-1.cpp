#include<iostream>
using namespace std;
typedef struct
{
	char  *base;
	char *top;
	int stacksize;
}SqStack, *LinkStNode;
void InitStack(SqStack &S)
{
	S.base = (char *)malloc(100*sizeof(char));
	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = 100;
}
bool GetTop(SqStack S, char &e)
{
	if (S.top == S.base)
		return 0;
	e = *(S.top - 1);
	return 1;
}
void Push(SqStack &S, char e)
{
	if ((S.top - S.base) >= S.stacksize)
{
S.base = (char*)realloc(S.base, (S.stacksize + 10) * sizeof(char));
if (!S.base)
exit(OVERFLOW);

S.top = S.base + S.stacksize;
S.stacksize += 10;
}
	*S.top++ = e;
}
void Pop(SqStack &S, char &e)
{
	if (S.top == S.base)
		exit(0);
	e = *--S.top;
}
bool Match(char exp[],int n)
{
	SqStack ls;
	InitStack(ls);
	int i = 0;
	char e;
	bool flag = true;
	while (i < n&&flag)
	{
		if (exp[i] == '(')
			Push(ls, exp[i]);
		if (exp[i] == ')')
		{
			if (GetTop(ls, e))
			{
				if (e == '(')
					Pop(ls, e);
				else flag = false;
			}
			else flag = false;
		}i++;
	}return flag;
}
int main()
{
	int n=0;
	char exp[100];
	cout << "请输入符号(输入结束时请输入0)：" << endl;
	for (int i = 0; i < 100; i++)
	{
		cin >> exp[i];
		if (exp[i] == '0')
			break;
		n++;
	}
	cout << "判断结果：" << endl;
	if( Match(exp,  n))
		cout<<"yes";
	else cout << "no";
}