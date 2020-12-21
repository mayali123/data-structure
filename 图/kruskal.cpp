#include<bits/stdc++.h>
#define MAXVER 200
#define MAXEDGE 300
using namespace std;
typedef struct Node {
	int begin, end, weight;
}node;
bool cmp(node a,node b)  // 从小到大排
{
	return a.weight < b.weight;
}
// 找到f所在集合 的根节点 
int Find(int *parent,int f)
{
	while (parent[f] > 0)
		f = parent[f];   //如果 他的 父亲结点不是根节点 则找父亲节点的 根节点
	return f;			// 返回 所在集合 的 根节点 	
}
void kruskal()
{
	// vertex_num 结点数
	// edge_num 边数
	int vertex_num, edge_num ,i,n,m;
	node edge[MAXEDGE];		// 保存边
	int parent[MAXVER];		//  用来保存 集合的 父节点 
	printf("请分别输入结点数和边数:"); 
	scanf("%d%d",&vertex_num,&edge_num);
	for (i = 0; i < edge_num; i++)
		cin >> edge[i].begin >> edge[i].end >> edge[i].weight;

	// 从小到大排
	sort(edge, edge+ edge_num,cmp);
	
	// 初始化 parent 数组 也就是每个 是自己的根节点
	for (i = 0; i <= vertex_num; i++)
		parent[i] = 0;	// 用 0 作为 根节点的标志 
	
	for (i = 0; i < edge_num; i++)
	{
		// 找到 begin end 所在的集合 的 根节点
		n = Find(parent,edge[i].begin);
		m = Find(parent,edge[i].end);
		//printf("n=%d m=%d \n",n,m);
		if (n != m)
		{
			// 合并 集合 
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