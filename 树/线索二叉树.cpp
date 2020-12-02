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
	Link,  //  ���Һ���
	Thread // ǰ����
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

//��Ҫ�ں����иı������ֵ�����ͱ�����ָ��
// ��Ҫ�ں����иı�ָ���ֵ������ָ���ָ�룬ĳЩָ����Ǳ�����
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
//void InThreading(T*tree)  // ��������
//{
//	if (tree)
//	{
//		InThreading(tree->lchild);
//
//		// ��� 
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
//	// ����һ��ͷ�ڵ�
//	head = (T*)malloc(sizeof(T));
//	//��ʼ�� ͷ�ڵ�
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
		// ��ϲ��
	QU* q = (QU*)malloc(sizeof(QU));
	q->front = q->rear = -1;

	/*ST* st = (ST*)malloc(sizeof(ST));
	st->top = -1;*/
	if (tree)
	{
		/*
		// �������
		printf("%c ",tree->data);
		show(tree->lchild );
		show(tree->rchild );
		*/
		
		// �������
		/*show(tree->lchild);
		printf("%c ",tree->data);
		show(tree->rchild);
		*/
		/*
			// �������
			show(tree->lchild );
			show(tree->rchild );
			printf("%c ",tree->data);
		*/

		// ��α���
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

void InThreading(T* tree) // ��������
{
	if ( tree!=NULL)
	{
		// �� �� ��
		// ������
		InThreading(tree->lchild);
		// ��  
		
		// �� �������� ǰ�� 
		if (!tree ->lchild)
		{
			tree->LTag = Thread;
			tree->lchild = pre;
		}
		else
			tree->LTag = Link;
		// �� �������� ��� 
		if (!pre->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = tree;
		}
		else
			pre->RTag = Link;

		pre = tree;

		// ������
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

		// ������֮�� 
		pre->RTag = Thread;
		pre->rchild = *head;

		(*head)->rchild = pre;
	}
}

// �÷ǵݹ�ķ�ʽ�� ������� ������
void ThInOrder(T* head)
{ 
	// �� �� ��
	T* p = head->lchild;
	while (p != head)
	{
		// ��ȥ �����
		while (p->LTag==Link) p = p->lchild;
		printf("%c ",p->data);
		// ͨ�� ��� ����
		while (p->RTag == Thread && p->rchild != head)
		{
			p = p->rchild;
			printf("%c ",p->data);
		}
		//��� û�� p->RTag != Thread
		p = p->rchild;
	}
	
}
int main()
{
	// ����һ�ö�����
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