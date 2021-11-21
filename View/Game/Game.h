#ifndef GAME_h
#define GAME_h
#include "../../ADT/boolean.h"
#include "../../ADT/Player/Player.h"

// how many players are playing
extern int playersPlaying;
// if someone win then isEndGame
extern boolean isEndGame;

void GameView(int opsi);

void NewGame();

void LoadGame();

void StartGame();

void ExitGame();

//void displayMap();

void rankPlayers(Player *players[4]);
// sort player based on their position
void displayRank();
// display player rank
void displayGameRule();
// display game rule

#endif 
