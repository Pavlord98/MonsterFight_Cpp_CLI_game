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
	// initialize and great player
	Player player{ getPlayerName() };

	// aks user to choose a pet to accompany them
	std::unique_ptr<Pet> pet {createPet()};

	// create a round counter
	int roundCounter{ 1 };

	// If the player isn't dead and hasn't won yet, the game continues
	while (!player.isDead() && !player.hasWon())
	{
		art::drawLines();
		std::cout << "Starting round number: " << roundCounter++ << '\n';

		pet->specialEffect(player);
		waitForInput();

		Monster monster{ spawnMonster() };

		// Ask the player what to do
		battle(player, monster);

		// Inform the player of their health and level
		reportToPlayer(player);

	}

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

	return 0;
}

