#pragma once
#include <array>
#include "Type.h"
#include "Pokemon.h"
#include <iostream>
#include <unordered_map>


namespace Pokemon_Pokedex_constants {
	extern const std::string MISSINGNO;
}

static class Pokemon_Pokedex {
public:
	const static std::unordered_map<std::string, Gen1_Pokemon>gen1_Pokemon_map;
public:
	const static std::unordered_map<std::string, Gen1_Pokemon>initialise_pokemon_map();
	static const Gen1_Pokemon& get_gen1_pokemon(std::string name);
	static bool is_pokemon_in_map(std::string name);
};