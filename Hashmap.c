#include "md5.c"
#include "LinkedList.c"
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define maxOfType(x) 1 << ((sizeof(x) << 3) - 1)

typedef struct Hashmap Hashmap;

struct Hashmap{
	DataType keyType;
	DataType valueType;
	Node* arr[];
};


uint32_t Hash(const char str[]){
	MD5_CTX md5;
	MD5_Init(&md5);
	MD5_Update(&md5, str, 4);

	unsigned char* digest;
	MD5_Final(digest, &md5);
	uint32_t result = digest[0] + (digest[1] << 8) + (digest[2] << 16) + (digest[3] << 24);
	return result;
}

Hashmap* NewHashmap(DataType keyType, DataType valueType){
	uint32_t mapSize = maxOfType(uint32_t);
	mapSize = 4;
	Hashmap* hashmap = malloc(sizeof(Hashmap*) + sizeof(Node*[4]));
	hashmap->keyType = keyType;
	hashmap->valueType = valueType;
	return hashmap;
}

void Post(Hashmap* hashmap, void* key, void* value){
	uint32_t index = Hash(key);
	Node* node = NewNodeEx(hashmap->keyType, value, NULL);
	hashmap->arr[index] = node;
}

void* Lookup(Hashmap* hashmap, void* key){
	uint32_t index = Hash(key);
	return hashmap->arr[index];
}

__attribute__((always_inline))void freeHashmap(Hashmap* hashmap){
	free(hashmap);
}


int main(int argc, char* argv[]){
	int a = 6;
	int* ptr1 = &a;

	int b = 1;
	int* ptr2 = &b;

	Hashmap* hashmap = NewHashmap(INT, INT);
	Post(hashmap, &a, &b);
	freeHashmap(hashmap);
	return 0;
}