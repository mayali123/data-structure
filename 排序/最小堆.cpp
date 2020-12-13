//// ʹ�� ��ȫ������ ʵ����С��
//// ʹ�����鱣��data
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define ElemType int
typedef struct Heap{
	ElemType *data;
	// �ѵ����ֵ �����ѵ�ʱ��ʹ��
	int max_size;
	// ���� �ѵĴ�С
	int size;  
}H;
H* Create_Heap(int max_size)
{
	// ��ʼ��
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
		printf("������\n");
		return;
	}
	int i,father ;
	//  �������±�Ϊ1�ĵط���ʼ����
	father = ++heap->size;
	for (; father / 2 >= 1 && heap->data[father/2] > e; father /= 2)
		heap->data[father] = heap->data[father/2];
	heap->data[father] = e;
}

// ɾ����С���Ǹ� Ԫ�� Ҳ���� ���ڵ� 
ElemType del_min(H* heap)
{
	//  �յ����
	if (heap->size <= 0)
	{
		printf("Ϊ��\n");
		return -1;
	}
	int min = heap->data[1],e,father=1,child,min_index;
	// ��ʱ�����һ�������� ���ڵ�
	e = heap->data[heap->size--];
	// ������ �Ƚ�
	for (; father*2 <= heap->size;father=min_index)
	{
		// child ����
		child = 2 * father;
		min_index = child;
		// �ж��Ƿ����ҽ�� �ҳ���С��ֵ
		if (child + 1 <= heap->size && heap->data[child] > heap->data[child + 1])
			min_index = child + 1;
		if (e <= heap->data[min_index])
			break;
		else
			heap->data[father] = heap->data[min_index];
	}
	heap->data[father] = e;
	return min;
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
		printf("%d ",del_min(p));
}