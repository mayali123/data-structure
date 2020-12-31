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
// 全局变量 
T* pre = NULL;
void CreatTree(T**tree)
{
	char e;
	scanf("%c",&e);
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
void InThreading(T* tree) // 中序索引
{
	if(tree)
	{
		InThreading(tree->lchild);  // 先遍历 左树 
		
		if(tree->lchild==NULL)
		{
			tree->LTag = Thread;
			tree->lchild = pre;
		}
		else
			tree->LTag = Link;
		if(pre->rchild==NULL)
		{
			pre->RTag = Thread;
			pre->rchild = tree;
		}
		else
			pre->RTag = Link;
		pre = tree;
		
		InThreading(tree->rchild);
	}
} 
void inOrderThreading(T** root,T* tree)
{
	*root = (T*)malloc(sizeof(T));
	(*root)->LTag = Link;
	(*root)->RTag = Thread;
	(*root)->lchild = *root;
	if(tree==NULL)
	{
		(*root)->rchild = *root;
	}
	else
	{
		(*root)->lchild = tree;
		pre = *root; 
		

		InThreading((*root)->lchild) ;
		
		pre->rchild = *root;
		pre->RTag = Thread;
		
		(*root)->rchild = pre;
	}	
} 

// 递归 的 中序遍历 
void InOrder(T *tree)
{
	if(tree)
	{
		if(tree->LTag==Link)
			InOrder(tree->lchild);
		printf("%c ",tree->data);
		if(tree->RTag==Link)
			InOrder(tree->rchild);
	} 
} 
// 非递归 的 中序遍历 
void InOrder1(T *tree)
{
	T *p = tree->lchild;
	while(p!=tree)
	{
		// 左 
		while(p->lchild&&p->LTag==Link )
			p=p->lchild;
		// 根 
		printf("%c ",p->data);
		// 右 
		while(p->rchild&&p->RTag==Thread&&p->rchild!=tree)
		{
			p=p->rchild; 
			printf("%c ",p->data); 
		}
		p=p->rchild; 
	} 
} 
int main()
{
	// 创建一棵二叉树
	T* tree ,*head,*t;
	CreatTree(&tree);
	inOrderThreading(&head,tree);
	printf("\n");
	printf("递归的中序遍历: ");
	InOrder(head->lchild);
	printf("\n非递归的中序遍历: ");
	InOrder1(head);
}
//ab d  ce   
//b d a e c
//b d a e c
