#include"_List_H.h"

typedef List Stack;
int num = 0;

char Pop(Stack S)
{
	Position P, TmpCall;
	ElemType Ans;

	P = S;
	if (S->Next == NULL)
	{
		return '#';
	}
	while (P->Next->Next != NULL)
	{
		P = P->Next;
	}
	Ans = P->Next->Element;
	TmpCall = P->Next;
	P->Next = NULL;
	free(TmpCall);
	num -= 1;
	return Ans;
}

void Push(Stack S, ElemType X)
{
	Position TmpCell, P;

	P = S;
	TmpCell = (Position)calloc(1, sizeof(struct Node));
	if (NULL == TmpCell)
	{
		printf("Error!\n");
		exit(1);
	}
	while (P->Next != NULL)
	{
		P = P->Next;
	}
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
	num += 1;
}

int Prior(char ch)//定义字符优先级
{
	int priorCh;

	switch (ch)
	{
	case '+':
		priorCh = 1;
		break;
	case '*':
		priorCh = 2;
		break;
	case '(':
	case ')':
		priorCh = 3;
		break;
	case '#':
		priorCh = 0;
		break;
	default:
		printf("Error input!\n");
		break;
	}

	return priorCh;
}

int Compare(Stack S, char ch)//若新字符优先级高于栈顶字符，返回1，否则返回0
{
	int prch, prpop;//存储优先级
	char chpop;//存储栈顶值

	if (S->Next == NULL)
	{
		chpop = '#';
	}
	else
	{
		chpop = Pop(S);
		Push(S, chpop);
		if (chpop == '(')
		{
			return 1;
		}
	}

	prch = Prior(ch);//分别计算字符优先级
	prpop = Prior(chpop);
	
	if (prch > prpop)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Decide(Stack S, char ch)
{
	if (ch == '(')
	{
		Push(S, ch);
	}
	else if (ch == ')')
	{
		ch = Pop(S);
		while (ch != '(')
		{
			printf("%c ", ch);
			ch = Pop(S);
		}
	}
	else
	{
		while (!Compare(S, ch))
		{
			char Tmp = Pop(S);
			printf("%c ", Tmp);
		}
		Push(S, ch);
	}
}

int NotOper(char ch)
{
	return (ch >= '0'&& ch <= '9')||(ch >= 'a'&&ch <= 'z');
}

int main()
{
	List S;
	S = (List)calloc(1, sizeof(struct Node));
	if (NULL == S)
	{
		printf("Error!\n");
		exit(1);
	}
	char ch;
	InitList(S);

	ch = getchar();
	while (ch != '#')
	{
		if (NotOper(ch))
		{
			printf("%c ", ch);
		}
		else
		{
			Decide(S, ch);
		}

		ch = getchar();
	}
	while (num > 0)
	{
		ch = Pop(S);
		printf("%c ", ch);
	}
	getchar();
	getchar();
	return 0;
}
