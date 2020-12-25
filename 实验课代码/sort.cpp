#include<stdio.h>
#include<stdlib.h>
#define ElemType int

void swap(ElemType *a,ElemType *b)
{
	ElemType t;
	t =*a;
	*a = *b;
	*b = t; 
}

// 插入排序 从小到大排 
void insertSort(ElemType *p, int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		// 从第二个开始排
		ElemType tmp=p[i]; 
		// 和他前面的一个比 直到他不大小于 前面的 or j=0 
		for(j=i-1;j>=0&&p[j]>tmp;j--)
			p[j+1] = p[j];
		p[j+1] = tmp;
	}
}

// 冒泡排序1  
void BubbleSort1(ElemType *p, int n)
{
	int i,j;
	for(i=n-1;i>=0;i--)
		for(j=0;j<i;j++)
			if(p[j]>p[j+1])
				swap(&p[j],&p[j+1]);
} 
// 冒泡排序2 
void BubbleSort2(ElemType *p, int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=n-1;j>i;j--)
			if(p[j]<p[j-1])
				swap(&p[j],&p[j-1]);
} 
// 选排 
void SelectSort(ElemType *p, int n)
{
	int i,j,min_index;
	for(i=0;i<n;i++)
	{
		min_index = i;
		for(j=i+1;j<n;j++)
			if(p[min_index]>p[j])
				min_index = j;
		if(min_index!=i)
			swap(&p[i],&p[min_index]);	
	} 
}
// 希尔 排序 
void ShellSort(ElemType *p, int n)
{
	int i,j,d,tmp;
	// 增量  
	for(d=n/2;d>=1;d/=2)
		for(i=d;i<n;i++)
		{
			tmp = p[i];
			for(j=i-d;j>=0&&p[j]>tmp;j-=d)
				p[j+d] = p[j];
			p[j+d] = tmp;
		}
}
// 二路归并
void Merge(ElemType *p,ElemType*tmp, int LStart, int RStart ,int Rend) 
{
	int i=LStart,j=RStart,k=LStart,Lend = RStart-1;
	while(j<=Rend&&i<=Lend) 
	{
		if(p[i]<p[j])
			tmp[k++] = p[i++];
		else if(p[i]>p[j])
			tmp[k++] = p[j++];
	}
	while(i<=Lend)
		tmp[k++] = p[i++];
	while(j<=Rend)
		tmp[k++] = p[j++];
	for(i=LStart;i<=Rend;i++)
		p[i] = tmp[i];
}
// 归并排序 
void Msort(ElemType *p,ElemType*tmp, int L,int R)
{
	if(L<R)
	{
		int L,R,mid=(L+R)/2;
		Msort(p,tmp,L,mid);
		Msort(p,tmp,mid+1,R);
		Merge(p,tmp,L,mid+1,R);
	}
}
// 归并排序的接口 
void MergeSort(ElemType *p, int n)
{
	ElemType * tmp =(ElemType*)malloc(sizeof(ElemType)*n);
	Msort(p,tmp,0,n-1); 
}
// 二分查找 
int BinSearch(ElemType *p, int n,ElemType Find_e)
{
	int L=0,R=n-1,mid;
	while(L<=R)
	{
		mid = (L+R)/2;
		if(p[mid]>Find_e)
			R = mid -1;
		else if(p[mid]<Find_e)
			L = mid +1;
		else
			return mid;
	}
	return -1;
}
// 快排
void Qsort(ElemType *p, int L,int R) 
{
	if(L<R) 
	{
		// 选元组
		ElemType tmp = p[R];
		int i=L,j=R-1;
		while(1)
		{
			while(p[i]<tmp)
				i++;
			while(p[j]>tmp)
				j--;
			if(i<j)
				swap(&p[i],&p[j]);
			else
				break;
		}
		swap(&p[i],&p[R]);
		Qsort(p,L,i-1);
		Qsort(p,i+1,R);
	}
} 
void QuickSort(ElemType *p, int n)
{
	Qsort(p,0,n-1);
} 
int main()
{
	int n,i,num;
	scanf("%d",&n);
	ElemType * p=(ElemType*) malloc(sizeof(ElemType)*n);
	for(i=0;i<n;i++)
	{
		num = rand()%20;
		printf("%d ",num);
		p[i] =num;
 	} 
 	// 插入排序 
// 	insertSort(p,n);
// 	printf("\n");
// 	for(i=0;i<n;i++)
// 		printf("%d ",p[i]);
 	
 	
 	// 冒泡排序1
//	BubbleSort1(p,n); 
// 	printf("\n");
// 	for(i=0;i<n;i++)
// 		printf("%d ",p[i]);
		
	// 选排
//	SelectSort(p,n); 
// 	printf("\n");
// 	for(i=0;i<n;i++)
// 		printf("%d ",p[i]);	

	// 希尔排序
//	ShellSort(p,n); 
// 	printf("\n");
// 	for(i=0;i<n;i++)
// 		printf("%d ",p[i]);	

	// 二分查找
//	ElemType e = 88;
//	int p[]= {1,4,5,7,8,10,22,45,77,88};
//	n =10;
//	printf("\n%d index = %d\n",e,BinSearch(p,n,e)); 
	// 归并排序
//	MergeSort(p,n);
// 	printf("\n");
// 	for(i=0;i<n;i++)
// 		printf("%d ",p[i]);	

	// 快排
	QuickSort(p,n);
	printf("\n");
 	for(i=0;i<n;i++)
 		printf("%d ",p[i]);	 
 	return 0;
} 
