#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define ElmeType int
#define MAXSIZE 500
typedef struct BinTree{
	ElmeType data;
	struct BinTree* L;
	struct BinTree* R;
}BT;
BT* Find(BT* tree, ElmeType find_e)
{
	if (tree == NULL)
		return NULL;  // δ�ҵ�
	if (tree->data == find_e)
		return tree;  // ����λ��
	else if (find_e > tree->data)
		return Find(tree->R, find_e); 
	else 
		return Find(tree->L, find_e);
}
BT* FindMax(BT* tree)
{
	if(tree)
		while (tree->R) tree = tree->R;
	return tree;
}
BT* FindMin(BT* tree)
{
	if (tree)
		while (tree->L) tree = tree->L;
	return tree;
}
BT* insert(BT* tree, ElmeType e)
{
	if (tree == NULL)
	{
		BT * add_tree = (BT*)malloc(sizeof(BT));
		add_tree->data = e;
		add_tree->L = add_tree->R = NULL;
		return add_tree;
	}
	if (e > tree->data)
		tree->R = insert(tree->R, e);
	else if (e< tree->data)
		tree->L = insert(tree->L, e);
	return tree;
}
// �������
void LevelOrderTrave(BT *tree)
{
	// ����
	BT *queue[MAXSIZE];
	int front, rear;
	front = rear = -1;
	queue[++front] = tree;
	while (front != rear)
	{
		//  ����
		rear++;
		printf("%d ",queue[rear]->data);
		if (queue[rear]->L)
			queue[++front] = queue[rear]->L;
		if (queue[rear]->R)
			queue[++front] = queue[rear]->R;
	}
	printf("\n");
}
// ɾ�� ���
BT* delNode(BT*tree,ElmeType del_e)
{
	if (tree == NULL)
		printf("δ�ҵ�Ҫɾ����\n");
	else if (del_e > tree->data)
		tree->R =  delNode(tree->R,del_e);
	else if(del_e < tree->data)
		tree->L = delNode(tree->L, del_e);
	else
	{
		// ���������  Ҫɾ�����������  or һ�� or û��
		if (tree->L != NULL && tree->R != NULL)
		{
			BT* t;
			t = FindMin(tree->R);  // �ҵ���������С��
			tree->data = t->data;
			printf("data  %d\n", tree->data);
			tree->R = delNode(tree->R, tree->data);
		}
		else //  һ����� or û��
		{
			BT* t = tree;
			if(!tree->L)
				tree = tree->R;
			else if(!tree->R)
				tree =  tree->L;
			free(t);
		}
	}
	return tree;
}
int main()
{
	BT *tree = insert(NULL,5);
	BT* t = tree;
	printf("����%d\n", 5);
	for (int i = 0; i < 9; i++)
	{
		int rand_num = rand()%10;
		printf("����%d\n",rand_num);
		insert(tree, rand_num);
	}
	LevelOrderTrave(tree);
	printf("���ֵ%d\n",FindMax(tree)->data);
	printf("��Сֵ%d\n", FindMin(tree)->data);
	for (int i = 0; i < 4; i++)
	{
		int rand_num ;
		while ((rand_num = rand() % 10)&& rand_num==5);
		printf("ɾ��%d\n", rand_num);
		delNode(tree, rand_num);
	}
	printf("���ֵ%d\n", FindMax(tree)->data);
	printf("��Сֵ%d\n", FindMin(tree)->data);
	LevelOrderTrave(t);
	return 0;
}