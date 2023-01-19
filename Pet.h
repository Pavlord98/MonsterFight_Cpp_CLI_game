#ifndef PET_H
#define PET_H

#include "Creature.h"
#include "Player.h"

class Pet : public Creature
{
public:
	virtual ~Pet() {};
	virtual std::string speak() = 0;
	virtual void specialEffect(Player& player) = 0;

	
	Pet(std::string name)
		: Creature{ name }
	{
	}
	

};


#endif