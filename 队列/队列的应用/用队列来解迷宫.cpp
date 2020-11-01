#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 200
#define Status int
#define N 10
typedef struct BOXS {
	int x;
	int y;
	int pre;
}BOX;
#define ElemType BOX  
typedef struct queue {
	ElemType data[MAXSIZE];
	int front;
	int rear;
}QU;

// 栈
typedef struct stack {
	ElemType data[MAXSIZE];
	int top;
}ST;
int  mg[N][N] ={
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
/* {
	1,1,1,1,1,
	1,0,0,0,1,
	1,1,1,1,1,
	1,0,0,0,1,
	1,1,1,1,1,
};*/
void print(QU* p, int front);
int find(int x1, int y1, int x2, int y2) 
{
	// 初始化
	QU *p = (QU*)malloc(sizeof(QU));
	p->front = p->rear = -1;

	//入队
	p->data[++p->rear].x = x1;
	p->data[p->rear].y = y1;
	p->data[p->rear].pre = -1;
	mg[x1][y1] = -1;

	while (p->front != p->rear)
	{
		BOX e;
		p->front++;
		e=p->data[p->front];
		if (e.x == x2 && e.y == y2)
		{
			printf("找到了！！！\n");
			print(p,p->front);
			free(p);
			return 1;
		}
		int x3,y3;
		for (int i = 0; i < 4; i++)
		{
			switch (i)
			{
			case 0:
				x3 = e.x, y3 = e.y-1;
				break;
			case 1:
				x3 = e.x+1, y3 = e.y ;
				break;
			case 2:
				x3 = e.x, y3 = e.y + 1;
				break;
			case 3:
				x3 = e.x-1, y3 = e.y;
				break;
			}
			if (mg[y3][x3] == 0)
			{
				// 入队
				p->rear++;
				p->data[p->rear].x = x3;
				p->data[p->rear].y = y3;
				p->data[p->rear].pre = p->front;
				mg[y3][x3] = -1;
			}
		}
	}
	free(p);
	return 0;
}
void print(QU* p,int front)
{
	int k = front;
	// 初始化
	ST* q=(ST*)malloc(sizeof(ST));
	q->top=-1;
	while (front!= -1)
	{
		q->data[++q->top]=p->data[front];
		front = p->data[front].pre;
	}
	while (q->top != -1)
	{
		BOX e = q->data[q->top--];
		printf("(%d,%d) ",e.y,e.x);
	}
	free(q);
}
int main()
{
	if (!find(1, 1, N - 2, N - 2))
		printf("未找到");
}