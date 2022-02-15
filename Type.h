#pragma once
#include <iostream>
#include <unordered_map>
#include <array>

struct Type {
	//type attacking arrays
	static const std::array<double, 16>NORMAL_ATTACK;
	//type defending arrays
	static const std::array<double, 16>NORMAL_DEFENCE;
	//the Type enum
	enum class Type_Enum
	{
		NONE, Normal, Fighting, Flying, Poison, Ground, Rock, Bug, Ghost, Fire, Water, Grass, Electric, Psychic, Ice, Dragon
	};
	//map of type attacking effectiveness
	static const std::unordered_map<Type_Enum, std::array<double, 16>>type_attack_map;
	//map of type defending effectiveness
	static const std::unordered_map<Type_Enum, std::array<double,16>>type_defence_map;
	//The actual names of the types
	static const std::string type_name[16];
	//the string converter of the name
	static std::string get_type_name(Type_Enum& te);
};