#pragma once

#include "Monster.h"
#include "Player.h"
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "ASCII_art.h"

void attackMonster(Player& player, Monster& monster)
{
	// reduce the monsters health by the players damage ability
	monster.reduceHealth(player.getDamage());
}

void attackPlayer(Player& player, Monster& monster)
{
	// reduce the players health by the monsters damage ability
	player.reduceHealth( monster.getDamage());
}


// Generates monster, lets the player choose to run or to fight
Monster spawnMonster() 
{
	Monster monster{ Monster::getRandomMonster() };
	std::cout << "You have encoutered a " << monster.getName() << "!\n";
	drawMonster(monster);
	return monster;
}


std::string getPlayerName()
{
	welcomePlayer();
	drawLines();

	std::cout << "Enter your name : ";
	std::string name;
	std::cin >> name;
	

	drawLines();

	return name;
}


void congratulatePlayer(Player player)
{
	drawLines();
	drawFireworks();
	std::cout << "Congratulations " << player.getName() << "!\n";
}

void waitForInput()
{
	std::cout << "Enter 1 to continue: ";
	char wait = '0';
	while (wait != '1')
	std::cin >> wait;
}

void reportToPlayer(Player& player)
{
	std::cout << "You currently have " << player.getHealth() << " health, and are at level " << player.getLevel() << '\n';
	std::cout << "You have: " << player.getGold() << " gold.\n";
	
	waitForInput();
}


