#include "Battle_Pokemon.h"

//don't think this works very well, need to reconsider it
//doesn't work at all at the moment
//pointer is the problem
//think it's because it's pointing to a deleted object
Battle_Pokemon::Battle_Pokemon(const Gen1_Pokemon& pokemon) {
	int x = pokemon.get_m_stats().at(stats_value::ATTACK);
	std::cout << x<<std::endl;
	gp = pokemon;
	std::cout <<"gp value is "<< gp.get_m_stats().at(stats_value::ATTACK) << std::endl;
}

int Battle_Pokemon::modified_attack()const
{
	return gp.get_m_stats().at(stats_value::ATTACK) * attack_modifier;
}

int Battle_Pokemon::modified_defence()
{
	return 0;
}

int Battle_Pokemon::modified_speed()
{
	return 0;
}

int Battle_Pokemon::modified_special()
{
	return 0;
}

int Battle_Pokemon::modified_critical()
{
	return 0;
}

void Battle_Pokemon::show_battle_stats()const
{
	std::cout <<"modified attack is "<< modified_attack();
}
