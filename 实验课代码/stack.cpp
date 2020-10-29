#include<stdio.h>
#include<malloc.h>
#define ElemType char 
#define MAXSIZE 100
#define Status int 
#define Error 0
#define True 1
#define FALSE 0
#define OK 1
typedef struct stack{
	ElemType data[MAXSIZE];
	int top;
}ST; 
ST* InitStack()
{
	ST* stack =(ST*)malloc(sizeof(ST)) ;
	stack->top =-1;
	return stack;
}


Status Push(ST*stack,ElemType e)
{
	if(stack->top==MAXSIZE-1)
		return FALSE;
	stack->data[++stack->top] = e;
	return OK;
}


Status Pop(ST*stack,ElemType *e)
{
	if(stack->top==-1)
		return FALSE;
	*e = stack->data[stack->top--];
	return OK;
}

void DestroyStack(ST* stack)
{
	free(stack);
}

// 为空返回 1  不为空返回0
int StackEmpty(ST* stack)
{
	return (stack->top == -1);
}

int GetTop(ST* stack,ElemType * e)
{
	if (stack->top == -1)
		return Error;
	*e = stack->data[stack->top];
	return True;
}

void show(ST* stack)
{
	for (int i = 0; i <= stack->top; i++)
	{
		printf("%d ", stack->data[i]);
	}
}


void trans(char *exp,char *postexp)
{
	ST * p=InitStack();
	int k=0;
	char e;
	for(int i=0;exp[i]!='\0';i++)
	{
		switch(exp[i])
		{
			case '(':
				Push(p,exp[i]);
				break;
			case ')':
				while(1)
				{
					Pop(p,&e);
					if(e =='(')
						break;
					postexp[k++]=e;
				}
				break;
			case '+':
				while(1)
					{
						Pop(p,&e);
						if(StackEmpty(p)||e=='(')
							break;
						postexp[k++] = e;
					}
					Push(p,exp[i]);
					break;
			case '-':
				
			case '*':
				
				break;
			case '/':
				
				break;
			default:
				while('0'<=exp[i]&&exp[i]<='9')
				{
					postexp[k++]=exp[i];
					i++;
				}
				postexp[k++] = ' ';
		}
	}
	while(!StackEmpty(p))
	{
		Pop(p,&e);
		printf("%c ",e);
		postexp[k++] = e;
	}
	postexp[k++]='\0';
}
/*int comp(char *exp)
{
	ST *p =InitStack();
	int num1,num2,e;
	for(int i=0;exp[i]!='\0';i++)
	{
		switch(exp[i])
		{
			case '+':
				Pop(p,&num1);
				Pop(p,&num2);
				Push(p,num1+num2);
				break;
			case '-':
				Pop(p,&num1);
				Pop(p,&num2);
				Push(p,num2-num1);
				break;
			case '*':
				Pop(p,&num1);
				Pop(p,&num2);
				Push(p,num2*num1);
				break;
			case '/':
				Pop(p,&num1);
				Pop(p,&num2);
				Push(p,num2/num1);
				break;
			default:
				int a=0;
				while('0'<=exp[i]&&exp[i]<='9')
				{
					a =a*10+exp[i]-'0';	
					i++;
				}
				Push(p,a);
		}
	}
	GetTop(p,&e);
	DestroyStack(p);
	return e;
}
*/
int main()
{
	/*int i=comp("122 2 -");
	printf("%d",i);
	return 0;*/
	char ch[]="123+2",ch1[100];
	trans(ch,ch1);
	printf("%s",ch1);
}

