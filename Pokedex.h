#pragma once
#include "Type.h"
#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <unordered_map>
#include "Battle_Pokemon.h"

//we have a method that loads and returns a map with all the pokemon
//we use this method to initialise the class variable

extern int MAX_MOVES;

class Pokedex {
public:
	const static std::unordered_map<std::string, Gen1_Pokemon>gen1_Pokemon_map;
	const static std::unordered_map<std::string, Move>gen1_moves;
	const static std::unordered_map < std::string, std::array<const Move*, 4>>gen1_default_movesets;
public:
	const static std::unordered_map<std::string, Gen1_Pokemon>initialise_pokemon_map();
	const static std::unordered_map<std::string, Move>initialise_gen1_moves();
	const static std::unordered_map < std::string, std::array<const Move*, 4>>initialise_gen1_default_movesets();
};