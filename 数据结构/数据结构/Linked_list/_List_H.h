//The defination of LIST, element of head node is the number of valid nodes.
#ifndef _List_H

#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef int ElemType;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitList(List L);
void DestoryList(List L);
void ClearList(List L);
ElemType ListEmpty(List L);
int ListLength(List L);
ElemType GetElem(List L, int i);
void Delete(ElemType X, List L);
Position LocateElem(ElemType X, List L);
Position PriorElem(ElemType X, List L);
Position NextElem(ElemType X, List L);
void ListInsert(ElemType X, List L, int i);
ElemType ListDelete(List L, int i);

#endif // !_List_H


struct Node
{
	ElemType Element;
	Position Next;
};