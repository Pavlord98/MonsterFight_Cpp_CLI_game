#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include "Monster.h"
#include "Player.h"
#include "Cat.h"
#include "Dog.h"
#include "Crow.h"
#include "ASCII_art.h"
#include <memory>

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
	art::drawMonster(monster);
	return monster;
}


std::string createPlayer()
{
	art::welcomePlayer();
	art::drawLines();

	std::cout << "Enter your name : ";
	std::string name;
	std::cin >> name;
	

	art::drawLines();

	return name;
}


void congratulatePlayer(Player player)
{
	art::drawLines();
	art::drawFireworks();
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
	art::drawLines();
	
	waitForInput();
}

void battle(Player& player, Monster& monster)
{
	std::cout << "Do you want to fight this monster or run away? \n";
		std::cout << "Input 'F' for fight and 'R' for Run : \n";
		char decision{};
		std::cin >> decision;
		art::drawLines();

		if (decision == 'R' || decision == 'r') {

			
			std::cout << "You decided to run. \n";
			
			if (getRandomNumber(0, 1) == 0) {
				attackPlayer(player, monster); // reduces the player's health
				std::cout << "You got hit by the monster while running away. \n";
			}
			else {
				std::cout << "You managed to get away scar-free. \n";
			}
		}

		else if (decision == 'F' || decision == 'f')
		{
			std::cout << "You decided to fight. \n";

			// The player attacks first
			attackMonster(player, monster);
			// If the monster's not dead, the monster attacks back
			if (!monster.isDead()) { attackPlayer(player,monster); }

			std::cout << "The monster ran away \n";

			player.addGold(monster.getGold());

			std::cout << "You leveled up! \n";
			player.levelUp();
		}
		else {
			std::cout << "Invalid selection! \n";
		};
}

std::unique_ptr<Pet> createPet()
{
	std::cout << "Choose a pet. (cat,dog or crow): ";
	std::string decision;
	std::cin >> decision;

	std::cout << "Chose a name for your pet: ";
	std::string petName;
	std::cin >> petName;

	// initialize a corresponding class
	std::unique_ptr<Pet> pet;
	if (decision == "cat")
		pet.reset(new Cat(petName));
	else if (decision == "dog")
		pet.reset(new Dog(petName));
	else
		pet.reset(new Crow(petName));

	return pet;
}

void endGameScreen(Player& player)
{
if (player.hasWon())
	{
		art::drawLines();
		congratulatePlayer(player);
		waitForInput();
	}
	else
	{
		art::drawLines();
		std::cout << "You died! Better luck next time.";
		art::drawGameOverArt();
		waitForInput();
	}
}

#endif