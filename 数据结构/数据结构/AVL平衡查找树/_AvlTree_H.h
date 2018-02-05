#ifndef _AvlTree_H

#include<stdio.h>
#include<stdlib.h>

struct AvlNode;
typedef int ElementType;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FinfMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
static int Height(Position P);
static Position SingleRotateWithLeft(Position K2);
static Position DoubleRoateWithLeft(Position K3);

#endif // !_AvlTree_H

struct AvlNode
{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};
