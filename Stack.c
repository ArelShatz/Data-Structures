//standard library
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.c"

//type definitions
typedef struct Stack Stack;

struct Stack{
	DataType type;
	Node* top;
};


//stack functions
Stack* NewStack(DataType type){
	Stack* stack = malloc(sizeof(Node*) + sizeof(type));
	stack->type = type;
	stack->top = NULL;
	return stack;
}

void Push(Stack* stack, void* value){
	Node* node = NewNodeEx(stack->type, value, stack->top);
	stack->top = node;
}

bool IsEmpty(Stack* stack){
	return stack->top == NULL;
}

//Popping when stack is empty will result in undefined behavior
void* Pop(Stack* stack){
	if (IsEmpty(stack)){
		return NULL;
	}

	Node* top = stack->top;
	void* value = GetValue(top);
	stack->top = GetNext(top);
	FreeNode(top);
	return value;
}

//Topping when stack is empty will result in undefined behavior
void* Top(Stack* stack){
	if (IsEmpty(stack)){
		return NULL;
	}

	return GetValue(stack->top);
}


void PrintStack(Stack* stack){
	Node* top = stack->top;
	while (top != NULL){
		void* value = GetValue(top);
		printf("|           |\n|     %d     |\n|           |\n", *(int*)value);
		top = GetNext(top);
	}
	printf(" -----------\n\n");
}


__attribute__((always_inline))void FreeStack(Stack* stack){
	free(stack);
}

#ifndef MAIN
#define MAIN
int main(int argc, char* argv[]){
	return 0;
}
#endif