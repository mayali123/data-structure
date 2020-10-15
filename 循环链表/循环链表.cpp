#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
#define Status int
#define ElemType int  
typedef struct CycleList {
	ElemType data;
	struct CycleList* next;
}CL;
CL* InitCycleList()
{
	CL*clist=(CL*)malloc(sizeof(CL));
	clist->next = clist;
	return clist;
}
void CreateCycleList(CL* clist,ElemType *e,int len)  // 带头结点  尾插
{
	CL* f = clist, *s;
	for (int i = 0; i < len; i++)
	{
		s=(CL*)malloc(sizeof(CL));
		s->data = e[i];
		f->next = s;
		f = s;
	}
	f->next = clist;
}
void show(CL* clist)
{
	CL* f = clist->next;
	for (; f!= clist; f = f->next)
	{
		printf("%d ",f->data);
	}
	printf("\n");
}
int CycleListLength(CL* clist)
{
	CL* f = clist->next;
	int i = 0;
	for (; f!=clist; f = f->next)
		i++;
	return i;
}
Status ElemInsert(CL* clist, int index, ElemType e)
{
	int i;
	CL* f,*s;
	if (index<0 || index>CycleListLength(clist)+1)
		return ERROR;
	if (index == 1)
	{
		f = clist;
		s = (CL*)malloc(sizeof(CL));
		s->data = e;
		s->next = f->next;
		f->next = s;
		i = 0;
		return OK;
	}
	else
	{
		f = clist->next;
		i = 1;
		for (; f != clist; f = f->next)
		{
			if (index - 1 == i)
			{
				s = (CL*)malloc(sizeof(CL));
				s->data = e;
				s->next = f->next;
				f->next = s;
				return OK;
			}
		}
		return ERROR;
	}
	
}
Status ElemDel(CL* clist, int index, ElemType* e)
{
	int i;
	CL* f, * s;
	if (index<0 || index>CycleListLength(clist) + 1)
		return ERROR;
	if (index == 1)
	{
		f = clist;
		s = f->next;
		*e = s->data;
		f->next = s->next;
		free(s);
	}
	else
	{
		f = clist->next;
		i = 1;
		for (; f != clist; f = f->next)
		{
			if (index - 1 == i)
			{
				s = f->next;
				*e = s->data;
				f->next = s->next;
				free(s);
				return OK;
			}
			i++;
		}
	}
}
Status GetElem(CL* clist, int index, ElemType* e)
{
	CL* f = clist->next;
	int i = 1;
	if (index<1 || index>CycleListLength(clist))
		return ERROR;
	for(;f!=clist;f=f->next,i++)
	{ 
		if (i == index)
		{
			*e = f->data;
			return OK;
		}
	}
	return FALSE;
}
int LocateElem(CL* clist, ElemType e)
{
	CL* f = clist->next;
	int i = 1;
	for (; f != clist; f = f->next, i++)
	{
		if (f->data == e)
			return i;
	}
	return NULL;
}
int main()
{
	ElemType E[] = { 1,2,3,4,5,6 },e;
	CL* clist = InitCycleList();
	CreateCycleList(clist,E,6);
	show(clist);
	printf("clist length:%d\n", CycleListLength(clist));
	ElemInsert(clist,1,100);
	show(clist);
	ElemDel(clist, 7, &e);
	printf("删除%d\n",e);
	show(clist);
	GetElem(clist,2,&e);
	printf("第index= 2 的元素为:%d\n",e);
	printf("在list查找 3 index = %d\n", LocateElem(clist,3));
}
