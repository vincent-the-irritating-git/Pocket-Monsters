#pragma once
#include <iostream>
#include <array>
#include "Type.h"

struct Status_Effect {
public:
	enum class status_effect_value {
		NORMAL, PARALYSIS, BURN, POISON, FREEZE, SLEEP
	};
private:
	status_effect_value m_status_effect=Status_Effect::status_effect_value::BURN;
	double m_chance=0;
	static const std::array<std::string, 6>effect_names;
public:
	Status_Effect(Status_Effect::status_effect_value status_effect, double chance);
	std::string get_status_effect_name();
	double get_status_get_chance();
};

struct Stats {
public:
	enum class stats_value {
			HP, ATTACK, DEFENCE, SPEED, SPECIAL
	};
private:
	stats_value m_stats_value=Stats::stats_value::ATTACK;
	int m_stages=0;
	static const std::array<std::string, 5> stat_names;
public:
	Stats(Stats::stats_value, int);
	Stats();
	std::string get_stats_value_names();
	int get_stats_stages();
};

struct Move {
	bool is_target_enemy = true;
	bool is_status_inflicting = false;
	bool is_stats_changing = false;
	std::string m_name = "";
	int m_pp = 1;
	int m_accuracy = 1;
	Type::Type_Enum m_type = Type::Type_Enum::Normal;
	Move();
	Move(std::string, int, int, Type::Type_Enum);
};

/*we must remember moves like dig and fury swipes*/

//attack move has, in addition, a power and a status
struct Attack_Move:public Move {
	int m_power = 0;
	Attack_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, int power);
};

struct Status_Effect_Attack_Move : public Attack_Move {
	Status_Effect m_status_effect;
	Status_Effect_Attack_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, int power, Status_Effect stats_effect);
};

struct Stats_Value_Attack_Move : public Attack_Move {
	Stats m_stats_value;
	Stats_Value_Attack_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, int power, Stats stats_change);
};

struct Defence_Move :public Move {
	Stats m_stats_value;
	Defence_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, Stats status);
};