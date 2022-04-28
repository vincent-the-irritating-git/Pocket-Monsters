#include "Type.h"

const std::string Type::type_name[16]{ "", "Normal", "Fighting", "Flying", "Poison", "Ground", "Rock", "Bug", "Ghost", "Fire", "Water", "Grass", "Electric", "Psychic", "Ice", "Dragon" };

std::shared_ptr<Type::Type_Enum>Type::NONE_TYPE_POINTER = std::make_shared<Type::Type_Enum>(Type::Type_Enum::NONE);

std::unordered_map< std::shared_ptr<Type::Type_Enum>, std::unordered_map<std::shared_ptr<Type::Type_Enum>, double> >Type::ATTACK_MATCHUPS{
	{Type::NONE_TYPE_POINTER, Type::NONE_ATTACK_MATCHUPS}
};
	
std::unordered_map< std::shared_ptr<Type::Type_Enum>, double >Type::NONE_ATTACK_MATCHUPS{
	{Type::NONE_TYPE_POINTER, 1.00}
};
std::string Type::get_type_name(const Type_Enum& te) {
	return type_name[static_cast<int>(te)];
}