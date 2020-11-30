#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 200
#define Status int
typedef struct String{
	char data[MAXSIZE];
	int length;
}Str;

// 赋值
void strAssign(Str &str,char *src)
{
	int i=0;
	for(;src[i]!='\0';i++)
	{
		str.data[i]= src[i];
	}
	str.length = i; 
}
// copy
void strCopy(Str &str,Str src)
{
	for(int i=0;i<src.length;i++)
		str.data[i] = src.data[i];
	str.length=src.length;
}
// 相等 
Status strEqual(Str str,Str t)
{
	if(str.length!=t.length)
		return FALSE;
	for(int i=0;i<str.length;i++)
	{
		if(str.data[i]!=t.data[i])
			return FALSE;
	}
	return TRUE;
}

int strLength(Str str)
{
	return str.length;
}

// 将 str 与 t 连接在一起 通过return返回 
Str Concat(Str str,Str t)
{
	Str str1;
	for(int i=0;i<str.length;i++)
		str1.data[i] = str.data[i];
	for(int i=0;i<t.length;i++)
		str1.data[str.length+i] = t.data[i];
	str1.length = str.length+t.length;
	return str1;
}

// 求子串
Str Substr(Str str,int a,int b)  // i 从1开始  从第i个 取j个 
{
	Str t;
	t.length=0;
	if(a<=0||a>str.length||b<0||a+b-1>str.length)
		return t;  
	for(int i=0;i<b;i++)
		t.data[i]=str.data[a+i-1];
	t.length =  b;
	return t;
}
void DispStr (Str str)
{
	for(int i=0;i<str.length;i++)
		printf("%c",str.data[i]);
	printf("\n");
}
Str InsStr(Str str,int i,Str t) // 在 str 的第 i 个位置插入 t 
{
	Str st;
	int j;
	st.length = 0;
	if(i<=0||i>str.length+1)
		return st;
	
	for(j=0;j<i-1;j++)
		st.data[j] = str.data[j];
	for(j=0;j<t.length;j++)
		st.data[i-1+j] = t.data[j];
	for(j=i-1;j<str.length;j++)
		st.data[j+t.length] = str.data[j];
	st.length = str.length+t.length;
	return st;
}

Str DelStr(Str str,int a,int b) 
{
	Str st;
	st.length = 0;
	
	if(a<=0||a>str.length||b<0||a+b-1>str.length)
		return st;  
		
	for(int i=0;i<a-1;i++)
		st.data[i]=str.data[i];
		
	for(int i=a+b-1;i<str.length;i++)
		st.data[i-a]=str.data[i];

	st.length =  str.length - b;
	
	return st;
}
Str RepStr(Str str,int a,int b,Str src) 
{
	int i;
	Str st;
	st.length = 0;
	
	if(a<=0||a>str.length||b<0||a+b-1>str.length)
		return st;  
	
	for(i=0;i<a-1;i++)
		st.data[i] = str.data[i];
	for(i=0;i<src.length;i++)
		st.data[a+i-1] = src.data[i];
	for(i=a+b-1;i<str.length;i++)
		st.data[src.length+i-b] = str.data[i];
	st.length = str.length - b + src.length;
	return st;
}
int main()
{
	Str s,s1,s2,s3,s4;
	
	strAssign(s,"abcdefj");
	printf("将s赋值为：");
	DispStr(s); 
	printf("将s的长度为%d\n",strLength(s));
	
	printf("将s复制到s1中：");
	strCopy(s1,s); 
	DispStr(s1); 
	
	printf("判断s和s1是否相等 %d\n",strEqual(s,s1));
	
	printf("将s和s1是连接在一起 s2:");
	s2 = Concat(s,s1);
	DispStr(s2);
	
	printf("求s2  2~4 的字串 ");
	s3 = Substr(s2,2,2);
	DispStr(s3);
	
	printf("将s3  插入s2中 赋值给s1： ");
	s1 =InsStr(s2,3,s3); 
	DispStr(s1);
	
	printf("删除s1 2~12 s1： ");
	s1= DelStr(s1,2,10); 
	DispStr(s1);
	
	strAssign(s4,"22");
	printf("用s4 代替 s1 2~4 s1:");
	s1 = RepStr(s1,2,2,s4);
	DispStr(s1);
	return 0;
}
