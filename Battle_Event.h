#pragma once
#include <iostream>
#include "Pokemon.h"
#include "Battle_Pokemon.h"
#include "Pokedex.h"
#include <array>

static class Battle_Event {
private:
	static std::array<Battle_Pokemon*,2> turn_order;
	static bool isFainted;
	static Battle_Pokemon user;
	static Battle_Pokemon enemy;
public:
	//TODO get rid of this one
	static void show_turn_order();
	static void start_battle();
	static bool is_pokemon_in_map(std::string&);
	static const Gen1_Pokemon* find_pokemon_from_map(std::string& choice);
	static bool is_stunned(Battle_Pokemon* bp);
	static bool is_status_effect_a_stun(Battle_Pokemon* bp);
	static bool calculate_if_stunned(Battle_Pokemon* bp);
	static void speed_check();
	Battle_Event();
	static void select_pokemon_to_battle();
	static void turn(Battle_Pokemon*);
	static int compare_speeds();
	static void assign_turn_order(int);
	static void random_turn_order();
	static void select_user_pokemon();
	static void select_enemy_pokemon();
	static void battle();
};