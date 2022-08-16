#include "Move_Pokedex.h"
#include "Move.h"

namespace {
	namespace moves {
	Attack_Move NULL_MOVE(" ", 0, 0, Type::NONE, 0);
	//Status_Effect_Attack_Move poison_powder("Poison Powder", 15, 75, Type::POISON, 0, Status_Effect_Change(status_effect_value::POISON, 100));
	Stats_Value_Attack_Move growl("Growl", 40, 100, Type::NORMAL, 0, Stats_Change(status_and_stats::stats_value::ATTACK, 1));
	Status_Effect_Attack_Move thundershock("Thunder Shock", 30, 100, Type::ELECTRIC, 40, Status_Effect_Change(status_and_stats::status_effect_value::PARALYSIS, 10));
	Attack_Move tackle("Tackle", 35, 95, Type::NORMAL, 35);
}
	const std::string NULL_MOVE = " ";
	const int MAX_MOVES = 4;
}



const std::unordered_map<std::string,Move*> Move_Pokedex::initialise_gen1_moves()
{
	using namespace moves;
	std::unordered_map<std::string, Move*> m;
	//Status_Effect_Attack_Move* ptr_poison_powder = std::make_shared <Status_Effect_Attack_Move>(poison_powder);
	Status_Effect_Attack_Move* ptr_thundershock = &thundershock;
	Stats_Value_Attack_Move* ptr_growl = &growl;
	Attack_Move* ptr_NULL_MOVE = &moves::NULL_MOVE;
	Attack_Move* ptr_tackle=&tackle;
	//m.insert({ poison_powder.m_name,ptr_poison_powder });
	m.insert({ growl.m_name, ptr_growl });
	m.insert({ ::NULL_MOVE, ptr_NULL_MOVE });
	m.insert({ thundershock.m_name, ptr_thundershock });
	m.insert({ tackle.m_name, ptr_tackle });
	//m.insert({ moves::NULL_MOVE.m_name, moves::NULL_MOVE });
	return m;
}

const std::unordered_map<std::string, const std::array<const Move*, 4>> Move_Pokedex::initialise_gen1_default_movesets()
{
	std::unordered_map<std::string, const std::array<const Move*, 4>>m;
	std::array<const Move*, 4>pikachu_moves{
		Move_Pokedex::gen1_moves.at("Tackle"),
		Move_Pokedex::gen1_moves.at("Thunder Shock"),
		Move_Pokedex::gen1_moves.at(" "),
		Move_Pokedex::gen1_moves.at(" ")
	};

	std::array<const Move*, 4>missingo_moves{
		Move_Pokedex::gen1_moves.at(" "),
		Move_Pokedex::gen1_moves.at(" "),
		Move_Pokedex::gen1_moves.at(" "),
		Move_Pokedex::gen1_moves.at(" ")
	};
	m.insert({ "Pikachu", pikachu_moves });
	m.insert({ "Missingno", missingo_moves });
	return m;
}

const std::unordered_map<std::string, Move*> Move_Pokedex::gen1_moves{ Move_Pokedex::initialise_gen1_moves() };
const std::unordered_map < std::string, const std::array<const Move*, 4>>Move_Pokedex::gen1_default_movesets{ Move_Pokedex::initialise_gen1_default_movesets() };

bool Move_Pokedex::is_move_in_map(std::string name)
{
	try {
		Move_Pokedex::gen1_moves.at(name);
		return true;
	}
	catch (std::exception e) {
		return false;
	}
}

bool Move_Pokedex::is_default_moveset_in_map(std::string name)
{
	try {
		Move_Pokedex::gen1_default_movesets.at(name);
		return true;
	}
	catch (std::exception e) {
		return false;
	}
}

const Move* Move_Pokedex::get_gen1_moves(std::string name)
{
	try {
		return Move_Pokedex::gen1_moves.at(name);
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		std::cout << "No such move found.";
	}
	return Move_Pokedex::gen1_moves.at(NULL_MOVE);
}

const std::array<const Move*, 4>& Move_Pokedex::get_gen1_default_movesets(std::string name)
{
	try {
		return Move_Pokedex::gen1_default_movesets.at(name);
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		std::cout << "No such moveset found.";
	}
	return Move_Pokedex::gen1_default_movesets.at(Pokemon_Pokedex_constants::MISSINGNO);
}