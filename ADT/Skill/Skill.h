// File: Skill.h
// Define skill adt (use list linear implementation)

#ifndef Skill_h
#define Skill_h

#include "../boolean.h"
#include "ListLinier.h"

#define Nil NULL

extern int tabSkill[100]; // tabskill created for random skill based on probability
typedef List skill; // define skill as list liniear

#define Skill1 "Pintu Ga Ke Mana Mana"
#define Skill2 "Mesin Waktu"
#define Skill3 "Baling Baling Jambu"
#define Skill4 "Cermin Pengganda"
#define Skill5 "Senter Pembesar Hoki"
#define Skill6 "Senter Pengecil Hoki"
#define Skill7 "Mesin Penukar Posisi"
#define Skill8 "Teknologi Gagal"


void createTabSkill();

void createEmptySkill(skill *LS);

int countSkill(skill LS);

int getRandomSkill();

void insertSkill(skill *LS, infotype X);

void deleteSkill(skill *LS, int num);

void printSkill(skill LS);


#endif