#include "Crow.h"

#include "Pet.h"
#include "Player.h"
#include "ASCII_art.h"

Crow::Crow(std::string name)
		: Pet{ name }
	{
	}

std::string Crow::speak()  { return "Caw!"; }

void Crow::specialEffect(Player& player)
	{
		player.addGold(5);
		std::cout << "Your pet crow " << m_name << " found some gold and brought it to you. \n";
		art::drawCrow();
		art::drawLines();
	}