#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;
void CreateList(LinkList &L,int n)
{LinkList p;
L = (LinkList)malloc(sizeof(LNode));
L->next = NULL;
for (int i = n; i > 0; i--)
{
	p = (LinkList)malloc(sizeof(LNode));
	cin >> p->data;
	p->next = L->next;
	L->next = p;
}}
void PrintList(LinkList &L,int n)
{
	LinkList p = L->next;
	for (int i = 0; i < n; i++)
	{
		cout<< p->data<<" ";
		p = p->next;
	}
	cout << endl;
}
void reverse(LinkList &H)
{
	LNode *p, *q;
	p = H->next;
	H->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		q->next = H->next;
		H->next = q;
	}
}
int main()
{
	LinkList L;
	int n;
	cout << "请输入链表长度：";
	cin >> n;
	cout << "请输入数据：" << endl;
	CreateList(L, n);
	 PrintList( L,  n);
	 reverse( L);
	 PrintList( L, n);
}