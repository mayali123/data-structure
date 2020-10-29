#include"struct.h"

void trans(char* exp, char* postexp)
{
	ST* p = InitStack();
	int k = 0;
	char e;
	for (int i = 0; exp[i] != '\0';)
	{
		switch (exp[i])
		{
		case '(':
			Push(p, exp[i]);
			i++;
			break;
		case ')':
			while (1)
			{
				Pop(p, &e);
				if (e == '(')
					break;
				postexp[k++] = e;
			}
			i++;
			break;
		case '+':
		case '-':
			while (!StackEmpty(p))
			{
				GetTop(p, &e);
				if (e != '(')
				{
					Pop(p, &e);
					postexp[k++] = e;
				}
				else
					break;
			}
			Push(p, exp[i]);
			i++;
			break;
		case '*':
		case '/':
			while (!StackEmpty(p))
			{
				GetTop(p, &e);
				if (e == '(' || e == '+' || e == '-')
					break;
				Pop(p, &e);
				postexp[k++] = e;
			}
			Push(p, exp[i]);
			i++;
			break;
		default:
			while ('0' <= exp[i] && exp[i] <= '9')
			{
				postexp[k++] = exp[i];
				i++;
			}
			postexp[k++] = ' ';
		}
	}
	while (!StackEmpty(p))
	{
		Pop(p, &e);
		postexp[k++] = e;
	}
	postexp[k++] = '\0';
}

void comp(const char* exp, int* result)
{
	ST* p = InitStack();
	int num1, num2, e;
	int i = 0, a;
	for (; exp[i] != '\0'; i++)
	{
		switch (exp[i])
		{
		case '+':
			Pop_num(p, &num1);
			Pop_num(p, &num2);
			Push_num(p, num1 + num2);
			break;
		case '-':
			Pop_num(p, &num1);
			Pop_num(p, &num2);
			Push_num(p, num2 - num1);
			break;
		case '*':
			Pop_num(p, &num1);
			Pop_num(p, &num2);
			Push_num(p, num2 * num1);
			break;
		case '/':
			Pop_num(p, &num1);
			Pop_num(p, &num2);
			Push_num(p, num2 / num1);
			break;
		default:
			a = 0;
			while ('0' <= exp[i] && exp[i] <= '9')
			{
				a = a * 10 + exp[i] - '0';
				i++;
			}
			Push_num(p, a);
		}
	}
	Pop_num(p, &e);
	*result = e;
	DestroyStack(p);
}

int main()
{
	int a;
	char ch[MAXSIZE],ch2[MAXSIZE];
	printf("请输入一个计算式：");
	scanf("%s",ch);
	trans(ch, ch2);
	comp(ch2,&a);
	printf("%s=%d",ch,a);
	return 0;
	// 18 2 +3 *
}