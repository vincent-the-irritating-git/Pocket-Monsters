#include "Type.h"
#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <unordered_map>

std::unordered_map <std::string, Gen1_Pokemon> Gen1_Pokedex;
std::unordered_map<std::string, Move> Move_List;

int main() {
	Gen1_Pokedex.insert({ bulbasaur.pokemon_name(), bulbasaur });
	Gen1_Pokedex.insert({ alakazam.pokemon_name(),alakazam });
	Gen1_Pokedex.insert({ pinsir.pokemon_name(),pinsir });
	Move_List.insert({ barrier.m_name,barrier });
	Move_List.insert({ tackle.m_name,tackle });

}