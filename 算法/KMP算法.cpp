#include<stdio.h>
#include<string.h>
#define N 200
void get_index(char* t, int* next)
{
	int i = 0, j = -1;
	int tlen = strlen(t);
	next[0] = -1;
	//printf("%d",tlen);
	while (i< tlen) // 找个地方写  i<len  or i<len-1  都没什么关系
	{
		if (j == -1 || t[i] == t[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}
int find(char* s, char* t,int *next)
{
	int i = 0, j = 0;
	int slen = strlen(s);
	int tlen = strlen(t);
	while (i <  slen && j < tlen)
	{
		if (j == -1|| s[i] == t[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j >= tlen)
		return i - tlen;
	return -1;
}
int main()
{
	char S[N], T[N];
	printf("请输入两个字符串：");
	scanf("%s%s",S,T);
	int next[N];
	get_index(T,next);
	int tlen = strlen(T);
	/*for (int i = 0; i < tlen; i++)
		printf("%d ",next[i]);*/
	printf("%s在%s的%d位置\n",T,S,find(S,T,next));
}
