#pragma once
#include "Type.h"
#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <unordered_map>
#include "Battle_Pokemon.h"

//we have a method that loads and returns a map with all the pokemon
//we use this method to initialise the class variable

namespace Pokedex_constants {
	extern const std::string MISSINGNO;
	extern const std::string NULL_MOVE;
	extern const int MAX_MOVES;
}

static class Pokedex {
public:
	const static std::unordered_map<std::string, Gen1_Pokemon>gen1_Pokemon_map;
	const static std::unordered_map<std::string, std::shared_ptr<Move>>gen1_moves;
	const static std::unordered_map < std::string, const std::array<const Move*, 4>>gen1_default_movesets;
public:
	const static std::unordered_map<std::string, Gen1_Pokemon>initialise_pokemon_map();
	const static std::unordered_map<std::string, std::shared_ptr<Move>>initialise_gen1_moves();
	const static std::unordered_map < std::string, const std::array<const Move*, 4>>initialise_gen1_default_movesets();
	static const Gen1_Pokemon& get_gen1_pokemon(std::string name);
	static const std::shared_ptr<Move> get_gen1_moves(std::string name);
	//still want to get rid of that magic number
	static const std::array<const Move*,4>& get_gen1_default_movesets(std::string name);
	static bool is_pokemon_in_map(std::string name);
	static bool is_move_in_map(std::string name);
	static bool is_default_moveset_in_map(std::string name);
};