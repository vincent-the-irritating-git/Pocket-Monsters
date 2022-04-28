#include "Type.h"
#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <unordered_map>
#include "Battle_Pokemon.h"
#include "Pokedex.h"
#include "Battle_Event.h"

int main() {
	//Gen1_Pokemon p = Pokedex::gen1_Pokemon_map.at("Pikachu");
	//Battle_Pokemon bp(p);
	//Battle_Pokemon* bpp = &bp;
	//Battle_Event::human_turn(bpp);
	//const Move* move = &Pokedex::gen1_moves.at("Tackle");
	//Battle_Event::determine_move_class(move);
	std::cout << static_cast<int>(Type::Type_Enum::NONE);
	std::cout << std::endl;
	std::cout << static_cast<int>(Type::Type_Enum::NORMAL);
	
}