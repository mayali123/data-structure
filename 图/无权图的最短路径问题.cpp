#include<bits/stdc++.h>
#define MaxVertex  200
using namespace std;
int path[MaxVertex];
int dist[MaxVertex];  // 存储路径长度
int G[MaxVertex][MaxVertex]; // 图
int Ne;  // 顶点数 
int Nv;  // 边 
typedef struct queue{
	int data[MaxVertex];
	int front,rear;
}QU;
typedef struct stack{
	int data[MaxVertex];
	int top;
}ST;
void build()
{
	int i,j;
 	cin>>Nv;
 	for(i=1;i<=Nv;i++)
 		for(j=1;j<=Nv;j++)
 			G[i][j] = 0;
 	for(i=1;i<=Nv;i++)
 	{
 		path[i] = -1;
		dist[i] = -1;	
	}
 	cin>> Ne;
 	int v1,v2;  //有向图 无权图 
	for(i=0;i<Ne;i++)
	{
		cin>>v1>>v2;
		G[v1][v2] = 1;  
	} 
}
// v 是起点  
void Unweighted(int v)
{
	int i,j;
	QU *p =(QU*)malloc(sizeof(QU));
	p->front= p->rear = -1;
	p->data[++p->rear] = v;
	dist[v] = 0; 
	//当其不为空时 
	while(p->front!=p->rear)
	{
		i = p->data[++p->front];
		for(j=1;j<=Nv;j++)
			if(dist[j]==-1&&G[i][j]!=0)
			{
				dist[j] = dist[i]+1;
				path[j] = i;
				p->data[++p->rear] = j;
			}
	}
}
void getTail(int v)
{
	int i,j;
	ST * p=(ST*) malloc(sizeof(ST));
	
	for(i=1;i<=Nv;i++)
	{
		p->top=-1; 
		if(i==v)
			continue;
		j = i; 
		while(path[j] !=-1)
		{
			p->data[++p->top] = j;
			j = path[j];
		}
		p->data[++p->top] = v;
		cout<<v<<"到"<<i<<"的距离为："<<dist[i]<<"\t"<<"其路径为："; 
		while(p->top!=-1)
			cout<< p->data[p->top--]<<" ";
		cout<<endl;
	}
}
int main()
{
	build();
	Unweighted(3);
	getTail(3); 
	return 0;
}
/*
7 12
3 1
3 6
1 4
1 2
2 5
2 4
4 3
4 5
4 6
4 7
5 7
7 6
*/ 
