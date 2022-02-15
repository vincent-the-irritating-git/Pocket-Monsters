#include "Battle_Pokemon.h"

Battle_Pokemon::Battle_Pokemon(Gen1_Pokemon& pokemon){
	//TODO get pokemon reference's stats
	
}

Battle_Pokemon::Battle_Pokemon(Gen2_Pokemon& pokemon){

}

void Battle_Pokemon::show_battle_stats(){
	for (auto x : m_battle_stats) {
		std::cout << get_stats_value_names(x.first) << "\t" << x.second << std::endl;
	}
}