#include "Pokemon.h"

using namespace status_and_stats;

	//where the pokemon's evolutions are held and what level they evolve to them at
	Pokemon::Evolutions::Evolutions(int m_evolution_index_no, int m_evolution_level) :m_evolution_index_no(m_evolution_index_no), m_evolution_level(m_evolution_level) {
			this->m_evolution_index_no = m_evolution_index_no;
			this->m_evolution_level = m_evolution_level;
		}
	Pokemon::Evolutions::Evolutions() {};

	Pokemon::Pokemon() {};
	/*constructor*/
	Pokemon::Pokemon(int index_no, std::string name, std::shared_ptr<Type> type, std::shared_ptr<Type> type2, Evolutions evolutions) :m_index_no(index_no), m_name(name), m_type(type), m_type2(type2), m_evolution(evolutions){
		this->m_index_no = index_no;
		this->m_name = name;
		this->m_type = type;
		this->m_type2 = type2;
		this->m_evolution = evolutions;
	}

	void Pokemon::show_base_stats() const{
		std::cout<<"Name: " << m_name << std::endl;
		std::cout << "Type: " << Type::get_type_name(m_type->get_type()) << std::endl;
		std::cout << "Type 2: " << Type::get_type_name(m_type2->get_type()) << std::endl;
	}

	std::string Pokemon::get_pokemon_name() const{
		return m_name;
	}

	//default
	Gen1_Pokemon::Gen1_Stats::Gen1_Stats() {};
	//gen1 stats constructor
	Gen1_Pokemon::Gen1_Stats::Gen1_Stats(int hp, int attack, int defence, int special, int speed){
		Gen1_Stats::pokemon_stats.at(stats_value::HP)=hp;
		Gen1_Stats::pokemon_stats.at(stats_value::ATTACK) = attack;
		Gen1_Stats::pokemon_stats.at(stats_value::DEFENCE) = defence;
		Gen1_Stats::pokemon_stats.at(stats_value::SPECIAL) = special;
		Gen1_Stats::pokemon_stats.at(stats_value::SPEED) = speed;
	}
	//default pokemon
	Gen1_Pokemon::Gen1_Pokemon() {};
	//gen1 constructor
	Gen1_Pokemon::Gen1_Pokemon(int index_no, std::string name, std::shared_ptr<Type> type, std::shared_ptr<Type> type2, Evolutions evolutions, Gen1_Stats stats) : Pokemon(index_no, name, type, type2, evolutions), m_stats(stats) {
		m_stats = stats;
	}
	void Gen1_Pokemon::show_gen1_pokemon_stats()const
	{
		printf("HP: %d\nAttack: %d\nDefence: %d\nSpeed: %d\nSpecial: %d\n\n", m_stats.pokemon_stats.at(stats_value::HP), m_stats.pokemon_stats.at(stats_value::ATTACK), m_stats.pokemon_stats.at(stats_value::DEFENCE), m_stats.pokemon_stats.at(stats_value::SPEED), m_stats.pokemon_stats.at(stats_value::SPECIAL));

	}

	bool Gen1_Pokemon::operator==(const Gen1_Pokemon& other)const {
		if (this == &other)
			return true;
		return false;
	}
	
	std::unordered_map<stats_value, int>Gen1_Pokemon::get_m_stats()const {
		return Gen1_Pokemon::m_stats.pokemon_stats;
	}

	//int Gen1_Pokemon::Gen1_Stats

	//default stats
	Gen2_Pokemon::Gen2_Stats::Gen2_Stats() {};
	//gen2 stats constructor
	Gen2_Pokemon::Gen2_Stats::Gen2_Stats(int hp, int attack, int defence, int special_attack, int special_defence, int speed){
		Gen2_Stats::pokemon_stats.at(stats_value::HP) = hp;
		Gen2_Stats::pokemon_stats.at(stats_value::ATTACK) = attack;
		Gen2_Stats::pokemon_stats.at(stats_value::DEFENCE) = defence;
		Gen2_Stats::pokemon_stats.at(stats_value::SPECIAL_ATTACK) = special_attack;
		Gen2_Stats::pokemon_stats.at(stats_value::SPECIAL_DEFENCE) = special_defence;
		Gen2_Stats::pokemon_stats.at(stats_value::SPEED) = speed;
	}
	//default pokemon
	Gen2_Pokemon::Gen2_Pokemon() {};
	//gen2 constructor
	Gen2_Pokemon::Gen2_Pokemon(int index_no, std::string name, std::shared_ptr<Type> type, std::shared_ptr<Type> type2, Evolutions evolutions, Gen2_Stats stats) :Pokemon(index_no, name, type, type2, evolutions),m_stats(stats) {
		m_stats = stats;
	}