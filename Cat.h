#ifndef CAT_H
#define CAT_H

#include "Pet.h"
#include "Player.h"
#include <string>
//#include "ASCII_art.h"

class Cat : public Pet
{
public:
	
	std::string speak(); 

	void specialEffect(Player& player);

	Cat(std::string name);

};

#endif
