#include "quick.h"
#include <stdio.h>

Nodo *getPivo(List *list, Nodo *init, Nodo *final) {
  Nodo *i, *j;
  i = init;
  j = final;

  while (i != j || i != j->next) {
    i = i->next;
    j = j->prev;
  }
  return i;
}

int isSmaller(Nodo *small, Nodo *big) {
  printf("\nsmall->%s\nbig->%s\n", small->info, big->info);
  int res1 = strcmp(small->info, big->info);

  if (res1 < 0) {
    return 1;
  }
  if (res1 > 0) {
    return 2;
  }
  return 0;
}

int getPos(List *list, Nodo *nodo) {
  Nodo *auxNodo;
  int pos;
  auxNodo = list->head;
  pos = 0;
  if (nodo == NULL) {
    return -1;
  }
  while (auxNodo != nodo) {
    pos++;
    auxNodo = auxNodo->next;
  }
  return pos;
}

Nodo *getPivoByPos(Nodo *i, Nodo *f) {
  Nodo *init, *final;
  init = i;
  final = f;
  while ((init != final) && (init != final->next)) {
    init = init->next;
    final = final->prev;
  }
  return init;
}

Nodo *getNodoByPos(List *list, int pos) {
  Nodo *nodo;
  int count;
  nodo = list->head;
  count = 0;
  while (count < pos) {
    count++;
    nodo = nodo->next;
  }
  return nodo;
}

List *quickSort(List *list, int initNodo, int finalNodo) {
  Nodo *i, *j, *pivo, *aux;
  int iCont, jCont;

  i = getNodoByPos(list, initNodo);
  j = getNodoByPos(list, finalNodo);
  pivo = getPivoByPos(i, j);
  printf("\npivo -> %s", pivo->info);
  printf("\ninicial -> %i\nfinal -> %i\n", initNodo, finalNodo);
  while (getPos(list, i) <= getPos(list, j)) {
    while (isSmaller(i, pivo) == 1) {
      i = i->next;
    }
    while (isSmaller(j, pivo) == 2) {
      j = j->prev;
    }
    if (getPos(list, i) <= getPos(list, j)) {
      printf("\nantes\ni -> %s\nj -> %s\n", i->info, j->info);
      swapNodos(list, i, j);
      aux = i;
      i = j;
      j = aux;
      i = i->next;
      j = j->prev;
      printf("\ndepois\ni -> %s\nj -> %s\n", i->info, j->info);
    }
    printf("-------------------------------------------------------------------"
           "----------------------");
    printList(list);
  }
  if (getPos(list, getNodoByPos(list, initNodo)) < getPos(list, j)) {
    quickSort(list, initNodo, getPos(list, j));
  }
  if (getPos(list, i) < getPos(list, getNodoByPos(list, finalNodo))) {
    quickSort(list, getPos(list, i), finalNodo);
  }
}