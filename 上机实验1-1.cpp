#include<stdio.h>
#include<stdlib.h>
#define ElemType int
#define List_Init_Size 100
#define LISTINCREMENT 10
typedef int Status;

typedef struct {
	int *elem;
	int length;
	int ListSize;
}SqList;
Status Existsin(SqList L,int  e)
	{
	int result=0,i ;
	if (L.length == 0)
		return result;
	for(i=0;i<L.length;i++)
	{
		int ai = *(L.elem + i);
		if(ai==e)
		{
			break;
			result = 1;
		}
	}
	return result;

}
Status Initialize_table(SqList &L)
{
	int i, data,m;
	L.elem = (int*)malloc(List_Init_Size * sizeof(int));
	if (!L.elem)
		exit(1);
	L.ListSize = List_Init_Size; L.length = 0;
		printf("Please input the size of linear table(<=%d):" , List_Init_Size);
		scanf_s("%d", &m);
		for (i = 0; i<m; i++)
		{	printf("Please input the NO.%d element:", i + 1);
		scanf_s("%d", &data);
		*(L.elem + i) = data;
		L.length++;
	}
	return 0;
}
Status PrintSq(SqList L)
{
	int i;
	printf("Allocated Memory Size=%d Lenth=%d", L.ListSize, L.length);
	printf("\n");
	for (i = 0; i < L.length; i++)
	{	printf("%d", L.elem[i]);
	printf(" ");
}
	return 0;
}
Status ListDelete(SqList &L, int i, ElemType &e)
{
	int *p, *q;
	if ((i < 1) || (i > L.length))
		return -1;
	p = L.elem + i - 1;
	e = *p;
	q = L.elem + L.length - 1;
	for (++p; p <= q; ++p)
	{	*(p +1) = *p;
	L.length--;
}
	return 0;
}
Status ListInsert(SqList &L, int i, ElemType e)
{
	int *p, *q,*newbase;
	if ((i < 1) || (i > L.length + 1))return -1;
	if (L.length >= L.ListSize)
	{
		newbase = (int*)realloc(L.elem, (L.ListSize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)\
			printf("OVERFLOW");
		L.elem = newbase;
	L.ListSize += LISTINCREMENT;
	}
	q = &(L.elem[i - 1]);
	for (p = &(L.elem[L.length - 1]); p >= q; --p)*(p + 1) = *p;
	*q = e;
	++L.length;
	return 0;
}
void MergeList(SqList &L1,SqList L2)
{
	int i = 0, k = L1.length;
	int ai;
	while (i < L2.length)
	{
		ai = *(L2.elem + i);
		if (!Existsin(L1, ai))
			ListInsert(L1, k++, ai);
		++i;
	}

}
Status main(void)
{
	int result;
	SqList La, Lb;
	Initialize_table(La);
	Initialize_table(Lb);
	ListDelete(La, 3, result);
	ListInsert(Lb, 4, 35);
	MergeList(La, Lb);
	PrintSq(La);
	free(La.elem);
	free(Lb.elem);
	return 0;
}