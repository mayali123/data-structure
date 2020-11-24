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
		return NULL;  // 未找到
	if (tree->data == find_e)
		return tree;  // 返回位置
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
// 层序遍历
void LevelOrderTrave(BT *tree)
{
	// 队列
	BT *queue[MAXSIZE];
	int front, rear;
	front = rear = -1;
	queue[++front] = tree;
	while (front != rear)
	{
		//  出队
		rear++;
		printf("%d ",queue[rear]->data);
		if (queue[rear]->L)
			queue[++front] = queue[rear]->L;
		if (queue[rear]->R)
			queue[++front] = queue[rear]->R;
	}
	printf("\n");
}
// 删除 结点
BT* delNode(BT*tree,ElmeType del_e)
{
	if (tree == NULL)
		printf("未找到要删除的\n");
	else if (del_e > tree->data)
		tree->R =  delNode(tree->R,del_e);
	else if(del_e < tree->data)
		tree->L = delNode(tree->L, del_e);
	else
	{
		// 分三种情况  要删的有两个结点  or 一个 or 没有
		if (tree->L != NULL && tree->R != NULL)
		{
			BT* t;
			t = FindMin(tree->R);  // 找到右子树最小的
			tree->data = t->data;
			printf("data  %d\n", tree->data);
			tree->R = delNode(tree->R, tree->data);
		}
		else //  一个结点 or 没有
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
	printf("插入%d\n", 5);
	for (int i = 0; i < 9; i++)
	{
		int rand_num = rand()%10;
		printf("插入%d\n",rand_num);
		insert(tree, rand_num);
	}
	LevelOrderTrave(tree);
	printf("最大值%d\n",FindMax(tree)->data);
	printf("最小值%d\n", FindMin(tree)->data);
	for (int i = 0; i < 4; i++)
	{
		int rand_num ;
		while ((rand_num = rand() % 10)&& rand_num==5);
		printf("删除%d\n", rand_num);
		delNode(tree, rand_num);
	}
	printf("最大值%d\n", FindMax(tree)->data);
	printf("最小值%d\n", FindMin(tree)->data);
	LevelOrderTrave(t);
	return 0;
}