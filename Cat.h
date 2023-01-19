#ifndef CAT_H
#define CAT_H

#include "Pet.h"
#include "Player.h"
#include "ASCII_art.h"

class Cat : public Pet
{
public:
	
	virtual std::string speak()  { return "Meow!"; }

	virtual void specialEffect(Player& player)
	{
		player.healPlayer(1);
		std::cout << "Your cat " << m_name << " healed you for 1 health. \n";
		std::cout << "Current health is: " << player.getHealth() << '\n';
		drawHeart();
		drawCat();
		drawLines();
	}

	Cat(std::string name)
		: Pet{ name }
	{
	}

};

#endif
