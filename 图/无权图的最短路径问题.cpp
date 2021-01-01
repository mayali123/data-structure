//#include<bits/stdc++.h>
//#define MaxVertex  200
//using namespace std;
//int path[MaxVertex];
//int dist[MaxVertex];  // �洢·������
//int G[MaxVertex][MaxVertex]; // ͼ
//int Ne;  // ������ 
//int Nv;  // �� 
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
// 	int v1,v2;  //����ͼ ��Ȩͼ 
//	for(i=0;i<Ne;i++)
//	{
//		cin>>v1>>v2;
//		G[v1][v2] = 1;  
//	} 
//}
//// v �����  
//void Unweighted(int v)
//{
//	int i,j;
//	QU *p =(QU*)malloc(sizeof(QU));
//	p->front= p->rear = -1;
//	p->data[++p->rear] = v;
//	dist[v] = 0; 
//	//���䲻Ϊ��ʱ 
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
//		cout<<v<<"��"<<i<<"�ľ���Ϊ��"<<dist[i]<<"\t"<<"��·��Ϊ��"; 
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
int path[MaxVertex];  // �洢·��
int dist[MaxVertex];  // �洢·������
int G[MaxVertex][MaxVertex]; // ͼ
int Ne;  // ������ 
int Nv;  // �� 
typedef int Vertex;
using namespace std;


void build(){
	int v1,v2;
	// ��ʼ���� 
	cin>>Nv;
	for(int i=1;i<=Nv;i++)
		for(int j=1;j<=Nv;j++)
		 	G[i][j] = 0;
	// ��ʼ��·��
	for(int i=1;i<=Nv;i++)
		path[i] = Init;
	// ��ʼ��·������
	for(int i=1;i<=Nv;i++)
		 dist[i] = Init;
	// ��ʼ���� 
	cin>>Ne;
	for(int i=0;i<Ne;i++){
		cin>>v1>>v2;
		G[v1][v2] = 1; // ����ͼ�� 
	}
}

void Unweighted(Vertex v){
	queue<Vertex> q;
	dist[v] = 0;  // ���Լ��ľ����� 0 
	Vertex w;
	q.push(v);
	while(!q.empty()){
		 w = q.front();
		 q.pop();
		 for(int i=1;i<=Nv;i++)
		 	// ���û�����ʹ�������ͨ 
		 	if(dist[i]==Init && G[w][i]){
		 		dist[i] = dist[w]+1;  // ����һ���ľ��� + 1 
		 		path[i] = w;  // w ����һ��Ҫ��·������һ��·�� 
		 		q.push(i);
		 	}
	}
}

// ��ȡ·�� 
void getTail(Vertex v){
	for(int i=1;i<=Nv;i++){
		if(i==v)
			continue;
		stack<Vertex> s;
		cout<<v<<"��"<<i<<"����̾����ǣ�"<<dist[i];
		Vertex w = i;
		// ��û������ʼ���ǰһֱ��ѭ�� 
		while(path[w]!=Init){
			s.push(w);  // ��ջ 
			w = path[w];
		}
		// ���������ջԪ�أ��õ�·�� 
		cout<<"    ��·��Ϊ��";
		if(v != i)
			cout<<v;
		while(!s.empty()){
			// ���ջ��Ԫ�� 
			cout<<"��"<<s.top();
			s.pop(); // ��ջ 
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
