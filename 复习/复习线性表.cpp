#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
#define Status int
#define ElemType int  
typedef struct List {
	ElemType data[MAXSIZE];
	int length;
}L;
L* InitList()
{
	L* list = (L*)malloc(sizeof(L));
	list->length = 0;
}
void CreateList(L* list, ElemType* e, int len)
{
	for (int i = 0; i < len; i++)
	{
		list->data[i] = e[i];
	}
	list->length = len;
}
void Show(L* list)
{
	printf("\n");
	for (int i = 0; i < list->length; i++)
		printf("%d ", list->data[i]);
	printf("\n");
}
int ListEmpty(L* list)
{
	return list->length == 0;
}
Status GetElem(L* list, int index, ElemType* e)
{
	if (index<1 || index>list->length)
		return ERROR;
	for (int i = 0; i < list->length; i++)
	{
		if (i + 1 == index)
			*e = list->data[i];
	}
	return OK;
}
Status LocateElem(L* list, ElemType e)
{
	for (int i = 0; i < list->length; i++)
	{
		if (list->data[i] == e)
			return i + 1;
	}
	return FALSE;
}
Status ElemInsert(L* list, int index, ElemType e)
{
	if (index<1 || index>list->length + 1)
		return ERROR;
	if (list->length == MAXSIZE)
		return ERROR;
	if (index <= list->length + 1)
	{

		for (int i = list->length - 1; i >= index - 1; i--)
		{
			list->data[i + 1] = list->data[i];
		}
	}
	list->data[index - 1] = e;
	list->length++;
	return OK;
}
Status ElemDel(L* list, int index, ElemType* e)
{
	if (index<1 || index>list->length)
		return ERROR;
	int i = index - 1;
	*e = list->data[i];
	for (; i + 1 < list->length; i++)
		list->data[i] = list->data[i + 1];
	return OK;
}
int main()
{
	L* list = InitList();
	int E[6] = { 1,2,3,4,5,6 }, e;
	CreateList(list, E, 6);
	Show(list);
	GetElem(list, 6, &e);
	printf("%d\n", e);
	printf("%d在%d\n", e, LocateElem(list, e));
	ElemInsert(list, 2, 10);
	Show(list);
	ElemDel(list, 1, &e);
	printf("删除了%d\n", e);
}
