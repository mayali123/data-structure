#include<stdio.h>
#include<string.h>
#define N 4
//char path[N];
char a[N] = { '1','2','3','4'};

void backtrack(char *p,int len)
{
	// ����������
	if (len == N)
	{
		for(int i=0;i<len;i++)
			printf("%c ",p[i]);
		printf("\n");
	}
	for (int k = 0; k < N; k++)
	{
		/*printf("%c\n",a[k]);*/
		// ��֦
		int flag = 0;
		for (int j = 0; j < len; j++)
			if (p[j] == a[k])
				flag =1;
		if (flag == 1)
			continue;

		// ѡ��
		p[len] = a[k];
		len++;
		// ������һ��ѡ��
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