#include "Battle_Pokemon.h"

Battle_Pokemon::Battle_Pokemon(Gen1_Pokemon& pokemon){
	m_battle_stats = pokemon.get_stats_map();
}

Battle_Pokemon::Battle_Pokemon(Gen2_Pokemon& pokemon){
	//TODO do the same as gen1
}

void Battle_Pokemon::show_battle_stats(){
	for (auto x : m_battle_stats) {
		std::cout << get_stats_value_name(x.first) << "\t" << x.second << std::endl;
	}
}