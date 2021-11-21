#ifndef PLAYER_H
#define PLAYER_H
#include "boolean.h"
#include "skill.h"
#include "listskill.h"
#include "buff.h"

/* Definisi Type Data */
typedef struct {
    int Nomor;
	int Posisi;
    char Nama[25];
	ListSkill Skill;
	ListBuff Buff;
} Player;

#define Nomor(P) (P).Nomor
#define Posisi(P) (P).Posisi
#define LSkill(P) (P).Skill
#define LBuff(P) (P).Buff
#define Nama(P) (P).Nama


void CreateEmptyPlayer(Player *P);
/*I.S. Sembarang */
/*F.S. Terdefinisi player kosong*/

void GetPlayerSkill(Player P, ListSkill *LS);
/*I.S. Player terdefinisi */
/*F.S. Mengembalikan IdSkill Dari player dengan index ke-x dari List skill*/

void RemPlayerSkill(Player *P, int x);
/*I.S. Player terdefinisi */
/*F.S. Menghilangkan skill ke-x dari player*/

void GetPlayerBuff(Player P, ListBuff LB);
/*I.S. Player terdefinisi */
/*F.S. Mengembalikan IdBuff Dari player dengan index ke-x dari List skill*/

void RemPlayerBuff(Player *P, int x);
/*I.S. Player terdefinisi */
/*F.S. Menghilangkan buff ke-x dari player*/

void PrintInfoPlayer(Player P);
/*I.S. Player terdefinisi */
/*F.S. Mencetak informasi player*/

#endif
