#ifndef Buff_H
#define Buff_H

#include "../boolean.h"
#include "../ListLInier/ListLinier.h"


typedef List Buff;

#define Buff1 "Imunitas Telport"
#define Buff2 "Cermin Pengganda"
#define Buff3 "Senter Pembesar Hoki"
#define Buff4 "Senter Pengecil Hoki"


void CreateEmptyBuff (Buff *LB);

int CountBuff(Buff LB);

#endif