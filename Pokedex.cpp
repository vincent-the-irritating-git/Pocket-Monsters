#include "Pokedex.h"

int MAX_MOVES = 4;

const std::unordered_map<std::string, Gen1_Pokemon> Pokedex::initialise_pokemon_map()
{
	std::unordered_map<std::string, Gen1_Pokemon> m;
	Gen1_Pokemon bulbasaur(1, "Bulbasaur", Type::Type_Enum::GRASS, Type::Type_Enum::POISON, Pokemon::Evolutions(2, 16), Gen1_Pokemon::Gen1_Stats(45, 49, 49, 65, 45));
	Gen1_Pokemon pikachu(25, "Pikachu", Type::Type_Enum::ELECTRIC, Type::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(35, 55, 30, 50, 90));
	Gen1_Pokemon alakazam(65, "Alakazam", Type::Type_Enum::PSYCHIC, Type::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(55, 50, 45, 135, 120));
	Gen1_Pokemon pinsir(127, "Pinsir", Type::Type_Enum::BUG, Type::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(65, 125, 100, 55, 85));
	Gen1_Pokemon moltres(146, "Moltres", Type::Type_Enum::FIRE, Type::Type_Enum::FLYING, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(90, 100, 90, 125, 90));
	m.insert({ bulbasaur.get_pokemon_name(),bulbasaur });
	m.insert({ pikachu.get_pokemon_name(),pikachu });
	m.insert({ moltres.get_pokemon_name(),moltres });
	return m;
}

const std::unordered_map<std::string, Move> Pokedex::initialise_gen1_moves()
{
	std::unordered_map<std::string, Move> m;
	Move NULL_MOVE(" ", 0, 0, Type::Type_Enum::NONE);
	Status_Effect_Attack_Move poison_powder("Poison Powder", 15, 75, Type::Type_Enum::POISON, 0, Status_Effect_Change(status_effect_value::POISON, 100));
	Stats_Value_Attack_Move growl("Growl", 40, 100, Type::Type_Enum::NORMAL, 0, Stats_Change(stats_value::ATTACK, 1));
	Status_Effect_Attack_Move thundershock("Thunder Shock", 30, 100, Type::Type_Enum::ELECTRIC, 40, Status_Effect_Change(status_effect_value::PARALYSIS, 10));
	Attack_Move tackle("Tackle", 35, 95, Type::Type_Enum::NORMAL, 35);
	m.insert({ poison_powder.m_name,poison_powder });
	m.insert({ growl.m_name, growl });
	m.insert({ thundershock.m_name, thundershock });
	m.insert({ tackle.m_name, tackle });
	m.insert({ NULL_MOVE.m_name, NULL_MOVE });
	return m;
}

const std::unordered_map<std::string, std::array<const Move*, 4>> Pokedex::initialise_gen1_default_movesets()
{
	std::unordered_map<std::string, std::array<const Move*, 4>>m;
	std::array<const Move*, 4>pikachu_moves{
		&(Pokedex::gen1_moves.at("Tackle")),
		&(Pokedex::gen1_moves.at("Thunder Shock")),
		&(Pokedex::gen1_moves.at(" ")),
		&(Pokedex::gen1_moves.at(" "))
	};
	m.insert({ "Pikachu", pikachu_moves });
	return m;
}

const std::unordered_map<std::string, Gen1_Pokemon> Pokedex::gen1_Pokemon_map{ Pokedex::initialise_pokemon_map() };
const std::unordered_map<std::string, Move> Pokedex::gen1_moves{ Pokedex::initialise_gen1_moves() };
const std::unordered_map < std::string, std::array<const Move*, 4>>Pokedex::gen1_default_movesets {Pokedex::initialise_gen1_default_movesets()};