#include "Pet.h"

#include "Creature.h"
#include "Player.h"

Pet::Pet(std::string name)
	: Creature{ name }
	{
	}

Pet::~Pet() {}