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
void Bulle_sort(ElemType*p,int n)  // 冒泡排序
{
	int i, j, flag = 0;
	for(i=n-1;i>=0;i--)  // 这个代表需要排序的 最后 一个 
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
void insert_sort(ElemType* p, int n)  //插入排序
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

void insert_sort2(ElemType* p, int n) //插入排序2
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
void BIN_insert_sort(ElemType* p, int n)  // 择半插入排序
{
	int i,j,tmp;
	for(i=1;i<n;i++)
	{
		tmp = p[i];
		if(tmp<p[i-1])
		{
			int L=0,R=i-1,mid;
			while(L<=R)
			{
				mid = (L+R)/2;
				if(p[mid]>tmp)
					R = mid - 1;
				else
					L = mid +1;
			}
			for(j=i-1;j>=L;j--)
				p[j+1] = p[j];
			p[j+1] = tmp; 
		}
	}
} 
void Selection_sort(ElemType* p, int n)  // 选择排序
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
// 希尔排序
void shell_sort(ElemType* p, int n)
{
	int D, i, j,tmp;
	for (D = n / 2; D >= 1; D /= 2)  // 控制 希尔增量的 
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
void shell_sort2(ElemType* p, int n)// 希尔排序2
{
	int D, i, j, tmp;
	for (D = n / 2; D >= 1; D =D/2)  // 控制 希尔增量的 
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
//归并排序 将两个 已排好序 结合在一起
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
// 分而治之  实现p的排序
void Msort(ElemType* p, ElemType* tmp,int L,int RightEnd)
{
	int Center = (L + RightEnd) / 2;
	if (L < RightEnd) 
	{
		Msort(p, tmp, L, Center);
		Msort(p, tmp, Center + 1, RightEnd);
		// 合并
		Merge(p,tmp,L,Center+1,RightEnd);
	}
}
// 归并排序的接口 
void Merge_sort(ElemType* p, int n)
{
	ElemType* tmp = (ElemType*)malloc(sizeof(ElemType) * n);
	if (tmp != NULL)
	{
		Msort(p,tmp,0,n-1);
		free(tmp);
	}
	else
		printf("内存不足！\n");
}
// 堆排序 
// 对下标为 i和 其子节点 构造成 最大堆  
void heaping(ElemType *a,int n,int i)
{
	if(i>=n)
		return;
	int c1=i*2,c2=i*2+1;
	int max=i;
	if(c1<n&&a[max]<a[c1]) 
		max = c1;
	if(c2<n&&a[max]<a[c2])
		max = c2;
	if(max !=i)
	{
		swap(&a[i],&a[max]);
		heaping(a,n,max); 
	}
}
void Bulit_heap(ElemType *a,int n)
{
	int last_node = n - 1;
	int i=(last_node-1)/2; // 最后一个 非叶节点的 结点 
	for(;i>=0;i--)
	{
		heaping(a,n,i); 
	} 
}
void heap_sort(ElemType *a,int n)
{
	Bulit_heap(a,n);
	for(int i=n-1;i>=0;i--)
	{
		swap(&a[0],&a[i]);
		heaping(a,i,0);
	}
}

// 找到 3个中 的中位数
ElemType mid3(ElemType* p,int Left,int Right)
{
	int center = (Left+Right)/2;
	if (p[Left] > p[center])
		swap(&p[Left], &p[center]);
	if(p[Left] > p[Right])
		swap(&p[Left], &p[Right]);
	if(p[center] > p[Right])
		swap(&p[center], &p[Right]);
	// 一个小把戏
	swap(&p[center], &p[Right-1]);
	return p[Right - 1];
}
/// 快排
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
			// 选好的主元 放到正确的位置上
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
// 封装一下
void quick_sort(ElemType* p, int n)
{
	qsort(p,0,n-1);
}

// 另一种 
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
// 真正的快排
void qsort2(ElemType* p,int L,int R )
{
	int mid = (L+R)/2,i=L,j =R;
	while(i<j)
	{
		// 如果 i等于j的话 
		//下面的循环 就有一个会满足 
		// 导致出错 
		while(p[i]<p[mid]) i++;
		while(p[j]>p[mid]) j--;
		if(i<j)
			swap(&p[i],&p[j]);
	}
	if(L<mid-1)qsort(p,L,mid-1);
	if(mid+1<R)qsort(p,mid+1,R);
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

	// 冒泡排序
	/*Bulle_sort(p,n);
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);
	printf("\n");*/

	// 插入排序 
	/*insert_sort2(p, n);
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);*/

	// 选择排序
	/*Selection_sort(p, n);
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);*/

	// 希尔排序
	//shell_sort2(p, n);
	//for (int i = 0; i < n; i++)
	//	printf("%d ", p[i]);

	// 归并排序
	/*Merge_sort(p,n);
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);*/

	// 快排
	quick_sort1(p,n);
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);
	return 0;
}
