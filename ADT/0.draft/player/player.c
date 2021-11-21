#include "player.h"
#include <string.h>
#include "buff.c"
#include "skill.c"

void CreateEmptyPlayer(Player *P)
/*I.S. Sembarang */
/*F.S. Terdefinisi player kosong*/
{
    ListSkill S;
	ListBuff B;
    CreateEmptySkill(&S);
    CreateEmptyBuff(&B);
    LSkill(*P) = S;
	LBuff(*P) = B;
    strcpy(Nama(*P),"Unknown");
    Nomor(*P) = 0;
    Posisi(*P) = 0;
}

void InsertPlayerName(Player *P)
/*I.S. Sembarang */
/*F.S. Mengubah nama player sesuai input user*/
{
    char PlayerName[25];
    printf("Masukkan nama pemain: ");
    scanf("%s",&PlayerName);
    strcpy(Nama(*P),PlayerName);
}

void GetPlayerSkill(Player P, ListSkill *LS)
/*I.S. Player terdefinisi */
/*F.S. Mengembalikan IdSkill Dari player dengan index ke-x dari List skill*/
{
    (*LS).First = LSkill(P).First;
}

void RemPlayerSkill(Player *P, int x)
/*I.S. Player terdefinisi */
/*F.S. Menghilangkan skill ke-x dari player*/
{
    ListSkill L = LSkill(*P);
    address Q = SearchSkill(LSkill(*P),x);  // ini mau dibikin fungsi search atau aku bikin loop lokal aja(?)
    DeleteSkill(&L,Q);
}

void GetPlayerBuff(Player P, ListBuff LB)
/*I.S. Player terdefinisi */
/*F.S. Mengembalikan IdBuff Dari player dengan index ke-x dari List skill*/
{
    LB = LBuff(P);
}

void RemPlayerBuff(Player *P, int x)
/*I.S. Player terdefinisi */
/*F.S. Menghilangkan buff ke-x dari player*/
{
    ListBuff LB;
    LB = LBuff(*P);
    RemoveBuff(&LB,x); // BELUM ADA
}

void PrintInfoPlayer(Player P)
{
    printf("Nomor: %d\n",Nomor(P));
    printf("Nama: %s\n", Nama(P));
    printf("Posisi: %d\n", Posisi(P));
    PrintSkill(LSkill(P));
    PrintInfoBuff(LBuff(P)); // BELUM ADA
}
