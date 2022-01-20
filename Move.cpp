#include "Move.h"
#include <string>

const std::array<std::string, 5> Status_Change::stat_names{ "HP","Attack","Defence","Speed","Special" };

std::string Status_Change::get_status_change_names() {
	return stat_names[static_cast<int>(m_status_change)];
}

std::string Status_Change::get_status_stages() {
	return std::to_string(m_stages);
}

Status_Effect::Status_Effect(Status_Effect::status_effect status, double chance) :m_status_effect(status),m_chance(chance) {
	m_status_effect = status;
	m_chance = chance;
}

Status_Change::Status_Change(Status_Change::status_change status, int stages): m_status_change(status), m_stages(stages)
{
	m_status_change = status;
	m_stages = stages;
}

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
	std::cout << std::endl;
}

Attack_Move_Stats_Effect::Attack_Move_Stats_Effect(std::string name, int pp, int accuracy, Type::Type_Enum type, int power, Status_Effect::status_effect stats_effect) :Attack_Move(name, pp, accuracy, type, power), m_stats(stats_effect){
	m_stats = stats_effect;
	std::cout << "Stats effect: " << m_stats << std::endl;
}

Defence_Move::Defence_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, Status_Change status) : Move(name, pp, accuracy, type), m_status(status) {
	m_status = status;
	std::cout << "Status change: " << m_status.get_status_change_names()<<std::endl;
	std::cout << "Stages changed: " << m_status.get_status_stages() << std::endl;
	std::cout << std::endl;
}