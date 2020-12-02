#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
#define Status int
#define ElemType char
typedef struct tree {
	ElemType data;
	struct tree* lchild, * rchild;
}T;
typedef struct queue {
	T* data[MAXSIZE];
	int front, rear;
}QU;
typedef struct stack {
	T data[MAXSIZE];
	int top;
}ST;
//需要在函数中改变变量的值，传送变量的指针
// 需要在函数中改变指针的值，传送指针的指针，某些指针就是变量。
// 为什么要用 **呢 因为 要修改 指针的值 所以要传递他的地址
void CreateTree(T** tree)  
{
	char e;
	scanf_s("%c", &e, 1);
	if (' ' == e)
		*tree = NULL;
	else
	{
		(*tree) = (T*)malloc(sizeof(T));
		// 先序 
		(*tree)->data = e;
		CreateTree(&(*tree)->lchild);
		CreateTree(&(*tree)->rchild);
	}
}
void show(T* tree)
{
	/*if (!tree)
		return;*/

	// 配合层次
	QU *q = (QU*)malloc(sizeof(QU));
	q->front = q->rear = -1;

	ST* st = (ST*)malloc(sizeof(ST));
	st->top = -1;
	if (tree)
	{
		
		// //先序遍历
		//printf("%c ",tree->data);
		//show(tree->lchild );
		//show(tree->rchild );
		
		//// 中序遍历
		//show(tree->lchild);
		//printf("%c ",tree->data );
		//show(tree->rchild);

		//// 后序遍历
		//show(tree->lchild );
		//show(tree->rchild );
		//printf("%c ",tree->data );
		

		// 层次遍历
		/*T* t = tree;
		q->data[++q->rear] = t;
		while (q->front != q->rear)
		{
			t = q->data[++q->front];
			printf("%c ", t->data);
			if (t->lchild)
				q->data[++q->rear] = t->lchild;
			if (t->rchild)
				q->data[++q->rear] = t->rchild;
		}*/
	}
}
int main()
{
	T* tree = (T*)malloc(sizeof(T));
	CreateTree(&tree);
	show(tree);
	return 0;
}
//ab d  ce   
