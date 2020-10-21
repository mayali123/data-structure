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
LL* CreateListR(ElemType* e, int len)  // 尾插 带头结点
{
	LL* linklist = (LL*)malloc(sizeof(LL)), * r, * s;
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
		printf("%d ", f->data);
	}
	printf("\n");
}
Status GetElem(LL* linklist, int index, ElemType* e)
{
	LL* f = linklist->next;
	if (index < 0)
		return ERROR;
	for (int i = 1; f; f = f->next, i++)
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
	LL* f = linklist, * s;
	if (index < 0 || index>ListLength(linklist) + 1)
		return ERROR;
	for (; f; f = f->next, i++)
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
	LL* f = linklist, * s = f->next;
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
	for (; f->next;)
	{
		if (f->next->next)
		{
			f = f->next->next;
			s = s->next;
		}
		else
			f = f->next;
	}
	printf("%d\n", s->data);
}
int LocateElemPlus_Up(LL* linklist, ElemType e)  //适用于元素是升序的
{
	int i = 1, flog = 1;  //flog 用来判断是不是第一个
	//1 3 5 7
	LL* f = linklist->next, * s = f;
	for (; f->next;)
	{
		if (f->data == e)
		{
			/*printf("f:%d\n", f->data);*/
			return i;
		}
		else if (f->data > e)
		{
			if (s->data == e)
			{
				/*printf("s:%d\n", s->data);*/
				if (!flog)  //第一个就不用减1了 其他的要减
					i--;
				return i;
			}
			else
				return NULL;
		}
		else {
			if (f->next->next)
			{
				s = f->next;
				f = f->next->next;
				i += 2;
			}
			else
			{
				f = f->next;
				/*i += 1;*/
			}
			flog = 0;
		}
	}
	return ListLength(linklist);
}

int LocateElemPlus_Down(LL* linklist, ElemType e)
{
	int i = 1, flog = 1;  //flog 用来判断是不是第一个
	//1 3 5 7
	LL* f = linklist->next, * s = f;
	for (; f->next;)
	{
		if (f->data == e)
		{
			/*printf("f:%d\n", f->data);*/
			return i;
		}
		else if (f->data < e)
		{
			if (s->data == e)
			{
				/*printf("s:%d\n", s->data);*/
				if (!flog)
					i--;
				return i;
			}
			else
				return NULL;
		}
		else {
			if (f->next->next)
			{
				s = f->next;
				f = f->next->next;
				i += 2;
			}
			else
			{
				f = f->next;
				/*i += 1;*/
			}
			flog = 0;
		}
	}
	return ListLength(linklist);
}
LL* transform(LL *list) // 头插  带头结点  然后与原顺序相反
{ 
	//ElemType* e;
	//int len;
	LL* linklist = (LL*)malloc(sizeof(LL)), * s,*p=list->next;
	linklist->next = NULL;
	for (; p; p=p->next)
	{
		s = (LL*)malloc(sizeof(LL));
		s->data = p->data;
		s->next = linklist->next;
		linklist->next = s;
	}
	return linklist;
}
int main()
{
	int E2[] = { 1,2,3,4,5,6 }, e;
	LL* linklistR = CreateListR(E2, 6);
	//LL* linklistF = CreateListF(E,6);
	show(linklistR);
	printf("list 的长度是 %d\n", ListLength(linklistR));
	GetElem(linklistR, 2, &e);
	printf("index=%d的元素是%d\n", 2, e);
	printf("%d在list的第%d个\n", 4, LocateElem(linklistR, 4));
	printf("在index=1插入一个值\n");
	ElemInsert(linklistR, 2, 9);
	show(linklistR);
	ElemDel(linklistR, 7, &e);
	printf("在index=1删除一个值%d\n", e);
	show(linklistR);
	printf("释放list\n");
	ListDestroy(linklistR);

	printf("\n\n");
	ElemType E1[] = { 15,12,11,9,7,5,4,2,1 };
	LL* linklist1 = CreateListR(E1, 9);
	printf("降序的list为 ");
	show(linklist1);

	ElemType E[] = { 1,2,3 ,4,5,6,7,8,9 };
	LL* linklist = CreateListR(E, 9);
	printf("升序的list为 ");
	show(linklist);


	printf("查找降序的list的中间元素 ");
	quick_middle_search(linklist1);


	int index = LocateElemPlus_Up(linklist, 3);
	printf("在升序的list查找3的index=%d\n", index);


	int index1 = LocateElemPlus_Down(linklist1, 5);
	printf("在降序的list查找5的index=%d\n", index1);

	printf("翻转\n");
	show(linklist);
	LL *tran_list=transform(linklist);
	show(tran_list);
}
