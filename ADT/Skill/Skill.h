#ifndef Skill_H
#define Skill_H

#include "../boolean.h"
#include "../ListLInier/ListLinier.h"


extern int TabSkill[100];

typedef List Skill;

#define Skill1 "Pintu Ga Ke Mana Mana"
#define Skill2 "Mesin Waktu"
#define Skill3 "Baling Baling Jambu"
#define Skill4 "Cermin Pengganda"
#define Skill5 "Senter Pembesar Hoki"
#define Skill6 "Senter Pengecil Hoki"
#define Skill7 "Mesin Penukar Posisi"
#define Skill8 "Teknologi Gagal"

void CreateTabSkill();

void CreateEmptySkill (Skill *LS);

int CountSkill(Skill LS);

int RandomSkill();

void InsertSkill (Skill *LS, infotype X);

void DeleteSkill (Skill *LS, int Num);

void PrintSkill (Skill LS);

void RunSkill(Skill LS, int Num);

void RunSkill1();

void RunSkill2();

void RunSkill3();

void RunSkill4();

void RunSkill5();

void RunSkill6();

void RunSkill7();

void RunSkill8();


#endif