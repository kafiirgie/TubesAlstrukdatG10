// File: Player.h
// Define player adt 

#ifndef Player_h
#define Player_h

#include "../boolean.h"
#include "../Skill/Skill.h"


typedef struct {
    int position; //Initial position is always 0
    char name[20];
    skill skills;
    boolean buff[4]; //Initial pbuff is always all false
} player;


void setPlayer(player *thePlayer);
// Set player properties

void playerRoleDice(player *thePlayer, int maxDice);
// Role dice

//void playerTeleport(player *thePlayer, int outPoint);
// Teleport

void playerTeleport(player *thePlayer);
// Check if teleport eligible at that point and condition, if it's then the player will teleport

boolean isCanTeleport(player *thePlayer);
// Check is teleport eligible at that point

boolean isPlayerCanMove(int change, int position, boolean isUpward);
// Check future displacement

int playerOption();
// Scan the option

/*void playerUseSkill(player *thePlayer);
// Use skill*/

int getIdSkill(skill LS, int num);
// get skill id based on user selection 

/*void useSkill1(player *thePlayer);
// use skill 1 : Pintu Ga Ke Mana Mana
void useSkill2(player *thePlayer);
// use skill 2 : Mesin Waktu
void useSkill3(player *thePlayer);
// use skill 3 : Baling Baling Jambu
void useSkill4(player *thePlayer);
// use skill 4 : Cermin Pengganda
void useSkill5(player *thePlayer);
// use skill 5 : Senter Pembesar Hoki
void useSkill6(player *thePlayer);
// use skill 6 : Senter Pengecil Hoki
void useSkill7(player *thePlayer1, player *thePlayer2);
// use skill 7 : Mesin Penukar Posisi
void useSkill8(player *thePlayer);
// use skill 8 : Teknologi Gagal*/

void resetPlayerBuff(player *thePlayer);
// reset player buff for every round

void showPlayerBuff(player *thePlayer);
// show player buff that active


#endif