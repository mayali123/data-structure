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
LL* CreateListR(ElemType *e ,int len)  // β�� ��ͷ���
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
LL* CreateListF(ElemType* e, int len) // ͷ��  ��ͷ���  Ȼ����ԭ˳���෴
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
	if (index < 0)
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
int main()
{
	int E[] = { 1,2,3,4,5,6 },e;
	LL* linklistR = CreateListR(E, 6);
	//LL* linklistF = CreateListF(E,6);
	show(linklistR);
	printf("list �ĳ����� %d\n",ListLength(linklistR));
	GetElem(linklistR,2,&e);
	printf("index=%d��Ԫ����%d\n",2,e);
	printf("%d��list�ĵ�%d��",4, LocateElem(linklistR,4));
	printf("��index=1����һ��ֵ\n");
	ElemInsert(linklistR,2,9);
	show(linklistR);
	ElemDel(linklistR,7, &e);
	printf("��index=1ɾ��һ��ֵ%d\n",e);
	show(linklistR);
	printf("�ͷ�list\n");
	ListDestroy(linklistR);
}