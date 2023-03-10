
#include <iostream>

#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "Cat.h"
#include "Dog.h"
#include "Crow.h"
#include "ASCII_art.h"
#include "GameMechanics.h"
#include "Scoreboard.h"

int main()
{
	// initialize and great the player
	Player player{ createPlayer() };

	// create a pet of the player's choosing
	std::unique_ptr<Pet> pet {createPet()};

	// create a round counter
	int roundCounter{ 1 };

	// If the player isn't dead and hasn't won yet, the game continues
	while (!player.isDead() && !player.hasWon())
	{
		// Indicate start of a new round
		std::cout << "Starting round number: " << roundCounter++ << '\n';

		// Activate the pet's signature abillity
		pet->specialEffect(player);
		
		// Wait for player to respond
		waitForInput();

		// A monster is created (a new one for each round)
		Monster monster{ spawnMonster() };

		// Player ecnounters a monster
		battle(player, monster);

		// Inform the player of their health, level and gold
		reportToPlayer(player);
		
		std::cout << currentDateTime();
		
	}

	// show appropriate end Game message
	endGameScreen(player);

	player.writeScoreToFile(currentDateTime());	

	printScoreboard();

	return 0;
}

