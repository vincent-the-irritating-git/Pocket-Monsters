#pragma once
#include "Pokemon.h"

//we will need two classes, one for each
class Battle_Pokemon
	//here we have stat modifiers to track how stats have changed
	//when we do the calculation we do (reference_stat*modifier),
	//this will be calculated using both of these and returned in a method, which
	//is what the damage calculation uses
{
private:
	status_effect_value m_current_pokemon_status =status_effect_value::NORMAL;
	Gen1_Pokemon gp;
	int attack_modifier = 1;
	int defence_modifier = 1;
	int speed_modifier = 1;
	int special_modifier = 1;
	int critical_modifier = 1;
public:
	Battle_Pokemon(const Gen1_Pokemon&);
	int modified_attack()const;
	int modified_defence();
	int modified_speed();
	int modified_special();
	int modified_critical();
	void show_battle_stats()const;
};

