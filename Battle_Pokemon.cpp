#include "Battle_Pokemon.h"

Battle_Pokemon::Battle_Pokemon(Pokemon& pokemon){
	//TODO get pokemon reference's stats
}

void Battle_Pokemon::show_battle_stats(){
	for (auto x : m_battle_stats) {
		std::cout << get_stats_value_names(x.first) << "\t" << x.second << std::endl;
	}
}