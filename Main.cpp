#include "Type.h"
#include <iostream>
#include <unordered_map>
#include "Pokemon.h"
#include "Pokemon_Pokedex.h"
#include "Constants.h"
#include "Stats_n_Status.h"
#include "Move.h"
#include "Move_Pokedex.h"
#include "Battle_Pokemon.h"

int main() {
	std::cout << "BUG vs NONE is " << *Type::BUG->get_matchup_value(type_properties::Type_Enum::NONE);
	std::cout << std::endl;
	std::cout << "BUG vs BUG is " << *Type::BUG->get_matchup_value(type_properties::Type_Enum::BUG)<<std::endl;
	Pokemon_Pokedex::get_gen1_pokemon("Pikachu").show_base_stats();
	std::cout<<std::boolalpha<<Move_Pokedex::is_move_in_map("Thunder Shock")<<std::endl;
	std::cout<<Move_Pokedex::get_gen1_moves("Thunder Shock")->m_type->get_matchup_value(Pokemon_Pokedex::get_gen1_pokemon("Pikachu").get_type1()->get_type())->get_effectiveness()<<std::endl;

	Battle_Pokemon phantom(Pokemon_Pokedex::get_gen1_pokemon(Pokemon_names::PIKACHU));
	std::cout<<phantom.get_battle_pokemon_name()<<std::endl;
	phantom.show_battle_stats();
	phantom.DEBUG_set_status(status_and_stats::status_effect_value::PARALYSIS);
	std::cout << phantom.get_status_effect()<<std::endl<<phantom.get_stun_chance();
}