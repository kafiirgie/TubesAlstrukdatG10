/* ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#ifndef skill_H
#define skill_H

#include "../../boolean.h"
#include "listlinier.h"
#include "listlinier.c"

typedef struct {
	int TI [100];
} TabSkill;



#define TI(Tab) (Tab).TI


void CreateTabSkill(TabSkill *TS);

void CreateEmptySkill (List *L);

int CountSkill(List L);

int RandomSkill(List L, TabSkill TS);

void InsertSkill (List *L, infotype X);

void DeleteSkill (List *L, infotype X);

void PrintSkill (List LSkill);

void RunSkill(List L, infotype X);


#endif
