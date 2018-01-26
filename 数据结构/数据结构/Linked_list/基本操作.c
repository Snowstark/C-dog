#include"_List_H.h"


//Return true if L is empty
ElemType ListEmpty(List L)
{
	return L->Next == NULL;
}


//Return true if P is the last position in last L
ElemType IsLast(Position P, List L)
{
	return P->Next == NULL;
}


//Return position if X in L, NULL for not found 
Position LocateElem(ElemType X, List L)   //更广泛的可以用compare匹配元素
{
	Position P;

	P = L->Next;

	while (P != NULL && P->Element != X)
	{
		P = P->Next;
	}
	if (NULL == P)
	{
		printf("Not found!\n");
	}

	return P;
}


//Delete first occurrence of X from a list
void Delete(ElemType X, List L)
{
	Position P, TmpCell;
	
	P = FindPrevious(X, L);

	if (!IsLast(P, L))//X is found in L and P->next->ElemType = X
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
		L->Element -= 1;
	}
	else
	{
		printf("Not found!\n");
	}
}


//Delete the i th element, return value of the i th element
ElemType ListDelete(List L, int i)
{
	Position P, TmpCall;
	ElemType Tmp;

	P = L;

	if (i > L->Element)
	{
		printf("Error!\n");
		return 0;
	}
	while (i > 1)
	{
		P = P->Next;
		i--;
	}
	TmpCall = P->Next;
	P->Next = P->Next->Next;
	Tmp = TmpCall->Element;
	free(TmpCall);
	
	return Tmp;
}


//Return position before X, or NULL for which X is not found in L. 
//X is not the first element.(In fact, it returns head node when X is the 
//first element)
Position PriorElem(ElemType X, List L)
{
	Position P;

	P = L->Next;

	while (P->Next != NULL && P->Next->Element != X)
	{
		P = P->Next;
	}
	
	return P;
}


//Return position after X, or NULL for which X is not found in L
//X is not the last element
Position NextElem(ElemType X, List L)
{
	Position P;

	P = L->Next;

	while (P->Next != NULL && P->Element != X)
	{
		P = P->Next;
	}
	if (NULL == P->Next)
	{
		prinf("Error! X is the last element!\n");
	}
	P = P->Next;

	return P;
}


//Insert X after P in L
void ListInsert(ElemType X, List L, int i)
{
	Position TmpCell, P;

	if (i > L->Element)
	{
		printf("Error!\n");
		return 0;
	}
	P = L;
	TmpCell = (Position)calloc(1, sizeof(struct Node));
	if (NULL == TmpCell)
	{
		printf("Error!\n");
		exit(1);
	}
	while (i > 1)
	{
		P = P->Next;
		i--;
	}
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
	L->Element += 1;
}


//make L clear, return a new head Node.(The address of L is changed.)
void DestoryList(List L)
{
	Position TmpCall;
	
	TmpCall = L;

	while (L->Next != NULL)
	{
		L = L->Next;
		free(TmpCall);
		TmpCall = L;
	}
	free(TmpCall);
}


//initlize the list, element means number of Node(except the first Node).
void InitList(List L)
{
	L->Next = NULL;
	L->Element = 0;
}


//Clear the list
void ClearList(List L)
{
	Position TmpCall;

	TmpCall = L;

	while (L->Next != NULL)
	{
		L = L->Next;
		free(TmpCall);
		TmpCall = L;
	}
	L->Element = 0;
}


//Ruturn the length of list
int ListLength(List L)
{
	return L->Element;
}


//Return the i th element
ElemType GetElem(List L, int i)
{
	Position P;

	P = L->Next;

	if (i > L->Element)
	{
		printf("Error!\n");
		return  0;
	}
	while (i > 1)
	{
		P = P->Next;
		i--;
	}
	return P->Element;
}