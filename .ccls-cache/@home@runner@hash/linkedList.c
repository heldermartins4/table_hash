#include "list.h"

// ---- Funções

Nodo *allocMemoryToNodo() { return (Nodo *)malloc(sizeof(Nodo)); }

List *allocMemoryToList() { return (List *)malloc(sizeof(List)); }

Nodo *createNodo(char value) {
  Nodo *nodo = allocMemoryToNodo();
  if (nodo != NULL) {
    nodo->value = 'A';
    if (sizeof(nodo->value) > 0) {
      nodo->value = value;
    } else {
      free(nodo);
      nodo = NULL;
    }
  }
  return nodo;
}

// char delimitador = {{'(', ')'}}; // 0: () 1: [] 2: {}

List *createList() {
  List *list;
  list = allocMemoryToList();
  if (list != NULL) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
  }
  return list;
}

void handleErrorToInsert(int error) {
  if (error == -1)
    printf("\nErro: ponteiro incorreto ou indefinido.\n");
  else if (error == -2)
    printf("\nErro: Limite excedido.\n");
  // else
  //   printf("Operação realizada com êxito.");
}

void handleErrorToRemove(int error) {
  if (error == -1)
    printf("\nErro: Lista vazia.\n");
  else if (error == -2)
    printf("\nErro: Elemento inexistente.\n");
  // else
  //   printf("Operação realizada com êxito.");
}

int listNull(List *list) {
  if (list->size == 0)
    return 1;
  return 0;
}

int insertElToList(List *list, Nodo *ref, char value) {
  Nodo *newEl;
  newEl = createNodo(value);

  // LIsta Simples
  if (ref == NULL && !listNull(list))
    return -1;

  if (listNull(list)) {
    list->head = newEl;
    list->tail = newEl;
  } else {
    newEl->next = ref->next;
    newEl->prev = ref;
    if (ref->next == NULL)
      list->tail = newEl;
    else
      ref->next->prev = newEl;

    ref->next = newEl;
  }
  list->size++;
  return 0;
  // if (ref == NULL && !listNull(list))
  //   return -1;

  // if (listNull(list)) {
  //   list->head = newEl;
  //   list->tail = newEl;
  // } else {
  //   // isHead
  //   if (ref->prev == NULL) {
  //     newEl->next = list->head;
  //     newEl->prev = newEl->next->prev;
  //     list->head = newEl;
  //     list->head->next->prev = newEl;
  //     printf("is head.");
  //   } else {
  //     newEl->next = ref->next;
  //     newEl->prev = ref;
  //     if (ref->next == NULL)
  //       list->tail = newEl;
  //     else
  //       ref->next->prev = newEl;

  //     ref->next = newEl;
  //     printf("is tail.");
  //   }
  // }
  list->size++;
  return 0;
}

int removeElFromList(Nodo *el, List *list) {
  if (listNull(list))
    return -1;

  if ((el != NULL) && (!listNull(list))) {
    if (el == list->head) {
      list->head = el->next;
      if (list->head == NULL)
        list->tail = NULL;
      else
        el->next->prev = NULL;
    } else {
      el->prev->next = el->next;
      if (el->next == NULL) {
        list->tail = el->prev;
      } else {
        el->next->prev = el->prev;
      }
    }
    free(el);
    list->size--;
  }
  return 0;
}

void write(List *list) {
  Nodo *nodo;

  if (listNull(list)) {
    printf("\nErro: lista está vazia(o).\n");
  } else {
    printf("\nLista:\n\n");
    nodo = list->head;

    while (nodo != NULL) {
      if (nodo->prev != NULL) {
        printf("ant: %c\t", nodo->prev->value);
      } else
        printf("ant: _\t");

      printf("atual: %c\t", nodo->value);

      if (nodo->next != NULL) {
        printf("próx: %c\t", nodo->next->value);
      } else
        printf("próx: _\t");

      nodo = nodo->next;
      printf("\n==============================================\n");
    }
    printf("\nTotal: %i\n\n", list->size);
  }
}

void destroyList(List *list) {
  Nodo *current = list->head;

  while (current != NULL) {
    Nodo *next = current->next;
    // free(current->value);
    free(current);
    current = next;
  }
  free(list);
}

Nodo *getNodo(List *list, char value) {
  Nodo *nodo;

  if (!listNull(list)) {
    nodo = list->head;
    while (nodo != NULL) {
      if (nodo->value == value) {
        return nodo;
      }
      nodo = nodo->next;
    }
  }
  return nodo;
}

void search(List *list, List *waitList, char value) {
  Nodo *nodo;
  nodo = getNodo(list, value);

  if (nodo != NULL) {
    printf("\nElemento encontrado!\n");
    printf("Valor: %c\n", nodo->value);
  } else {
    printf("Elemento não encontrada.\n");
  }
}