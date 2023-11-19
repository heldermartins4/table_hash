#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---- Constants
#define NAME_MAX 20

// ---- Struct

typedef struct nodo {
  char info[NAME_MAX];
  struct nodo *prev;
  struct nodo *next;
} Nodo;

typedef struct list {
  int size;
  struct nodo *head;
  struct nodo *tail;
} List;

// ---- Prototype
Nodo *allocMemoryToNodo();

List *allocMemoryToList();

Nodo *createNode(char data[]);

List *createList();

void handleErrorToInsert(int error);

void handleErrorToRemove(int error);

int listNull(List *list);

int insertElToList(List *list, Nodo *ref, char data[]);

int removeElFromList(List *list, Nodo *el);

void printInfo(char info[NAME_MAX]);

void printList(List *list);

void write(List *list);

void destroyList(List *list);

void freeList(List *queue);

void swapNodos(List *list, Nodo *nodo1, Nodo *nodo2);