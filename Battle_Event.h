#pragma once
#include <iostream>
#include "Pokemon.h"
#include "Battle_Pokemon.h"
#include "Pokedex.h"
#include <array>
#include <regex>

static class Battle_Event {
private:
	//make this smart pointers
	static std::array<std::shared_ptr<Battle_Pokemon>,2> turn_order;
	static bool isFainted;
	//make these two smart pointers
	static std::shared_ptr<Battle_Pokemon> current;
	static std::shared_ptr<Battle_Pokemon> opposing;
	//
	static Battle_Pokemon user;
	static Battle_Pokemon ai;
public:
	static void determine_move_class(const Move& move);
	static void determine_attack_move(Battle_Pokemon& bp, const Move& move);
	static void do_defence_move(Battle_Pokemon& bp, const Move& move);
	static void display_moves(Battle_Pokemon& current);
	static int select_move(Battle_Pokemon& current);
	static void do_move(Battle_Pokemon& current, const Move& chosen_move);
	static void inflict_damage(Battle_Pokemon& bp, const Attack_Move& move);
	static const Move& retrieve_move_from_map(Battle_Pokemon& bp, int m);
	static bool is_valid_move_choice(int choice);
	static bool is_NULL_MOVE(const Move& move);
	static void DEBUG_SET_USER(Gen1_Pokemon);
	static void DEBUG_SET_ENEMY(Gen1_Pokemon);
	static std::array<std::shared_ptr<Battle_Pokemon>, 2> DEBUG_get_turn_order();
	static void start_battle();
	static bool is_pokemon_in_map(std::string&);
	static const Gen1_Pokemon& find_pokemon_from_map(std::string& choice);
	static bool is_stunned(Battle_Pokemon& current);
	static bool is_status_effect_a_stun(Battle_Pokemon& current);
	static bool calculate_if_stunned(Battle_Pokemon& current);
	static void speed_check();
	Battle_Event();
	static void select_pokemon_to_battle();
	static void turn(std::shared_ptr<Battle_Pokemon> current, std::shared_ptr<Battle_Pokemon> opposing);
	static void ai_turn(Battle_Pokemon& current);
	static void human_turn(Battle_Pokemon& current);
	static int compare_speeds();
	static void assign_turn_order(int);
	static void random_turn_order();
	static void select_user_pokemon();
	static void select_enemy_pokemon();
	static void battle();
};