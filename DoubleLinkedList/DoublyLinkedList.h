﻿#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
} Node;

/* 함수 원형 선언(Function prototype) */
Node* DLL_CreateNode(ElementType NewData);
void DLL_DestroyNode(Node* Node);
void DLL_AppendNode(Node** Head, Node* NewNode);
void DLL_RemoveNode(Node** Head, Node* Remove);
void DLL_InsertAfter(Node* Current, Node* NewNode);
Node* DLL_GetNodeAt(Node* Head, int Location);
int DLL_GetNodeCount(Node* Head);

#endif // !DOUBLY_LINKEDLIST_H
