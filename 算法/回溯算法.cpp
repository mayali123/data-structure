#include<stdio.h>
#include<string.h>
#define N 4
//char path[N];
char a[N] = { '1','2','3','4'};

void backtrack(char *p,int len)
{
	// 结束的条件
	if (len == N)
	{
		for(int i=0;i<len;i++)
			printf("%c ",p[i]);
		printf("\n");
	}
	for (int k = 0; k < N; k++)
	{
		/*printf("%c\n",a[k]);*/
		// 剪枝
		int flag = 0;
		for (int j = 0; j < len; j++)
			if (p[j] == a[k])
				flag =1;
		if (flag == 1)
			continue;

		// 选择
		p[len] = a[k];
		len++;
		// 进行下一次选择
		backtrack(p, len);
		// 
		len--;
	}
	
}
int main()
{
	char path[N];
	backtrack(path,0);
}