#include "LinkedList.h"
#include "LinkedList.h"


int main(int argc, char* argv[]){
	int a = 4;
	Node* node = NewNodeEx(INT, &a, NULL);
	PrintNodeEx(node);
	FreeNode(node);
	return 0;
}