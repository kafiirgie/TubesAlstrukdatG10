// File: Skill.h
// Define skill adt (use list linear implementation)

#ifndef Skill_h
#define Skill_h

#include "../boolean.h"
#include "ListLinier.h"

#define Nil NULL

extern int tabSkill[100]; // tabskill created for random skill based on probability
typedef List skill; // define skill as list linear
// skill represented by id skill 1-8 as shown below
#define Skill1 "Pintu Ga Ke Mana Mana"
#define Skill2 "Mesin Waktu"
#define Skill3 "Baling Baling Jambu"
#define Skill4 "Cermin Pengganda"
#define Skill5 "Senter Pembesar Hoki"
#define Skill6 "Senter Pengecil Hoki"
#define Skill7 "Mesin Penukar Posisi"
#define Skill8 "Teknologi Gagal"


void createTabSkill();
// create array skill to used for generate random skill based on probability

void createEmptySkill(skill *LS);
// create empty skill list

int countSkill(skill LS);
// count user skill

int getRandomSkill();
// generate random id skill 1-8

void insertSkill(skill *LS, infotype X);
// insert new id skill to list skill

void deleteSkill(skill *LS, int num);
// delete skill based on user selection

void printSkill(skill LS);
// show all user skill

int getIdSkill(skill LS, int num);
// get skill id based on user selection

#endif