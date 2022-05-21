#include "Pokedex.h"

using namespace status_and_stats;
using namespace Pokedex_constants;

const std::string Pokedex_constants::MISSINGNO = "Missingno";
const std::string Pokedex_constants::NULL_MOVE = " ";
const int Pokedex_constants::MAX_MOVES = 4;

namespace moves{
	Attack_Move NULL_MOVE(" ", 0, 0, Type_Data::Type_Enum::NONE, 0);
	Status_Effect_Attack_Move poison_powder("Poison Powder", 15, 75, Type_Data::Type_Enum::POISON, 0, Status_Effect_Change(status_effect_value::POISON, 100));
	Stats_Value_Attack_Move growl("Growl", 40, 100, Type_Data::Type_Enum::NORMAL, 0, Stats_Change(stats_value::ATTACK, 1));
	Status_Effect_Attack_Move thundershock("Thunder Shock", 30, 100, Type_Data::Type_Enum::ELECTRIC, 40, Status_Effect_Change(status_effect_value::PARALYSIS, 10));
	Attack_Move tackle("Tackle", 35, 95, Type_Data::Type_Enum::NORMAL, 35);
}

const std::unordered_map<std::string, Gen1_Pokemon> Pokedex::initialise_pokemon_map()
{
	std::unordered_map<std::string, Gen1_Pokemon> m;
	Gen1_Pokemon missingno(-1, "Missingno", Type_Data::Type_Enum::NONE, Type_Data::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(0, 0, 0, 0, 0));
	Gen1_Pokemon bulbasaur(1, "Bulbasaur", Type_Data::Type_Enum::GRASS, Type_Data::Type_Enum::POISON, Pokemon::Evolutions(2, 16), Gen1_Pokemon::Gen1_Stats(45, 49, 49, 65, 45));
	Gen1_Pokemon pikachu(25, "Pikachu", Type_Data::Type_Enum::ELECTRIC, Type_Data::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(35, 55, 30, 50, 90));
	Gen1_Pokemon alakazam(65, "Alakazam", Type_Data::Type_Enum::PSYCHIC, Type_Data::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(55, 50, 45, 135, 120));
	Gen1_Pokemon pinsir(127, "Pinsir", Type_Data::Type_Enum::BUG, Type_Data::Type_Enum::NONE, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(65, 125, 100, 55, 85));
	Gen1_Pokemon moltres(146, "Moltres", Type_Data::Type_Enum::FIRE, Type_Data::Type_Enum::FLYING, Pokemon::Evolutions(), Gen1_Pokemon::Gen1_Stats(90, 100, 90, 125, 90));
	m.insert({ missingno.get_pokemon_name(), missingno });
	m.insert({ bulbasaur.get_pokemon_name(),bulbasaur });
	m.insert({ pikachu.get_pokemon_name(),pikachu });
	m.insert({ moltres.get_pokemon_name(),moltres });
	return m;
}

const std::unordered_map<std::string, std::shared_ptr<Move>> Pokedex::initialise_gen1_moves()
{
	using namespace moves;
	std::unordered_map<std::string, std::shared_ptr<Move>> m;
	std::shared_ptr<Status_Effect_Attack_Move>ptr_poison_powder = std::make_shared <Status_Effect_Attack_Move>(poison_powder);
	std::shared_ptr<Stats_Value_Attack_Move>ptr_growl = std::make_shared < Stats_Value_Attack_Move >(growl);
	std::shared_ptr<Attack_Move>ptr_NULL_MOVE = std::make_shared<Attack_Move>(moves::NULL_MOVE);
	m.insert({ poison_powder.m_name,ptr_poison_powder});
	m.insert({ growl.m_name, ptr_growl });
	m.insert({ Pokedex_constants::NULL_MOVE, ptr_NULL_MOVE });
	//m.insert({ thundershock.m_name, thundershock });
	//m.insert({ tackle.m_name, tackle });
	//m.insert({ moves::NULL_MOVE.m_name, moves::NULL_MOVE });
	return m;
}

const std::unordered_map<std::string, const std::array<const Move*, 4>> Pokedex::initialise_gen1_default_movesets()
{
	std::unordered_map<std::string, const std::array<const Move*, 4>>m;
	/*std::array<const Move*, 4>pikachu_moves{
		&(Pokedex::gen1_moves.at("Tackle")),
		&(Pokedex::gen1_moves.at("Thunder Shock")),
		&(Pokedex::gen1_moves.at(" ")),
		&(Pokedex::gen1_moves.at(" "))
	};

	std::array<const Move*, 4>missingo_moves{
		&(Pokedex::gen1_moves.at(" ")),
		&(Pokedex::gen1_moves.at(" ")),
		&(Pokedex::gen1_moves.at(" ")),
		&(Pokedex::gen1_moves.at(" "))
	};
	m.insert({ "Pikachu", pikachu_moves });
	m.insert({ "Missingno", missingo_moves });*/
	return m;
}

const std::unordered_map<std::string, Gen1_Pokemon> Pokedex::gen1_Pokemon_map{ Pokedex::initialise_pokemon_map() };
const std::unordered_map<std::string, std::shared_ptr<Move>> Pokedex::gen1_moves{ Pokedex::initialise_gen1_moves() };
const std::unordered_map < std::string, const std::array<const Move*, 4>>Pokedex::gen1_default_movesets {Pokedex::initialise_gen1_default_movesets()};

const Gen1_Pokemon& Pokedex::get_gen1_pokemon(std::string name) {
	try {
		return Pokedex::gen1_Pokemon_map.at(name);
	}
	catch(std::exception e){
		std::cout << e.what() << std::endl;
		std::cout << "No such pokemon found.";
	}
	return Pokedex::gen1_Pokemon_map.at(MISSINGNO);
}

const std::shared_ptr<Move> Pokedex::get_gen1_moves(std::string name)
{
	try {
		return Pokedex::gen1_moves.at(name);
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		std::cout << "No such move found.";
	}
	return Pokedex::gen1_moves.at(NULL_MOVE);
}

const std::array<const Move*, 4>& Pokedex::get_gen1_default_movesets(std::string name)
{
	try {
		return Pokedex::gen1_default_movesets.at(name);
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		std::cout << "No such moveset found.";
	}
	return Pokedex::gen1_default_movesets.at(MISSINGNO);
}

bool Pokedex::is_pokemon_in_map(std::string name)
{
	try {
		Pokedex::gen1_Pokemon_map.at(name);
		return true;
	}
	catch (std::exception e) {
		return false;
	}
}

bool Pokedex::is_move_in_map(std::string name)
{
	try {
		Pokedex::gen1_moves.at(name);
		return true;
	}
	catch (std::exception e) {
		return false;
	}
}

bool Pokedex::is_default_moveset_in_map(std::string name)
{
	try {
		Pokedex::gen1_default_movesets.at(name);
		return true;
	}
	catch (std::exception e) {
		return false;
	}
}