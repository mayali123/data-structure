// ȫ����
//#include<stdio.h>
//#include<string.h>
//#define N 4
////char path[N];
//char a[N] = { '1','2','3','4'};
//
//void backtrack(char *p,int len)
//{
//	// ����������
//	if (len == N)
//	{
//		for(int i=0;i<len;i++)
//			printf("%c ",p[i]);
//		printf("\n");
//	}
//	for (int k = 0; k < N; k++)
//	{
//		/*printf("%c\n",a[k]);*/
//		// ��֦
//		int flag = 0;
//		for (int j = 0; j < len; j++)
//			if (p[j] == a[k])
//				flag =1;
//		if (flag == 1)
//			continue;
//
//		// ѡ��
//		p[len] = a[k];
//		len++;
//		// ������һ��ѡ��
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


// 4 �ʺ�����
#include<stdio.h>
#define N 4
int a[N][N] = {0};
int num = 0;
int IsOK(int(*p)[N], int han, int lie)
{
	// ��
	for (int k = 0; k < han; k++)
	{
		if (p[k][lie] == 1)
			return 0;
	}

	// ���Ϸ�
	for (int i = han - 1, j = lie - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (p[i][j] == 1)
			return 0;
	}

	// ���Ϸ�
	for (int i = han - 1, j = lie + 1; i >= 0 && j < N; i--, j++)
	{
		if (p[i][j] == 1)
			return 0;
	}
	return 1;
}
void backtrack(int (*p)[N], int han)
{
	//�������� �ҵ���һ���������
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
