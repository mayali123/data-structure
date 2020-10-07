// ��˳��洢ʵ�ֵĶ���
#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 5
#define ElemType int
typedef struct queue{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}QU;

QU* CreateQueue()
{
	QU* queue = (QU*)malloc(sizeof(QU));
	queue->front = -1;
	queue->rear = -1;
	return queue;
}

void addQueue(QU *queue,ElemType e)
{
	if ((queue->rear + 1) % MAXSIZE == queue->front)
	{
		printf("��������");
		return;
	}
	queue->rear = queue->rear+1 % MAXSIZE;
	queue->data[queue->rear] = e;
}

void DeleteQueue(QU* queue)
{
	if (queue->front == queue->rear)
	{
		printf("����Ϊ�գ�");
		return;
	}
	queue->front = queue->front + 1 % MAXSIZE;
}

void show(QU* queue)
{
	if(queue->front+1<queue->rear)
	{ 
		printf("С��");
		for (int i = queue->front+1; i <= queue->rear;i++)
		{
			printf("%d ", queue->data[i]);
		}
	}
	else
	{
		for (int i = queue->front+1; i <= MAXSIZE + queue->rear; i++)
		{
			printf("%d ",queue->data[i% MAXSIZE]);
		}
	}

}

int main()
{
	QU* queue= CreateQueue();
	ElemType ch;
	scanf_s("%d",&ch);
	while (ch != -1)
	{
		addQueue(queue,ch);
		scanf_s("%d", &ch);
	}
	show(queue);
	for (int i = 0; i < 2; i++)
		DeleteQueue(queue);
	printf("\n");
	show(queue);
	scanf_s("%d", &ch);
	while (ch != -1)
	{
		addQueue(queue, ch);
		scanf_s("%d", &ch);
	}
	show(queue);
}