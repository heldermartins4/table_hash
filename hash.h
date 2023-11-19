#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quick.h"

#define HASH_SIZE 53
#define MAX_STRING_SIZE 20

typedef struct {
  struct list *col[HASH_SIZE];
} HashTable;

HashTable *iniciateHash();

int stringToAscii(char data[MAX_STRING_SIZE]);

int getSeachInfoPos(List *list, char data[]);

int hashFunction(char data[MAX_STRING_SIZE]);

//  inserção

void hashInsert(char data[MAX_STRING_SIZE], HashTable *hashTable);

//  consulta

void hashSearch(char data[MAX_STRING_SIZE], HashTable *hashTable);

//  quantidade de elementos por chave
void getAllElements(HashTable *hashTable);

// quantidade de elementos na chave
void getElementsInCol(HashTable *hashTable, int col);

Nodo *searchInfo(List *list, char data[]);

//  remoção
void hashRemove(char data[MAX_STRING_SIZE], HashTable *hashTable);

void freeHash(HashTable *hTable);