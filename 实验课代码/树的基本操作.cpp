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
void ProOrder1(BTN *tree)
{
	ST * p=(ST *)malloc(sizeof(ST));
	BTN *t;
	p->top=-1;
	if(tree)
	{
		p->data[++p->top] = tree;
		while(p->top!=-1)
		{
			t = p->data[p->top--];
			printf("%c ",t->data);
			if(t->right)
				p->data[++p->top] =t->right;
			if(t->left)
				p->data[++p->top] =t->left;
		}
		printf("\n");
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
void InOrder1(BTN *tree)
{
	ST * p=(ST *)malloc(sizeof(ST));
	BTN *t;
	p->top=-1;
	if(tree)
	{
		t = tree;
		// 第一个是栈不为空   
		//p!=NULL是因为第一个 不满足栈 
		//不为空的条件所有要加这个 
		while(p->top>-1||t!=NULL) 
		{
		
			// 遍历左子树
			while(t)
			{
				p->data[++p->top] = t;
				t= t->left;	
			}
			
			if(p->top>-1) //不为空时 
			{
				//中
				t = p->data[p->top--];
				printf("%c ",t->data);
				// 右 	
				t = t->right;
			} 
		}
		printf("\n");
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
void PastOrder1(BTN *tree)
{
	ST * p=(ST *)malloc(sizeof(ST));
	BTN *t,*last;
	p->top=-1;
	int flag ;
	if(tree)
	{
		t = tree;
		do 
		{
			// 遍历左子树
			while(t)
			{
				p->data[++p->top] = t;
				t= t->left;	
			}
			last=NULL; // 上一个遍历的节点 
			
			flag =1 ;
			while(p->top>-1&&flag)
			{
				t = p->data[p->top];
				if(t->right==last)
				{
					printf("%c ",t->data);
					p->top--;
					last = t;
				}
				else
				{
					t = t->right;
					flag = 0; 
				}
			}
		}while(p->top>-1);
		printf("\n");
	}
}
// 层次遍历
void TravOrder(BTN *tree)
{
	QU *p = (QU*)malloc(sizeof(QU));
	p->front = p->rear = 0;
	p->data[p->rear++] = tree;
	while(p->rear!=p->front)
	{
		BTN*t = p->data[p->front++];
		printf("%c ",t->data);
		if(t->left)
			p->data[p->rear++] = t->left;
		if(t->right)
			p->data[p->rear++] = t->right;
	}
	printf("\n");
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
