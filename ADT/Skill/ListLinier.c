#include <stdio.h>
#include <stdlib.h>
#include "ListLinier.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
/* Mengirim true jika list kosong */
    /* KAMUS */
    /* ALGORITMA */
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    /* KAMUS */
    /* ALGORTIMA */
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    /* KAMUS */
    address P;
    /* ALGORITMA */
    P = (ElmtList *) malloc(sizeof(ElmtList));
    if (P!= Nil) {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    } else {
        return Nil;
    }
}

void Dealokasi (address *P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    /* KAMUS */
    /* ALGORITMA */
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    /* KAMUS */
    address P;
    boolean found;
    /* ALGORITMA */
    P = First(L);
    found = 0;
    while ((P != Nil) && (!found)) {
        if (Info(P) == X) {
            found = 1;
        }
        else {
            P = Next(P);
        }
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    /* KAMUS */
    address P;
    /* ALGORITMA */
    P = Alokasi(X);
    if (P != Nil) {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast (List *L, infotype X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS */
    address P;
    /* ALGORITMA */
    P = Alokasi(X);
    if (P != Nil) {
        InsertLast(L,P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X) {
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    /* KAMUS */
    address P;
    /* ALGORITMA */
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    /* KAMUS */
    address P;
    /* ALGORTIMA */
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    /* KAMUS */
    /* ALGORITMA */
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec) {
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    /* KAMUS */
    /* ALGORITMA */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    /* KAMUS */
    address last;
    /* ALGORITMA */
    if (IsEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        last = First(*L);
        while (Next(last) != Nil) {
            last = Next(last);
        }
        InsertAfter(L, P, last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    /* KAMUS */
    /* ALGORITMA */
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}

void DelP (List *L, infotype X) {
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    /* KAMUS */
    address P, Prec, Pdel;
    boolean found;
    /* ALGORITMA */
    P = First(*L);
    Prec = Nil;
    found = 0;
    while ((P != Nil) && (!found)) {
        if (Info(P) == X) {
            found = 1;
        } else {
            Prec = P;
            P = Next(P);
        }
    }
    if (found == 1) {
        if (Prec == Nil) { // X merupakan elemen pertama
            DelFirst(L, &Pdel);
            Dealokasi(&Pdel);
        } else {  // X bukan merupkan elemen pertama
            DelAfter(L, &Pdel, Prec);
            Dealokasi(&Pdel);
        }
    }
}

void DelLast (List *L, address *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    /* KAMUS */
    address last, precLast;
    /* ALGORITMA */
    last = First(*L);
    precLast = Nil;
    while (Next(last) != Nil) {
        precLast = last;
        last = Next(last);
    }
    if (precLast == Nil) {
        DelFirst(L, P);
    } else {
        DelAfter(L, P, precLast);
    }
}

void DelAfter (List *L, address *Pdel, address Prec) {
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    /* KAMUS */
    address P;
    boolean found;
    /* ALGORITMA */
    P = First(*L);
    found = 0;
    while ((P != Nil) && (!found)) {
        if (P == Prec) {
            found = 1;
        } else {
            P = Next(P);
        }
    }
    *Pdel = Next(P);
    Next(P) = Next(Next(P));
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    /* KAMUS */
    address P;
    /* ALGORITMA */
    if (IsEmpty(L)) {
        printf("[]");
    } else {
        P = First(L);
        printf("[%d", Info(P));
        P = Next(P);
        while (P != Nil) {
            printf(",%d", Info(P));
            P = Next(P);
        }
        printf("]");
    }
}

int NbElmt (List L) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    /* KAMUS */
    int count;
    address P;
    /* ALGORITMA */
    count = 0;
    P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}