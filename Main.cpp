#include "Type.h"
#include <iostream>
#include <unordered_map>
#include "Pokemon.h"
#include "Pokemon_Pokedex.h"

int main() {
	Gen1_Pokemon yosser(1, "Yosser", Type::BUG, Type::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(1, 2, 3, 4, 5));
	Gen1_Pokemon def = Pokemon_Pokedex::get_gen1_pokemon("neil");
	def.show_base_stats();
}