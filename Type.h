#pragma once
#include <iostream>
#include <unordered_map>
#include <array>

struct Type {
	static enum class Type_Enum
	{
		NONE, NORMAL, FIGHTING, FLYING, POISON, GROUND, ROCK, BUG, GHOST, FIRE, WATER, GRASS, ELECTRIC, PSYCHIC, ICE, DRAGON
	};

	static const int NUMBER_OF_TYPES = 16;

	const static std::array<std::string, Type::NUMBER_OF_TYPES> type_name;

struct Effectiveness {
	float m_effectiveness;
	Effectiveness(float f);
};

	static std::unordered_map < std::shared_ptr<Type::Type_Enum>, std::unordered_map<std::shared_ptr<Type::Type_Enum>, double> > ATTACK_MATCHUPS;
	static std::unordered_map < std::shared_ptr<Type::Type_Enum>, double > NONE_ATTACK_MATCHUPS;

	static std::string get_type_name(const Type_Enum& te);
};