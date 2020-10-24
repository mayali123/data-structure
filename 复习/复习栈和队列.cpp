#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
#define Status int
#define ElemType int  

// 栈的顺序存储
/*
typedef struct stack{
	ElemType data[MAXSIZE];
	int top;
}ST;

ST* InitStack()
{
	ST * stack=(ST*)malloc(sizeof(ST));
	stack->top = -1;
	return 0;
}

Status Push(ST *stack,ElemType e)
{
	// 栈满
	if (stack->top == MAXSIZE-1)
		return ERROR;
	stack->data[++stack->top] = e;
	return OK;
}

Status Pop(ST* stack, ElemType* e)
{
	// 判断 是否为空
	if (stack->top == -1)
		return ERROR;
	*e = stack->data[stack->top--];
	return OK;
}
*/

// 共享栈 
/*
typedef struct DoubleStack {
	ElemType data[MAXSIZE];
	int top1;
	int top2;
}DS;


DS* InitDoubleStack()
{
	DS* DoubleStack= (DS*)malloc(sizeof(DS));
	DoubleStack->top1 = -1;
	DoubleStack->top2 = MAXSIZE;
	return DoubleStack;
}


// flag 等于 1 表示是 第一个  flag 等于2 表示第二个
Status Push(DS* stack, ElemType e,int flag)
{
	// 栈满
	if (stack->top2 - stack->top1 == 1)
		return ERROR;
	if (flag == 1)
	{
		stack->data[++stack->top1] = e;
		return OK;
	}
	else if (flag == 2)
	{
		stack->data[--stack->top2] = e;
		return OK;
	}
	else 
		return ERROR; // flag格式错误
}

// flag 等于 1 表示是 第一个  flag 等于2 表示第二个
Status Pop(DS* stack, ElemType* e, int flag)
{
	
	if (flag == 1)
	{
		// 栈空
		if (stack->top1 == -1)
			return ERROR;
		*e = stack->data[stack->top1--];
		return OK;
	}
	else if (flag == 2)
	{
		if (stack->top2 == MAXSIZE)
			return ERROR;
		*e = stack->data[stack->top1++];
		return OK;
	}
	else
		return ERROR;  // flag格式错误
}
*/

// 用链表实现栈
/*
typedef struct LinkStack {
	ElemType data;
	struct LinkStack* next;
}LS;

// 带头结点  
LS* InitLinkStack()
{
	LS*linkStack=(LS*)malloc(sizeof(LS));
	linkStack->next = NULL;
}

Status Push(LS* linkStack, ElemType e)
{
	LS* f = linkStack,*s;
	s = (LS*)malloc(sizeof(LS));
	s->data = e;
	s->next = f->next;
	f->next = s;
}


Status Pop(LS* linkStack, ElemType *e)
{
	LS* f = linkStack , * p;
	if (f->next)
		return FALSE;
	p = f->next;
	*e = p->data;
	f->next = p->next;
	free(p);
	return OK;
}
*/

//顺序队列
/*
typedef struct Queue {
	ElemType data[MAXSIZE];
	int front;
	int rear;
}QU;


QU* InitQueue()
{
	QU* queue=(QU*)malloc(sizeof(QU));
	queue->front = queue->rear = -1;  // 如果这个为0   则在 判断是否队列已满 			
	return queue;					  //那改为 queue->rear == MAXSIZE
}

Status enQueue(QU*queue,ElemType e)
{
	//判断是否队列已满
	if (queue->rear == MAXSIZE - 1)  
		return ERROR;
	queue->data[queue->rear++] = e;
	return OK;
}

Status deQueue(QU* queue, ElemType* e)
{
	// 判断队列是否为空
	if (queue->rear == queue->front)
		return ERROR;
	*e = queue->data[queue->front++];
	return OK;
}
*/

//循环队列
/*
typedef struct CycleQueue {
	ElemType data[MAXSIZE];
	int front;
	int rear;
}CQU;

CQU* InitQueue()
{
	CQU* queue = (CQU*)malloc(sizeof(CQU));
	queue->front = queue->rear = 0;  // 如果这个为-1 那在判断 是否为空和 队列是否已满 都会出问题
	return queue;					  
}
Status enQueue(CQU*queue,ElemType e)
{
	//判断是否队列已满
	if ((queue->rear+1)%MAXSIZE ==queue->front)  
		return ERROR;
	queue->data[queue->rear] = e; 
	queue->rear = (queue->rear + 1) % MAXSIZE;
	return OK;
}

Status deQueue(CQU* queue, ElemType* e)
{
	// 判断队列是否为空
	if (queue->rear == queue->front)
		return ERROR;
	*e = queue->data[queue->front];
	queue->front = (queue->front + 1) % MAXSIZE;
	return OK;
}
*/

//用链表实现队列
/*
typedef struct LinkQueue {
	ElemType data;
	struct LinkQueue* next;
}LQ;
typedef struct LinkQueuePoint {
	LQ* fornt, * rear;
}LQP;
LQP* InitLinkQueue()
{
	LQP*linkqueuepoint=(LQP*)malloc(sizeof(LQP));

	//头节点
	LQ* p = (LQ*)malloc(sizeof(LQ));
	p->next = NULL;

	linkqueuepoint->fornt = linkqueuepoint->rear = p;
	return linkqueuepoint;
}
Status enQueue(LQP* linkqueuepoint,ElemType e)
{
	LQ *s= (LQ*)malloc(sizeof(LQ));
	s->data = e;
	s->next = NULL;
	linkqueuepoint->rear->next = s;
	linkqueuepoint->rear = s;
	return OK;
}

Status deQueue(LQP* linkqueuepoint, ElemType *e)
{
	// 判断是否为空
	if (linkqueuepoint->fornt == linkqueuepoint->rear)
		return ERROR;
	LQ* s;
	s = linkqueuepoint->fornt;
	linkqueuepoint->fornt = s->next;
	*e = s->data;
	if (s->next == linkqueuepoint->rear)  // 这种就是只有一个头节点 和一个数据结点 
		linkqueuepoint->rear = linkqueuepoint->fornt; // 要将 rear 指向 头节点
	free(s);
	return OK;
}
*/