#include "Type.h"
#include <iostream>
#include <unordered_map>
#include "Pokemon.h"
#include "Pokemon_Pokedex.h"

int main() {
	std::cout<<"the string is "<<Pokemon_Pokedex::al.at(0);
	std::cout<<std::endl;
	Gen1_Pokemon yosser(1, "Yosser", Type::BUG, Type::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(1, 2, 3, 4, 5));
	Gen1_Pokemon def;
	def=Pokemon_Pokedex::get_gen1_pokemon("Missingno");
	def.show_base_stats();
}