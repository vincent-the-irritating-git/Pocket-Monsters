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

		extern bool is_Classification_physical(type_properties::Classification tc);
		extern std::ostream& operator << (std::ostream& out, const type_properties::Type_Enum& te);
	}

class Effectiveness_Data {
private:
	std::string m_name;
	float m_effectiveness;
public:
	Effectiveness_Data(std::string name, float effectiveness);
	std::string get_name();
	float get_effectiveness();
	friend std::ostream& operator<<(std::ostream& out, const Effectiveness_Data& ed);
};

namespace Effectiveness {
	extern Effectiveness_Data* UNEFFECTIVE;
	extern Effectiveness_Data* NOT_VERY_EFFECTIVE;
	extern Effectiveness_Data* NEUTRAL;
	extern Effectiveness_Data* SUPER_EFFECTIVE;
};

class Type_Data {
private:
	type_properties::Classification m_classification;
	type_properties::Type_Enum m_type;
	std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>m_ATTACK_MATCHUPS;
public:
	Type_Data(type_properties::Type_Enum, type_properties::Classification);
	Type_Data(type_properties::Type_Enum, type_properties::Classification, std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>);
	std::unordered_map<type_properties::Type_Enum, Effectiveness_Data*>get_attack_matchups_map();
	type_properties::Type_Enum get_type()const;
	type_properties::Classification get_classification()const;
	std::string get_type_name() const;
	bool operator==(Type_Data* t) const;
	Effectiveness_Data* get_matchup_value(type_properties::Type_Enum defending_type);
};

namespace Type{
	extern Type_Data* BUG;
	extern Type_Data* NONE;
	extern Type_Data* NORMAL;
	extern Type_Data* ELECTRIC;
};