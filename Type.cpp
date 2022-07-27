#include "Type.h"

namespace {
	namespace effectiveness_constants {
		Effectiveness_Data UNEFFECTIVE("UNEFFECTIVE", 0.00f);
		Effectiveness_Data NOT_VERY_EFFECTIVE("NOT VERY EFFECTIVE", 0.5f);
		Effectiveness_Data NEUTRAL("NEUTRAL", 1.00f);
		Effectiveness_Data SUPER_EFFECTIVE("SUPER EFFECTIVENESS", 2.00f);
	}
}

Effectiveness_Data* Effectiveness::UNEFFECTIVE = &effectiveness_constants::UNEFFECTIVE;
Effectiveness_Data* Effectiveness::NOT_VERY_EFFECTIVE = &effectiveness_constants::NOT_VERY_EFFECTIVE;
Effectiveness_Data* Effectiveness::NEUTRAL = &effectiveness_constants::NEUTRAL;
Effectiveness_Data* Effectiveness::SUPER_EFFECTIVE = &effectiveness_constants::SUPER_EFFECTIVE;

namespace {
	namespace bug_type {
		std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>BUG_ATTACKING_MAP{
			{type_properties::Type_Enum::NONE, Effectiveness::NEUTRAL},
			{type_properties::Type_Enum::BUG, Effectiveness::NEUTRAL}
		};
		std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>BUG_DEFENDING_MAP{
			{type_properties::Type_Enum::NONE, Effectiveness::NEUTRAL},
			{type_properties::Type_Enum::BUG, Effectiveness::NEUTRAL}
		};
		Type_Data BUG(type_properties::Type_Enum::BUG, type_properties::Classification::PHYSICAL, BUG_ATTACKING_MAP, BUG_DEFENDING_MAP);
	}
	namespace electric_type {
		std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>ELECTRIC_ATTACKING_MAP{
		{type_properties::Type_Enum::NONE, Effectiveness::NEUTRAL},
		{type_properties::Type_Enum::BUG, Effectiveness::NEUTRAL}
		};
		std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>ELECTRIC_DEFENDING_MAP{
			{type_properties::Type_Enum::NONE, Effectiveness::NEUTRAL},
			{type_properties::Type_Enum::BUG, Effectiveness::NEUTRAL}
		};
		Type_Data ELECTRIC(type_properties::Type_Enum::ELECTRIC, type_properties::Classification::SPECIAL, ELECTRIC_ATTACKING_MAP, ELECTRIC_DEFENDING_MAP);
	}
	namespace none_type {
		std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>NONE_ATTACKING_MAP{
		{type_properties::Type_Enum::NONE, Effectiveness::NEUTRAL},
		{type_properties::Type_Enum::BUG, Effectiveness::NEUTRAL}
		};
		std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>NONE_DEFENDING_MAP{
			{type_properties::Type_Enum::NONE, Effectiveness::NEUTRAL},
			{type_properties::Type_Enum::BUG, Effectiveness::NEUTRAL}
		};
		Type_Data NONE(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL, NONE_ATTACKING_MAP, NONE_DEFENDING_MAP);
	}
	namespace types {
		Type_Data FIRE(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
		Type_Data GHOST(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
		Type_Data PSYCHIC(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
		Type_Data WATER(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
		Type_Data GRASS(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
		Type_Data POISON(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
		Type_Data FLYING(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
		Type_Data FIGHTING(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
		Type_Data ROCK(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
		Type_Data GROUND(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
		Type_Data DRAGON(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
		Type_Data ICE(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
	}
	namespace normal_type {
		std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>NORMAL_ATTACKING_MAP{
		{type_properties::Type_Enum::NONE, Effectiveness::NEUTRAL},
		{type_properties::Type_Enum::BUG, Effectiveness::NEUTRAL}
		};
		std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>NORMAL_DEFENDING_MAP{
			{type_properties::Type_Enum::NONE, Effectiveness::NEUTRAL},
			{type_properties::Type_Enum::BUG, Effectiveness::NEUTRAL}
		};
		Type_Data NORMAL(type_properties::Type_Enum::NORMAL, type_properties::Classification::PHYSICAL, NORMAL_ATTACKING_MAP, NORMAL_DEFENDING_MAP);
	}
}

Type_Data* Type::ELECTRIC = &electric_type::ELECTRIC;
Type_Data* Type::NORMAL = &normal_type::NORMAL;
Type_Data* Type::BUG = &bug_type::BUG;
Type_Data* Type::NONE = &none_type::NONE;

std::ostream& type_properties::operator << (std::ostream& out, const type_properties::Type_Enum& te)
{
	out << type_properties::type_names.at(te);
	return out;
}

std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*> Type_Data::get_attack_matchups_map()
{
	return m_ATTACK_MATCHUPS;
}

std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*> Type_Data::get_defence_matchups_map()
{
	return m_DEFENCE_MATCHUPS;
}

Type_Data::Type_Data(type_properties::Type_Enum type, type_properties::Classification classification) :m_type(type), m_classification(classification) {
	m_type = type;
	m_classification = classification;
}

Type_Data::Type_Data(type_properties::Type_Enum type, type_properties::Classification classification, std::unordered_map <type_properties::Type_Enum, Effectiveness_Data*> map, std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>d_map) : m_type(type), m_classification(classification), m_ATTACK_MATCHUPS(map), m_DEFENCE_MATCHUPS(d_map) {
	m_type = type;
	m_classification = classification;
	m_ATTACK_MATCHUPS = map;
	m_DEFENCE_MATCHUPS = d_map;
}

type_properties::Type_Enum Type_Data::get_type()const
{
	return m_type;
}

type_properties::Classification Type_Data::get_classification()const {
	return m_classification;
}

std::string Type_Data::get_type_name()const
{
	try {
		return type_properties::type_names.at(this->get_type());
	}
	catch (std::exception e) {
		std::cout << e.what()<<std::endl;
		std::cerr << "No type name found!" << std::endl;
		}
}

bool Type_Data::operator==(std::shared_ptr<Type_Data>t)
{
	if (t.get() == this)
		return true;
	return false;
}

static bool type_properties::is_Classification_physical(type_properties::Classification tc) {
	if (static_cast<int>(tc) == 0)
		return true;
	else return false;
}

Effectiveness_Data* Type_Data::get_matchup_value(type_properties::Type_Enum defending_type)
{
	return this->get_attack_matchups_map().at(defending_type);
}

Effectiveness_Data::Effectiveness_Data(std::string name, float effectiveness) :m_name(name), m_effectiveness(effectiveness) {
	m_name = name;
	m_effectiveness = effectiveness;
}

std::string Effectiveness_Data::get_name()
{
	return m_name;
}

float Effectiveness_Data::get_effectiveness()
{
	return m_effectiveness;
}

std::ostream& Effectiveness_Data::operator<<(std::ostream& out)
{
	out << this->m_name;
	return out;
}