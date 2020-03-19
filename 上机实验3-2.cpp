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
	cout << "���������֣�" << endl;
	while (true)
	{
		cin >> a;
		if (a > 0)
		{if (!EnQueue(qu, a))
				cout << "���������ܽ���";
	}
		else if (a < 0)
		{
			if (!DeQueue(qu, e))
				cout << "�Կգ����ܳ���";
			else cout << e;
		}
			else break;
		}
}
int main()
{
	fun();
}