#pragma once
#ifndef _List_H

#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef int ElemType;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
Position Find(ElemType X, List L);
void Delete(ElemType X, List L);
Position FindPrevious(ElemType X, List L);
void Insert(ElemType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(List L);
ElemType Retrieve(Position P);

#endif // !_List_H


struct Node
{
	ElemType Element;
	Position Next;
};