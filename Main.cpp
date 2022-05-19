#include "Type.h"
#include <iostream>
#include <unordered_map>



//	Status_Effect_Attack_Move thundershock("Thunder Shock", 30, 100, Type::Type_Enum::ELECTRIC, 40, Status_Effect_Change(status_effect_value::PARALYSIS, 10));
//	Defence_Move defence_curl("Defence Curl", 40, 100, Type::Type_Enum::NORMAL, Stats_Change(status_and_stats::stats_value::DEFENCE, 1));
//	Move* m = &thundershock;
//
//	std::unordered_map<std::string,std::shared_ptr<Move>>mm{
//		{thundershock.m_name, std::make_shared<Status_Effect_Attack_Move>(thundershock)},
//		{defence_curl.m_name, std::make_shared<Defence_Move>(defence_curl)}
//	};
//
//std::shared_ptr<Move>get_move(std::string s) {
//	return mm.at(s);
//}
int main() {
	
	std::cout<<types::BUG.get_type_name()<<std::endl;
	return 0;
}