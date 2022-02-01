#include "Move.h"
#include <string>

const std::array<std::string, 5> Stats::stat_names{ "HP","Attack","Defence","Speed","Special" };
const std::array<std::string, 6> Status_Effect::effect_names{ "Normal","Paralysis","Burn","Poison","Freeze","Sleep" };

std::string Stats::get_stats_value_names() {
	return stat_names[static_cast<int>(m_stats_value)];
}

int Stats::get_stats_stages() {
	return m_stages;
}

Status_Effect::Status_Effect(Status_Effect::status_effect_value status, double chance) :m_status_effect(status),m_chance(chance) {
	m_status_effect = status;
	m_chance = chance;
}

std::string Status_Effect::get_status_effect_name() {
	return effect_names[static_cast<int>(m_status_effect)];
}

double Status_Effect::get_status_get_chance() {
	return m_chance;
}

Stats::Stats(Stats::stats_value status, int stages): m_stats_value(status), m_stages(stages)
{
	m_stats_value = status;
	m_stages = stages;
}

Stats::Stats() {};

Move::Move() {};

Move::Move(std::string name, int pp, int accuracy, Type::Type_Enum type) : m_name(name), m_pp(pp), m_accuracy(accuracy), m_type(type) {
	m_name = name;
	m_pp = pp;
	m_accuracy = accuracy;
	m_type = type;
	printf("Move: %s\nType: %s\nPP: %d\nAccuracy: %d\n",m_name.c_str(),Type::get_type_name(m_type).c_str(),m_pp,m_accuracy);
}

Attack_Move::Attack_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, int power):Move(name,pp,accuracy,type),m_power(power){
	m_power = power;
	std::cout <<"Power: " << power << std::endl;
}

Status_Effect_Attack_Move::Status_Effect_Attack_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, int power, Status_Effect stats_effect) :Attack_Move(name, pp, accuracy, type, power), m_status_effect(stats_effect){
	m_status_effect = stats_effect;
	std::cout << "Stats effect: " << m_status_effect.get_status_effect_name() << std::endl;
	std::cout << "Chance: " << m_status_effect.get_status_get_chance() << std::endl;
	std::cout << std::endl;
}

Stats_Value_Attack_Move::Stats_Value_Attack_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, int power, Stats stats_change) :Attack_Move(name, pp, accuracy, type, power), m_stats_value(stats_change) {
	m_stats_value = stats_change;
	std::cout << "Stats change: " << m_stats_value.get_stats_value_names() << std::endl;
	std::cout << "Stages changed: " << m_stats_value.get_stats_stages() << std::endl;
	std::cout << std::endl;
}

Defence_Move::Defence_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, Stats stats) : Move(name, pp, accuracy, type), m_stats_value(stats) {
	m_stats_value = stats;
	std::cout << "Stats change: " << m_stats_value.get_stats_value_names()<<std::endl;
	std::cout << "Stages changed: " << m_stats_value.get_stats_stages() << std::endl;
	std::cout << std::endl;
}