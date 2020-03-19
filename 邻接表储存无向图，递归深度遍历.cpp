#include<iostream>
using namespace std;
#define MAXVEX 20
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode     //�߱���  
{
	int adjvex;              //�ö����±�  
	EdgeType weight;         //�洢Ȩֵ  
	struct EdgeNode *next;   //ָ����һ���ڽӵ�  
}EdgeNode;

typedef struct VertexNode   //�������  
{
	VertexType data;        //�����򣬴洢������Ϣ  
	EdgeNode *firstedge;    //ָ���һ����  
}VertexNode, Adjlist[MAXVEX];
typedef struct               //ͼ�Ľṹ��  
{
	Adjlist adjlist;
	int numVertexs, numEdges;
}GraphAdjlist;
void CreateGraph(GraphAdjlist *G)
{
	
	int i, j, w, k;
	EdgeNode *e;

	printf("���붥�����ͱ���:\n");
	scanf_s("%d,%d", &G->numVertexs, &G->numEdges);

	for (i = 0;i<G->numVertexs; i++)       //���������  
	{
		scanf_s(&G->adjlist[i].data);       //���붥����Ϣ  
		G->adjlist[i].firstedge = NULL;     //�߱��ʼ��Ϊ��  
	}

	for (k = 0;k<G->numEdges; k++)         //�����߱�  
	{
		printf("�����(Vi,Vj)���±�i���ϱ�j��Ȩֵw\n");
		scanf_s("%d,%d,%d", &i, &j, &w);

		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->weight = w;
		e->next = G->adjlist[i].firstedge;     //ͷ�巨���ߵ���Ϣ�����ڽӱ�  
		G->adjlist[i].firstedge = e;

		e = (EdgeNode *)malloc(sizeof(EdgeNode));    //����ͼ���Զ���i,j�ֱ����  
		e->adjvex = i;
		e->weight = w;
		e->next = G->adjlist[j].firstedge;
		G->adjlist[j].firstedge = e;
	}
}
int visited[MAXVEX] = {0};
void DFS(GraphAdjlist G, int v)
{
	//ͼ�Ķ��������ָ��
	EdgeNode *p;
	//���ѷ��ʱ��
	visited[v] = 1;
	//��������ʶ���ı��
	printf("%d  ", v);
	//pָ�򶥵�v�ĵ�һ�����Ļ�ͷ���
	p = G.adjlist[v].firstedge;
	while (p != NULL)
	{
		//��p->adjvex����δ����,�ݹ������
		if (visited[p->adjvex] == 0)
		{
			DFS(G, p->adjvex);
		}
		//pָ�򶥵�v����һ�����Ļ�ͷ���
		p = p->next;
	}
}
int main()
{
	GraphAdjlist G;
	CreateGraph(&G);
	int v;
	cout << "��������ڵ����ţ�";
	cin >> v;
	cout << endl;
	DFS(G, v);
}