#pragma once
#include <iostream>
#include <unordered_map>
#include <array>

namespace type_properties {

	static enum class Type_Enum
	{
		NONE, NORMAL, FIGHTING, FLYING, POISON, GROUND, ROCK, BUG, GHOST, FIRE, WATER, GRASS, ELECTRIC, PSYCHIC, ICE, DRAGON
	};

	static enum class Classification {
		PHYSICAL, SPECIAL
	};

	static std::unordered_map<type_properties::Type_Enum, std::string>type_names{
	{type_properties::Type_Enum::BUG, "BUG"},
	{type_properties::Type_Enum::NONE, "NONE"},
	{type_properties::Type_Enum::ELECTRIC, "ELECTRIC" }
	};

	extern std::ostream& operator << (std::ostream& out, const type_properties::Type_Enum& te);
}

class Type_Data {
private:
	type_properties::Classification m_classification;
	type_properties::Type_Enum m_type;
	std::unordered_map<type_properties::Type_Enum, std::shared_ptr<float>>m_ATTACK_MATCHUPS;
	std::unordered_map<type_properties::Type_Enum, std::shared_ptr<float>>m_DEFENCE_MATCHUPS;
public:
	Type_Data(type_properties::Type_Enum, type_properties::Classification);
	Type_Data(type_properties::Type_Enum, type_properties::Classification, std::unordered_map<type_properties::Type_Enum, std::shared_ptr<float>>, std::unordered_map<type_properties::Type_Enum, std::shared_ptr<float>>);
	std::unordered_map<type_properties::Type_Enum, std::shared_ptr<float>>get_attack_matchups_map();
	std::unordered_map<type_properties::Type_Enum, std::shared_ptr<float>>get_defence_matchups_map();
	type_properties::Type_Enum get_type()const;
	type_properties::Classification get_classification()const;
	std::string get_type_name() const;
	bool operator==(std::shared_ptr<Type_Data>t);
};

class Type{
public:
	static std::shared_ptr<Type_Data>BUG;
	static std::shared_ptr<Type_Data>NONE;
	static std::shared_ptr<Type_Data>NORMAL;
	static std::shared_ptr<Type_Data>ELECTRIC;
};

struct Effectiveness {
	static std::shared_ptr<float> UNEFFECTIVE;
	static std::shared_ptr<float> NOT_VERY_EFFECTIVE;
	static std::shared_ptr<float> NEUTRAL;
	static std::shared_ptr<float> SUPER_EFFECTIVE;
};