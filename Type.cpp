#include "Type.h"

namespace {
	namespace effectiveness_constants {
		Effectiveness_Data UNEFFECTIVE("UNEFFECTIVE", 0.00f);
		Effectiveness_Data NOT_VERY_EFFECTIVE("NOT VERY EFFECTIVE", 0.5f);
		Effectiveness_Data NEUTRAL("NEUTRAL", 1.00f);
		Effectiveness_Data SUPER_EFFECTIVE("SUPER EFFECTIVE", 2.00f);
	}

	namespace none_type {
		using namespace type_properties;
		using namespace Effectiveness;
		std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>NONE_ATTACKING_MAP{
			{Type_Enum::NONE, &NEUTRAL},
			{Type_Enum::NORMAL, &NEUTRAL},
			{Type_Enum::FIRE, &NEUTRAL},
			{Type_Enum::WATER, & NEUTRAL},
			{Type_Enum::ELECTRIC, &NEUTRAL},
			{Type_Enum::GRASS, &NEUTRAL},
			{Type_Enum::ICE, &NEUTRAL},
			{Type_Enum::FIGHTING, &NEUTRAL},
			{Type_Enum::POISON, &NEUTRAL},
			{Type_Enum::GROUND, &NEUTRAL},
			{Type_Enum::FLYING, &NEUTRAL},
			{Type_Enum::PSYCHIC, &NEUTRAL},
			{Type_Enum::BUG, &NEUTRAL},
			{Type_Enum::ROCK, &NEUTRAL},
			{Type_Enum::GHOST, &NEUTRAL },
			{Type_Enum::DRAGON, &NEUTRAL }
		};
		Type_Data NONE(type_properties::Type_Enum::NONE, type_properties::Classification::PHYSICAL, NONE_ATTACKING_MAP);
	}
	namespace normal_type {
		using namespace type_properties;
		using namespace Effectiveness;
		std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>NORMAL_ATTACKING_MAP{
			{Type_Enum::NONE, &NEUTRAL},
			{Type_Enum::NORMAL, &NEUTRAL},
			{Type_Enum::FIRE, &NEUTRAL},
			{Type_Enum::WATER, &NEUTRAL},
			{Type_Enum::ELECTRIC, &NEUTRAL},
			{Type_Enum::GRASS, &NEUTRAL},
			{Type_Enum::ICE, &NEUTRAL},
			{Type_Enum::FIGHTING, &NEUTRAL},
			{Type_Enum::POISON, &NEUTRAL},
			{Type_Enum::GROUND, &NEUTRAL},
			{Type_Enum::FLYING, &NEUTRAL},
			{Type_Enum::PSYCHIC, &NEUTRAL},
			{Type_Enum::BUG, &NEUTRAL},
			{Type_Enum::ROCK, &NOT_VERY_EFFECTIVE},
			{Type_Enum::GHOST, &UNEFFECTIVE },
			{Type_Enum::DRAGON, &NEUTRAL }
		};
		Type_Data NORMAL(type_properties::Type_Enum::NORMAL, type_properties::Classification::PHYSICAL, NORMAL_ATTACKING_MAP);
	}
	namespace electric_type {
		using namespace type_properties;
		using namespace Effectiveness;
		std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>ELECTRIC_ATTACKING_MAP{
			{Type_Enum::NONE, &NEUTRAL},
			{Type_Enum::NORMAL, &NEUTRAL},
			{Type_Enum::FIRE, &NEUTRAL},
			{Type_Enum::WATER, &SUPER_EFFECTIVE},
			{Type_Enum::ELECTRIC, &NOT_VERY_EFFECTIVE},
			{Type_Enum::GRASS, &NOT_VERY_EFFECTIVE},
			{Type_Enum::ICE, &NEUTRAL},
			{Type_Enum::FIGHTING, &NEUTRAL},
			{Type_Enum::POISON, &NEUTRAL},
			{Type_Enum::GROUND, &UNEFFECTIVE},
			{Type_Enum::FLYING, &SUPER_EFFECTIVE},
			{Type_Enum::PSYCHIC, &NEUTRAL},
			{Type_Enum::BUG, &NEUTRAL},
			{Type_Enum::ROCK, &NOT_VERY_EFFECTIVE},
			{Type_Enum::GHOST, &NEUTRAL },
			{Type_Enum::DRAGON, &NOT_VERY_EFFECTIVE }
		};
		Type_Data ELECTRIC(type_properties::Type_Enum::ELECTRIC, type_properties::Classification::SPECIAL, ELECTRIC_ATTACKING_MAP);
	}
	namespace bug_type {
		using namespace type_properties;
		using namespace Effectiveness;
		std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>BUG_ATTACKING_MAP{
			{Type_Enum::NONE, &NEUTRAL},
			{Type_Enum::NORMAL, &NEUTRAL},
			{Type_Enum::FIRE, &NOT_VERY_EFFECTIVE},
			{Type_Enum::WATER, &NEUTRAL},
			{Type_Enum::ELECTRIC, &NEUTRAL},
			{Type_Enum::GRASS, &SUPER_EFFECTIVE},
			{Type_Enum::ICE, &NEUTRAL},
			{Type_Enum::FIGHTING, &NOT_VERY_EFFECTIVE},
			{Type_Enum::POISON, &SUPER_EFFECTIVE},
			{Type_Enum::GROUND, &NEUTRAL},
			{Type_Enum::FLYING, &NOT_VERY_EFFECTIVE},
			{Type_Enum::PSYCHIC, &SUPER_EFFECTIVE},
			{Type_Enum::BUG, &NEUTRAL},
			{Type_Enum::ROCK, &NEUTRAL},
			{Type_Enum::GHOST, &NOT_VERY_EFFECTIVE },
			{Type_Enum::DRAGON, &NEUTRAL }
		};
		Type_Data BUG(type_properties::Type_Enum::BUG, type_properties::Classification::PHYSICAL, BUG_ATTACKING_MAP);
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
}

Effectiveness_Data& Effectiveness::UNEFFECTIVE = effectiveness_constants::UNEFFECTIVE;
Effectiveness_Data& Effectiveness::NOT_VERY_EFFECTIVE = effectiveness_constants::NOT_VERY_EFFECTIVE;
Effectiveness_Data& Effectiveness::NEUTRAL = effectiveness_constants::NEUTRAL;
Effectiveness_Data& Effectiveness::SUPER_EFFECTIVE = effectiveness_constants::SUPER_EFFECTIVE;

Type_Data& Type::ELECTRIC = electric_type::ELECTRIC;
Type_Data& Type::NORMAL = normal_type::NORMAL;
Type_Data& Type::BUG = bug_type::BUG;
Type_Data& Type::NONE = none_type::NONE;

std::ostream& type_properties::operator << (std::ostream& out, const type_properties::Type_Enum& te)
{
	out << type_properties::type_names.at(te);
	return out;
}

std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*> Type_Data::get_attack_matchups_map()
{
	return m_ATTACK_MATCHUPS;
}

Type_Data::Type_Data(type_properties::Type_Enum type, type_properties::Classification classification) :m_type(type), m_classification(classification) {
	m_type = type;
	m_classification = classification;
}

Type_Data::Type_Data(type_properties::Type_Enum type, type_properties::Classification classification, std::unordered_map <type_properties::Type_Enum, Effectiveness_Data*> map): m_type(type), m_classification(classification), m_ATTACK_MATCHUPS(map){
	m_type = type;
	m_classification = classification;
	m_ATTACK_MATCHUPS = map;
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

bool Type_Data::operator==(Type_Data* t) const
{
	if (t == this)
		return true;
	return false;
}

bool Type_Data::is_Classification_physical() {
	if (static_cast<int>(this->m_classification) == 0)
		return true;
	else return false;
}

Effectiveness_Data& Type_Data::get_matchup_value(type_properties::Type_Enum defending_type)
{
	try {
		return *(this->get_attack_matchups_map().at(defending_type));
	}
	catch (std::exception e) {
		std::cout <<"No type matchup found!"<<std::endl<< e.what()<<std::endl;
	}
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

std::ostream& operator<<(std::ostream& out, const Effectiveness_Data& ed)
{
	out << ed.m_name;
	return out;
}