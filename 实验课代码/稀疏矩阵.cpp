#include<stdio.h>
#include<malloc.h>
#define N 4
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 200
#define Status int
#define ElemType int  
typedef struct TupNode{
	int x,y,data;  // x代表 行 y 代表列 data 是值  
}T;
typedef struct TsMatrix{
	int rows;  		// 总行数 
	int cols;  		// 总列数 
	int NotZeroNums; // 非零元素的个数 
	T data[MAXSIZE];
}TM; 
TM* CreatMat(ElemType A[N][N])
{
	int i,j;
	TM *matrix = (TM*)malloc(sizeof(TM));
	matrix->cols = matrix->rows = N;
	matrix->NotZeroNums = 0;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++) 
			if(A[i][j])
			{
				matrix->data[matrix->NotZeroNums].data =  A[i][j];
				matrix->data[matrix->NotZeroNums].x = i;
				matrix->data[matrix->NotZeroNums].y = j;
				matrix->NotZeroNums++;
			}
	return matrix;
}
void disM(TM* matrix)
{
	int i,j,k=0;
	for(i=0;i<matrix->rows;i++)
	{
		for(j=0;j<matrix->cols;j++)
		{
			if(matrix->data[k].x==i&&matrix->data[k].y==j)
				printf("%d ",matrix->data[k++].data);
			else
				printf("0 ");	 
		}
		printf("\n"); 
	}
}
void TranMat(TM* matrix,TM* matrix1)
{
	int i,j,k=0;
	matrix1->cols = matrix->rows;
	matrix1->rows =matrix->cols;
	matrix1->NotZeroNums = matrix->NotZeroNums;
	
	// 为了适应 上面disM函数 要以列 转置
	for(i=0;i<matrix->cols;i++)
		for(j=0;j<matrix->NotZeroNums;j++)
			if(matrix->data[j].y==i) 
			{
				matrix1->data[k].data = matrix->data[j].data;
				matrix1->data[k].x = matrix->data[j].y;
				matrix1->data[k].y = matrix->data[j].x;
				k++;
			}
}


void MatAdd(TM* t,TM* t1,TM* t2) // t+t1 保存  在t2中 
{
	if(t->cols!=t1->cols||t->rows!=t1->rows)
		return;
	t2->NotZeroNums = 0;
	t2->cols = t1->cols;
	t2->rows = t1->rows;
	int i,j,p=0,n=0;
	for(i=0;i<t1->rows;i++)
	{
		for(j=0;j<t1->cols;j++)
		{
			if((t->data[p].x==i&&t->data[p].y==j)&&(t1->data[n].x==i&&t1->data[n].y==j))
			{
				t2->data[t2->NotZeroNums].data = t->data[p].data + t1->data[n].data;
				t2->data[t2->NotZeroNums].x = i;
				t2->data[t2->NotZeroNums].y = j;
				t2->NotZeroNums++;
				p++;
				n++;
			}
			else if (t->data[p].x==i&&t->data[p].y==j) 
			{
				t2->data[t2->NotZeroNums].data = t->data[p].data;
				t2->data[t2->NotZeroNums].x = i;
				t2->data[t2->NotZeroNums].y = j;
				t2->NotZeroNums++;
				p++;
			}
			else if(t1->data[n].x==i&&t1->data[n].y==j)
			{
				t2->data[t2->NotZeroNums].data = t1->data[n].data;
				t2->data[t2->NotZeroNums].x = i;
				t2->data[t2->NotZeroNums].y = j;
				t2->NotZeroNums++;
				n++;
			}
		}
	}
}
int main()
{
	int a[N][N]={
		1,0,3,0,
		0,1,0,0,
		0,0,1,0,
		0,0,1,1,
	},b[N][N]={
		3,0,0,0,
		0,4,0,0,
		0,0,1,0,
		0,0,0,2,
	};
	TM *ta=CreatMat(a);
	TM *tb=CreatMat(b);
	TM *tc=(TM*)malloc(sizeof(TM)); 
	printf("a:\n");
	disM(ta);
	printf("b:\n");
	disM(tb);
//	TranMat(ta,tc);
//	
	// 显示 转置之后的 tc
//	printf("ta 转置之后的 tc:\n");
//	disM(tc);
    printf("c:\n");
	MatAdd(ta,tb,tc);
	disM(tc);
	return 0;
}
