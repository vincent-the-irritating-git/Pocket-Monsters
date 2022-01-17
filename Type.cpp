#include "Type.h"

//the array of the names of the types
const std::string Type::type_name[16]{ "", "Normal", "Fighting", "Flying", "Poison", "Ground", "Rock", "Bug", "Ghost", "Fire", "Water", "Grass", "Electric", "Psychic", "Ice", "Dragon" };
//the data for the type attacking effectiveness
const std::array<double, 16>NORMAL_ATTACK{ 1,1,1,1,1,1,0.5,1,0,1,1,1,1,1,1,1 };
//the data for the type defending effectiveness
const std::array<double, 16>NORMAL_DEFENCE{ 1,1,2,1,1,1,1,1,0,1,1,1,1,1,1,1 };
//the map of attack type effectiveness
const std::unordered_map < Type::Type_Enum, std::array<double, 16>>type_attack_map{
	{Type::Type_Enum::Normal,NORMAL_ATTACK}
};
//the map of defence type effectiveness
const std::unordered_map < Type::Type_Enum, std::array<double, 16>>type_defence_map{
	{Type::Type_Enum::Normal,NORMAL_DEFENCE}
};
//the function to convert the type_enum to a string
std::string Type::get_type_name(Type_Enum te) {
	return type_name[static_cast<int>(te)];
}