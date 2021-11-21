#ifndef Player_h
#define Player_h

#include "../boolean.h"
#include "../MesinKarKat/mesin_kata.h"
#include "../Configuration/Configuration.h"
#include "../Skill/Skill.h"
#include "../Buff/Buff.h"
#include "../Map/Map.h"
#include "../Teleport/Teleport.h"

typedef struct {
    int Position; //Initial position is always 0
    char Name[20];
    Map PMap;
    Skill PSkill;
    Buff PBuff;
} Player;

#define Position(P) (P).Position
#define Name(P) (P).Name
#define PMap(P) (P).PMap
#define PSkill(P) (P).PSkill
#define PBuff(P) (P).PBuff

void setPlayer(Player *thePlayer);
// set player properties

void setPlayerMap(Player *thePlayer);
// move '*' in player map

void playerRoleDice(Player *thePlayer, int maxDice);
// Role dice

void playerTeleport(Player *thePlayer, int endPoint);
// teleport


////void playerUseSkill(Player *thePlayer);
// use skill

////void playerOption();



#endif