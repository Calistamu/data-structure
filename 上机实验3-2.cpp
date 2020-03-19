#include<iostream>
using namespace std;
#define MAXQSIZE 100
typedef struct
{
	int *base;
	int front;
	int rear;
}SqQueue;
void InitQueue(SqQueue &Q)
{
	Q.base = (int*)malloc(MAXQSIZE*sizeof(int));
	if (!Q.base)exit(OVERFLOW);
	Q.front = Q.rear = 0;
}
bool EnQueue(SqQueue &Q, int e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return true;
}
bool DeQueue(SqQueue &Q, int &e)
{
	if (Q.front == Q.rear)
		return false;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return true;
}
void fun()
{
	int a,e;
	SqQueue qu;
	InitQueue(qu);
	cout << "请输入数字：" << endl;
	while (true)
	{
		cin >> a;
		if (a > 0)
		{if (!EnQueue(qu, a))
				cout << "队满，不能进队";
	}
		else if (a < 0)
		{
			if (!DeQueue(qu, e))
				cout << "对空，不能出队";
			else cout << e;
		}
			else break;
		}
}
int main()
{
	fun();
}