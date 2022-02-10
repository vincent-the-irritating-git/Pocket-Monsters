#pragma once
#include "Pokemon.h"

static class Battle_Pokemon
{
private:
	std::unordered_map<stats_value, int>m_battle_stats;
	status_effect_value m_current_status_effect=status_effect_value::NORMAL;
	Battle_Pokemon(Pokemon&);
	void show_battle_stats();
};

