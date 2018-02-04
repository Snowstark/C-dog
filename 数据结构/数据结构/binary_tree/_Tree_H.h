#ifndef _Tree_H

#include<stdio.h>
#include<stdlib.h>

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;
typedef int ElementType;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMax(SearchTree T);
Position FindMin(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);

#endif // !_Tree_H

struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};