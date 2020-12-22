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

// �� �� ��  
void ProOrder1(BTN *tree)
{
	BTN * t = tree;
	ST *p =(ST*)malloc(sizeof(ST)); 
	p->top= -1;
	while(t!=NULL||p->top!=-1)
	{
		while(t)
		{
			// �� 
			printf("%c ",t->data);
			p->data[++p->top] = t;
			// ��  
			t=t->left;	
		} 
		if(p->top!=-1)
		{
			t = p->data[p->top--];
			// ��
			t = t->right;
		}
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
// �� �� �� 
void InOrder1(BTN *tree)
{
	BTN * t = tree;
	ST *p =(ST*)malloc(sizeof(ST)); 
	p->top= -1;
	while(t!=NULL||p->top!=-1)
	{
		// ���� 
		while(t)
		{
			p->data[++p->top] =t;
			t=t->left;
		} 
		if(p->top!=-1)
		{
			// ��ջ  
			t = p->data[p->top--];
			// �� 
			printf("%c ",t->data);
			// ��  
			t = t->right ;
		} 
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
// �� �� �� 
// �����ȱ��� �� �� �� �ڷ����� 
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

// ��α��� 
void TravOrder(BTN *tree)
{
	BTN *t = tree;
	QU *p = (QU*)malloc(sizeof(QU));
	p->front=p->rear =0;
	// ��� 
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
