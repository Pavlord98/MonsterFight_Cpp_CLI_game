#pragma once

#include "Pet.h"
#include "Player.h"
#include "ASCII_art.h"

class Crow : public Pet
{
public:

	virtual std::string speak()  { return "Caw!"; }

	virtual void specialEffect(Player& player)
	{
		player.addGold(5);
		std::cout << "Your pet crow " << m_name << " found some gold and brought it to you. \n";
		art::drawCrow();
		art::drawLines();
	}
	Crow(std::string name)
		: Pet{ name }
	{
	}
};
