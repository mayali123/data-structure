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
int main()
{
	GL g;
	CreatALGraph(&g);
	disPAL(&g);
}