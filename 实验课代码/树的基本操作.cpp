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
// �ҵ�ĳ�ڵ�
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
// ��� 
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
 

// �������  
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
// �ǵݹ� �������  
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
// ������� 
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
// �ǵݹ�  ������� 
void InOrder1(BTN *tree)
{
	ST * p=(ST *)malloc(sizeof(ST));
	BTN *t;
	p->top=-1;
	if(tree)
	{
		t = tree;
		// ��һ����ջ��Ϊ��   
		//p!=NULL����Ϊ��һ�� ������ջ 
		//��Ϊ�յ���������Ҫ����� 
		while(p->top>-1||t!=NULL) 
		{
		
			// ����������
			while(t)
			{
				p->data[++p->top] = t;
				t= t->left;	
			}
			
			if(p->top>-1) //��Ϊ��ʱ 
			{
				//��
				t = p->data[p->top--];
				printf("%c ",t->data);
				// �� 	
				t = t->right;
			} 
		}
		printf("\n");
	}
}
//  ������� 
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
			// ����������
			while(t)
			{
				p->data[++p->top] = t;
				t= t->left;	
			}
			last=NULL; // ��һ�������Ľڵ� 
			
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
// ��α���
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
	
	printf("���������");
	ProOrder(tree); 
	printf("\n");
	
	printf("�ǵݹ�����������");
	ProOrder1(tree); 
	printf("\n");
	
	printf("���������");
	InOrder(tree); 
	printf("\n");
	 
	printf("�ǵݹ�����������");
	InOrder1(tree); 
	printf("\n");
	
	
	printf("���������");
	PastOrder(tree); 
	printf("\n");
	
	
	printf("�ǵݹ�ĺ��������");
	PastOrder1(tree); 
	printf("\n");
	
	printf("��α�����");
	TravOrder(tree); 
	printf("\n");

		
	char e = 'e';
	BTN *t = Find(tree,e);
	printf("����%c:\n");
	if(t) 
		printf("�ҵ���ֵΪ%c\n",e,t->data);
	else
		printf("δ�ҵ���ֵΪ%c\n",e);

	printf("��������ȣ�%d\n",BTHeight(tree));
	return 0;
}
