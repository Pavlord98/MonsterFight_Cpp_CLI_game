#include "Dog.h"

#include "Pet.h"
#include "Player.h"
#include "ASCII_art.h"

Dog::Dog(std::string name)
		: Pet{ name }
	{
	}

std::string Dog::speak()  { return "Woof!"; }

void Dog::specialEffect(Player& player)
	{
		player.buffPlayerDamage(1);
		std::cout << "Your dog " << m_name << " incerased your damage by 1. \n";
		art::drawDog();
		art::drawLines();
	}
