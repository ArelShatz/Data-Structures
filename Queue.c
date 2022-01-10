//standard library
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.c"

//type definitions
typedef struct Queue Queue;

struct Queue{
	DataType type;
	Node* head;
	Node* back;
};


Queue* NewQueue(DataType type){
	Queue* queue = malloc(sizeof(Queue));
	queue->type = type;
	queue->head = NULL;
	return queue;
}

void Insert(Queue* queue, void* value){
	
}

int main(int argc, char* argv[]){
	Queue* queue = NewQueue(INT);
	return 0;
}