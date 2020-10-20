#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 5
#define Status int
#define ElemType int  
typedef struct queue {
	ElemType data[MAXSIZE];
	int front;
	int rear;
}QU;

//QU* InitQueue()
//{
//	QU* queue=(QU*)malloc(sizeof(QU));
//	queue->front = queue->rear = -1;
//	return queue;
//
//}
//void Destory(QU*queue)
//{
//	free(queue);
//}
//int QueueEmpty(QU* queue)
//{
//	return(queue->rear == queue->front);
//}
//Status enQueue(QU* queue,ElemType e)
//{
//	if (queue->rear == MAXSIZE - 1)
//		return FALSE;
//	queue->data[++queue->rear] = e;
//	return OK;
//}
//Status deQueue(QU* queue, ElemType* e)
//{
//	if (queue->front == queue->rear)
//		return FALSE;
//	*e = queue->data[++queue->front];
//	return OK;
//}
//void show(QU* queue)
//{
//	for (int i = queue->front+1; i <= queue->rear; i++)
//		printf("%d ",queue->data[i]);
//	printf("\n");
//}
//int main()
//{
//	QU*queue=InitQueue();
//	for (int i = 0; i < 10; i++)
//	{
//		enQueue(queue,i);
//	}
//	show(queue);
//	for(int i=0;i<3;i++)
//	{ 
//		deQueue(queue,&i);
//		printf("删除%d\n",i);
//	}
//	show(queue);
//}

// 循环队列
QU* InitQueue()
{
	QU* queue=(QU*)malloc(sizeof(QU));
	queue->front = queue->rear = 0;  //这里必需要设为0 
	return queue;
}
void Destory(QU*queue)
{
	free(queue);
}
int QueueEmpty(QU* queue)
{
	return(queue->rear == queue->front);
}
Status enQueue(QU* queue,ElemType e)
{
	if ((queue->rear + 1) % MAXSIZE == queue->front)
		return FALSE;
	queue->rear = (queue->rear + 1) % MAXSIZE;
	queue->data[queue->rear] = e;
	return OK;
}
Status deQueue(QU* queue, ElemType* e)
{
	if (QueueEmpty(queue))
		return FALSE;
	queue->front = (queue->front + 1) % MAXSIZE;
	*e = queue->data[queue->front];
	return OK;
}
void show(QU* queue)
{
	int addnum = 0;
	if (queue->rear < queue->front)
		addnum = MAXSIZE;
	for (int i = queue->front + 1; i <= queue->rear + addnum; i++)
		printf("%d ",queue->data[i%MAXSIZE]);
	printf("\n");
}
int main()
{
	QU*queue=InitQueue();
	for (int i = 0; i < 4; i++)
	{
		enQueue(queue,i);
	}
	show(queue);
	for(int i=0;i<3;i++)
	{ 
		deQueue(queue,&i);
		printf("删除%d\n",i);
	}
	for (int i = 0; i < 3; i++)
	{
		enQueue(queue,i);
	}
	show(queue);
}
