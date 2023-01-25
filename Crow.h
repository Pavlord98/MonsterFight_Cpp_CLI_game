#ifndef CROW_H
#define CROW_H

#include "Pet.h"
#include "Player.h"

class Crow : public Pet
{
public:

	virtual std::string speak();

	virtual void specialEffect(Player& player);
	
	Crow(std::string name);
};

#endif