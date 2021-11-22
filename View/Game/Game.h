// File: Game.h

#ifndef Game_h
#define Game_h
#include "../../ADT/boolean.h"
#include "../../ADT/Player/Player.h"

extern int playersPlaying; // how many players are playing
extern boolean isEndGame; // if someone win then isEndGame

void showPlayerCommand();
// show player command

void GameView(int opsi);

void NewGame();

void LoadGame();

void StartGame();

void ExitGame();

void displayGameRule();
// display game rule

boolean checkIsEndGame(int position);
//check if it's the end of the game

void rankPlayers(player *players[4]);
// sort player based on their position

void displayRank();
// display player rank

void showPlayerPosition(int position); //adt player
// show the position of the player

void displayMap(); //adt map
// display game map

void inspectMap(int point); //adt map
// Check if there is a teleporter at that point

void playerUseSkill(int idPlayer, int countPlayersPlaying);
// Use skill

void useSkill1(int idPlayer);
// use skill 1 : Pintu Ga Ke Mana Mana
void useSkill2(int idPlayer);
// use skill 2 : Mesin Waktu
void useSkill3(int idPlayer);
// use skill 3 : Baling Baling Jambu
void useSkill4(int idPlayer);
// use skill 4 : Cermin Pengganda
void useSkill5(int idPlayer);
// use skill 5 : Senter Pembesar Hoki
void useSkill6(int idPlayer);
// use skill 6 : Senter Pengecil Hoki
void useSkill7(int idPlayer, int countPlayersPlaying);
// use skill 7 : Mesin Penukar Posisi
void useSkill8(int idPlayer);
// use skill 8 : Teknologi Gagal

#endif