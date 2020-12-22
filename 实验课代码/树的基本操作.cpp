#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100 
#define Elmetype char 
typedef struct BinTreeNode {
	Elmetype data;
	struct BinTreeNode *left,*right;
}BTN;
typedef struct queue {
	BTN* data[MAXSIZE];
	int front,rear;
}QU;
typedef struct stack {
	BTN* data[MAXSIZE];
	int top;
}ST;

BTN* CreateBTree(BTN **tree)
{
	char ch;
	scanf("%c",&ch);
	if(' '==ch)
		*tree = NULL;
	else
	{
		(*tree) =(BTN*)malloc(sizeof(BTN));
		(*tree)->data = ch;
		CreateBTree(&(*tree)->left);
		CreateBTree(&(*tree)->right);
	}
}
// 找到某节点
BTN *Find(BTN  *tree,Elmetype e)
{
	if(!tree)
		return NULL;
	else if(tree->data==e)
			return tree;
	else
	{
		BTN *p= Find(tree->left,e);
		if(p)
			return p;
		else
			return Find(tree->right,e);
	}
}
// 深度 
int BTHeight(BTN  *tree)
{
	int max,RHeight;
	if(!tree)
		return 0; 
	else
	{
		max = BTHeight(tree->left);
		RHeight = BTHeight(tree->right);
		if(max<RHeight)
			max = RHeight;
		return max+1;
	}
}
 

// 先序遍历  
void ProOrder(BTN *tree)
{
	if(!tree)
		return;
	else
	{
		printf("%c ",tree->data);
		ProOrder(tree->left);
		ProOrder(tree->right);
	}
}
// 非递归 先序遍历

// 根 左 右  
void ProOrder1(BTN *tree)
{
	BTN * t = tree;
	ST *p =(ST*)malloc(sizeof(ST)); 
	p->top= -1;
	while(t!=NULL||p->top!=-1)
	{
		while(t)
		{
			// 根 
			printf("%c ",t->data);
			p->data[++p->top] = t;
			// 左  
			t=t->left;	
		} 
		if(p->top!=-1)
		{
			t = p->data[p->top--];
			// 右
			t = t->right;
		}
	}
}




// 中序遍历 
void InOrder(BTN *tree)
{
	if(!tree)
		return;
	else
	{
		InOrder(tree->left);
		printf("%c ",tree->data);
		InOrder(tree->right);
	}
}
// 非递归  中序遍历 
// 左 根 右 
void InOrder1(BTN *tree)
{
	BTN * t = tree;
	ST *p =(ST*)malloc(sizeof(ST)); 
	p->top= -1;
	while(t!=NULL||p->top!=-1)
	{
		// 左树 
		while(t)
		{
			p->data[++p->top] =t;
			t=t->left;
		} 
		if(p->top!=-1)
		{
			// 出栈  
			t = p->data[p->top--];
			// 根 
			printf("%c ",t->data);
			// 右  
			t = t->right ;
		} 
	}
}

//  后序遍历 
void PastOrder(BTN *tree)
{
	if(!tree)
		return;
	else
	{
		PastOrder(tree->left);
		PastOrder(tree->right);
		printf("%c ",tree->data);
	}
}
// 左 右 根 
// 可以先遍历 根 右 左 在反过来 
void PastOrder1(BTN *tree)
{
	BTN * t = tree;
	ST *p =(ST*)malloc(sizeof(ST)); 
	ST *q =(ST*)malloc(sizeof(ST)); 
	p->top= -1;
	q->top =-1;
	while(t!=NULL||p->top!=-1)
	{
		while(t)
		{
			p->data[++p->top] = t;
			q->data[++q->top] = t;
			t = t->right;
		}
		if(p->top!=-1)
		{
			t=p->data[p->top--];
			t=t->left;	
		} 
	}
	while(q->top!=-1)
		printf("%c ",q->data[q->top--]->data);
}

// 层次遍历 
void TravOrder(BTN *tree)
{
	BTN *t = tree;
	QU *p = (QU*)malloc(sizeof(QU));
	p->front=p->rear =0;
	// 入队 
	p->data[p->rear++] = t;
	while(p->front!=p->rear)
	{
		t = p->data[p->front++];
		printf("%c ",t->data);
		if(t->left)
			p->data[p->rear++] = t->left;
		if(t->right)
			p->data[p->rear++] = t->right;
	}
}

//ab d  ce   
int main()
{
	BTN *tree;
	CreateBTree(&tree);
	
	printf("先序遍历：");
	ProOrder(tree); 
	printf("\n");
	
	printf("非递归的先序遍历：");
	ProOrder1(tree); 
	printf("\n");
	
	printf("中序遍历：");
	InOrder(tree); 
	printf("\n");
	 
	printf("非递归的中序遍历：");
	InOrder1(tree); 
	printf("\n");
	
	
	printf("后序遍历：");
	PastOrder(tree); 
	printf("\n");
	
	
	printf("非递归的后序遍历：");
	PastOrder1(tree); 
	printf("\n");
	
	printf("层次遍历：");
	TravOrder(tree); 
	printf("\n");

		
	char e = 'e';
	BTN *t = Find(tree,e);
	printf("查找%c:\n");
	if(t) 
		printf("找到了值为%c\n",e,t->data);
	else
		printf("未找到了值为%c\n",e);

	printf("此树的深度：%d\n",BTHeight(tree));
	return 0;
}
