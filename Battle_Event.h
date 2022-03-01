#pragma once
#include <iostream>
#include "Pokemon.h"
#include "Battle_Pokemon.h"
#include <array>

static Battle_Pokemon user;
static Battle_Pokemon enemy;

//gen_selection(){};
Pokemon select_user_pokemon();
Pokemon select_enemy_pokemon();
