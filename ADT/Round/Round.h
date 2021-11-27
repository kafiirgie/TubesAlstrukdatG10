#ifndef Round_h
#define Round_h

// typedef int addressRonde; 
#include "../Player/Player.h"

typedef struct {
    player players[4];
    int rondeKeberapa;
} roundData;

typedef struct tElmtRonde * addressRonde;
typedef struct tElmtRonde { 
  roundData Info;
  addressRonde Next; 
} ElmtRonde; 

/* Type Ronde dengan ciri TOP : */
typedef struct { 
  addressRonde TOP;  /* alamat TOP: elemen puncak */
} Ronde;


#define CurrRonde(S) (S).TOP->Info
#define TopRonde(S) (S).TOP
#define PrevRonde(P) (P)->Next
#define InfoRonde(P) (P)->Info


void AlokasiRonde (addressRonde *P, roundData X);
/* I.S. Sembarang */
/* F.S. Alamat P diAlokasiRonde, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika AlokasiRonde gagal */
void DeAlokasiRonde (addressRonde P);
/* I.S. P adalah hasil AlokasiRonde, P != Nil */
/* F.S. Alamat P dideAlokasiRonde, dikembalikan ke sistem */ 

/* ********* PROTOTYPE REPRESENTASI LOJIK Ronde ***************/
boolean IsRondeEmpty (Ronde S);
/* Mengirim true jika Ronde kosong: TOP(S) = Nil */
void CreateRondeEmpty (Ronde * S);
/* I.S. sembarang */ 
/* F.S. Membuat sebuah Ronde S yang kosong */
void PushRonde (Ronde * S, roundData X);
/* Menambahkan X sebagai elemen Ronde S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika AlokasiRonde X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void PopRonde (Ronde * S, roundData * X);
/* Menghapus X dari Ronde S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama dideAlokasiRonde */
/* Pada dasarnya adalah operasi Delete First pada list linier */





#endif