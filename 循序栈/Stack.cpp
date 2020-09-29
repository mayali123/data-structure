# include<stdio.h>
# include<malloc.h>
#define TpyeElem int
#define MAXSIZE 20
#define Error 0
#define True 1
/*
	ADT 线性栈
	操作集： 
		InitStack()				初始化
		DestroyStack(ST *St)	销毁
		StackEmpty(ST *St)		判断是否为空
		Push(ST* St, TpyeElem e)压入
		Pop(ST* St, TpyeElem* e)弹出
		GetTop(ST* St, TpyeElem* e)得到栈顶的元素
*/

typedef struct stack
{
	TpyeElem data[MAXSIZE];
	int top;
}ST;

ST* InitStack()
{
	ST* St = (ST*)malloc(sizeof(ST));
	St->top = -1;
	return St;

}

void DestroyStack(ST* St)
{
	free(St);
}

// 为空返回 1  不为空返回0
int StackEmpty(ST* St)
{
	return (St->top == -1);
}

int Push(ST* St, TpyeElem e)
{
	if (St->top == MAXSIZE - 1)
		return Error;
	St->top++;
	St->data[St->top] = e;
	return True;
}

int Pop(ST* St, TpyeElem* e)
{
	if (St->top == -1)
		return Error;
	*e = St->data[St->top];
	St->top--;
	return True;
}

int GetTop(ST* St, TpyeElem* e)
{
	if (St->top == -1)
		return Error;
	*e = St->data[St->top];
	return True;
}

void show(ST* St)
{
	for (int i = 0; i <= St->top; i++)
	{
		printf("%d ", St->data[i]);
	}
}

int main()
{
	ST* stack = InitStack();
	int j,e;
	while (1)
	{
		scanf_s("%d",&j);
		if (j == -1)
			break;
		Push(stack, j);
	}
	show(stack);
	Pop(stack, &e);
	printf("弹出%d\n",e);
	show(stack);
	GetTop(stack,&e);
	printf("栈顶%d\n", e);

}
