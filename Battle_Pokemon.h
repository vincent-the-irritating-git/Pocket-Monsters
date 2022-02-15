#pragma once
#include "Pokemon.h"

static class Battle_Pokemon
{
private:
	std::unordered_map<stats_value, int>m_battle_stats;
	status_effect_value m_current_pokemon_status =status_effect_value::NORMAL;
public:
	Battle_Pokemon(Gen1_Pokemon&);
	Battle_Pokemon(Gen2_Pokemon&);
	void show_battle_stats();
};

