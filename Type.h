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

	//CAN'T MAKE THIS STATIC FOR SOME REASON
	//TODO not using this at the moment
	//static const std::unordered_map<Type_Enum, std::string>map_type_name{
	//	{Type::Type_Enum::Normal,"Normal"},
	//	{Type::Type_Enum::Fighting,"Fighting"},
	//	{Type::Type_Enum::Flying,"Flying"},
	//	{Type::Type_Enum::Poison,"Poison"},
	//	{Type::Type_Enum::Ground,"Ground"},
	//	{Type::Type_Enum::Rock,"Rock"},
	//	{Type::Type_Enum::Bug,"Bug"},
	//	{Type::Type_Enum::Ghost,"Ghost"},
	//	{Type::Type_Enum::Fire,"Fire"},
	//	{Type::Type_Enum::Water,"Water"},
	//	{Type::Type_Enum::Grass,"Grass"},
	//	{Type::Type_Enum::Electric,"Electric"},
	//	{Type::Type_Enum::Psychic,"Psychic"},
	//	{Type::Type_Enum::Ice,"Ice"},
	//	{Type::Type_Enum::Dragon,"Dragon"}
	//};
	
	//The actual names of the types
	static const std::string type_name[16];
	//the string converter of the name
	static std::string get_type_name(Type_Enum& te);
};