// 使用 完全二叉树 实现最大堆
// 使用数组保存data
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define ElemType int
typedef struct Heap{
	ElemType *data;
	// 堆的最大值 创建堆的时候使用
	int max_size;
	// 现在 堆的大小
	int size;  
}H;
H* Create_Heap(int max_size)
{
	// 初始化
	H* heap= (H*)malloc(sizeof(H) * max_size);
	heap->data = (ElemType*)malloc(sizeof(ElemType)*max_size);
	heap->max_size = max_size;
	heap->size = 0;

	return heap;
}
void insert(H *heap, ElemType e)
{
	if (heap->size + 1 > heap->max_size)
	{
		printf("堆已满\n");
		return;
	}
	int i,father ;
	//  从数组下标为1的地方开始保存
	father = ++heap->size;
	for (; father / 2 >= 1 && heap->data[father/2] < e; father /= 2)
		heap->data[father] = heap->data[father/2];
	heap->data[father] = e;
}
// 删除最大的那个 元素 也就是 根节点 
ElemType del_max(H* heap)
{
	//  空的情况
	if (heap->size <= 0)
	{
		printf("为空\n");
		return -1;
	}
	int max = heap->data[1],e,father=1,child,max_index;
	// 暂时用最后一个来代替 根节点
	e = heap->data[heap->size--];
	// 接下来 比
	for (; father*2 <= heap->size;father=max_index)
	{
		// child 左结点
		child = 2 * father;
		max_index = child;
		// 判断是否有右结点 找出最大的值
		if (child + 1 <= heap->size && heap->data[child] < heap->data[child + 1])
			max_index = child + 1;
		if (e >= heap->data[max_index])
			break;
		else
			heap->data[father] = heap->data[max_index];
	}
	heap->data[father] = e;
	return max;
}
int main()
{
	int num;
	H* p = Create_Heap(20);
	for (int i = 0; i < 5; i++)
	{
		num = rand() % 100+1;
		insert(p, num);
		printf("%d ", num);
	}
	printf("\n");
	for (int i = 0; i < 5; i++)
		printf("%d ",del_max(p));
}