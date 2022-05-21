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

class Type_Data {
private:
	type_properties::Classification m_classification;
	type_properties::Type_Enum m_type;
	//std::unordered_map<type_properties::Type_Enum, Effectiveness>m_ATTACK_MATCHUPS;
	//std::unordered_map<type_properties::Type_Enum, Effectiveness>m_DEFENCE_MATCHUPS;
public:
	Type_Data(type_properties::Type_Enum, type_properties::Classification);
	type_properties::Type_Enum get_type()const;
	type_properties::Classification get_classification()const;
	std::string get_type_name() const;
	bool operator==(std::shared_ptr<Type_Data>t);
};

class Type {
public:
	static std::shared_ptr<Type_Data>BUG;
	static std::shared_ptr<Type_Data>NONE;
};

struct Effectiveness {
	static std::shared_ptr<float> UNEFFECTIVE;
	static std::shared_ptr<float> NOT_VERY_EFFECTIVE;
	static std::shared_ptr<float> NEUTRAL;
	static std::shared_ptr<float> SUPER_EFFECTIVE;
};