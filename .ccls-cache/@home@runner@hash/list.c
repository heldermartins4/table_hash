#include "list.h"

// ---- Funções

Nodo *allocMemoryToNodo() { return (Nodo *)malloc(sizeof(Nodo)); }

List *allocMemoryToList() { return (List *)malloc(sizeof(List)); }

Nodo *createNodo(char data[]) {
  Nodo *nodo;
  int size;
  nodo = (Nodo *)malloc(sizeof(Nodo));
  if (nodo != NULL) {
    size = strlen(data);
    for (int i = 0; i < size; i++) {
      nodo->info[i] = data[i];
    }
    nodo->next = NULL;
    nodo->prev = NULL;
  }
  return nodo;
}

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

int insertElToList(List *list, Nodo *ref, char data[]) {
  Nodo *newEl;
  newEl = createNodo(data);

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
}

int removeElFromList(List *list, Nodo *el) {
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

void printInfo(char info[NAME_MAX]) {
  for (int i = 0; i < NAME_MAX; i++) {
    printf("#%d: %c\n", i, info[i]);
  }
}

void printList(List *list) {
  Nodo *nodo;
  if (listNull(list)) {
    printf("\nLista esta vazia!\n");
  } else {
    nodo = list->head;
    printf("\n<-- Lista -->\n");

    // for (int i = 0; i < list->size; i++)
    // {
    //     printf("%s\n", nodo->info);
    //     nodo = nodo->next;
    // }

    while (nodo != NULL) {
      printf("%s\n", nodo->info);
      nodo = nodo->next;
    }
  }
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
        // printf("ant: %c\t", nodo->prev->value);
        printInfo(nodo->prev->info);
      } else
        printf("ant: _\t");

      // printf("atual: %c\t", nodo->value);
      printInfo(nodo->info);

      if (nodo->next != NULL) {
        // printf("próx: %c\t", nodo->next->value);
        printInfo(nodo->next->info);
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

void freeList(List *queue) {
  Nodo *delNodo, *auxNodo;
  int i;
  delNodo = queue->head;
  for (i = 0; i < queue->size; i++) {
    auxNodo = delNodo->next;
    free(delNodo);
    delNodo = auxNodo;
  }
  free(queue);
}

void swapNodos(List *list, Nodo *nodo1, Nodo *nodo2) {
  Nodo *auxPrev, *auxNext;
  //  atribuição nos campos das listas
  if (nodo1 == list->head) {
    list->head = nodo2;
  } else if (nodo2 == list->head) {
    list->head = nodo1;
  }
  if (nodo1 == list->tail) {
    list->tail = nodo2;
  } else if (nodo2 == list->tail) {
    list->tail = nodo1;
  }

  //  troca dos elementos
  auxNext = nodo1->next;
  auxPrev = nodo1->prev;
  //  verificação do nodo2
  if (nodo2->next == nodo1) {
    nodo1->next = nodo2;
  } else {
    nodo1->next = nodo2->next;
    if (nodo2->next != NULL) {
      nodo2->next->prev = nodo1;
    }
  }
  if (nodo2->prev == nodo1) {
    nodo1->prev = nodo2;
  } else {
    nodo1->prev = nodo2->prev;
    if (nodo2->prev != NULL) {
      nodo2->prev->next = nodo1;
    }
  }

  //  verificação do nodo1
  if (auxNext == nodo2) {
    nodo2->next = nodo1;
  } else {
    nodo2->next = auxNext;
    if (auxNext != NULL) {
      auxNext->prev = nodo2;
    }
  }
  if (auxPrev == nodo2) {
    nodo2->prev = nodo1;
  } else {
    nodo2->prev = auxPrev;
    if (auxPrev != NULL) {
      auxPrev->next = nodo2;
    }
  }
}