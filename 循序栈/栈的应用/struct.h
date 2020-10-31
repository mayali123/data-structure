#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define ElemType char 
#define MAXSIZE 100
#define Status int 
#define Error 0
#define True 1
#define FALSE 0
#define OK 1
typedef struct stack {
	ElemType data[MAXSIZE];
	int top;
}ST;
ST* InitStack()
{
	ST* stack = (ST*)malloc(sizeof(ST));
	stack->top = -1;
	return stack;
}

Status Push(ST* stack, ElemType e)
{
	if (stack->top == MAXSIZE - 1)
		return FALSE;
	stack->data[++stack->top] = e;
	return OK;
}

Status Pop(ST* stack, ElemType* e)
{
	if (stack->top == -1)
		return FALSE;
	*e = stack->data[stack->top--];
	return OK;
}

void DestroyStack(ST* stack)
{
	free(stack);
}


int StackEmpty(ST* stack)
{
	return (stack->top == -1);
}

int GetTop(ST* stack, ElemType* e)
{
	if (stack->top == -1)
		return Error;
	*e = stack->data[stack->top];
	return True;
}

void show(ST* stack)
{
	int i = 0;
	for (; i <= stack->top; i++)
	{
		printf("%c", stack->data[i]);
	}
}

//  数字 转 字符串
void NumToChar(int a, char* ch)
{
	char ch1[MAXSIZE];
	int j = 0;
	while (a)
	{
		ch1[j++] = a % 10 + '0';
		a /= 10;
	}
	ch1[j] = '\0';
	int k = 0;
	// 反转
	for (; k < strlen(ch1); k++)
	{
		ch[k] = ch1[strlen(ch1) - 1 - k];
	}
	// 用 空格分开
	ch[k++] = ' ';
	ch[k] = '\0';
}

Status Pop_num(ST* stack, int* e)
{
	// 栈空
	if (stack->top == -1)
		return FALSE;
	char ch = stack->data[stack->top], ch1[MAXSIZE], ch2[MAXSIZE];
	int flag = 1, a = 0, k = 0, j;
	while (!StackEmpty(stack))
	{
		if (ch == ' ')
		{
			if (flag == 1)
				flag = 0;
			else
				break;
		}
		else
		{
			ch1[k++] = ch;
		}
		ch = stack->data[--stack->top];
	}
	ch1[k] = '\0';
	//反转
	for (j = 0; j < strlen(ch1); j++)
		ch2[j] = ch1[strlen(ch1) - j - 1];
	ch2[j] = '\0';
	// 字符串转数字
	for (j = 0; j < strlen(ch2); j++)
		a = a * 10 + ch2[j] - '0';
	*e = a;
	return OK;
}
Status Push_num(ST* stack, int e)
{
	if (stack->top == MAXSIZE - 1)
		return FALSE;
	char ch[200];
	NumToChar(e, ch);
	//printf("ch = %s",ch);
	int i = 0;
	for (; i < strlen(ch); i++)
		stack->data[++stack->top] = ch[i];
	return OK;
}