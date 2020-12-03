#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
#define Status int
#define MAXV 100
#define INF 65535
typedef struct MatGraph{
	int edges[MAXV][MAXV];
	int numV, numE;  // ���� �� and ������
	char vexs[MAXV];
}MG;
void CreatMat(MG *g)
{
	printf("�����붥�����ͱ�����");
	scanf("%d%d",&g->numV,&g->numE);
	
	//  ��ʼ��
	for (int i = 0; i < MAXV; i++)
		for (int j = 0; j < MAXV; j++)
			g->edges[i][j] = INF;

	// �� ������и�ֵ
	for (int i = 0; i < g->numV; i++)
	{
		printf("�����붥��:");
		getchar();
		scanf("%c",&g->vexs[i]);
	}
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

int main()
{
	MG g;
	CreatMat(&g);
	disMat(&g);
}