#include<stdio.h>
#include<string.h>
// a b a b a a a b a
// 0     2 3 4
// i . . . 3 4 5 6 
// j . . . 1 2 3 4 
void Get_next(char *T,int *next)
{
	int i=1, j=0;  //i  后缀  j 前缀 j还可以表示相同部分的最长的长度
	next[1] = 0;
	while (i < T[0]-'0')
	{
		if (j==0||T[j] == T[i] )
		{
			j++;
			i++;
			next[i] = j;
		}
		else  // j!=0
		{
			j = next[j];
		}
	}
}

int get_index(char *T,char *T2,int pos)
{
	int i = pos,j=1;
	int next[255];
	Get_next(T2, next);
	while (i <= T[0]-'0' && j <= T2[0]-'0')
	{
		if (T[i] == T2[j]||j==0)
		{
			i++;
			j++;
		}
		else 
		{
			j = next[j];
		}
	}
	/*printf("i = %d j = %d ,%d \n",i,j, T2[0] - '0');*/
	if (j > T2[0]-'0')
		return i -(T2[0]-'0');
	else
		return 0;
}

int main()
{
	char s[] = " dbabcbc";
	char T[] = " b";
	s[0] = 7+'0';
	T[0] = 1+'0';
	printf("%d",get_index(s,T,1));
}