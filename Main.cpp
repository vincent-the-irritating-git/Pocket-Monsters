#include "Type.h"
#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <unordered_map>

typedef Gen1_Pokemon::Gen1_Stats Generation_1;
typedef Gen2_Pokemon::Gen2_Stats Generation_2;

std::unordered_map <std::string, Gen1_Pokemon> Gen1_Pokedex;
std::unordered_map<std::string, Move> Move_List;

int main() {
	Defence_Move barrier("Barrier", 15, 100, Type::Type_Enum::Psychic, { Status_Change::status_change::DEFENCE, 2 });
	Attack_Move tackle("Tackle", 35, 95, Type::Type_Enum::Normal, 30);
	Attack_Move_Stats_Effect poison_powder("Poison Powder", 15, 75, Type::Type_Enum::Poison, 0, Status_Effect::status_effect::POISON, 100);
	Attack_Move_Stats_Effect growl("Growl",40,100,Type::Type_Enum::Normal,0,)

	Gen1_Pokemon bulbasaur(1, "Bulbasaur", Type::Type_Enum::Grass, Type::Type_Enum::Poison, Pokemon::Evolutions(2, 16), Generation_1::Gen1_Stats(45, 49, 49, 65, 45));
	Gen1_Pokemon alakazam(65, "Alakazam", Type::Type_Enum::Psychic, Type::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(55, 50, 45, 135, 120));
	Gen1_Pokemon pinsir(127, "Pinsir", Type::Type_Enum::Bug, Type::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(65, 125, 100, 55, 85));

	bulbasaur.define_moveset({ std::vector<Move>{barrier,tackle,poison_powder} });
	bulbasaur.show_moves();

	Gen1_Pokedex.insert({ bulbasaur.pokemon_name(), bulbasaur });
	Gen1_Pokedex.insert({ alakazam.pokemon_name(),alakazam });
	Gen1_Pokedex.insert({ pinsir.pokemon_name(),pinsir });
	Move_List.insert({ barrier.m_name,barrier });
	Move_List.insert({ tackle.m_name,tackle });

}