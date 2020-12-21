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
	int i, j,z;
	// parent 用于保存与之相连的 结点 
	int* parent = (int*)malloc(sizeof(g->numV));
	parent[0] = 0; 
	// 一个保存 权重的数组 and 收入集合的标志
	int* weight = (int*)malloc(sizeof(g->numV));

	// 从下表为1的开始
	for (i = 1; i < g->numV; i++)
	{ 
		parent[i] = 0;
		weight[i] = g->edges[0][i];  // 权重
	}
	for (i = 1; i < g->numV; i++)
	{
		int min = INF,k;
		//weight 找一个最小值
		for (j = 1; j < g->numV; j++)
		{
			if (weight[j] != 0 && weight[j] < min)
			{
				min = weight[j];
				k = j;
			}
		}
		printf("(%d,%d) \n",parent[k],k);
		weight[k] = 0; // 变成 树 里的 没有距离了
		for (z = 1; z < g->numV; z++)
		{
			if (weight != 0 && g->edges[k][z] < weight[z])
			{
				weight[z] = g->edges[k][z];
				// 改变父节点
				parent[z] = k;
			}
		}
	}
}
int main()
{
	MG* g = (MG*)malloc(sizeof(MG));
	CreatMat(g);
	//disMat(g);
	prim(g);
	return 0;
}