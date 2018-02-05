#include"_AvlTree_H.h"


//Return height of P.
static int Height(Position P)
{
	if (P == NULL)
	{
		return -1;
	}
	else
	{
		return P->Height;
	}
}


//Insert an element, keep the tree balance.
AvlTree Insert(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		T = (AvlTree)calloc(1, sizeof(struct AvlNode));
		if (T == NULL)
		{
			printf("Out of space.\n");
		}
		else
		{
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element)
	{

		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
		{
			if (X < T->Left->Element)
			{
				T = SingleRotateWithLeft(T);
			}
			else
			{
				T = DoubleRoateWithLeft(T);
			}
		}
	}
	else if (X > T->Element)
	{
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (X < T->Right->Element)
			{
				T = SingleRotateWithLeft(T);
			}
			else
			{
				T = DoubleRoateWithLeft(T);
			}
		}
	}

	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}


//Text to be finished.
static Position SingleRotateWithLeft(Position K2)
{
	Position K1; 
	
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), K2->Height) + 1;

	return K1;
}


//Text to be finished.(Just double SingleRotateWithLeft)
static Position DoubleRotateWithLeft(Position K3)
{
	K3->Left = SingleRotateWithLeft(K3->Left);
	
	return SingleRotateWithLeft(K3);
}