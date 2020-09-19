#include<stdio.h>
#include<malloc.h>
//#define _CRT_SECURE_NO_WARNINGS
#define N  6
typedef struct student
{
	int num;
	char name[10];
	char sex[4];
	int Class;
	struct student* next;
}ST;



ST* create();
ST* ListInsert(ST* head, ST* inster, int index);
ST* ListDelete(ST* head, int index);
int ListLen(ST*head);
void show(ST* head);


void main()
{

	ST inster = {123,"好好","男",123};
	show(ListDelete(create(),1));
}


void show(ST* head)
{
	ST* p = head;
	while (p->next != NULL)
	{
		printf("学号%d 名字%s 性别%s 班级%d \n", p->num, p->name, p->sex, p->Class);
		p = p->next;
	}
}

ST* create()
{
	ST* head, * newPoint, * p;
	head = (ST*)malloc(sizeof(ST));
	printf("请输入分别输入 学号 名字 性别 班级:");
	scanf_s("%d%s%s%d", &head->num, head->name, 10, head->sex, 4, &head->Class);
	getchar();
	/*printf("%d %s %s %d ", head->num, head->name, head->sex, head->Class);*/
	p = (ST*)malloc(sizeof(ST));
	head->next = p;
	char j;
	printf("是否要继续输入y/n:");
	scanf_s("%c", &j, 1);
	while (j == 'y')
	{
		newPoint = (ST*)malloc(sizeof(ST));
		printf("请输入分别输入 学号 名字 性别 班级:");
		scanf_s("%d%s%s%d", &p->num, p->name, 10, p->sex, 4, &p->Class);
		getchar();
		p->next = newPoint;
		p = newPoint;
		printf("是否要继续输入y/n:");
		scanf_s("%c", &j, 1);
	}
	p->next = NULL;
	return head;
}

void find(ST* head)
{
	ST* p = head;
	int num;
	printf("请输入你要查找的学号:");
	scanf_s("%d", &num);
	while (p->next != NULL)
	{
		if (p->num == num)
		{
			printf("学号%d 名字%s 性别%s 班级%d \n", p->num, p->name, p->sex, p->Class);
			break;
		}
		p = p->next;
	}
	if (p->next == NULL)
		printf("未找到学号为%d的学生", num);

}

int ListLen(ST* head)
{
	int len=0;
	ST* p=head;
	while (p->next!=NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}

ST* ListInsert(ST* head,ST *inster,int index)
{
	if (ListLen(head) < index)
	{
		printf("%d超过了链表",index);
		return 0;
	}
	if (index == 1)
	{
		inster->next = head;
		head = inster;
	}
	else
	{
		int i=1;
		ST* p=head;
		while (p->next != NULL)
		{
			if (i == index - 1)
			{
				inster->next = p->next;
				p->next = inster;
				break;
			}
			p = p->next;
			i++;
		}
	}
	return head;
}

ST* ListDelete(ST* head, int index)
{
	if (ListLen(head) < index)
	{
		printf("%d超过了链表", index);
		return 0;
	}
	if (index == 1)
		head = head->next;
	else
	{
		int i=1;
		ST* p=head;
		while (p->next != NULL)
		{
			if (i == index - 1)
			{
				p->next = p->next->next;
				break;
			}
			p = p->next;
			i++;
		}
	}
	return head;
}