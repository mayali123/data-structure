// 用链表实现的队列
#include<stdio.h>
#include<malloc.h>
#define ElemType int 
typedef struct List{
	ElemType data;
	struct List* next;
}L;

typedef struct LinkQueue{
	L* front;
	L* rear;
}LQ;

LQ* CreateLinkQueue()
{
	LQ* lq = (LQ*)malloc(sizeof(LQ));
	lq->front = lq->rear = NULL;
	return lq;
}

void AddElem(LQ *lq,ElemType e)
{
	L* n = (L*)malloc(sizeof(L));
	n->data = e;
	if (lq->rear == NULL)
	{
		lq->front = n;
		lq->rear = n;
	}
	else
	{
		lq->rear->next = n;
		lq->rear=n;
		lq->rear->next = NULL;
	}
}

void show(LQ* lq)
{
	L* list = lq->front;
	while (list!=NULL)
	{
		printf("%d ",list->data);
		list = list->next;
	}
	printf("\n");
}

void DeletElem(LQ* lq)
{
	if (lq->front == NULL)
	{
		printf("队列为空！");
		return;
	}
	L* n= lq->front;
	lq->front = lq->front->next;
	free(n);
}
int main()
{
	LQ* lq = CreateLinkQueue();
	for (int i = 0; i < 5; i++)
	{
		AddElem(lq, i);
	}
	show(lq);
	for (int i = 0; i < 2; i++)
		DeletElem(lq);
	show(lq);
	return 0;
}