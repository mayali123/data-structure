#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
#define Status int
#define ElemType char  
typedef enum 
{
	Link,  //  左右孩子
	Thread // 前后驱
}PointerTag;
typedef struct tree {
	ElemType data; 
	PointerTag RTag, LTag;
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
T* pre = NULL;

//需要在函数中改变变量的值，传送变量的指针
// 需要在函数中改变指针的值，传送指针的指针，某些指针就是变量。
void CreatTree(T**tree)
{
	char e;
	scanf_s("%c",&e,1);
	if (' ' == e)
		 *tree = NULL;
	else {
		*tree = (T*)malloc(sizeof(T));
		(*tree)->data = e;
		(*tree)->LTag = Link;
		(*tree)->RTag = Link;
		CreatTree(&(*tree)->lchild);
		CreatTree(&(*tree)->rchild);
	}
}
//void InThreading(T*tree)  // 中序索引
//{
//	if (tree)
//	{
//		InThreading(tree->lchild);
//
//		// 结点 
//		if (!tree->lchild)
//		{
//			tree->LTag = Thread;
//			tree->lchild = pre;
//		}
//		if (!tree->rchild)
//		{
//			tree->RTag = Thread;
//			pre->rchild = tree;
//		}
//
//		InThreading(tree->rchild);
//	}
//}
//void inOrderThreading(T*head,T**tree)
//{
//	// 创建一个头节点
//	head = (T*)malloc(sizeof(T));
//	//初始化 头节点
//	head->LTag = Link;
//	head->RTag = Thread;
//	if (!tree)
//	{
//		head->lchild = head;
//	}
//	else
//	{
//		head->lchild = *tree;
//		pre = head;
//		InThreading(*tree);
//		pre->RTag = Thread;
//		pre->rchild = head;
//	}
//}
void show(T* tree )
{
	/*if (!tree)
		return;*/
		// 配合层次
	QU* q = (QU*)malloc(sizeof(QU));
	q->front = q->rear = -1;

	/*ST* st = (ST*)malloc(sizeof(ST));
	st->top = -1;*/
	if (tree)
	{
		/*
		// 先序遍历
		printf("%c ",tree->data);
		show(tree->lchild );
		show(tree->rchild );
		*/
		
		// 中序遍历
		/*show(tree->lchild);
		printf("%c ",tree->data);
		show(tree->rchild);
		*/
		/*
			// 后序遍历
			show(tree->lchild );
			show(tree->rchild );
			printf("%c ",tree->data);
		*/

		// 层次遍历
		T* t=tree;
		q->data[++q->rear] =  t;
		while (q->front != q->rear)
		{
			t = q->data[++q->front];
			printf("%c ", t->data);
			if (t->lchild)
				q->data[++q->rear] = t->lchild;
			if (t->rchild)
				q->data[++q->rear] = t->rchild;
		}

	}
}

void InThreading(T* tree) // 中序索引
{
	if ( tree!=NULL)
	{
		// 左 中 右
		// 左子树
		InThreading(tree->lchild);
		// 中  
		
		// 左 边来保存 前驱 
		if (!tree ->lchild)
		{
			tree->LTag = Thread;
			tree->lchild = pre;
		}
		else
			tree->LTag = Link;
		// 右 边来保存 后继 
		if (!pre->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = tree;
		}
		else
			pre->RTag = Link;

		pre = tree;

		// 右子树
		InThreading(tree->rchild);
		
	}
}

void inOrderThreading(T** head,T* tree)
{
	*head =(T*) malloc(sizeof(T));
	(*head)->LTag = Link;
	(*head)->RTag = Thread;
	(*head)->rchild = *head;
	if ( tree == NULL)
		(*head)->lchild = *head;
	else
	{
		pre = *head;
		(*head)->lchild =  tree;
		
		InThreading((*head)->lchild);

		// 遍历完之后 
		pre->RTag = Thread;
		pre->rchild = *head;

		(*head)->rchild = pre;
	}
}

// 用非递归的方式来 中序遍历 二叉树
void ThInOrder(T* head)
{ 
	// 左 中 右
	T* p = head->lchild;
	while (p != head)
	{
		// 先去 最左边
		while (p->LTag==Link) p = p->lchild;
		printf("%c ",p->data);
		// 通过 后继 来走
		while (p->RTag == Thread && p->rchild != head)
		{
			p = p->rchild;
			printf("%c ",p->data);
		}
		//如果 没有 p->RTag != Thread
		p = p->rchild;
	}
	
}
int main()
{
	// 创建一棵二叉树
	T* tree ,*head,*t;
	CreatTree(&tree);
	show(tree);
	inOrderThreading(&head,tree);
	printf("\n");
	
	ThInOrder(head);
}
//ab d  ce   
//b d a e c
//b d a e c