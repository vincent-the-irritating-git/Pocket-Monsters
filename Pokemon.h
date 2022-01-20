#pragma once
#include <iostream>
#include <array>
#include "Type.h"
#include "Move.h"

class Pokemon {
public:
	//where the pokemon's evolutions and levels they evolve at are held
	struct Evolutions {
		//where the pokemon's evolutions are held and what level they evolve to them at
	public:
		int m_evolution_index_no = 0;
		int m_evolution_level = 0;
	public:
		Evolutions(int m_evolution_index_no, int m_evolution_level);
		Evolutions();
	};
	//member variables for Pokemon class
protected:
	int m_index_no=-1;
	std::string m_name = "";
	Type::Type_Enum m_type=Type::Type_Enum::NONE, m_type2=Type::Type_Enum::NONE;
	Evolutions m_evolution;
	std::vector<Move> m_moveset;
	std::array<Move, 4>m_known_moves;
public:
	Pokemon();
	/*constructor*/
	Pokemon(int index_no, std::string name, Type::Type_Enum type, Type::Type_Enum type2, Evolutions evolutions);
	//methods
	std::string pokemon_name();
	//for all moves pokemon can learn
	void define_moveset(std::vector<Move>);
	//for setting moves Pokemon knows
	void define_known_moves(std::array<Move, 4>);
	void show_moves();
};

//gen1 Pokemon
class Gen1_Pokemon: public Pokemon {
public:
	//where the pokemon stats are held
	struct Gen1_Stats {
		friend class Gen1_Pokemon;
	public:
		Gen1_Stats();
		Gen1_Stats(int hp, int attack, int defence, int speed, int special);
	private:
		int m_hp = 1;
		int m_attack = 1;
		int m_defence = 1;
		int m_speed = 1;
		int m_special = 1;
	};
	//the Gen1 member variable
protected:
	Gen1_Stats m_stats;
public:
	//constructors
	Gen1_Pokemon();
	Gen1_Pokemon(int index_no, std::string name, Type::Type_Enum type, Type::Type_Enum type2, Evolutions evolutions, Gen1_Stats stats);
};

//gen2 Pokemon
class Gen2_Pokemon: public Pokemon {
public:
	//where the pokemon stats are held
	struct Gen2_Stats {
		friend class Gen2_Pokemon;
	public:
		Gen2_Stats();
		Gen2_Stats(int hp, int attack, int defence, int speed, int special_attack, int special_defence);
	private:
		int m_hp = 1;
		int m_attack = 1;
		int m_defence = 1;
		int m_speed = 1;
		int m_special_attack = 1;
		int m_special_defence = 1;
	};
protected:
	Gen2_Stats m_stats;
public:
	//constructors
	Gen2_Pokemon();
	Gen2_Pokemon(int index_no, std::string name, Type::Type_Enum type, Type::Type_Enum type2, Evolutions evolutions, Gen2_Stats stats);
};