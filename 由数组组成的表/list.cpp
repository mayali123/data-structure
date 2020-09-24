#include<stdio.h>
#include<malloc.h>
//��������ɵ�˳��洢�ı�

/*�������������
  �������� ���Ա�
  ������ ��
	L* create();
	void show(L*list);
	void ElementInster(L* list, Type inster, int index);
	void ElementDelete(L* list, int index);
	int Find(L* list, int Find_num);
*/

/*
*   index �� 1 ��ʼ 
*/

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
void Find(L* list, int Find_num,int* num);
int main()
{
	L* list = create();
	int num[20] = {0}, i = 0;
	Find(list,1,num);
	while (num[i]!=0)
	{
		printf("%d ",num[i]);
		i++;
	}
	if (num[0] == 0)
		printf("δ�ҵ�");
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
	if (index < 1||list->length==MAXSIZE||index>MAXSIZE)
		return;
	/*if (index > list->length&&list->length<MAXSIZE)
		list->data[list->length++] = inster;*/
	else if(list->length+1<=MAXSIZE)
	{
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
	if (index < 1 || index > list->length)
		return;
	int i = index - 1;
	i++;	//�Ƶ�Ҫɾ���ĺ�һ����
	for (;i<list->length;i++)
	{
		list->data[i - 1] = list->data[i];
	}
	list->length--;//ע��Ҫ����Ҫ��һ
}

void Find(L* list, int Find_num,int *num)
{
	int i,j=0;
	for (i=0;i<list->length;i++)
	{
		if (list->data[i] == Find_num)
			num[j++] = i + 1;
	}
}


