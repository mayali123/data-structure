#include<stdio.h>
#include<string.h>
#define N 50
#define M 2*N-1
typedef struct {
	char data[10];
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTnode;
typedef struct {
	char cd[N];  // 用于保存 哈夫曼 编码
	int start;  // 因为是反着保存的 所以要保存开始的位置
}HCode;
void CreateHT(HTnode ht [],int n)   //  n 为结点数
{
	int i, k, lnode, rnode;
	for (i = 0; i < 2 * n - 1; i++) // 2*n-1 是 哈夫曼树的结点数  
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;

	int min1, min2;
	for (i = n; i < 2 * n - 1; i++)
	{
		min1 = min2 = 32767; // 设一个最大值
		lnode = rnode = -1;
		for (k = 0; k < i; k++)
		{
			if (ht[k].parent == -1)
			{
				//	找两个最小的  min2 第二小 min1第一小
				if (ht[k].weight < min1)
				{
					min2 = min1;
					rnode = lnode;


					min1 = ht[k].weight;
					lnode = k;
				}
				else if(ht[k].weight < min2)
				{ 
					min2 = ht[k].weight;
					rnode = k;
				}
			}
		}
		ht[rnode].parent = i;
		ht[lnode].parent = i;
		ht[i].weight = ht[rnode].weight + ht[lnode].weight;
		ht[i].lchild = lnode;
		ht[i].rchild = rnode;
	}
}

void CreateHCode(HTnode ht[],HCode hcd[] ,int n)
{
	int parent,now_index;
	for (int i = 0; i < n; i++)
	{
		now_index = i;  // 保存 现在的上一个的index
		hcd[i].start = n;
		parent = ht[i].parent;
		while (parent != -1)
		{
			if (ht[parent].lchild == now_index)  
				hcd[i].cd[--hcd[i].start] = '0';
			else
				hcd[i].cd[--hcd[i].start] = '1';
			now_index = parent;
			parent = ht[parent].parent;
		}
	}
}

void Disphocde(HTnode ht[],HCode hcd[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\t%s:\t",ht[i].data);
		for (int k = hcd[i].start; k < n; k++)
			printf("%c",hcd[i].cd[k]);
		printf("\n");
	}
}
void decode(HTnode ht[], char*ch,int n)
{
	// 根节点 为 2*n-2;
	int root = 2 * n - 2,now_index=root;
	for (int i = 0; ch[i] != '\0'; i++)
	{
		if(ch[i]=='0')
		{ 
			if (ht[now_index].lchild == -1)
			{
				printf("%s ",ht[now_index].data);
				now_index = root;
			}
			now_index = ht[now_index].lchild;
		}
		else if (ch[i] == '1')
		{
			if (ht[now_index].rchild == -1)
			{
				printf("%s ", ht[now_index].data);
				now_index = root;
			}
			now_index = ht[now_index].rchild;
		}
	}
	printf("%s ", ht[now_index].data);
}
int main()
{
	int n = 15;
	const char* str[] = {"The","of","a","to","and","in","that","he","is","at","on","for","His","are","be"};
	int fnum[] = { 1192,677,541,518,462,450,242,195,190,181,174,157,138,124,123 };
	HTnode ht[M];
	HCode hcd[N];
	for (int i = 0; i < n; i++)
	{
		strcpy_s(ht[i].data, str[i]);
		ht[i].weight = fnum[i];
	}
	CreateHT(ht,n);
	CreateHCode(ht,hcd,n);
	Disphocde(ht,hcd,n);
	char  ch[] = "100011000001101000\0";
	decode(ht,ch,n);
}