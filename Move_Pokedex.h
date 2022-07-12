#pragma once
#include <array>
#include "Move.h"

extern const std::string NULL_MOVE;
extern const int MAX_MOVES;

class Move_Pokedex {
public:
	const static std::unordered_map<std::string, std::shared_ptr<Move>>gen1_moves;
	const static std::unordered_map < std::string, const std::array<const Move*, 4>>gen1_default_movesets;
public:
	const static std::unordered_map<std::string, std::shared_ptr<Move>>initialise_gen1_moves();
	const static std::unordered_map < std::string, const std::array<const Move*, 4>>initialise_gen1_default_movesets();
	//still want to get rid of that magic number
	static const std::array<const Move*, 4>& get_gen1_default_movesets(std::string name);
	static const std::shared_ptr<Move> get_gen1_moves(std::string name);
	static bool is_move_in_map(std::string name);
	static bool is_default_moveset_in_map(std::string name);
};