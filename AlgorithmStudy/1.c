#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int Data;
	struct tagNode* NextNode;
} Node;

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
	// ��� ��尡 NULL�̶�� ���ο� ��尡 Head
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		// ������ ã�� NewNode�� �����Ѵ�
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
	
	whlie(Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

int main()
{
	printf("%d\n", sizeof(Node));
	printf("%d\n", sizeof(Node*));

	return 0;
}
