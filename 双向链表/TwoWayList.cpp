#include<stdio.h>
#include<malloc.h>
#define N 4
typedef int ELemType;

typedef struct TwoWayList {
	ELemType data;
	struct TwoWayList* prior;
	struct TwoWayList* next;
}TL;

TL* InitList()
{
	TL *list = (TL*)malloc(sizeof(TL));
	list->prior=list->next = NULL;
	list->data = 0;
	return list;
}

void CreateList(TL*list, ELemType*a,int len)
{
	TL* L = (TL*)malloc(sizeof(TL));
	L = list;
	for (int i=0;i<len;i++)
	{
		TL *s= (TL*)malloc(sizeof(TL));
		s->data= a[i];
		L->next = s;
		s->prior = L;
		L = s;
	}
	list->data = len;		//用list 的data来保存长度
	L->next= NULL;
}
int Listlength(TL* list)
{
	return list->data;
}

void show(TL* head)
{
	TL* p = head->next;
	printf("\n");
	for(int i=0;i<Listlength(head);i++)
	{
		printf("%c ",p->data);
		p = p->next;
	}
}
int GetElem(TL* list,int index, ELemType *e)
{
	TL* p = list->next;
	if (index <1 || index>Listlength(list))
		return 0;
	for (int i = 1; i < Listlength(list); i++)
	{
		if (i == index)
			*e = p->data;
		p = p->next;
	}
	return 1;
}

int LoactElem(TL* list, ELemType* e)
{
	TL* p = list->next;
	int i;
	for (i = 0; i < Listlength(list); i++)
	{
		if (p->data == *e)
			return i+1;
		p = p->next;
	}
	if (i >= Listlength(list))
		return 0;
}
void InsertElem(TL* list,int index,ELemType e)
{
	TL* p = list->next;
	if (index <1 || index>Listlength(list))
		return ;
	for (int i = 1; i <= Listlength(list); i++)
	{
		if (i == index)
		{
			TL* m =(TL*)malloc(sizeof(TL));
			m->data = e;
			m->next = p;
			m->prior = p->prior;
			p->prior->next = m;
			p->prior = m;
		}
		p = p->next;
	}
	list->data++;
	printf("\nlen=%d", list->data);
}
void DeletElem(TL* list, int index, ELemType* e)
{
	TL* p = list->next;
	if (index <1 || index>Listlength(list))
		return;
	for (int i = 1; i <= Listlength(list); i++)
	{
		if (i == index)
		{
			/*p->prior->next = p->next;
			p->next= p->prior;*/
			p->next->prior = p->prior;
			p->prior->next = p->next;
			*e = p->data;
			free(p);	
			break;
		}
		p =p->next;
	}
	list->data--;
}
int main()
{
	TL* list = InitList();
	ELemType a[N] = { 'a','b','c','h' },e;
	CreateList(list,a,N);
	show(list);
	GetElem(list, 2, &e);
	printf("第二个为e=%c",e);
	printf("\n%d\n", LoactElem(list,&e));
	InsertElem(list,2,'l');
	show(list);
	DeletElem(list, 4,&e);
	printf("\ndd");
	show(list);
	printf("\n删除的是%c", e);
}






