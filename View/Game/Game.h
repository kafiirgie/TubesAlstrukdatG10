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

void StartGame();

void ExitGame();

boolean checkIsEndGame(int position);
//check if it's the end of the game

void rankPlayers();
// sort player based on their position

void displayRank();
// display player rank

void playerUseSkill(int idPlayer, int countPlayersPlaying);
// Use skill

void useSkill1(int idPlayer);
// use skill 1 : Pintu Ga Ke Mana Mana
void useSkill2(int idPlayer, int countPlayersPlaying);
// use skill 2 : Mesin Waktu
void useSkill3(int idPlayer, int countPlayersPlaying);
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