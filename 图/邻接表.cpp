#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
#define Status int
#define MAXV 100
typedef struct EdgeNode {
	int weight;
	int adjvex; // 连解的结点对应的下表
	struct EdgeNode* next;
}ENode;
typedef struct {
	char data;
	ENode* FristEdge;
}VNode;
typedef struct {
	VNode adjList[MAXV];
	int numV, numE;
}GL;

//  队列
typedef struct {
	int data[MAXV];
	int front, rear;
}queue;
void CreatALGraph(GL *g)
{
	printf("请输入顶点数和边数：");
	scanf("%d%d",&g->numV,&g->numE);
	printf("请输入顶点:");
	for (int i = 0; i < MAXV; i++)
		g->adjList[i].FristEdge = NULL;
	for (int i = 0; i < g->numV; i++)
	{ 
		getchar();
		scanf("%c", &g->adjList[i].data);
	}
	for (int z = 0; z < g->numE; z++)
	{
		int i, j, w;
		printf("请输入（vi,vj）上的i,j:");
		scanf("%d%d", &i, &j);
		ENode* k = (ENode*)malloc(sizeof(ENode));
		k->adjvex = j;
		k->next = g->adjList[i].FristEdge;
		g->adjList[i].FristEdge = k;

		k  = (ENode*)malloc(sizeof(ENode));
		k->adjvex = i;
		k->next = g->adjList[j].FristEdge;
		g->adjList[j].FristEdge = k;
	}
}
void disPAL(GL *g)
{
	for (int i=0; i < g->numV; i++)
	{
		ENode *p=g->adjList[i].FristEdge;
		printf("%c :", g->adjList[i].data);
		while (p != NULL)
		{
			printf("%d ",p->adjvex);
			p = p->next;
		}
		printf("\n");
	}
}

int visit[MAXV];

// 实现 对 g->adjList[v]和其 链接 的 遍历 
void DFS(GL* g,int v)
{
	ENode* p;
	visit[v] = 1;
	printf("%c ",g->adjList[v].data);
	p = g->adjList[v].FristEdge;
	while (p)
	{
		if (visit[p->adjvex]== 0)
			DFS(g,p->adjvex);
		p = p->next;
	}
}
void DFSTraver(GL* g)
{
	for (int i = 0; i < MAXV; i++)
		visit[i] = 0;
	for (int i = 0; i < g->numV; i++)
		if (visit[i] == 0)
			DFS(g,i);
}
void BFS(GL* g)
{
	int visit[MAXV] = { 0 };
	queue *p = (queue*)malloc(sizeof(queue));
	p->front = p->rear = 0;
	for(int i=0;i<g->numV;i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			p->data[p->front++] = i;
			while (p->front != p->rear)
			{
				int e = p->data[p->rear++];
				printf("%c ",g->adjList[e].data);
				ENode* node = g->adjList[e].FristEdge;
				while (node)
				{
					if(visit[node->adjvex]==0)
					{ 
						visit[node->adjvex] = 1;
						p->data[p->front++] = node->adjvex;  // 入队 
					}
					node = node->next;
				}
			}
		}
	}
}
int main()
{
	GL g;
	CreatALGraph(&g);
	disPAL(&g);
	DFSTraver(&g);
	printf("\n");
	BFS(&g);
}