#include<stdio.h>
#include<malloc.h>
#define WeightType int
#define VertexType int 
#define MaxVertex 100

// 边 
typedef struct Enode{
	int v1,v2;
	WeightType weight;
}Enode;
// 连解表的 元素  
typedef struct AdjVNode{
	int v ; // 他指向的结点  
	WeightType weight;
	struct AdjVNode* next; 
}AdjVNode;
typedef struct VNode{
	// 结点数据  
 	VertexType Data;
 	AdjVNode * FirstNode; // 充当 头节点  
}VNode; 
typedef struct Gnode{
	VNode data[MaxVertex];
	int v,e; // 边数 和 结点数  
}Gnode; 


// 队列
typedef struct queue{
	VertexType data[MaxVertex];
	int front,rear;
}QU; 


Gnode * InitGnode(int Vnum)
{
	Gnode* g =(Gnode*) malloc(sizeof(Gnode));
	g->v = Vnum;
	g->e = 0;
	for(int i=0;i<Vnum;i++)
		g->data[i].FirstNode =NULL; 
	return g;
}
void insert(Gnode *g,Enode *e)
{
	AdjVNode*s = (AdjVNode *)malloc(sizeof(AdjVNode));
	s->weight = e->weight;
	s->v  =  e->v2;
	
	// 头插法 
	s->next = g->data[e->v1].FirstNode;  
	g->data[e->v1].FirstNode = s ;
	
	
	s = (AdjVNode *)malloc(sizeof(AdjVNode));
	s->weight = e->weight;
	s->v  =  e->v1;
	
	// 头插法 
	s->next = g->data[e->v2].FirstNode;  
	g->data[e->v2].FirstNode = s;

}
void disp(Gnode *g)
{
	int i,j;
	
	for(i=0;i<g->v;i++)
	{
		
		AdjVNode *p = g->data[i].FirstNode;
		printf("%d\t",i);
		while(p)
		{
			printf("%d->",p->v,p->weight);
			p=p->next;
		}
		printf("NULL\n");
	}
}
Gnode* BuildGraph()
{
	int v,i;
	Enode *e=(Enode*)malloc(sizeof(Enode));
	scanf("%d",&v);
	Gnode* g = InitGnode(v);
	scanf("%d",&g->e);
	for(i=0;i<g->e;i++)
	{
		scanf("%d%d%d",&e->v1,&e->v2,&e->weight);
		insert(g, e);
	}
	return g;
}
void BFS(Gnode* g)
{
	int i,j,z;
	int* values = (int *)malloc(sizeof(int)*g->v);
	for(i=0;i<g->v;i++)
		values[i] =0;

	QU * p=(QU*)malloc(sizeof(QU));
	p->front = p->rear = 0;	
	for(z=0;z<g->v;z++)
	{
		if(values[z]==0)
		{
			p->data[p->rear++] =z;
			values[z] = 1; 
			while(p->front!=p->rear)
			{
				i = p->data[p->front++];
				printf("%d ",i);
				AdjVNode *q = g->data[i].FirstNode; 
				while(q)
				{
					if(values[q->v]==0)
					{
						p->data[p->rear++] = q->v;
						values[q->v]= 1;
					}
					q=q->next;
				}
			}
		}
	}
}
int visit[MaxVertex] ;
void DFS(Gnode* g,int  j)
{
	int i;
	printf("%d ",j);
	visit[j] = 1;
	AdjVNode *p=g->data[j].FirstNode;
	while(p)
	{
		i = p->v;
		if(visit[i]==0)
			DFS(g,i);
		p=p->next;
	}
}
void Init_DFS(Gnode * g) 
{
	for (int i = 0; i < MaxVertex; i++)
		visit[i] = 0;
	for (int i = 0; i < g->v; i++)
		if (visit[i] == 0)
			DFS(g,i);
}
int main()
{
	Gnode* g = BuildGraph();
 	disp(g);
 	printf("\nBFS:");
 	BFS(g);
 	printf("\nDFS:");
	Init_DFS(g);
	return 0;
}
