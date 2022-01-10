#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdbool.h>
#include <stddef.h>
#define NODE_SIZE sizeof(Node)


typedef	enum{
	INT,
	CHAR,
	BOOL,
	UINT8,
} DataType;

typedef struct Node Node;


void SetValue(Node* node, void* value);
void SetNext(Node* node, Node* next);
void* GetValue(Node* node);
Node* GetNext(Node* node);
bool HasNext(Node* node);
Node* NewNode(DataType type);
Node* NewNodeEx(DataType type, void* value, Node* next);
void FreeNode(Node* node);
void PrintNode(Node* node);
void PrintNodeEx(Node* node);

#endif