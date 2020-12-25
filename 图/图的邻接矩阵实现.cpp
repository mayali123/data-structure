#include<stdio.h>
#include<malloc.h>
#define MaxVertexNum 200 
#define WeightType int
#define VertexType int 
typedef struct Gnode{
	int v; // 结点数 
	int e; // 边数 
	// 结点 
 	VertexType Data[MaxVertexNum];
 	// 边  
 	WeightType Edge[MaxVertexNum][MaxVertexNum]; 
}Gnode; 
typedef struct Enode{
	int v1,v2;  // 无向边 (v1,v2) v1 <-> v2   
	WeightType Weight;  
}Enode; 

// 队列
typedef struct queue{
	int data[MaxVertexNum];
	int front,rear;
}QU; 
Gnode* InitGnode(int VNum)
{
	int i,j;
	Gnode* g=(Gnode*)malloc(sizeof(Gnode));
	g->v = VNum;
	g->e = 0; 
	// 初始化 边  
	for(i=0;i<VNum;i++)
		for(j=0;j<VNum;j++)
			g->Edge[i][j] = 0; 
	return g;
}
void insert(Gnode * g,Enode* e)
{
	// 无向图的插入
	g->Edge[e->v1][e->v2] = e->Weight;
	
	g->Edge[e->v2][e->v1] = e->Weight;
	
}
Gnode* CreatGnode()
{
	int v,i,j; 
	// 结点数 
	scanf("%d",&v);
	Gnode* g = InitGnode(v);
	// 边数 
	scanf("%d",&g->e);
	if(g->e!=0) 
	{
		// 生成一个边  
		Enode *e = (Enode*)malloc(sizeof(Enode));
		for(i=0;i<g->e;i++)
		{
			// v1 v2 weight
			scanf("%d%d%d",&e->v1,&e->v2,&e->Weight); 
			// 将边插入图中
			insert(g,e);
		}
	}
	return g;
} 
void disp(Gnode * g) 
{
	int i,j;
	for(i=0;i<g->v;i++)
	{
		for(j=0;j<g->v;j++)
			printf("%5d",g->Edge[i][j]);
		printf("\n");
	}
}
void BFS(Gnode * g)
{
	int i,j;
	int* values = (int *)malloc(sizeof(int)*g->v);
	for(i=0;i<g->v;i++)
		values[i] =0;
	
	QU * p=(QU*)malloc(sizeof(QU));
	p->front = p->rear = 0;	
	for(i=0;i<g->v;i++)
	{
		if(values[i]==0)
		{
			p->data[p->rear++] = i;
			values[i] = 1;
			while(p->front!=p->rear)
			{
				i = p->data[p->front++];
				printf("%d ",i);
				for(j=0;j<g->v;j++)
					if(g->Edge[i][j]!=0&&!values[j])
					{
						p->data[p->rear++] = j;
						values[j]=1;
					}
			}
		}
	}
}
int visit[MaxVertexNum];
void DFS(Gnode * g,int i)
{
	int j;
	visit[i] = 1;
	printf("%d ",i);
	for(j=0;j<g->v;j++)
		if(visit[j]==0&&g->Edge[i][j]!=0)
			DFS(g,j); 
}
void Init_DFS(Gnode * g)
{
	int i; 
	for(i=0;i<MaxVertexNum;i++)
		visit[i] = 0;
	for(i=0;i<g->v;i++)
		if(visit[i]==0)
			DFS(g,i);
} 
int main()
{
	Gnode* g = CreatGnode();
	disp(g);
	printf("\nBFS:");
 	BFS(g);
 	printf("\nDFS:");
	Init_DFS(g);
	return 0;
}
