// 用栈解密宫
#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 200
#define N 6
#define M 6
typedef struct BOXS{
	int x;
	int y;
	int di;
}BOX; 
typedef struct satck{
	BOX data[MAXSIZE];
	int top;
}ST; 


int mg[N][M] = {
	1,1,1,1,1,1,
	1,0,0,0,1,1,
	1,0,1,0,0,1,
	1,0,0,0,1,1,
	1,1,0,0,0,1,
	1,1,1,1,1,1,
};

ST * p =(ST*) malloc(sizeof(ST));
ST * min_path =(ST*) malloc(sizeof(ST));

int minlen=MAXSIZE;
int count = 1;
void disPath()
{
	printf("%d:",count++);
	for(int i=0;i<=p->top;i++)
	{
		printf("(%d,%d)",p->data[i].y,p->data[i].x);
	}
	printf("\n");
	if(p->top+1<minlen)
	{
		minlen= p->top+1;
		for(int k=0;k<=p->top;k++)
			min_path->data[k] = p->data[k];
	}
}
void disminPath()
{
	printf("最短长度%d\n",minlen);
	for(int i=0;i<minlen;i++)
	{
		printf("(%d,%d)",min_path->data[i].y,min_path->data[i].x);
	}
	printf("\n");
}
void find(int x1,int y1,int x2,int y2)
{
	// 初始化 
	p->top=-1;
	p->top++;
	
	// 入栈
	p->data[p->top].x=x1;
	p->data[p->top].y=y1;
	p->data[p->top].di=-1;
	
	mg[y1][x1]=-1;
	// 当 栈不为空 时 
	while(p->top>-1)
	{
		
		int x=p->data[p->top].x,y=p->data[p->top].y,di=p->data[p->top].di; 
		
		// 当找到 出口时
		if(x==x2&&y==y2)
		{
			// 展示 
			disPath();
			// 退栈
			p->top--;
			mg[y][x] =0;
			x=p->data[p->top].x;
			y=p->data[p->top].y;
			di=p->data[p->top].di; 
		} 
		int to_x=x,to_y=y;
		for(;di<4;)
		{
			di++;
			switch (di)
			{
			case 0:
				to_x = x, to_y = y - 1;
				break;
			case 1:
				to_x = x + 1, to_y = y;
				break;
			case 2:
				to_x = x, to_y = y + 1;
				break;
			case 3:
				to_x = x - 1, to_y = y;
				break;
			}
			if(mg[to_y][to_x]==0)
			{
				p->data[p->top].di = di;
				mg[to_y][to_x]=-1;
				p->top++;
				// 入栈
				p->data[p->top].x=to_x;
				p->data[p->top].y=to_y;
				p->data[p->top].di=-1;
				break;
			}
		}
		if(di>=4)
		{
			// 出栈
			p->top--; 
			mg[y][x]=0;
		}
	}
	disminPath();
}

int main()
{
	find(1,1,N-2,M-2);
}

