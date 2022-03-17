#include "Type.h"

const std::string Type::type_name[16]{ "", "Normal", "Fighting", "Flying", "Poison", "Ground", "Rock", "Bug", "Ghost", "Fire", "Water", "Grass", "Electric", "Psychic", "Ice", "Dragon" };
const std::array<double, 16>NORMAL_ATTACK{ 1,1,1,1,1,1,0.5,1,0,1,1,1,1,1,1,1 };
const std::array<double, 16>NORMAL_DEFENCE{ 1,1,2,1,1,1,1,1,0,1,1,1,1,1,1,1 };
const std::unordered_map < Type::Type_Enum, std::array<double, 16>>type_attack_matrix{
	{Type::Type_Enum::Normal,NORMAL_ATTACK}
};
const std::unordered_map < Type::Type_Enum, std::array<double, 16>>type_defence_matrix{
	{Type::Type_Enum::Normal,NORMAL_DEFENCE}
};
std::string Type::get_type_name(const Type_Enum& te) {
	return type_name[static_cast<int>(te)];
}