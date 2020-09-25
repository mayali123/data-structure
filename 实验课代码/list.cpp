#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 200
#define ElemType char 
#define N 3
typedef struct list{
	ElemType data[MAXSIZE];
	int length;
}L;

void InitList(L *list);
void CreateList(L* list,ElemType *e,int len);
void DestroyList(L* list);
int ListEmpty(L* list);
int Listlength(L* list);
void DispList(L* list);
int GetElem(L* list,int index,ElemType *e);
int LocateElem(L* list,ElemType *e);
int  ListInsert(L*list,int index,ElemType e);
void LocateElemPlus(L* list,ElemType e,int *index);

int DeletEele(L*list,int index,ElemType *e);

int main()
{
	L * list;
	int index[MAXSIZE]={0};
	ElemType e='b';
	list=(L*)malloc(sizeof(L));
	list->length=0;
	char ch[N]={'h','b','b'};
	CreateList(list,ch,N);
	ListInsert(list,1,'a');
	DispList(list);
	printf("len=%d\n",Listlength(list));
	DispList(list);
	LocateElemPlus(list,'h',index);
	for(int i=0;index[i]!=0;i++)
	{
		printf("%d ",index[i]);
	}
	
}

void InitList(L *list)
{
	list=(L*)malloc(sizeof(L));
	list->length=0;
}

void CreateList(L* list,ElemType *e,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		list->data[i]=e[i];
	}
	list->length=len;
}

void DestroyList(L* list)
{
	free(list);
}


int ListEmpty(L* list)
{
	if(list->length)
		return 1;
	else 
		return 0;
}

int Listlength(L* list)
{
	int len=list->length;
	return len;
}

void DispList(L* list)
{
	int i;
	//printf("%d",list->length);
	for (i=0;i<list->length;i++)
	{
		printf("%c ",list->data[i]);
	}
	printf("\n");
}

int GetElem(L* list,int index,ElemType *e)
{
	int i;
	if(index<1||index>list->length)
		return 0;
	*e=list->data[index-1];
	return 1;
}

int LocateElem(L* list,ElemType *e)
{
	int i=0;
	for(;i<list->length;i++)
	{
		if(list->data[i]==*e)
			return i+1;	
		else
			return 0;	
	}
}

int  ListInsert(L*list,int index,ElemType e)
{
	//printf("\n%c\n",e);
	if(index<1||index>list->length)
		return 0;
	int i=index-1;
	int j; 
	for(j=list->length;j>i;j--)
	{
		list->data[j]=list->data[j-1];
	}
	list->data[i]=e;
	list->length++;
	return 1;

}


int DeletEele(L*list,int index,ElemType *e)
{
	if(index<1||index>list->length)
		return 0;
	index--;
	*e=list->data[index];
	int j;
	for(j=index+1;j<list->length;j++)
	{
		list->data[j-1]=list->data[j];
	}
	list->length--;
	return 1;
}


void LocateElemPlus(L* list,ElemType e,int *index)
{
	int i=0,j=0;
	for(;i<list->length;i++)
	{
		if(list->data[i]==e)
			index[j++]=i+1;
	}
}
