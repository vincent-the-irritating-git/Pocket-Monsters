#include "Type.h"
#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <unordered_map>
#include "Battle_Pokemon.h"
#include "Pokedex.h"



int main() {
	Pokedex pokedex;
	pokedex.load_in_all_data();
	bool b = pokedex.get_gen1_pokemon_from_map("Bulbasaur") == pokedex.get_gen1_pokemon_from_map("Pikachu");
	bool c = pokedex.get_gen1_pokemon_from_map("Bulbasaur") == pokedex.get_gen1_pokemon_from_map("Bulbasaur");
	pokedex.get_gen1_pokemon_from_map("Pikachu").show_base_stats();
	std::cout <<std::boolalpha<< b<<std::endl<<std::boolalpha<<c;
};