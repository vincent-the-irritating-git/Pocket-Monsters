#include "Type.h"

Effectiveness::Effectiveness(float f) :m_effectiveness(f) {
	m_effectiveness = f;
}

extern Effectiveness effectiveness::UNEFFECTIVE = 0;
extern Effectiveness effectiveness::NOT_VERY_EFFECTIVE = 0.5;
extern Effectiveness effectiveness::NEUTRAL = 1;
extern Effectiveness effectiveness::SUPER_EFFECTIVE = 2;

extern Type types::NONE(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
extern Type types::BUG(type_properties::Type_Enum::BUG, type_properties::Classification::PHYSICAL);
extern Type types::NORMAL(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
extern Type types::FIRE(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
extern Type types::ELECTRIC(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
extern Type types::GHOST(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
extern Type types::PSYCHIC(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
extern Type types::WATER(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
extern Type types::GRASS(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
extern Type types::POISON(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
extern Type types::FLYING(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
extern Type types::FIGHTING(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
extern Type types::ROCK(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
extern Type types::GROUND(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
extern Type types::DRAGON(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
extern Type types::ICE(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);

Type::Type(type_properties::Type_Enum type, type_properties::Classification classification) :m_type(type), m_classification(classification) {
	m_type = type;
	m_classification = classification;
}

type_properties::Type_Enum Type::get_type()const
{
	return m_type;
}

type_properties::Classification Type::get_classification()const {
	return m_classification;
}

std::string Type::get_type_name()const
{
	return "DEFAULT";
}