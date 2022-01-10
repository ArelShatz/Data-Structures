//standard library
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"

typedef struct DoubleNode DoubleNode;

struct DoubleNode{
	DataType type;
	void* value;
	Node* next;
	Node* previous;
};

//double node functions
void SetPrevious(Node* node, Node* previous){
	node->previous = previous;
}

Node* GetPrevious(Node* node){
	return node->previous;
}

Node* NewDNode(DataType type){
	size_t size;
	switch (type){
		case INT:
			size = sizeof(int);
			break;

		case CHAR:
			size = sizeof(int);
			break; 
	}

	Node* node = malloc(size + sizeof(Node*) + sizeof(DataType));
	node->type = type;
	node->next = NULL;
	node->previous = NULL;
	return node;
}

Node* NewDNodeEx(DataType type, void* value, Node* next, Node* previous){
	size_t size;
	switch (type){
		case INT:
			size = sizeof(int);
			break;

		case CHAR:
			size = sizeof(char);
			break; 
	}

	Node* node = malloc(size + sizeof(Node*) + sizeof(DataType));
	node->type = type;
	SetValue(node, value);
	node->next = next;
	node->previous = previous;
	return node;
}

__attribute__((always_inline))void FreeNode(Node* node){
	free(node);
}

void PrintNode(Node* node){
	void* value;
	int digits;

	while (node != NULL){
		switch (node->type){
			case INT:
				value = GetValue(node);
				digits = GetDigits(*(int*)value);
				break;

			case CHAR:
				value = GetValue(node);
				digits = 1;
				break;
		}

		switch (node->type){
			case INT:
				printf("%d", *(int*)value);
				break;

			case CHAR:
				printf("%c", *(char*)value);
				break;
		}

		if (HasNext(node)){
			printf(" --> ");
		}

		node = GetNext(node);
	}
	printf("\n");
}

void PrintNodeEx(Node* node){
	void* value;
	int digits;
	//int numOfUnder;
	//const char underDefault[] = " -----------";
	//const char spaceDefault[] = "           ";

	while (node != NULL){
		switch (node->type){
			case INT:
				value = GetValue(node);
				digits = GetDigits(*(int*)value);
				break;

			case CHAR:
				value = GetValue(node);
				digits = 1;
				break;
		}

		//char underAdd[] = "-";
		//strmul(underAdd, digits);
		//strcat(underDefault, underAdd);

		//char spaceAdd[] = " ";
		//strmul(spaceAdd, digits);
		//strcat(spaceDefault, spaceAdd);

		//printf("%s%s\n|%s%s|\n|     %d     |\n|%s%s|\n%s%s\n", underDefault, underAdd, spaceDefault, spaceAdd, value, spaceDefault, spaceAdd, underDefault, underAdd);
		switch (node->type){
			case INT:
				printf(" -----------\n|           |\n|     %d     |\n|           |\n -----------\n", *(int*)value);
				break;

			case CHAR:
				printf(" -----------\n|           |\n|     %c     |\n|           |\n -----------\n", *(char*)value);
				break;
		}

		if (HasNext(node)){
			printf("      |\n      |\n      V\n");
		}

		node = GetNext(node);
	}
	printf("\n");
}