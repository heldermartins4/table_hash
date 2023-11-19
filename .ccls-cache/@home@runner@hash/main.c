#include "hash.h"

// -----------------------------------------------------------------------

int main() {
  FILE *fptr;
  fptr = fopen("./data/nomes.txt", "r");
  char line[MAX_STRING_SIZE];
  HashTable *hTable;
  hTable = iniciateHash();

  while (fgets(line, MAX_STRING_SIZE, fptr)) {
    hashInsert(line, hTable);
  }

  getAllElements(hTable);
  // getElementsInCol(hTable, 47);
  // printList(hTable->col[46]);

  fclose(fptr);
  freeHash(hTable);
  return 0;
}