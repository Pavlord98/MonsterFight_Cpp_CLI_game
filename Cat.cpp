#include "Cat.h"

#include "Pet.h"
#include "Player.h"
#include <string>
#include "ASCII_art.h"

Cat::Cat(std::string name)
		: Pet{ name }
	{
	}

std::string Cat::speak()  { return "Meow!"; }

void Cat::specialEffect(Player& player)
	{
		player.healPlayer(1);
		std::cout << "Your cat " << m_name << " healed you for 1 health. \n";
		std::cout << "Current health is: " << player.getHealth() << '\n';
		art::drawHeart();
		art::drawCat();
		art::drawLines();
	}