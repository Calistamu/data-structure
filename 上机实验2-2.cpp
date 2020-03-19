#include<iostream>
using namespace std;
#define SIZE 100
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode,*LinkList;
void PrintList(LinkList &L, int n)
{
	LinkList p = L->next;
	for (int i = 0; i < n; i++)
	{
		cout<<p->data<<" ";
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
void split(LinkList list, LinkList &list1, LinkList &list2)
{
	list1 = (LinkList)malloc(sizeof(LNode));
	list2 = (LinkList)malloc(sizeof(LNode));
	LNode *p = list, *q = list1, *r = list2;
	int len1 = 0, len2 = 0;
	int mark = 1;
	while(p!=NULL)
	{
		if (mark == 1)
		{
			q->next = p;
			q = q->next;
			len1++;
			mark = 2;
	
	}
		else
		{
			r->next = p;
			r = r->next;
			len2++;
			mark = 1;
			
		}
		p = p->next;
		q->next = list1;
		r->next = list2;
		list1->data = len1;
		list2->data = len2;
	}         
	LinkList k = list1->next;
	for (int i = 0; i < len1; i++)
	{
		if (i == 0)
			k = k->next;
		else
		{
			cout << k->data << " ";
			k = k->next;
		}
	}
	k= list2->next;
	cout << endl;
	for (int i = 0; i < len2; i++)
	{
		cout << k->data << " ";
		k= k->next;
	}
}

void CreateList(LinkList &L, int n)
{
	LinkList p;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = n; i > 0; i--)
	{
		p = (LinkList)malloc(sizeof(LNode));
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}
int main()
{
	LinkList list, list1, list2;
	int n;
	cout << "拆分数据程序" << endl << "创建您的数组" <<endl<< "请输入数据元素的个数：";
	cin >> n;
	cout<<endl<< "请输入数据：" << endl;
	CreateList(list, n);
	reverse(list);
	PrintList(list, n);
   	split(list, list1, list2);
}