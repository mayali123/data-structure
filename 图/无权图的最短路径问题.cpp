//#include<bits/stdc++.h>
//#define MaxVertex  200
//using namespace std;
//int path[MaxVertex];
//int dist[MaxVertex];  // 存储路径长度
//int G[MaxVertex][MaxVertex]; // 图
//int Ne;  // 顶点数 
//int Nv;  // 边 
//typedef struct queue{
//	int data[MaxVertex];
//	int front,rear;
//}QU;
//typedef struct stack{
//	int data[MaxVertex];
//	int top;
//}ST;
//void build()
//{
//	int i,j;
// 	cin>>Nv;
// 	for(i=1;i<=Nv;i++)
// 		for(j=1;j<=Nv;j++)
// 			G[i][j] = 0;
// 	for(i=1;i<=Nv;i++)
// 	{
// 		path[i] = -1;
//		dist[i] = -1;	
//	}
// 	cin>> Ne;
// 	int v1,v2;  //有向图 无权图 
//	for(i=0;i<Ne;i++)
//	{
//		cin>>v1>>v2;
//		G[v1][v2] = 1;  
//	} 
//}
//// v 是起点  
//void Unweighted(int v)
//{
//	int i,j;
//	QU *p =(QU*)malloc(sizeof(QU));
//	p->front= p->rear = -1;
//	p->data[++p->rear] = v;
//	dist[v] = 0; 
//	//当其不为空时 
//	while(p->front!=p->rear)
//	{
//		i = p->data[++p->front];
//		for(j=1;j<=Nv;j++)
//			if(dist[j]==-1&&G[i][j]!=0)
//			{
//				dist[j] = dist[i]+1;
//				path[j] = i;
//				p->data[++p->rear] = j;
//			}
//	}
//}
//void getTail(int v)
//{
//	int i,j;
//	ST * p=(ST*) malloc(sizeof(ST));
//	
//	for(i=1;i<=Nv;i++)
//	{
//		p->top=-1; 
//		if(i==v)
//			continue;
//		j = i; 
//		while(path[j] !=-1)
//		{
//			p->data[++p->top] = j;
//			j = path[j];
//		}
//		p->data[++p->top] = v;
//		cout<<v<<"到"<<i<<"的距离为："<<dist[i]<<"\t"<<"其路径为："; 
//		while(p->top!=-1)
//			cout<< p->data[p->top--]<<" ";
//		cout<<endl;
//	}
//}
//int main()
//{
//	build();
//	Unweighted(3);
//	getTail(3); 
//	return 0;
//}
#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<queue>
#include<stack>
#define Init -1
#define MaxVertex  100
int path[MaxVertex];  // 存储路径
int dist[MaxVertex];  // 存储路径长度
int G[MaxVertex][MaxVertex]; // 图
int Ne;  // 顶点数 
int Nv;  // 边 
typedef int Vertex;
using namespace std;


void build(){
	int v1,v2;
	// 初始化点 
	cin>>Nv;
	for(int i=1;i<=Nv;i++)
		for(int j=1;j<=Nv;j++)
		 	G[i][j] = 0;
	// 初始化路径
	for(int i=1;i<=Nv;i++)
		path[i] = Init;
	// 初始化路径长度
	for(int i=1;i<=Nv;i++)
		 dist[i] = Init;
	// 初始化边 
	cin>>Ne;
	for(int i=0;i<Ne;i++){
		cin>>v1>>v2;
		G[v1][v2] = 1; // 有向图！ 
	}
}

void Unweighted(Vertex v){
	queue<Vertex> q;
	dist[v] = 0;  // 将自己的距离置 0 
	Vertex w;
	q.push(v);
	while(!q.empty()){
		 w = q.front();
		 q.pop();
		 for(int i=1;i<=Nv;i++)
		 	// 如果没被访问过，且连通 
		 	if(dist[i]==Init && G[w][i]){
		 		dist[i] = dist[w]+1;  // 是上一步的距离 + 1 
		 		path[i] = w;  // w 是上一步要走路径的下一步路径 
		 		q.push(i);
		 	}
	}
}

// 获取路径 
void getTail(Vertex v){
	for(int i=1;i<=Nv;i++){
		if(i==v)
			continue;
		stack<Vertex> s;
		cout<<v<<"到"<<i<<"的最短距离是："<<dist[i];
		Vertex w = i;
		// 当没到达起始起点前一直做循环 
		while(path[w]!=Init){
			s.push(w);  // 入栈 
			w = path[w];
		}
		// 逆序输出入栈元素，得到路径 
		cout<<"    其路径为：";
		if(v != i)
			cout<<v;
		while(!s.empty()){
			// 输出栈顶元素 
			cout<<"→"<<s.top();
			s.pop(); // 出栈 
		}
		cout<<endl;
	}
}


int main(){
	build();
	Unweighted(3);
	getTail(3); 
	return 0;
}
