#pragma once
#include <iostream>
#include "Pokemon.h"
#include "Battle_Pokemon.h"
#include <array>

static Battle_Pokemon user;
static Battle_Pokemon enemy;
std::array<Battle_Pokemon, 2>turn_order;

std::unordered_map <std::string, Gen1_Pokemon> Gen1_Pokedex;
std::unordered_map<std::string, Move> Move_List;

//gen_selection(){};
Pokemon select_user_pokemon() {};
Pokemon select_enemy_pokemon() {};
