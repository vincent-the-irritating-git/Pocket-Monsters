#pragma once
#include "Type.h"
#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <unordered_map>
#include "Battle_Pokemon.h"

class Pokedex {
private:
	std::unordered_map <std::string, Gen1_Pokemon> Gen1_pokemon_definitions_map;
	std::unordered_map<std::string, Move> Move_definitions_map;
public:
	Pokedex();
	void load_moves_into_map();
	void load_pokemon_into_map();
	void load_pokemon_with_default_moves();
	void list_pokemon();
	void load_in_all_data();
	Gen1_Pokemon& get_gen1_pokemon_from_map(std::string);
};