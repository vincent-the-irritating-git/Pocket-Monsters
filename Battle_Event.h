#pragma once
#include <iostream>
#include "Pokemon.h"
#include "Battle_Pokemon.h"
#include "Pokedex.h"
#include <array>

class Battle_Event {
private:
	static std::array<Battle_Pokemon*,2> turn_order;
	static bool isFainted;
	static Battle_Pokemon user;
	static Battle_Pokemon enemy;
public:
	//TODO get rid of this one
	void show_turn_order();
	void start_battle();
	bool is_pokemon_in_map(std::string&);
	const Gen1_Pokemon* find_pokemon_from_map(std::string& choice);
	bool is_stunned(Battle_Pokemon* bp);
	bool is_status_effect_a_stun(Battle_Pokemon* bp);
	bool calculate_if_stunned(Battle_Pokemon* bp);
	void speed_check();
	Battle_Event();
	void select_pokemon_to_battle();
	void turn(Battle_Pokemon*);
	int compare_speeds();
	void assign_turn_order(int);
	void random_turn_order();
	void select_user_pokemon();
	void select_enemy_pokemon();
	void battle();
};