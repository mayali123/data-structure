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
ST* ListAdd(ST*head, ST* Add);
ST* ListAddOne(ST* head, ST* Add);
int ListLen(ST*head);
void show(ST* head);
void find(ST* head);

ST* Union(ST* a, ST* b);

void list(ST* p)
{
	while (1)
	{
		if (p->next != NULL)
		{
			printf("%s\n", p->name);
			p = p->next;
		}
		else
		{
			printf("%s\n", p->name);
			break;
		}
	}
}

void main()
{

	ST*st2 = create();
	show(Union(st2,create()));

	
}


void show(ST* head)
{
	ST* p = head;
	while (p->next != NULL)
	{
		printf("学号%d 名字%s 性别%s 班级%d \n", p->num, p->name, p->sex, p->Class);
		p = p->next;
	}
	printf("学号%d 名字%s 性别%s 班级%d", p->num, p->name, p->sex, p->Class);
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
	p=head;
	char j;
	printf("是否要继续输入y/n:");
	scanf_s("%c", &j, 1);
	//printf("%c",j);
	while (j == 'y')
	{
		newPoint = (ST*)malloc(sizeof(ST));
		p->next = newPoint;
		p = newPoint;
		printf("请输入分别输入 学号 名字 性别 班级:");
		scanf_s("%d%s%s%d", &p->num, p->name, 10, p->sex, 4, &p->Class);
		getchar();
		
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
	while (p != NULL)
	{
		if (p->num == num)
		{
			printf("学号%d 名字%s 性别%s 班级%d \n", p->num, p->name, p->sex, p->Class);
			break;
		}
		p = p->next;
	}
	if (p== NULL)
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
	len++;
	return len;
}

ST* ListInsert(ST* head,ST *inster,int index)
{
	ST* p1=head, * p2=inster;
	if (ListLen(p1) < index)
	{
		printf("%d超过了链表",index);
		return 0;
	}
	if (index == 1)
	{
		while (p2->next != NULL)
			p2 = p2->next;
		p2->next = p1;
		head = p2;
	}
	else
	{
		int i=1;
		ST* p= p1;
		while (p->next != NULL)
		{
			if (i == index - 1)
			{
				
				while (p2->next != NULL)
					p2 = p2->next;
				p2->next = p->next;
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
ST* ListAdd(ST* head,ST*Add)
{
	ST* p = head,*p1=Add;
	while (p->next != NULL)
		p = p->next;
	p->next = p1;
	while (p1->next != NULL)
		p1 = p1->next;
	p1->next = NULL;
	return head;
}
ST* ListAddOne(ST* head, ST* Add)
{
	ST* p = head, * p1 = Add;
	while (p->next != NULL)
		p = p->next;
	p->next = p1;
	p1->next = NULL;
	return head;
}

ST* Union(ST* a,ST *b)
{
	ST* p1=a, * p2=b,*p3;
	int len=ListLen(a),len2=ListLen(b),j=0;
	printf("\n%d\n",len);
	while (p1!=NULL)
	{
		int k = 1,i=0;
		p1 = a;
		while (i<len)
		{
			printf("p1:%d  p2 %d\n",p1->num,p2->num);
			if (p2->num == p1->num)
			{ 
				k = 0;
				printf("xiandeng");
				break;

			}
			p1 = p1->next; 
			i++;
			printf("hhh\n");
		}
		if (k)
		{
			ListAddOne(a, p2);
			printf("add");
		}
		p2 = p2->next;
		j++;
	}
	return a;
}