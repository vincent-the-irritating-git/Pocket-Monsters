#include "Move.h"
#include <string>

using namespace status_and_stats;

Move::Move() {};

Move::Move(std::string name, int pp, int accuracy, Type::Type_Enum type) : m_name(name), m_pp(pp), m_accuracy(accuracy), m_type(type) {
	m_name = name;
	m_pp = pp;
	m_accuracy = accuracy;
	m_type = type;
}

Attack_Move::Attack_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, int power):Move(name,pp,accuracy,type),m_power(power){
	m_power = power;
}

void Attack_Move::show_move_values() {
	printf("Move: %s\nType: %s\nPP: %d\nAccuracy: %d\nPower: %d\n", m_name.c_str(), Type::get_type_name(m_type).c_str(), m_pp, m_accuracy,m_power);
	std::cout << std::endl;
}

Status_Effect_Attack_Move::Status_Effect_Attack_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, int power, Status_Effect_Change stats_effect) :Attack_Move(name, pp, accuracy, type, power), m_status_effect_change(stats_effect){
	is_status_inflicting = true;
	m_status_effect_change = stats_effect;
}

void Status_Effect_Attack_Move::show_move_values() {
	std::cout << "Move: " << m_name << std::endl;
	std::cout << "Type: " << Type::get_type_name(m_type) << std::endl;
	std::cout << "PP " << m_pp << std::endl;
	std::cout << "Accuracy " << m_accuracy << std::endl;
	std::cout << "Power: " << m_power << std::endl;
	std::cout << "Status effect: " << m_status_effect_change.get_status_effect_name() << std::endl;
	std::cout << "Chance: " << m_status_effect_change.get_status_get_chance() << std::endl;
	std::cout << std::endl;
}

Stats_Value_Attack_Move::Stats_Value_Attack_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, int power, Stats_Change stats_change) :Attack_Move(name, pp, accuracy, type, power), m_stats_change(stats_change) {
	is_stats_changing = true;
	m_stats_change = stats_change;
}

void Stats_Value_Attack_Move::show_move_values() {
	std::cout << "Move: " << m_name << std::endl;
	std::cout << "Type: " << Type::get_type_name(m_type) << std::endl;
	std::cout << "PP " << m_pp << std::endl;
	std::cout << "Accuracy " << m_accuracy << std::endl;
	std::cout << "Power: " << m_power << std::endl;
	std::cout << "Stats change: " << m_stats_change.get_stats_value() << std::endl;
	std::cout << "Stages changed: " << m_stats_change.get_stats_stages() << std::endl;
	std::cout << std::endl;
}

Defence_Move::Defence_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, Stats_Change stats) : Move(name, pp, accuracy, type), m_stats_change(stats) {
	is_target_enemy = false;
	is_stats_changing = true;
	m_stats_change = stats;
}

void Defence_Move::show_move_values() {
	std::cout << "Move: " << m_name << std::endl;
	std::cout << "Type: " << Type::get_type_name(m_type) << std::endl;
	std::cout << "PP " << m_pp << std::endl;
	std::cout << "Accuracy " << m_accuracy << std::endl;
	std::cout << "Stats change: " << m_stats_change.get_stats_value() << std::endl;
	std::cout << "Stages changed: " << m_stats_change.get_stats_stages() << std::endl;
	std::cout << std::endl;
}

bool Move::operator==(const Move& other)const {
	if (this == &other)
		return true;
	else
		return false;
}