/*
中缀表达式如何转换为后缀表达式:
	> 从头到尾读取中缀表达式的每个对象，对不同对象按不同的情况处理。
	①运算数 : 直接输出;
	左括号:压入堆栈;
	③右括号:将栈顶的运算符弹出并输出，直到遇到左括号（出栈，不输出）:
	④运算符:
	·若优先级大于栈顶运算符时，则把它压栈;
	·若优先级小于等于栈顶运算符时，将栈顶运算符弹出并输出; 再比
	较新的栈顶运算符，直到该运算符大于栈顶运算符优先级为止，然
	后将该运算符压栈
	'(' 的优先级最低
	⑤若各对象处理完毕，则把堆栈中存留的运算符一并输出。
*/

# include<stdio.h>
# include<malloc.h>
#define TpyeElem char
#define MAXSIZE 20
#define Error 0
#define True 1


typedef struct stack
{
	TpyeElem data[MAXSIZE];
	int top;
}ST;

ST* InitStack()
{
	ST* St = (ST*)malloc(sizeof(ST));
	St->top = -1;
	return St;

}

void DestroyStack(ST* St)
{
	free(St);
}

// 为空返回 1  不为空返回0
int StackEmpty(ST* St)
{
	return (St->top == -1);
}

int Push(ST* St, TpyeElem e)
{
	if (St->top == MAXSIZE - 1)
		return Error;
	St->top++;
	St->data[St->top] = e;
	return True;
}

int Pop(ST* St, TpyeElem* e)
{
	if (St->top == -1)
		return Error;
	*e = St->data[St->top];
	St->top--;
	return True;
}

int GetTop(ST* St, TpyeElem* e)
{
	if (St->top == -1)
		return Error;
	*e = St->data[St->top];
	return True;
}

void show(ST* St)
{
	for (int i = 0; i <= St->top; i++)
	{
		printf("%d ", St->data[i]);
	}
}

int main()
{
	ST* stack = InitStack();
	int i = 0, num;
	TpyeElem E[MAXSIZE], e;
	gets_s(E, MAXSIZE);
	while (E[i] != '#' && E[i] != '\0')
	{
		num = 0;
		while ('0' <= E[i] && E[i] <= '9')
		{
			//printf("E[%d]=%d ",i,E[i] );
			num = num * 10 + E[i] - '0';
			i++;
		}
		if (num)
			printf("%d ", num);
		if (E[i] == '(')
		{
			Push(stack, E[i]);
		}
		else if (E[i] == ')')
		{

			while (!StackEmpty(stack))
			{
				Pop(stack, &e);
				if (e == '(')
					break;
				printf("%c ", e);
			}
		}
		else if (E[i] == '+' || E[i] == '-' || E[i] == '*' || E[i] == '/')
		{
			GetTop(stack, &e);
			if (StackEmpty(stack))
				Push(stack, E[i]);
			else if (((E[i] == '*' || E[i] == '/') && (e == '-' || e == '+'))||((E[i] == '+' || E[i] == '-' || E[i] == '*' || E[i] == '/')&&e == '('))
			{
				Push(stack,E[i]);
			}
			else 
			{
				/*while (!StackEmpty(stack))
				{
					Pop(stack,&e);
					printf("%c ",e);
					if (((E[i] == '*' || E[i] == '/') && (e == '-' || e == '+')) || ((E[i] == '*' || E[i] == '/' || E[i] == '-' || E[i] == '+') &&e == '('))
					{
						Push(stack,E[i]);
						break;
					}
				}
				Push(stack, E[i]);*/
				if(!StackEmpty(stack))
					Pop(stack, &e);
				while (!(((E[i] == '*' || E[i] == '/') && (e == '-' || e == '+')) || ((E[i] == '+' || E[i] == '-' || E[i] == '*' || E[i] == '/') && e == '('))&&!StackEmpty(stack))
				{
					printf("%c ", e);
					Pop(stack, &e);
				}
				if ((((E[i] == '*' || E[i] == '/') && (e == '-' || e == '+')) || ((E[i] == '+' || E[i] == '-' || E[i] == '*' || E[i] == '/') && e == '(')))
					Push(stack, E[i]);
				else if (StackEmpty(stack))
				{ 
					Push(stack, E[i]);
					
				}
				if(e!='(')
					printf("%c ", e);
			}
		}
		i++;
	}
	//printf("next");
	for (;!StackEmpty(stack);)
	{
		Pop(stack,&e);
		printf("%c ",e);
	}
}
//2*(9+6/3-5)+4