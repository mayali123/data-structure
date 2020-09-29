# include<stdio.h>
# include<malloc.h>
#define TpyeElem int
#define MAXSIZE 20
#define Error 0
#define True 1
/*
	ADT 两栈共享线性栈
	操作集：
		InitStack()				初始化
		DestroyStack(ST *St)	销毁
		StackEmpty(ST *St)		判断是否为空
		Push(ST* St, TpyeElem e)压入
		Pop(ST* St, TpyeElem* e)弹出
		GetTop(ST* St, TpyeElem* e)得到栈顶的元素
*/

typedef struct Doubletack
{
	TpyeElem data[MAXSIZE];
	int top1;
	int top2;
}DS;

DS* InitStack()
{
	DS* St = (DS*)malloc(sizeof(DS));
	St->top1 = -1;
	St->top2 = MAXSIZE;
	return St;
}

void DestroyStack(DS* St)
{
	free(St);
}

// 为空返回 1  不为空返回0
int StackEmpty(DS* St)
{
	return (St->top1 == -1&& St->top2==MAXSIZE);
}

// 用 Tag 来区分两个不同的 线性栈 0代表前面的栈   1代表后面的栈
int Push(DS* St, TpyeElem e,int Tag)
{
	if (St->top2 -St->top1==1 )
		return Error;
	if (Tag == 0)
		St->data[++St->top1] = e;
	else if (Tag == 1)
		St->data[--St->top2] = e;
	else
		printf("格式错误");
	return True;
}

int Pop(DS* St, TpyeElem* e, int Tag)
{
	if ((St->top1 == -1&& Tag==0)||(St->top2 == MAXSIZE && Tag == 1))
		return Error;
	if (Tag == 0)
		*e = St->data[St->top1--];
	else if (Tag == 1)
		*e = St->data[St->top2++];
	else
		printf("输入格式错误");
	return True;
}

int GetTop(DS* St, TpyeElem* e, int Tag)
{
	if ((St->top1 == -1 && Tag == 0) || (St->top1 == MAXSIZE && Tag == 1))
		return Error;
	if (Tag == 0)
		*e = St->data[St->top1];
	else if (Tag == 1)
		*e = St->data[St->top2];
	return True;
}

void show(DS* St,int Tag)
{
	printf("\n");
	if (Tag == 0)
		for (int i = 0; i <= St->top1; i++)
			printf("%d ", St->data[i]);
	else if (Tag == 1)
		for (int i = MAXSIZE - 1; i >= St->top2; i--)
			printf("%d ", St->data[i]);
	else
		printf("格式错误");

}

int main()
{
	DS* stack = InitStack();
	int j, e;
	while (1)
	{
		scanf_s("%d", &j);
		if (j == -1)
			break;
		Push(stack, j,1);
	}
	while (1)
	{
		scanf_s("%d", &j);
		if (j == -1)
			break;
		Push(stack, j, 0);
	}
	show(stack,1);
	show(stack,0);
	Pop(stack, &e,0);
	printf("第一个弹出%d\n", e);
	show(stack,1);
	GetTop(stack, &e,1);
	printf("第二个栈顶%d\n", e);

}
