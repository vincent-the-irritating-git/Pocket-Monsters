#include "Pokedex.h"

Defence_Move barrier("Barrier", 15, 100, Type::Type_Enum::Psychic, Stats_Change(stats_value::DEFENCE, 2));
Attack_Move tackle("Tackle", 35, 95, Type::Type_Enum::Normal, 30);
Status_Effect_Attack_Move poison_powder("Poison Powder", 15, 75, Type::Type_Enum::Poison, 0, Status_Effect_Change(status_effect_value::POISON, 100));
Stats_Value_Attack_Move growl("Growl", 40, 100, Type::Type_Enum::Normal, 0, Stats_Change(stats_value::ATTACK, 1));
Status_Effect_Attack_Move thundershock("Thunder Shock", 30, 100, Type::Type_Enum::Electric, 40, Status_Effect_Change(status_effect_value::PARALYSIS, 10));

Gen1_Pokemon bulbasaur(1, "Bulbasaur", Type::Type_Enum::Grass, Type::Type_Enum::Poison, Pokemon::Evolutions(2, 16), Gen1_Pokemon::Gen1_Stats(45, 49, 49, 65, 45));
Gen1_Pokemon pikachu(25, "Pikachu", Type::Type_Enum::Electric, Type::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(35, 55, 30, 50, 90));
Gen1_Pokemon alakazam(65, "Alakazam", Type::Type_Enum::Psychic, Type::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(55, 50, 45, 135, 120));
Gen1_Pokemon pinsir(127, "Pinsir", Type::Type_Enum::Bug, Type::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(65, 125, 100, 55, 85));


Pokedex::Pokedex() {
}

void Pokedex::load_moves_into_map() {
	Move_definitions_map.insert({ poison_powder.m_name,poison_powder });
	Move_definitions_map.insert({ growl.m_name,growl });
	Move_definitions_map.insert({ thundershock.m_name,thundershock });
	Move_definitions_map.insert({ barrier.m_name,barrier });
	Move_definitions_map.insert({ tackle.m_name,tackle });
}

void Pokedex::load_pokemon_into_map() {
	Gen1_pokemon_definitions_map.insert({ bulbasaur.get_pokemon_name(), bulbasaur });
	Gen1_pokemon_definitions_map.insert({ pikachu.get_pokemon_name(),pikachu });
}

void Pokedex::load_pokemon_with_default_moves() {
	bulbasaur.define_all_possible_moves(std::vector<Move>{barrier, tackle, poison_powder, growl});
	bulbasaur.define_default_moves(std::array<Move, 4>{tackle, growl, poison_powder});

	pikachu.define_all_possible_moves(std::vector<Move>{tackle, growl, thundershock});
	pikachu.define_default_moves(std::array<Move, 4>{tackle, growl, thundershock});
}

void Pokedex::list_pokemon() {
	for (auto x : Gen1_pokemon_definitions_map) {
		 x.second.show_base_stats();
		 x.second.show_gen1_pokemon_stats();
		 x.second.show_moves();
	}
}

void Pokedex::load_in_all_data() {
	load_moves_into_map();
	load_pokemon_with_default_moves();
	load_pokemon_into_map();
}

//TODO needs error checking for values not in map
Gen1_Pokemon& Pokedex::get_gen1_pokemon_from_map(std::string name) {
	return Gen1_pokemon_definitions_map.at(name);
}