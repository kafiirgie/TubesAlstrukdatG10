#include "mesin_kata.h"
#include <stdio.h>

void printKata(Kata kata);

int main() {
  STARTKATA("config.txt");
  while (!EndKata) {
    printKata(CKata);
    ADVKATA();
  }
  return 0;
}

void printKata(Kata kata){
  for(int i = 0; i <= kata.Length; i++){
    printf("%c", kata.TabKata[i]);
  }
  printf("\n");
}