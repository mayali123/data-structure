#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define ElemType int  
void swap(int* a, int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
void Bulle_sort(ElemType*p,int n)  // ð������
{
	int i, j, flag = 0;
	for(i=n-1;i>=0;i--)  // ���������Ҫ����� ��� һ�� 
	{ 
		flag = 0;
		for (j = 0; j < i; j++)  
			if (p[j] > p[j + 1])
			{
				swap(&p[j],&p[j+1]);
				flag = 1;
			}
		if (flag == 0)
			break;
	}
}
void insert_sort(ElemType* p, int n)  //��������
{
	int i, j, t;
	for (i = 1; i < n; i++)
	{
		t = p[i];
		for (j = i; j >= 1 && p[j-1]>t; j--)
			p[j] = p[j-1];
		p[j] = t;
	}
}

void insert_sort2(ElemType* p, int n) //��������2
{
	int i, j,t;
	for(i=1;i<n;i++)
	{ 
		t = p[i];
		for (j = i - 1; j >= 0 && p[j] > t; j--)
			p[j + 1] = p[j];
		p[j + 1] = t;
	}
}

void Selection_sort(ElemType* p, int n)  // ѡ������
{
	int i, j,min_index;
	for (i = 0; i < n; i++)
	{
		min_index = i;
		for (j = i; j < n; j++)
			if (p[min_index] > p[j])
				min_index = j;
		swap(&p[i],&p[min_index]);
	}
}
// ϣ������
void shell_sort(ElemType* p, int n)
{
	int D, i, j,tmp;
	for (D = n / 2; D >= 1; D /= 2)  // ���� ϣ�������� 
	{ 
		for (i = D; i < n; i++)
		{
			tmp = p[i];
			for (j = i; j >=D  && p[j-D] > tmp; j -= D)
				p[j] = p[j-D];
			p[j] = tmp;
		}
	}
}
void shell_sort2(ElemType* p, int n)// ϣ������2
{
	int D, i, j, tmp;
	for (D = n / 2; D >= 1; D =D/2)  // ���� ϣ�������� 
	{
		for (i = D; i < n; i++)
		{
			tmp = p[i];
			for (j = i-D; j >= 0 && p[j] > tmp; j -= D)
				p[j+D] = p[j];
			p[j+D] = tmp;
		}
	}
}
//�鲢���� ������ ���ź��� �����һ��
void Merge(ElemType* p, ElemType* tmp, int L, int R, int RightEnd)
{
	int LeftEnd = R - 1,i=L,j=R,k=i;
	while (i <= LeftEnd && j <= RightEnd )
	{
		if (p[i] <= p[j])
			tmp[k++] = p[i++];
		else
			tmp[k++] = p[j++];
	}
	while(i<=LeftEnd)
		tmp[k++] = p[i++];
	while(j<=RightEnd)
		tmp[k++] = p[j++];
	for (i = L; i <= RightEnd; i++)
		p[i] = tmp[i];
}
// �ֶ���֮  ʵ��p������
void Msort(ElemType* p, ElemType* tmp,int L,int RightEnd)
{
	int Center = (L + RightEnd) / 2;
	if (L < RightEnd) 
	{
		Msort(p, tmp, L, Center);
		Msort(p, tmp, Center + 1, RightEnd);
		// �ϲ�
		Merge(p,tmp,L,Center+1,RightEnd);
	}
}
// �鲢����Ľӿ� 
void Merge_sort(ElemType* p, int n)
{
	ElemType* tmp = (ElemType*)malloc(sizeof(ElemType) * n);
	if (tmp != NULL)
	{
		Msort(p,tmp,0,n-1);
		free(tmp);
	}
	else
		printf("�ڴ治�㣡\n");
}
// �ҵ� 3���� ����λ��
ElemType mid3(ElemType* p,int Left,int Right)
{
	int center = (Left+Right)/2;
	if (p[Left] > p[center])
		swap(&p[Left], &p[center]);
	if(p[Left] > p[Right])
		swap(&p[Left], &p[Right]);
	if(p[center] > p[Right])
		swap(&p[center], &p[Right]);
	// һ��С��Ϸ
	swap(&p[center], &p[Right-1]);
	return p[Right - 1];
}
/// ����
void qsort(ElemType* p, int Left, int Right)
{
	if (Left<Right)
	{
		int i = Left, j = Right - 1;
		if(Right-Left+1>=3)
		{
			ElemType mid = mid3(p, Left, Right);
			//printf("mid = %d \n",mid);
			while (1)
			{
				while (p[++i] < mid);
				while (p[--j] > mid);
				if (i < j)
					swap(&p[i], &p[j]);
				else
					break;
			}
			// ѡ�õ���Ԫ �ŵ���ȷ��λ����
			swap(&p[i], &p[Right - 1]);
		}
		else
		{
			int center = (Left + Right) / 2;
			if (p[Left] > p[center])
				swap(&p[Left], &p[center]);
			if (p[Left] > p[Right])
				swap(&p[Left], &p[Right]);
			if (p[center] > p[Right])
				swap(&p[center], &p[Right]);
		}
		/*for (int i = 0; i < 5; i++)
			printf("%d ", p[i]);*/
		printf("\n");
		qsort(p, Left, i - 1);
		qsort(p, i + 1, Right);
	}
	/*else
		insert_sort(p, Right - Left + 1);*/
}
// ��װһ��
void quick_sort(ElemType* p, int n)
{
	qsort(p,0,n-1);
}

// ��һ�� 
void qsort1(ElemType* p, int Left, int Right)
{
	if (Left < Right)
	{
		int mid = p[Right],i=Left-1,j=Right;
		while (1)
		{
			while (p[++i] < mid);
			while (p[--j] > mid);
			if (i < j)
				swap(&p[i], &p[j]);
			else
				break;
		}
		swap(&p[i],&p[Right]);

		qsort1(p, Left, i - 1);
		qsort1(p, i + 1, Right);
	}
}
void quick_sort1(ElemType* p, int n)
{
	qsort1(p, 0, n - 1);
}
int main()
{
	int n;
	scanf("%d",&n);
	ElemType* p = (ElemType*)malloc(sizeof(ElemType) * n);
	for (int i = 0; i < n; i++)
	{
		p[i] = rand() % 100;
		printf("%d ",p[i]);
	}
	printf("\n");

	// ð������
	/*Bulle_sort(p,n);
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);
	printf("\n");*/

	// �������� 
	/*insert_sort2(p, n);
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);*/

	// ѡ������
	/*Selection_sort(p, n);
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);*/

	// ϣ������
	//shell_sort2(p, n);
	//for (int i = 0; i < n; i++)
	//	printf("%d ", p[i]);

	// �鲢����
	/*Merge_sort(p,n);
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);*/

	// ����
	quick_sort1(p,n);
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);
	return 0;
}