#pragma once
#include "Pokemon.h"

//we will need two classes, one for each
class Battle_Pokemon
	//here we have stat modifiers to track how stats have changed
	//when we do the calculation we do (reference_stat*modifier),
	//this will be calculated using both of these and returned in a method, which
	//is what the damage calculation uses
{
public:
	status_effect_value m_current_pokemon_status =status_effect_value::NORMAL;
	const Gen1_Pokemon* pokemon_ptr;
	int attack_modifier = 1;
	int defence_modifier = 1;
	int speed_modifier = 1;
	int special_modifier = 1;
	int hp=1;
	int critical_hit_ratio = 1;
	double stun_chance = 0;
public:
	Battle_Pokemon();
	Battle_Pokemon(const Gen1_Pokemon&);
	int modified_attack()const;
	int modified_defence()const;
	int modified_speed()const;
	int modified_special()const;
	void show_battle_stats()const;
	double get_stun_chance();
	status_effect_value get_status_effect();

};

