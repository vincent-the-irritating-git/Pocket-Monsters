#include "Type.h"

bool Type_Data::operator==(std::shared_ptr<Type_Data>t)
{
	if (t.get() == this)
		return true;
	return false;
}

std::shared_ptr<float> Effectiveness::UNEFFECTIVE=std::make_shared<float>(0);
std::shared_ptr<float> Effectiveness::NOT_VERY_EFFECTIVE = std::make_shared<float>(0.5);
std::shared_ptr<float> Effectiveness::NEUTRAL = std::make_shared<float>(1);
std::shared_ptr<float> Effectiveness::SUPER_EFFECTIVE = std::make_shared<float>(2);

namespace types {
	Type_Data NONE(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
	Type_Data BUG(type_properties::Type_Enum::BUG, type_properties::Classification::PHYSICAL);
	Type_Data NORMAL(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
	Type_Data FIRE(type_properties::Type_Enum::NONE, type_properties::Classification::SPECIAL);
	Type_Data ELECTRIC(type_properties::Type_Enum::ELECTRIC, type_properties::Classification::SPECIAL);
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
	
	std::unordered_map<type_properties::Type_Enum, std::string>type_names{
	{type_properties::Type_Enum::BUG, "BUG"},
	{type_properties::Type_Enum::NONE, "NONE"},
	{type_properties::Type_Enum::ELECTRIC, "ELECTRIC" }
	};
}

std::shared_ptr<Type_Data>Type::BUG = std::make_shared<Type_Data>(types::BUG);
std::shared_ptr<Type_Data>Type::NONE = std::make_shared<Type_Data>(types::NONE);


Type_Data::Type_Data(type_properties::Type_Enum type, type_properties::Classification classification) :m_type(type), m_classification(classification) {
	m_type = type;
	m_classification = classification;
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
		return types::type_names.at(this->get_type());
	}
	catch (std::exception e) {
		std::cout << e.what()<<std::endl;
		std::cerr << "No type name found!" << std::endl;
		}
}