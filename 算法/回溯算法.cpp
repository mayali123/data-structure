// 全排列
//#include<stdio.h>
//#include<string.h>
//#define N 4
////char path[N];
//char a[N] = { '1','2','3','4'};
//
//void backtrack(char *p,int len)
//{
//	// 结束的条件
//	if (len == N)
//	{
//		for(int i=0;i<len;i++)
//			printf("%c ",p[i]);
//		printf("\n");
//	}
//	for (int k = 0; k < N; k++)
//	{
//		/*printf("%c\n",a[k]);*/
//		// 剪枝
//		int flag = 0;
//		for (int j = 0; j < len; j++)
//			if (p[j] == a[k])
//				flag =1;
//		if (flag == 1)
//			continue;
//
//		// 选择
//		p[len] = a[k];
//		len++;
//		// 进行下一次选择
//		backtrack(p, len);
//		// 
//		len--;
//	}
//	
//}
//int main()
//{
//	char path[N];
//	backtrack(path,0);
//}


// 4 皇后问题
#include<stdio.h>
#define N 4
int a[N][N] = {0};
int num = 0;
int IsOK(int(*p)[N], int han, int lie)
{
	// 列
	for (int k = 0; k < han; k++)
	{
		if (p[k][lie] == 1)
			return 0;
	}

	// 左上方
	for (int i = han - 1, j = lie - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (p[i][j] == 1)
			return 0;
	}

	// 右上方
	for (int i = han - 1, j = lie + 1; i >= 0 && j < N; i--, j++)
	{
		if (p[i][j] == 1)
			return 0;
	}
	return 1;
}
void backtrack(int (*p)[N], int han)
{
	//结束条件 找到了一个解决方法
	if (han == N)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				printf("%d ",p[i][j]);
			printf("\n");
		}
		num++;
		printf("\n");
	}
	for (int k = 0; k < N; k++)
	{
		if (!IsOK(p, han, k))
			continue;
		p[han][k] = 1;
		backtrack(p, han + 1);
		p[han][k] = 0;
	}

}
int main()
{
	backtrack(a, 0);
	printf("num=%d\n",num);
}
