#pragma once
#include "Type.h"
#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <unordered_map>
#include "Battle_Pokemon.h"

//we have a method that loads and returns a map with all the pokemon
//we use this method to initialise the class variable


class Pokedex {
public:
	const static std::unordered_map<std::string, Gen1_Pokemon>gen1_Pokemon_map;
public:
	const static std::unordered_map<std::string, Gen1_Pokemon>initialise_pokemon_map();
};