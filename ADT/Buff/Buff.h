#ifndef Buff_H
#define Buff_H

#include "../boolean.h"
#include "../ListLInier/ListLinier.h"


typedef List Buff;

#define Buff1 "Imunitas Telport" // Will activate when Skill1 activated
#define Buff2 "Cermin Pengganda" // Will activate when Skill4 activated
#define Buff3 "Senter Pembesar Hoki" // Will activate when Skill5 activated
#define Buff4 "Senter Pengecil Hoki" // Will activate when Skill6 activated


void CreateEmptyBuff (Buff *LB);

int CountBuff(Buff LB);

void InsertBuff(Buff *LB, infotype X);

void DeleteBuff(Buff *LB, infotype X);

void ClearBuff(Buff *LB);

void PrintBuff(Buff LB);

#endif