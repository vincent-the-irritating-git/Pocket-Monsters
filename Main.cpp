#include "Type.h"
#include <iostream>
#include <unordered_map>
#include "Pokemon.h"
#include "Pokemon_Pokedex.h"

int main() {
	std::cout << "BUG vs NONE is " << *Type::BUG->get_matchup_value(type_properties::Type_Enum::NONE);
	std::cout << std::endl;
	std::cout << "BUG vs BUG is " << *Type::BUG->get_matchup_value(type_properties::Type_Enum::BUG);
}