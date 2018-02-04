#include"_Tree_H.h"

//All over, nothing left.
SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}


//Return pointer to X, or return NULL when unfound.
Position Find(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}

	if (X < T->Element)
	{
		return Find(X, T->Left);
	}
	else if (X > T->Element)
	{
		return Find(X, T->Right);
	}
	else
	{
		return T;
	}
}


//Return pointer to minimum of the tree, or return NULL when tree unfound.£¨recursion)
Position FindMin(SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else
	{
		if (T->Left == NULL)
		{
			return T;
		}
		else
		{
			return FindMin(T->Left);
		}
	}
}


//Return pointer to maxmium of the tree, or return NULL when tree unfound.(without recursion)
Position FindMax(SearchTree T)
{
	if (T != NULL)
	{
		while (T->Right != NULL)
		{
			T = T->Right;
		}
	}

	return T;
}


//Insert Element
SearchTree Insert(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		T = (SearchTree)calloc(1, sizeof(struct TreeNode));
		if (T == NULL)
		{
			printf("Error, out of space.\n");
		}
		else
		{
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else if (X > T->Element)
	{
		T->Right = Insert(X, T->Right);//change to "Insert(X, T->Right)"?
	}
	else if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);
	}

	return T;
}


//Delete Element
SearchTree Delete(ElementType X, SearchTree T)
{
	Position TmpCell;

	if (T == NULL)
	{
		printf("Element not found.\n");
	}
	else if (X < T->Element)
	{
		T->Left = Delete(X, T->Left);
	}
	else if (X > T->Element)
	{
		T->Right = Delete(X, T->Right);
	}
	else if (T->Left&&T->Right)
	{
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else
	{
		TmpCell = T;
		if (T->Left == NULL)
		{
			T = T->Right;
		}
		else if (T->Right == NULL)
		{
			T = T->Left;
		}
		free(TmpCell);
	}

	return T;
}