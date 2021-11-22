#include "../Configuration/Configuration.h"
#include "Progress.h"
#include <string.h>


char saveFileName[];

void progressName() {
    scanf("%s", saveFileName);
}

void loadProgress() {
    sscanf(saveFileName, "%s",fileName);
    STARTKATA(1);
}