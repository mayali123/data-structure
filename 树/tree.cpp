#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
#define Status int
#define ElemType char
typedef struct tree{
	ElemType data;
	struct tree* lchild, * rchild;
}T;
typedef struct queue {
	T data[MAXSIZE];
	int front, rear;
}QU;
typedef struct stack {
	T data[MAXSIZE];
	int top;
}ST;
void CreateTree(T**tree)
{
	char e;
	scanf_s("%c",&e,1);
	if (' ' == e)
		*tree = NULL;
	else
	{
		(*tree) =(T*)malloc(sizeof(T));
		// ���� 
		(*tree)->data = e;
		CreateTree(&(*tree)->lchild);
		CreateTree(&(*tree)->rchild);
	}
}
void show(T*tree)
{
	/*if (!tree)
		return;*/

	// ��ϲ��
	/*QU *q = (QU*)malloc(sizeof(QU));
	q->front = q->rear = -1;*/

	ST* st = (ST*)malloc(sizeof(ST));
	st->top = -1;
	if (tree)
	{
		/*
		// ������� 
		printf("%c �ڵ� %d ��\n",tree->data,level);
		show(tree->lchild, level + 1);
		show(tree->rchild, level + 1);
		*/
		/*
			// ������� 
			show(tree->lchild, level + 1);
			printf("%c �ڵ� %d ��\n",tree->data,level);
			show(tree->rchild, level + 1);
		*/
		/*
			// �������
			show(tree->lchild, level + 1);
			show(tree->rchild, level + 1);
			printf("%c �ڵ� %d ��\n",tree->data,level);
		*/
		
		// ��α���
		/*q->data[++q->rear] = *tree;

		while (q->front != q->rear)
		{
			*tree=q->data[++q->front];
			printf("%c ",tree->data);
			if (tree->lchild)
				q->data[++q->rear] = *tree->lchild;
			if (tree->rchild)
				q->data[++q->rear] = *tree->rchild;
		}*/
		// �ǵݹ鷽�� 
		//������� 
		st->data[++st->top] = *tree;
		while (st->top != -1)
		{
			if(tree->lchild)
				st->data[++st->top] = *tree->lchild;
			if (tree->rchild)
				st->data[++st->top] = *tree->rchild;
			
		}
	}
}
int main()
{
	T *tree= (T*)malloc(sizeof(T));
	CreateTree(&tree);
	show(tree);
	return 0;
}