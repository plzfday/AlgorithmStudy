// for commit
#include "LinkedList.h"

Node* SLL_CreatNode(int NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

void SLL_DestroyNode(Node* Node)
{
	free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
	// Çìµå ³ëµå°¡ NULLÀÌ¶ó¸é »õ·Î¿î ³ëµå°¡ Head
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;
	
	while(Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

/* 노드 제거 */
void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
	}
	else
	{
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		if (Current != NULL)
			Current->NextNode = Remove->NextNode;
	}
}

/* 노드 삽입 */
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead)
{
	Node* follow = (*Head);
	while (follow->NextNode != Current)
	{
		follow = follow->NextNode;
	}
	
	follow->NextNode = NewHead;
	NewHead->NextNode = Current;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
	if (*Head == NULL)
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

int SLL_GetNodeCount(Node* Head)
{
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}


void SLL_DestroyAllNodes(Node ** List)
{
	int Count = 0;
	Count = SLL_GetNodeCount(List);
	for (int i = 0; i < Count; i++)
	{
		Node* Current = SLL_GetNodeAt(List, i);

		if (Current != NULL)
		{
			SLL_RemoveNode(&List, Current);
			SLL_DestroyNode(Current);
		}
	}
}