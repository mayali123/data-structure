//#include<stdio.h>
//#include<malloc.h>
//#define ERROR 0
//#define OK 1
//#define TRUE 1
//#define FALSE 0
//#define MAXSIZE 20
//#define Status int
//#define MAXV 100
//#define INF 65535
//typedef struct MatGraph{
//	int edges[MAXV][MAXV];
//	int numV, numE;  // ���� �� and ������
//	char vexs[MAXV];
//}MG;
////  ����
//typedef struct {
//	int data[MAXV];
//	int front, rear;
//}queue;
//void CreatMat(MG *g)
//{
//	printf("�����붥�����ͱ�����");
//	scanf("%d%d",&g->numV,&g->numE);
//	
//	//  ��ʼ��
//	for (int i = 0; i < MAXV; i++)
//		for (int j = 0; j < MAXV; j++)
//			g->edges[i][j] = INF;
//
//	// �� ������и�ֵ
//	for (int i = 0; i < g->numV; i++)
//	{
//		printf("�����붥��:");
//		getchar();
//		scanf("%c",&g->vexs[i]);
//	}
//	// ���� ��
//	for(int z=0;z< g->numE;z++)
//	{
//		int i, j,w;
//		printf("�����루vi,vj���ϵ�i,j,��Ȩ��w:");
//		scanf("%d%d%d", &i, &j, &w);
//		g->edges[i][j] = w;
//		g->edges[j][i] = w;
//	}
//}
//void disMat(MG* g)
//{
//	for(int i=0;i<g->numV;i++)
//	{ 
//		for (int j=0; j < g->numV; j++)
//		{
//			if (g->edges[i][j] == INF)
//				printf("�� ");
//			else
//				printf("%d ",g->edges[i][j]);
//		}
//		printf("\n");
//	}
//}
//int visit[MAXV];
//void DFS(MG *g,int i)
//{
//	visit[i] = 1;
//	printf("%c ",g->vexs[i]);
//	for (int j = 0; j < g->numV; j++)
//	{
//		if (g->edges[i][j] != 0&&visit[j]==0)
//			DFS(g,j);
//	}
//}
//void DFSTraver(MG *g)
//{
//	for (int i = 0; i < MAXV; i++)
//		visit[i] = 0;
//	for (int i = 0; i < g->numV; i++)
//		if (visit[i] == 0)
//			DFS(g, i);
//}
////  ʹ�ö���
//void BFS(MG *g)
//{
//	int visit[MAXV] = {0};
//	queue* p = (queue*)malloc(sizeof(queue));
//
//	// ��ʼ�� ����
//	p->front = p->rear = 0;
//	int v = 0;
//	for(int v=0;v<g->numV;v++)
//	{
//		// ���
//		if (visit[v] == 0)
//		{
//			visit[v] = 1;
//			p->data[p->front++] = v;
//			// ������ ��Ϊ��ʱ 
//			while (p->front != p->rear)
//			{
//				// ����
//				int e = p->data[p->rear++];
//				printf("%c ", g->vexs[e]);
//				for (int i = 0; i < g->numV; i++)
//				{
//					if(g->edges[e][i]!= INF &&visit[i]==0)
//					{ 
//						visit[i] = 1;
//						p->data[p->front++] = i;
//					}
//				}
//			}
//
//		}
//	}
//}
//int main()
//{
//	MG g;
//	CreatMat(&g);
//	disMat(&g);
//	DFSTraver(&g);
//	printf("\n");
//	BFS(&g);
//}