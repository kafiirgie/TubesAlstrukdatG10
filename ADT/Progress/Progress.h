#ifndef PROGRESS_h
#define PROGRESS_h

#include <stdio.h>
#include <stdlib.h>
#include "../MesinKarKat/mesin_kata.h"
#include<string.h>

extern char saveFileName[];
extern char configName[];

void progressName();
void loadProgress();
void saveProgress();

#endif