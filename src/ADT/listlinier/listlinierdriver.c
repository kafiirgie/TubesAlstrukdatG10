#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"


int main(){
    /* KAMUS */
    List L;
    address p, q, r;
    infotype a, b;

    /* ALGORITMA */
    /* CreatEmpty Test */
    printf("CREATE EMPTY TEST\n");
    CreateEmpty(&L);
    if (IsEmpty(L)) {
        printf("List L berhasil dibuat\n");
    }
    printf("\n");

    /* Alokasi-Dealokasi Test */
    printf("ALOC-DEALOC TEST\n");
    p = Alokasi(20);
    printf("Alokasi p berhasil, p = %d\n", Info(p));
    Dealokasi(p);
    printf("\n");
    
    /* Search Test */
    printf("SEARCH TEST\n");
    InsVFirst(&L, 10);
    p = Search(L, 10);
    q = Search(L, 5);
    printf("Nilai ditemukan, nilai yang dicari = %d\n", Info(p));
    if (q == Nil) {
        printf("Nilai tidak ditemukan\n");
    }
    printf("\n");
    
    /* Insert-Print Test */
    printf("INSERT TEST\n");
    InsVLast(&L, 20);
    InsVFirst(&L, 5);
    InsVFirst(&L, 4);
    InsVFirst(&L, 3);
    InsVFirst(&L, 2);
    InsVFirst(&L, 1);
    p = Alokasi(999);
    q = Alokasi(990);
    r = Search(L, 3);
    InsertBefore(&L, p, r);
    InsertAfter(&L, q, r);
    PrintForward(L); printf("\n");
    PrintBackward(L);
    printf("\n");

    /* Delete-Print Test */
    printf("DELETE TEST\n");
    DelVLast(&L, &b);
    DelVFirst(&L, &a);
    printf("%d\n", a);
    printf("%d\n", b);
    DelP(&L, 2);
    DelBefore(&L, &p, r);
    DelAfter(&L, &q, r);
    PrintForward(L); printf("\n");
    PrintBackward(L);
    printf("\n");

    return 0;
}