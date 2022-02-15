#include "Type.h"
#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <unordered_map>
#include "Battle_Pokemon.h"

typedef Gen1_Pokemon::Gen1_Stats Generation_1;
typedef Gen2_Pokemon::Gen2_Stats Generation_2;

std::unordered_map <std::string, Gen1_Pokemon> Gen1_Pokedex;
std::unordered_map<std::string, Move> Move_List;

int main() {
	Defence_Move barrier("Barrier", 15, 100, Type::Type_Enum::Psychic, Stats_Change(stats_value::DEFENCE, 2));
	Attack_Move tackle("Tackle", 35, 95, Type::Type_Enum::Normal, 30);
	Status_Effect_Attack_Move poison_powder("Poison Powder", 15, 75, Type::Type_Enum::Poison, 0, Status_Effect_Change(status_effect_value::POISON, 100 ));
	Stats_Value_Attack_Move growl("Growl", 40, 100, Type::Type_Enum::Normal, 0, Stats_Change(stats_value::ATTACK,1 ));
	Status_Effect_Attack_Move thundershock("Thunder Shock", 30, 100, Type::Type_Enum::Electric, 40, Status_Effect_Change(status_effect_value::PARALYSIS,10 ));
	//tackle.show_move_values();
	//poison_powder.show_move_values();
	//barrier.show_move_values();
	//growl.show_move_values();
	Gen1_Pokemon bulbasaur(1, "Bulbasaur", Type::Type_Enum::Grass, Type::Type_Enum::Poison, Pokemon::Evolutions(2, 16), Generation_1::Gen1_Stats(45, 49, 49, 65, 45));
	Gen1_Pokemon pikachu(25, "Pikachu", Type::Type_Enum::Electric, Type::Type_Enum::NONE, Pokemon::Evolutions(), Generation_1::Gen1_Stats(35,55,30,50,90));
	Gen1_Pokemon alakazam(65, "Alakazam", Type::Type_Enum::Psychic, Type::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(55, 50, 45, 135, 120));
	Gen1_Pokemon pinsir(127, "Pinsir", Type::Type_Enum::Bug, Type::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(65, 125, 100, 55, 85));

	bulbasaur.define_all_possible_moves(std::vector<Move>{barrier,tackle,poison_powder,growl} );
	bulbasaur.define_default_moves(std::array<Move,4>{tackle,growl,poison_powder});
	//bulbasaur.show_moves();

	pikachu.define_all_possible_moves(std::vector<Move>{tackle, growl, thundershock});
	pikachu.define_default_moves(std::array<Move, 4>{tackle, growl, thundershock});
	//pikachu.show_moves();

	Gen1_Pokedex.insert({ bulbasaur.get_pokemon_name(), bulbasaur });
	Gen1_Pokedex.insert({ alakazam.get_pokemon_name(),alakazam });
	Gen1_Pokedex.insert({ pinsir.get_pokemon_name(),pinsir });
	Move_List.insert({ barrier.m_name,barrier });
	Move_List.insert({ tackle.m_name,tackle });

	Battle_Pokemon b_alakazam(alakazam);
	//b_alakazam.show_battle_stats();

}