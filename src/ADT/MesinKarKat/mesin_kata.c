#include <stdio.h>
#include "mesin_kata.h"
#include "boolean.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank(){
    while (CC == BLANK && CC != MARK){
        ADV();
    }
}


void SalinKata() {
    int i = 1;
    for (i = 1;(CC != BLANK) && (CC != MARK) && (i <= NMax);i++){
        CKata.TabKata[i] = CC ;
        ADV() ;
    }
    CKata.Length = i - 1;
}

void STARTKATA() {
    START();
    IgnoreBlank();
    EndKata = (CC==MARK);
    if (EndKata == TRUE) {
        ADVKATA();
    }
}

void ADVKATA() {
    IgnoreBlank();
    if (CC==MARK && !EndKata) {
        EndKata = TRUE;
    } else {
        SalinKata();
    }
}