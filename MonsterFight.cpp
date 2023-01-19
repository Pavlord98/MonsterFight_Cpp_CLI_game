// MonsterFight.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "GameMechanics.h"
#include "ASCII_art.h"
#include "Cat.h"
#include "Crow.h"
#include <memory>

int main()
{
	std::cout << "I made this line on my laptop";
	std::cout << "This is the new feature"; // yup, just this line
	// initialize and great player
	Player player{ getPlayerName() };

	// aks user to choose a pet to accompany them
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

	// create a round counter
	int roundCounter{ 1 };

	// If the player isn't dead and hasn't won yet, the game continues
	while (!player.isDead() && !player.hasWon())
	{
		drawLines();
		std::cout << "Starting round number: " << roundCounter++ << '\n';

		pet->specialEffect(player);
		waitForInput();

		Monster monster{ spawnMonster() };

		// Ask the player what to do
		std::cout << "Do you want to fight this monster or run away? \n";
		std::cout << "Input 'F' for fight and 'R' for Run : \n";
		char decision{};
		std::cin >> decision;
		drawLines();

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

		// Inform the player of their health and level
		reportToPlayer(player);

	}

	if (player.hasWon())
	{
		congratulatePlayer(player);
		waitForInput();
	}
	else
	{
		drawLines();
		std::cout << "You died! Better luck next time.";
		drawGameOverArt();
		waitForInput();
	}

	return 0;
}

