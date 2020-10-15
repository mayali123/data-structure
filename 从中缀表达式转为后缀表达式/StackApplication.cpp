/*
��׺���ʽ���ת��Ϊ��׺���ʽ:
	> ��ͷ��β��ȡ��׺���ʽ��ÿ�����󣬶Բ�ͬ���󰴲�ͬ���������
	�������� : ֱ�����;
	������:ѹ���ջ;
	��������:��ջ��������������������ֱ�����������ţ���ջ���������:
	�������:
	�������ȼ�����ջ�������ʱ�������ѹջ;
	�������ȼ�С�ڵ���ջ�������ʱ����ջ����������������; �ٱ�
	���µ�ջ���������ֱ�������������ջ����������ȼ�Ϊֹ��Ȼ
	�󽫸������ѹջ
	'(' �����ȼ����
	��������������ϣ���Ѷ�ջ�д����������һ�������
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

// Ϊ�շ��� 1  ��Ϊ�շ���0
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