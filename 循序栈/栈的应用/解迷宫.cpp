# include<stdio.h>
# include<malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 500
#define M 10
#define N 10
typedef struct BOXS {
	int x;
	int y;
	int direction;
}BOX;
#define TpyeElem BOX
//  x----> 
//  y ����
int mg[M][N] ={
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
/*{
	1,1,1,1,1,
	1,0,0,0,1,
	1,0,1,1,1,
	1,0,0,0,1,
	1,1,1,1,1,
};*/


typedef struct stack
{
	TpyeElem data[MAXSIZE];
	int top;
}ST;
int mgpath(int x1, int y1, int x2, int y2)
{
	// ��ʼ��
	ST* p = (ST*)malloc(sizeof(ST));
	p->top = 0;
	p->data[p->top].x = x1;
	p->data[p->top].y = y1;
	p->data[p->top].direction = -1;
	mg[x1][y1] = -1;

	

	// ����Ϊջ��ʱ
	while (p->top != -1)
	{
		//ȡ�� ջ��
		int x, y, di;
		x = p->data[p->top].x;
		y = p->data[p->top].y;
		di = p->data[p->top].direction;
		
		if (x == x2 && y == y2)  // �ҵ�ʱ
		{
			//���ڷ�ת 
			ST* path = (ST*)malloc(sizeof(ST));
			path->top = -1;
			
			printf("·������:\n");
			while (p->top != -1)
			{
				BOX e;
				e.x = p->data[p->top].x;
				e.y = p->data[p->top].y;
				path->data[++path->top] = e;
				p->top--;
			}
			while (path->top != -1) //��path��Ϊ��ʱ
			{
				printf("(%d,%d) ",path->data[path->top].y, path->data[path->top].x);
				path->top--;
			}
			return TRUE;
		}
		int to_x=x, to_y=y;
		for (; di < 4;)
		{
			di++;
			switch (di) 
			{
			case 0:
				to_x= x,to_y=y-1;
				break;
			case 1:
				to_x = x+1, to_y = y ;
				break;
			case 2:
				to_x = x, to_y = y +1;
				break;
			case 3:
				to_x = x - 1, to_y = y;
				break;
			}
			if (mg[to_y][to_x] == 0)
			{
				
				// ����һ����һ�εķ���
				p->data[p->top].direction = di;

				// ��ջ
				p->top++;
				p->data[p->top].x = to_x;
				p->data[p->top].y = to_y;
				p->data[p->top].direction = -1;
				// ���߹��ĸ�Ϊ-1 
				mg[to_y][to_x] = -1;
				break;
			}
		}
		if (di >= 4)
		{
			p->top--;
			mg[y][x] = 0;
		}
	}

	// ����ջ
	free(p);
	// δ�ҵ����� false
	return FALSE;
}

int main()
{
	if (!mgpath(1, 1, M-2, N-2))
		printf("δ�ҵ�");
}

