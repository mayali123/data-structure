#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
#define false 0
#define bool int 
#define ElemType char
typedef struct  Stack
{
	ElemType data[MaxSize];
	int top;
}SqStack;
SqStack* InitStack()
{
	SqStack *s=(SqStack*)malloc(sizeof(SqStack));
	s->top=-1;
	return s; 
}
void DestroyStack(SqStack *&s)
{
	free(s);
}
bool StackEmpty(SqStack*s)
{
	return(s->top==-1);
}
bool Push(SqStack *s,ElemType e)
{
	if (s->top==MaxSize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}
bool Pop(SqStack *&s,ElemType &e)
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(SqStack*s,ElemType &e)
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	return true;
}
int main()
{
	ElemType e;
	
	printf("˳��ջ�Ļ����������£�\n");
	printf("��1����ʼ��ջs\n");
	SqStack *s=InitStack();
	printf("��2��ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	printf("��3�����ν�ջԪ��a,b,c,d\n");
	Push(s,'a');
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	printf("��4��ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	printf("��5����ջ����:");
	while(!StackEmpty(s))
	{
		Pop(s,e);
		printf("%c",e); 
	}
	printf("\n");
	printf("��6��ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	printf("��7���ͷ�ջ\n");
	DestroyStack(s);
	return 1;
}
