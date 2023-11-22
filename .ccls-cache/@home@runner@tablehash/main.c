#include "hash.h"

// -----------------------------------------------------------------------

int main() {
  FILE *file;
  file = fopen("./data/nomes.txt", "r");
  char line[MAX_STRING_SIZE];
  HashTable *hTable;
  hTable = iniciateHash();

  while (fgets(line, MAX_STRING_SIZE, file)) {
    hashInsert(line, hTable);
  }

  getAllElements(hTable);

  fclose(file);
  freeHash(hTable);
}