#include<stdio.h>
#include<malloc.h> 
#define MAXSIZE 200 
typedef struct {
	int n;
	char a,b,c;
	int flag;  // 0������Բ��ƶ� 1��������ƶ� 
}Data;
typedef struct {
	Data data[MAXSIZE];
	int top;
}stack;
// �������� �� a�ܵ��� �ƶ��� c�� 
// �ݹ�ʵ�� 
void hanoi(int n,char a,char b,char c) 
{
	if(n==1)
		printf("��%c�ƶ���%c\n",a,c);
	else
	{
		// �� �� a���� n-1�� �� �� �ƶ� b�� 
		hanoi(n-1,a,c,b); 
		//  �� a ����� һ���� ��  �ƶ� c ��
		hanoi(1,a,b,c);
		// Ȼ�� b �� �ƶ� �� c�� 
		hanoi(n-1,b,a,c);
	}
}

// �������� �� a�ܵ��� �ƶ��� c�� 
// �ǵݹ� 
void hanoi2(int n,char a,char b,char c) 
{
	// �� ջ ʵ�� ��ȡ����
	// ��ʼ��ջ 
	stack * p =(stack*)malloc(sizeof(stack));
	p->top=-1;
	
	Data e,e1,e2,e3,e4;
	e.a =a;
	e.b = b;
	e.c = c;
	e.n = n;
	if(n!=1)
		e.flag = 0;
	else 
		e.flag = 1; 
	p->data[++p->top] = e; 
	while(p->top!=-1)  // ��Ϊ��ʱ 
	{
		e1 = p->data[p->top--];
		
		
		if(e1.flag== 1)  //����ֱ���ƶ�
			printf("��%c�ƶ���%c\n",e1.a,e1.c);
		else
		{
			//hanoi(n-1,b,a,c);
			e2.n = e1.n -1;
			e2.a = e1.b;
			e2.b =e1.a;
			e2.c = e1.c;
			if(e2.n ==1) 
				e2.flag =1;
			else
				e2.flag=0;
			// ��ջ 
			p->data[++p->top] = e2; 
			
			
			// ʵ�� hanoi(1,a,b,c);
			e3 = e1;
			e3.flag = 1;
			// ��ջ 
			p->data[++p->top] = e3; 

			// ʵ�� hanoi(n-1,a,c,b); 
			
			e4.n = e1.n -1;
			e4.a = e1.a;
			e4.b =e1.c;
			e4.c = e1.b;
			if(e4.n == 1) 
				e4.flag =1;
			else
				e4.flag=0;
			// ��ջ 
			p->data[++p->top] = e4; 
		}
		
	} 
}
int main()
{
	int n;
	printf("�����������");
	scanf("%d",&n);
	hanoi(n,'A','B','C'); 
	printf("\n"); 
	hanoi2(n,'A','B','C');
}
