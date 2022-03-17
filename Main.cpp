#include "Type.h"
#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <unordered_map>
#include "Battle_Pokemon.h"
#include "Pokedex.h"

int main() {
	//Pokedex::gen1_Pokemon_map.at("Bulbasaur").show_base_stats();
	//Pokedex::gen1_Pokemon_map.at("Bulbasaur").show_gen1_pokemon_stats();
	//std::cout<< Pokedex::gen1_Pokemon_map.at("Bulbasaur").get_pokemon_name();
	Battle_Pokemon bp(Pokedex::gen1_Pokemon_map.at("Bulbasaur"));
	bp.show_battle_stats();
}