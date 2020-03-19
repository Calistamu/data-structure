#include <iostream>
using namespace std;
#define N 20

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
	struct node *parent;
}BTNode;
void selectTwo(BTNode *ht, int &start1, int &start2, int end, int n, int &min1, int &min2);

void BTqsort(BTNode *ht, int start, int end);
void DispBTNode(BTNode *b)
{
	if (b != NULL)
	{
		cout << b->data;
		if (b->lchild != NULL || b->rchild != NULL)
		{
			cout << "(";
			DispBTNode(b->lchild);
			if (b->rchild != NULL)
				cout << ",";
			DispBTNode(b->rchild);
			cout << ")";
		}
	}
}

BTNode *CreateHT(BTNode *ht, int n)
{
	int i;
	BTqsort(ht, 0, n);
	for (int i = 0; i<2 * n - 1; i++) {
		ht[i].lchild = ht[i].rchild = ht[i].parent = NULL;
	}
	int min1 = 0;
	int min2 = 1;
	int start1 = 2;
	int start2 = n;
	for (i = n; i<2 * n - 1; i++) {
		ht[i].lchild = &ht[min1];
		ht[i].rchild = &ht[min2];
		ht[i].data = ht[min1].data + ht[min2].data;
		selectTwo(ht, start1, start2, i, n, min1, min2);
		start1++;
		start2++;
	}
	return &ht[i - 1];

}

void selectTwo(BTNode *ht, int &start1, int &start2, int end, int n, int &min1, int &min2)
{
	min1 = start1;
	min2 = start2;
	if (start1 + 1<n&&ht[start1 + 1].data<ht[min2].data) {
		min2 = start1 + 1;
		start1++;
	}
	else if (start2 + 1 <= end && ht[start2 + 1].data<ht[min1].data) {
		min1 = start2 + 1;
		start2++;
	}
}

void BTqsort(BTNode *ht, int start, int end)
{
	if (start >= end - 1)
		return;
	int key = ht[start].data;
	int i = start;
	int j = end - 1;
	while (i<j) {
		while (i<j&&ht[j].data>key) j--;
		if (i<j)
			ht[i].data = ht[j].data;
		while (i<j&&ht[i].data <= key) i++;
		if (i<j)
			ht[j].data = ht[i].data;
	}
	ht[i].data = key;
	BTqsort(ht, start, i);
	BTqsort(ht, i + 1, end);
}
void main()
{
	int n, i, temp;

	BTNode *m;
	cout << "哈夫曼程序开始\n" << "请输入二叉树结点个数：";/*输入带权节点的个数*/
	cin >> n;
	BTNode w[2 * N - 1];
	if (n<N)
	{
		cout << "请输入二叉树权值：";/*输入带权值的数*/
		for (i = 1; i <= n; i++)
		{
			cin >> temp;
			w[i - 1].data = temp;
		}
		m = CreateHT(w, n);
		cout << "该哈夫曼树为：";
		DispBTNode(m);
	}
}