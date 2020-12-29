#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
#define Status int
#define ElemType int  
typedef struct LinkList {
	ElemType data;
	struct LinkList* next;
}LL;
LL* CreateListR(ElemType *e ,int len)  // 尾插 带头结点
{
	LL *linklist=(LL*)malloc(sizeof(LL)),*r,*s;
	r = linklist;
	for (int i = 0; i < len; i++)
	{
		s = (LL*)malloc(sizeof(LL));
		s->data = e[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return linklist;
}
LL* CreateListF(ElemType* e, int len) // 头插  带头结点  然后与原顺序相反
{
	LL* linklist = (LL*)malloc(sizeof(LL)), * s;
	linklist->next = NULL;
	for (int i = 0; i < len; i++)
	{
		s = (LL*)malloc(sizeof(LL));
		s->data = e[i];
		s->next = linklist->next;
		linklist->next = s;
	}
	return linklist;
}
int ListLength(LL* linklist)
{
	LL* f = linklist->next;
	int len = 0;
	for (; f; f = f->next)
		len++;
	return len;
}
void show(LL* linklist)
{
	LL* f = linklist->next;
	for (; f; f = f->next)
	{
		printf("%d ",f->data);
	}
	printf("\n");
}
Status GetElem(LL* linklist, int index, ElemType* e)
{
	LL* f = linklist->next;
	if (index <= 0)
		return ERROR;
	for (int i = 1; f;f=f->next, i++)
	{
		if (i == index)
		{
			*e = f->data;
			return OK;
		}
	}
	return FALSE;
}
int LocateElem(LL* linklist, ElemType e)
{
	LL* f = linklist->next;
	for (int i = 1; f; f = f->next, i++)
	{
		if (f->data == e)
			return i;
	}
	return FALSE;
}
Status ElemInsert(LL* linklist, int index, ElemType e)
{
	int i = 0;
	LL* f = linklist,*s;
	if (index < 0||index>ListLength(linklist)+1)
		return ERROR;
	for (; f; f = f->next,i++)
	{
		if (i == index - 1)
		{
			s = (LL*)malloc(sizeof(LL));
			s->data = e;
			s->next = f->next;
			f->next = s;
		}
	}
	return FALSE;
}
Status ElemDel(LL* linklist, int index, ElemType* e)
{
	int i = 0;
	LL* f = linklist, * s;
	if (index < 0 || index>ListLength(linklist))
		return ERROR;
	for (; f; f = f->next, i++)
	{
		if (i == index - 1)
		{
			s = f->next;
			f->next = s->next;
			*e = s->data;
			free(s);
			return OK;
		}
	}
}
void ListDestroy(LL* linklist)
{
	LL* f = linklist,*s=f->next;
	for (; s;)
	{
		free(f);
		f = s;
		s = f->next;
	}
	free(f);
}
void quick_middle_search(LL* linklist)
{
	LL* f = linklist->next, * s = f;
	for (;f->next;)
	{
		if (f->next->next)
		{
			f = f->next->next;
			s = s->next;
		}
		else
			f = f->next;
	}
	printf("中间的 %d\n",s->data);
}
int main()
{
	int E[] = { 1,2,3,4,5,6 },e;
	LL* linklistR = CreateListR(E, 6);
	//LL* linklistF = CreateListF(E,6);
	show(linklistR);
	printf("list 的长度是 %d\n",ListLength(linklistR));
	GetElem(linklistR,2,&e);
	printf("index=%d的元素是%d\n",2,e);
	printf("%d在list的第%d个",4, LocateElem(linklistR,4));
	printf("在index=1插入一个值\n");
	ElemInsert(linklistR,2,9);
	show(linklistR);
	ElemDel(linklistR,7, &e);
	printf("在index=1删除一个值%d\n",e);
	show(linklistR);
	printf("释放list\n");
	ListDestroy(linklistR);
}
