#include<iostream>
using namespace std;
#define MAXVEX 20
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode     //边表结点  
{
	int adjvex;              //该顶点下标  
	EdgeType weight;         //存储权值  
	struct EdgeNode *next;   //指向下一个邻接点  
}EdgeNode;

typedef struct VertexNode   //顶点表结点  
{
	VertexType data;        //顶点域，存储顶点信息  
	EdgeNode *firstedge;    //指向第一条边  
}VertexNode, Adjlist[MAXVEX];
typedef struct               //图的结构体  
{
	Adjlist adjlist;
	int numVertexs, numEdges;
}GraphAdjlist;
void CreateGraph(GraphAdjlist *G)
{
	
	int i, j, w, k;
	EdgeNode *e;

	printf("输入顶点数和边数:\n");
	scanf_s("%d,%d", &G->numVertexs, &G->numEdges);

	for (i = 0;i<G->numVertexs; i++)       //创建顶点表  
	{
		scanf_s(&G->adjlist[i].data);       //输入顶点信息  
		G->adjlist[i].firstedge = NULL;     //边表初始化为空  
	}

	for (k = 0;k<G->numEdges; k++)         //创建边表  
	{
		printf("输入边(Vi,Vj)的下标i，上标j和权值w\n");
		scanf_s("%d,%d,%d", &i, &j, &w);

		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->weight = w;
		e->next = G->adjlist[i].firstedge;     //头插法将边的信息插入邻接表  
		G->adjlist[i].firstedge = e;

		e = (EdgeNode *)malloc(sizeof(EdgeNode));    //无向图，对顶点i,j分别插入  
		e->adjvex = i;
		e->weight = w;
		e->next = G->adjlist[j].firstedge;
		G->adjlist[j].firstedge = e;
	}
}
int visited[MAXVEX] = {0};
void DFS(GraphAdjlist G, int v)
{
	//图的顶点的搜索指针
	EdgeNode *p;
	//置已访问标记
	visited[v] = 1;
	//输出被访问顶点的编号
	printf("%d  ", v);
	//p指向顶点v的第一条弧的弧头结点
	p = G.adjlist[v].firstedge;
	while (p != NULL)
	{
		//若p->adjvex顶点未访问,递归访问它
		if (visited[p->adjvex] == 0)
		{
			DFS(G, p->adjvex);
		}
		//p指向顶点v的下一条弧的弧头结点
		p = p->next;
	}
}
int main()
{
	GraphAdjlist G;
	CreateGraph(&G);
	int v;
	cout << "输出遍历节点的序号：";
	cin >> v;
	cout << endl;
	DFS(G, v);
}