#include<stdio.h>
#include<malloc.h> 
#define MAXSIZE 200 
typedef struct {
	int n;
	char a,b,c;
	int flag;  // 0代表可以不移动 1代表可以移动 
}Data;
typedef struct {
	Data data[MAXSIZE];
	int top;
}stack;
// 函数功能 将 a杠的盘 移动到 c杠 
// 递归实现 
void hanoi(int n,char a,char b,char c) 
{
	if(n==1)
		printf("将%c移动到%c\n",a,c);
	else
	{
		// 先 将 a杠上 n-1个 的 盘 移动 b杠 
		hanoi(n-1,a,c,b); 
		//  将 a 杠最后 一个盘 的  移动 c 杠
		hanoi(1,a,b,c);
		// 然后将 b 杠 移动 到 c杠 
		hanoi(n-1,b,a,c);
	}
}

// 函数功能 将 a杠的盘 移动到 c杠 
// 非递归 
void hanoi2(int n,char a,char b,char c) 
{
	// 用 栈 实现 存取数据
	// 初始化栈 
	stack * p =(stack*)malloc(sizeof(stack));
	p->top=-1;
	
	Data e,e1,e2,e3,e4;
	e.a =a;
	e.b = b;
	e.c = c;
	e.n = n;
	if(n!=1)
		e.flag = 0;
	else 
		e.flag = 1; 
	p->data[++p->top] = e; 
	while(p->top!=-1)  // 不为空时 
	{
		e1 = p->data[p->top--];
		
		
		if(e1.flag== 1)  //可以直接移动
			printf("将%c移动到%c\n",e1.a,e1.c);
		else
		{
			//hanoi(n-1,b,a,c);
			e2.n = e1.n -1;
			e2.a = e1.b;
			e2.b =e1.a;
			e2.c = e1.c;
			if(e2.n ==1) 
				e2.flag =1;
			else
				e2.flag=0;
			// 入栈 
			p->data[++p->top] = e2; 
			
			
			// 实现 hanoi(1,a,b,c);
			e3 = e1;
			e3.flag = 1;
			// 入栈 
			p->data[++p->top] = e3; 

			// 实现 hanoi(n-1,a,c,b); 
			
			e4.n = e1.n -1;
			e4.a = e1.a;
			e4.b =e1.c;
			e4.c = e1.b;
			if(e4.n == 1) 
				e4.flag =1;
			else
				e4.flag=0;
			// 入栈 
			p->data[++p->top] = e4; 
		}
		
	} 
}
int main()
{
	int n;
	printf("请输入层数：");
	scanf("%d",&n);
	hanoi(n,'A','B','C'); 
	printf("\n"); 
	hanoi2(n,'A','B','C');
}
