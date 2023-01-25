#ifndef DOG_H
#define DOG_H

#include "Pet.h"
#include "Player.h"

class Dog : public Pet
{
public:

	virtual std::string speak();

	virtual void specialEffect(Player& player);

	Dog(std::string name);
};

#endif