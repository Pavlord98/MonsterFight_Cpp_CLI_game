#pragma once

#include "Pet.h"
#include "Player.h"

class Dog : public Pet
{
public:

	virtual std::string speak()  { return "Woof!"; }

	virtual void specialEffect(Player& player)
	{
		player.buffPlayerDamage(1);
		std::cout << "Your dog " << m_name << " incerased your damage by 1. \n";
		drawDog();
		drawLines();
	}

	Dog(std::string name)
		: Pet{ name }
	{
	}
};