#include<stdio.h>
#include<malloc.h>
#define MAXver 200
#define MAXedge 300
#define INF 65535
typedef struct  MatGraph {
	int edges[MAXver][MAXver];
	int numV, numE;  // 保存 边 and 顶点数
}MG;
void CreatMat(MG * g)
{
	printf("请输入顶点数和边数：");
	scanf("%d%d",&g->numV,&g->numE);
	
	//  初始化
	for (int i = 0; i < MAXver; i++)
		for (int j = 0; j < MAXver; j++)
			g->edges[i][j] = INF;

	// 读入 边
	for(int z=0;z< g->numE;z++)
	{
		int i, j,w;
		printf("请输入（vi,vj）上的i,j,和权重w:");
		scanf("%d%d%d", &i, &j, &w);
		g->edges[i][j] = w;
		g->edges[j][i] = w;
	}
}
void disMat(MG* g)
{
	for(int i=0;i<g->numV;i++)
	{ 
		for (int j=0; j < g->numV; j++)
		{
			if (g->edges[i][j] == INF)
				printf("∞ ");
			else
				printf("%d ",g->edges[i][j]);
		}
		printf("\n");
	}
}


void prim(MG* g)
{
	int i,j;
	// 保存上一个结点 
	int *parent = (int *)malloc(sizeof(int)*g->numV);
	
	// 距离 or 权重 
	int *weight = (int *)malloc(sizeof(int)*g->numV);
	
	for(i=0;i<g->numV;i++) 
	{
		weight[i] = g->edges[0][i];
		parent[i] = 0;		
	}
	weight[0] = 0; 
	// 只需要 n-1 边 
	for(i=1;i<g->numV;i++)
	{
		int min= INF,min_index; 
		//找出最小值 
		for(j=0;j<g->numV;j++)
		{
			// 不在树里 
			if(weight[j]!=0&&weight[j]<min)
			{
				min = weight[j];
				min_index = j;
			}
		}
		printf("(%d,%d)",parent[min_index],min_index);
		// 进来了 一个结点  所有要改变 一下weight
		weight[min_index] = 0;
		for(j=0;j<g->numV;j++)
		{
			// 不在树里
			if(weight[j]!=0&&g->edges[min_index][j] <weight[j])
			{
				weight[j] =  g->edges[min_index][j];
				parent[j] = min_index;
			}
		}
	}
} 

int main()
{
	MG* g = (MG*)malloc(sizeof(MG));
	CreatMat(g);
	disMat(g);
	prim(g);
	return 0;
}
/*
7 9
0 1 28
0 5 10
1 6 14
1 2 16
5 4 25
6 4 24
6 3 18
2 3 12
4 3 22
*/ 
