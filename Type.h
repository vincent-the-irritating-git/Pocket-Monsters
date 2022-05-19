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

}

struct Effectiveness {
	float m_effectiveness;
	Effectiveness(float f);
};

class Type {
private:
	type_properties::Classification m_classification;
	type_properties::Type_Enum m_type;
	//std::unordered_map<type_properties::Type_Enum, Effectiveness>m_ATTACK_MATCHUPS;
	//std::unordered_map<type_properties::Type_Enum, Effectiveness>m_DEFENCE_MATCHUPS;
public:
	Type(type_properties::Type_Enum, type_properties::Classification);
	type_properties::Type_Enum get_type()const;
	type_properties::Classification get_classification()const;
	std::string get_type_name() const;
};

namespace effectiveness {
	extern Effectiveness UNEFFECTIVE;
	extern Effectiveness NOT_VERY_EFFECTIVE;
	extern Effectiveness NEUTRAL;
	extern Effectiveness SUPER_EFFECTIVE;
}

namespace types {

	extern Type NONE;
	extern Type NORMAL;
	extern Type FIRE;
	extern Type ELECTRIC;
	extern Type GHOST;
	extern Type PSYCHIC;
	extern Type WATER;
	extern Type GRASS;
	extern Type POISON;
	extern Type BUG;
	extern Type FLYING;
	extern Type FIGHTING;
	extern Type ROCK;
	extern Type GROUND;
	extern Type DRAGON;
	extern Type ICE;
}