#pragma once
#include "Pokemon.h"

class Battle_Pokemon
{
	std::unordered_map<stats_value, int>battle_stats;
	status_effect_value current_status_effect=status_effect_value::NORMAL;
	Battle_Pokemon(std::unordered_map<stats_value,int>);
};

