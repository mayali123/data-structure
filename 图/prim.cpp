#include<stdio.h>
#include<malloc.h>
#define MAXver 200
#define MAXedge 300
#define INF 65535
typedef struct  MatGraph {
	int edges[MAXver][MAXver];
	int numV, numE;  // ���� �� and ������
}MG;
void CreatMat(MG * g)
{
	printf("�����붥�����ͱ�����");
	scanf("%d%d",&g->numV,&g->numE);
	
	//  ��ʼ��
	for (int i = 0; i < MAXver; i++)
		for (int j = 0; j < MAXver; j++)
			g->edges[i][j] = INF;

	// ���� ��
	for(int z=0;z< g->numE;z++)
	{
		int i, j,w;
		printf("�����루vi,vj���ϵ�i,j,��Ȩ��w:");
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
				printf("�� ");
			else
				printf("%d ",g->edges[i][j]);
		}
		printf("\n");
	}
}
void prim(MG* g)
{
	int i, j,z;
	// parent ���ڱ�����֮������ ��� 
	int* parent = (int*)malloc(sizeof(g->numV));
	parent[0] = 0; 
	// һ������ Ȩ�ص����� and ���뼯�ϵı�־
	int* weight = (int*)malloc(sizeof(g->numV));

	// ���±�Ϊ1�Ŀ�ʼ
	for (i = 1; i < g->numV; i++)
	{ 
		parent[i] = 0;
		weight[i] = g->edges[0][i];  // Ȩ��
	}
	for (i = 1; i < g->numV; i++)
	{
		int min = INF,k;
		//weight ��һ����Сֵ
		for (j = 1; j < g->numV; j++)
		{
			if (weight[j] != 0 && weight[j] < min)
			{
				min = weight[j];
				k = j;
			}
		}
		printf("(%d,%d) \n",parent[k],k);
		weight[k] = 0; // ��� �� ��� û�о�����
		for (z = 1; z < g->numV; z++)
		{
			if (weight != 0 && g->edges[k][z] < weight[z])
			{
				weight[z] = g->edges[k][z];
				// �ı丸�ڵ�
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