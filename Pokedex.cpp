#include "Pokedex.h"

const std::unordered_map<std::string, Gen1_Pokemon> Pokedex::initialise_pokemon_map()
{
	std::unordered_map<std::string, Gen1_Pokemon> m;
	Gen1_Pokemon bulbasaur(1, "Bulbasaur", Type::Type_Enum::Grass, Type::Type_Enum::Poison, Pokemon::Evolutions(2, 16), Gen1_Pokemon::Gen1_Stats(45, 49, 49, 65, 45));
	Gen1_Pokemon pikachu(25, "Pikachu", Type::Type_Enum::Electric, Type::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(35, 55, 30, 50, 90));
	Gen1_Pokemon alakazam(65, "Alakazam", Type::Type_Enum::Psychic, Type::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(55, 50, 45, 135, 120));
	Gen1_Pokemon pinsir(127, "Pinsir", Type::Type_Enum::Bug, Type::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(65, 125, 100, 55, 85));
	m.insert({ bulbasaur.get_pokemon_name(),bulbasaur });
	m.insert({ pikachu.get_pokemon_name(),pikachu });
	return m;
}

const std::unordered_map<std::string, Gen1_Pokemon> Pokedex::gen1_Pokemon_map{ Pokedex::initialise_pokemon_map() };