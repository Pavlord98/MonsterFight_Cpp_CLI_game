#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include "Monster.h"
#include "Player.h"
#include "Cat.h"
#include "Dog.h"
#include "Crow.h"
#include "ASCII_art.h"
#include <memory>


void attackMonster(Player& player, Monster& monster);


// Generates monster, lets the player choose to run or to fight
Monster spawnMonster();

std::string createPlayer();


void congratulatePlayer(Player player);

void waitForInput();

void reportToPlayer(Player& player);

void battle(Player& player, Monster& monster);


void endGameScreen(Player& player);

std::unique_ptr<Pet> createPet();



#endif