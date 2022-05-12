#include "Type.h"
#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <unordered_map>
#include "Battle_Pokemon.h"
#include "Pokedex.h"
#include "Battle_Event.h"

using namespace status_and_stats;


	Status_Effect_Attack_Move thundershock("Thunder Shock", 30, 100, Type::Type_Enum::ELECTRIC, 40, Status_Effect_Change(status_effect_value::PARALYSIS, 10));
	Defence_Move defence_curl("Defence Curl", 40, 100, Type::Type_Enum::NORMAL, Stats_Change(status_and_stats::stats_value::DEFENCE, 1));
	Move* m = &thundershock;

	std::unordered_map<std::string,std::shared_ptr<Move>>mm{
		{thundershock.m_name, std::make_shared<Status_Effect_Attack_Move>(thundershock)},
		{defence_curl.m_name, std::make_shared<Defence_Move>(defence_curl)}
	};

std::shared_ptr<Move>get_move(std::string s) {
	return mm.at(s);
}
int main() {
	std::shared_ptr<Move> m = get_move(defence_curl.m_name);
	m->show_move_values();
	m = get_move(thundershock.m_name);
	m->show_move_values();
	std::cout << m;
	//get_move(defence_curl.m_name).get()->show_move_values();
	//get_move(thundershock.m_name).get()->show_move_values();
	//mm.at(thundershock.m_name)->show_move_values();
	//mm.at(defence_curl.m_name)->show_move_values();
	//std::cout<<sizeof(mm.at(thundershock.m_name));
	//std::cout << std::endl;
	//std::cout<<sizeof(mm.at(defence_curl.m_name));

	return 0;
}