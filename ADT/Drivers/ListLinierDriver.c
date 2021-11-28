/* Driver for ListLinier */

#include <stdio.h>
#include <stdlib.h>
#include "../Skill/ListLinier.h"


int main(){
    List L;
    address p, q, r;
    infotype a, b;

    // CreatEmpty Test
    printf("\nCREATE EMPTY TEST\n");
    CreateEmpty(&L);
    if (IsEmpty(L)) {
        printf("List L berhasil dibuat, dan L kosong\n");
    }
    printf("\n");

    // Alokasi-Dealokasi Test
    printf("ALOC-DEALOC TEST\n");
    p = Alokasi(20);
    printf("Alokasi p berhasil, p = %d\n", Info(p));
    Dealokasi(&p);
    printf("P sudah didealokasi, p = %d\n", Info(p));
    printf("\n");
    
    // Search Test
    printf("SEARCH TEST\n");
    InsVFirst(&L, 10);
    p = Search(L, 10);
    q = Search(L, 5);
    printf("Nilai ditemukan, nilai yang dicari = %d\n", Info(p));
    if (q == Nil) {
        printf("Nilai tidak ditemukan, nilai yang dicari = %d\n", 5);
    }
    printf("\n");
    
    // Insert-Print Test
    printf("INSERT TEST\n");
    InsVLast(&L, 20);
    InsVFirst(&L, 5);
    InsVFirst(&L, 4);
    InsVFirst(&L, 3);
    InsVFirst(&L, 2);
    InsVFirst(&L, 1);
    p = Alokasi(999);
    r = Search(L, 3);
    InsertAfter(&L, p, r);
    PrintInfo(L); printf("\n");
    printf("\n");

    // Delete-Print Test
    printf("DELETE TEST\n");
    DelVFirst(&L, &a);
    DelVLast(&L, &b);
    printf("%d\n", a);
    printf("%d\n", b);
    DelP(&L, 2);
    DelAfter(&L, &p, r);
    PrintInfo(L); printf("\n");
    printf("\n");

    return 0;
}