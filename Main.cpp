#include "Type.h"
#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <unordered_map>
#include "Battle_Pokemon.h"
#include "Pokedex.h"
#include "Battle_Event.h"

using namespace status_and_stats;

int main() {
	std::cout << "where's the text?" << std::endl;
	Gen1_Pokemon p = Pokedex::gen1_Pokemon_map.at("Pikachu");
	p.show_base_stats();
	p.show_gen1_pokemon_stats();
	//Battle_Pokemon bp(p);
	//Battle_Pokemon* bpp = &bp;
	//Battle_Event::human_turn(bpp);
	//const Move* move = &Pokedex::gen1_moves.at("Tackle");
	//Battle_Event::determine_move_class(move);
	std::shared_ptr<int>x;
	int y=5;
	std::cout << static_cast<int>(Type::Type_Enum::DRAGON);
	std::cout << std::endl;
	std::cout << static_cast<int>(Type::Type_Enum::NORMAL);
	std::cout << std::endl;
	std::cout<<Type::get_type_name(Type::Type_Enum::BUG);
	std::cout << std::endl;
	std::cout << static_cast<int>(stats_value::ATTACK);
	std::cout << std::endl;

	return 0;
}