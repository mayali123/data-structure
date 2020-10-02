#include<stdio.h>
#include<malloc.h>
#define TypeElem int 
#define N 4 
typedef struct LinkStack
{
	TypeElem data;
	struct LinkStack* next;
}LS;
LS* InitStack()
{
	LS* stack = (LS*)malloc(sizeof(LS));
	stack->next = NULL;
	return stack;
}

void Push(LS *stack, TypeElem e)  //是将 st 放到第一个那
{
	LS* st = (LS*)malloc(sizeof(LS));
	st->data = e;
	st->next = stack->next;
	stack->next = st;
}


int StackEmpty(LS* stack)
{
	return stack->next == NULL;
}
void Pop(LS* stack, TypeElem* e)
{
	if (StackEmpty(stack))
		return;
	LS* st = stack->next;
	*e = st->data;
	stack->next = st->next;
	free(st);
}

int StackLength(LS* stack)
{
	int num = 0;
	LS* st2 = stack->next;
	while (st2)
	{ 
		st2 = st2->next;
		num++;
	}
	return num;
}

void DestroyStack(LS* stack)
{
	LS* st2 ;
	while (stack)
	{
		st2 = stack->next;
		free(stack);
		stack = st2;
	}
}

void show(LS* stack)
{
	LS* st2=stack->next;
	while (st2)
	{
		printf("%d ",st2->data);
		st2 = st2->next;
	}
}
int main()
{
	TypeElem e[N] = {2,4,7,65},E;
	LS* stack = InitStack();
	for (int i = 0; i < N; i++)
		Push(stack, e[i]);
	show(stack);
	Pop(stack,&E);
	printf("E=%d \n",E);
	show(stack);
	printf("len=%d\n", StackLength(stack));
	DestroyStack(stack);
	return 0;
} 