#pragma once
#include <iostream>
#include <unordered_map>
#include <array>

struct Type {
	static const enum class Type_Enum
	{
		NONE, NORMAL, FIGHTING, FLYING, POISON, GROUND, ROCK, BUG, GHOST, FIRE, WATER, GRASS, ELECTRIC, PSYCHIC, ICE, DRAGON
	};

	static const int NUMBER_OF_TYPES = 16;

	static std::shared_ptr<Type::Type_Enum>TYPE_POINTER;
	static std::shared_ptr<Type::Type_Enum>NONE_TYPE_POINTER;

	static std::unordered_map < std::shared_ptr<Type::Type_Enum>, std::unordered_map<std::shared_ptr<Type::Type_Enum>, double> > ATTACK_MATCHUPS;
	static std::unordered_map < std::shared_ptr<Type::Type_Enum>, double > NONE_ATTACK_MATCHUPS;

	//The actual names of the types
	static const std::string type_name[NUMBER_OF_TYPES];
	//the string converter of the name
	static std::string get_type_name(const Type_Enum& te);
};