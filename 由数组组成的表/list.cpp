#include<stdio.h>
#include<malloc.h>
//��������ɵ�˳��洢�İɱ�

#define Type int
#define MAXSIZE 20
typedef struct Mylist {
	Type data[MAXSIZE];
	int length;
}L;

L* create();
void show(L*list);
void ElementInster(L* list, Type inster, int index);
void ElementDelete(L* list, int index);
int main()
{
	L* list = create();
	ElementDelete(list,2);
	show(list);
	return 0;
}

L* create()
{
	L *list;
	list = (L*)malloc(sizeof(L));
	if (list == NULL)
		return 0;
	list->length = 0;
	char ch;
	do
	{
		printf("������һ��data:");
		scanf_s("%d", &list->data[list->length]);
		getchar();
		list->length++;
		printf("�Ƿ��������y/n:");
		scanf_s("%c",&ch,1);
	} while (list->length<=MAXSIZE&&ch=='y');
	return list;
}

void show(L*list)
{
	int i;
	for (i = 0; i < list->length; i++)
		printf("%d\n", list->data[i]);
}

void ElementInster(L*list,Type inster,int index)
{
	if (index < 1)
		return;
	if (index > list->length)
		list->data[list->length++] = inster;
	else if(list->length+1<=MAXSIZE)
	{
		Type k;
		int i = list->length-1;
		for (; i >= index - 1; i--)
		{
			list->data[i+1] = list->data[i];
		}
		list->data[i+1] = inster;
		list->length++;//ע��Ҫ����Ҫ��һ
	}
}

void ElementDelete(L* list, int index)
{
	if (index < 1 || index >= list->length)
		return;
	int i = index - 1;
	i++;	//�Ƶ�Ҫɾ���ĺ�һ����
	for (;i<list->length;i++)
	{
		list->data[i - 1] = list->data[i];
	}
	list->length--;//ע��Ҫ����Ҫ��һ
}
