#include "Move.h"

const std::array<std::string, 5> Status_Change::stat_names{ "HP","Attack","Defence","Speed","Special" };

std::string Status_Change::get_status_change_names(Status_Change::status_change sc) {
	return stat_names[static_cast<int>(sc)];
}

Status_Effect::Status_Effect(Status_Effect::status_effect status, double chance) :m_status_effect(status),m_chance(chance) {
	m_status_effect = status;
	m_chance = chance;
}

Status_Change::Status_Change(Status_Change::status_change status, int stages): m_status_change(status), m_stages(stages)
{
	m_status_change = status;
	m_stages = stages;
	printf("Status change: %s\nStages: %d\n", get_status_change_names(Status_Change::m_status_change).c_str(), Status_Change::m_stages);
}

Move::Move(std::string name, int pp, int accuracy, Type::Type_Enum type) : m_name(name), m_pp(pp), m_accuracy(accuracy), m_type(type) {
	m_name = name;
	m_pp = pp;
	m_accuracy = accuracy;
	m_type = type;
	printf("Move: %s\nPP: %d\nAccuracy: %d\n",m_name.c_str(),m_pp,m_accuracy);
	std::cout << std::endl;
}

Attack_Move::Attack_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, int power):Move(name,pp,accuracy,type),m_power(power){
	m_power = power;
	std::cout <<"Power: " << power << std::endl;
}

Defence_Move::Defence_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, Status_Change status) : Move(name, pp, accuracy, type), m_status(status) {
	m_status = status;
}