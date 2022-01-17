#include "Pokemon.h"

	//where the pokemon's evolutions are held and what level they evolve to them at
	Pokemon::Evolutions::Evolutions(int m_evolution_index_no, int m_evolution_level) :m_evolution_index_no(m_evolution_index_no), m_evolution_level(m_evolution_level) {
			this->m_evolution_index_no = m_evolution_index_no;
			this->m_evolution_level = m_evolution_level;
		}
	Pokemon::Evolutions::Evolutions() {};

	Pokemon::Pokemon() {};
	/*constructor for one type*/
	Pokemon::Pokemon(int index_no, std::string name, Type::Type_Enum type, Evolutions evolutions) :m_index_no(index_no), m_name(name), m_type(type), m_evolution(evolutions){
		this->m_index_no = index_no;
		this->m_name = name;
		this->m_type = type;
		this->m_evolution = evolutions;

		std::cout << m_index_no << "\t" << m_name << "\t" << Type::get_type_name(m_type) << "\t" << m_evolution.m_evolution_index_no << "\t" << m_evolution.m_evolution_level << std::endl;
	}
	/*constructor for two type*/
	Pokemon::Pokemon(int index_no, std::string name, Type::Type_Enum type, Type::Type_Enum type2, Evolutions evolutions) :m_index_no(index_no), m_name(name), m_type(type), m_type2(type2), m_evolution(evolutions){
		this->m_index_no = index_no;
		this->m_name = name;
		this->m_type = type;
		this->m_type2 = type2;
		this->m_evolution = evolutions;

		std::cout << m_index_no << "\t" << m_name << "\t" << Type::get_type_name(m_type) << "\t" << Type::get_type_name(m_type2) << "\t" << m_evolution.m_evolution_index_no << "\t" << m_evolution.m_evolution_level << std::endl;
		}

	std::string Pokemon::pokemon_name() {
		return m_name;
	}
	
	//default
	Gen1_Pokemon::Gen1_Stats::Gen1_Stats() {};
	//gen1 stats constructor
	Gen1_Pokemon::Gen1_Stats::Gen1_Stats(int hp, int attack, int defence, int speed, int special) :m_hp(hp), m_attack(attack), m_defence(defence), m_speed(speed), m_special(special) {
		m_hp = hp;
		m_attack = attack;
		m_defence = defence;
		m_speed = speed;
		m_special = special;
	}
	//default pokemon
	Gen1_Pokemon::Gen1_Pokemon() {};
	//gen1 constructor
	Gen1_Pokemon::Gen1_Pokemon(int index_no, std::string name, Type::Type_Enum type, Evolutions evolutions, Gen1_Stats stats): Pokemon(index_no, name, type, evolutions),m_stats(stats) {
		m_stats = stats;
		std::cout << m_stats.m_hp << "\t" << m_stats.m_attack << "\t" << m_stats.m_defence << "\t" << m_stats.m_speed << "\t" << m_stats.m_special << std::endl;
	}
	//gen1 overloaded constructor
	Gen1_Pokemon::Gen1_Pokemon(int index_no, std::string name, Type::Type_Enum type, Type::Type_Enum type2, Evolutions evolutions, Gen1_Stats stats) : Pokemon(index_no, name, type, type2, evolutions), m_stats(stats) {
		m_stats = stats;
		std::cout << m_stats.m_hp << "\t" << m_stats.m_attack << "\t" << m_stats.m_defence << "\t" << m_stats.m_speed << "\t" << m_stats.m_special << std::endl;
	}

	//default stats
	Gen2_Pokemon::Gen2_Stats::Gen2_Stats() {};
	//gen2 stats constructor
	Gen2_Pokemon::Gen2_Stats::Gen2_Stats(int hp, int attack, int defence, int speed, int special_attack, int special_defence) :m_hp(hp), m_attack(attack), m_defence(defence), m_speed(speed), m_special_attack(special_attack), m_special_defence(special_defence) {
		m_hp = hp;
		m_attack = attack;
		m_defence = defence;
		m_speed = speed;
		m_special_attack = special_attack;
		m_special_defence = special_defence;
	}
	//default pokemon
	Gen2_Pokemon::Gen2_Pokemon() {};
	//gen2 constructor
	Gen2_Pokemon::Gen2_Pokemon(int index_no, std::string name, Type::Type_Enum type, Evolutions evolutions, Gen2_Stats stats) :Pokemon(index_no, name, type, evolutions),m_stats(stats) {

		m_stats = stats;

		std::cout << m_stats.m_hp << "\t" << m_stats.m_attack << "\t" << m_stats.m_defence << "\t" << m_stats.m_speed << "\t" << m_stats.m_special_attack<<"\t"<<m_stats.m_special_defence << std::endl;
	}
	//gen2 overloaded constructor
	Gen2_Pokemon::Gen2_Pokemon(int index_no, std::string name, Type::Type_Enum type, Type::Type_Enum type2, Evolutions evolutions, Gen2_Stats stats) :Pokemon(index_no, name, type, type2, evolutions),m_stats(stats) {

		m_stats = stats;

		std::cout << m_stats.m_hp << "\t" << m_stats.m_attack << "\t" << m_stats.m_defence << "\t" << m_stats.m_speed << "\t" << m_stats.m_special_attack << "\t" << m_stats.m_special_defence << std::endl;
	}