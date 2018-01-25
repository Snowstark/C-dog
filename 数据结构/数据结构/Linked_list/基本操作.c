#include"_List_H.h"


//Return true if L is empty
int IsEmpty(List L)
{
	return L->Next == NULL;
}


//Return true if P is the last position in last L
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}


//Return position if X in L; NULL for not found
Position Find(ElemType X, List L)
{
	Position P;

	P = L->Next;
	while (P != NULL && P->Element != X)
	{
		P = P->Next;
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
	}
	else
	{
		printf("Not found!\n");
	}
}


//Return position before X, or NULL for  X is not found in L
Position FindPrevious(ElemType X, List L)
{
	Position P;

	P = L->Next;

	while (P->Next != NULL && P->Next->Element != X)
	{
		P = P->Next;
	}
	
	return P;
}


//Insert X after P in L
void Insert(ElemType X, List L, Position P)
{
	Position TmpCell;

	TmpCell = (Position)calloc(1, sizeof(struct Node));
	if (NULL == TmpCell)
	{
		printf("Error!\n");
		exit(1);
	}

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}


//make L clear, return a new head Node.(The address of L is changed.)
List DeleteList(List L)
{
	Position TmpCell;

	while (L->Next != NULL)
	{
		TmpCell = L;
		L = L->Next;
		free(TmpCell);
	}
	return L;
}