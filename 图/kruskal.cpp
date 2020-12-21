#include<bits/stdc++.h>
#define MAXVER 200
#define MAXEDGE 300
using namespace std;
typedef struct Node {
	int begin, end, weight;
}node;
bool cmp(node a,node b)  // ��С������
{
	return a.weight < b.weight;
}
// �ҵ�f���ڼ��� �ĸ��ڵ� 
int Find(int *parent,int f)
{
	while (parent[f] > 0)
		f = parent[f];   //��� ���� ���׽�㲻�Ǹ��ڵ� ���Ҹ��׽ڵ�� ���ڵ�
	return f;			// ���� ���ڼ��� �� ���ڵ� 	
}
void kruskal()
{
	// vertex_num �����
	// edge_num ����
	int vertex_num, edge_num ,i,n,m;
	node edge[MAXEDGE];		// �����
	int parent[MAXVER];		//  �������� ���ϵ� ���ڵ� 
	printf("��ֱ����������ͱ���:"); 
	scanf("%d%d",&vertex_num,&edge_num);
	for (i = 0; i < edge_num; i++)
		cin >> edge[i].begin >> edge[i].end >> edge[i].weight;

	// ��С������
	sort(edge, edge+ edge_num,cmp);
	
	// ��ʼ�� parent ���� Ҳ����ÿ�� ���Լ��ĸ��ڵ�
	for (i = 0; i <= vertex_num; i++)
		parent[i] = 0;	// �� 0 ��Ϊ ���ڵ�ı�־ 
	
	for (i = 0; i < edge_num; i++)
	{
		// �ҵ� begin end ���ڵļ��� �� ���ڵ�
		n = Find(parent,edge[i].begin);
		m = Find(parent,edge[i].end);
		//printf("n=%d m=%d \n",n,m);
		if (n != m)
		{
			// �ϲ� ���� 
			parent[m] = n;
			printf("(%d,%d) %d \n", edge[i].begin, edge[i].end,edge[i].weight);
		}
	}
}
int main()
{
	kruskal();
}

// 7 9
//0 1 28
//0 5 10
//1 6 14
//1 2 16
//5 4 25
//6 4 24
//6 3 18
//2 3 12
//4 3 22