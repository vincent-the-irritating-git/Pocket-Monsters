#pragma once
#include <iostream>
#include <array>
#include "Type.h"

namespace status_and_stats {
	enum class status_effect_value {
		NORMAL, PARALYSIS, BURN, POISON, FREEZE, SLEEP
	};

	enum class stats_value {
		HP, ATTACK, DEFENCE, SPEED, SPECIAL, SPECIAL_ATTACK, SPECIAL_DEFENCE, CRITICAL_HIT_RATIO
	};
}

struct Status_Effect_Change {
private:
	status_and_stats::status_effect_value m_status_effect= status_and_stats::status_effect_value::NORMAL;
	double m_chance=0;
	static const std::array<std::string, 6>effect_names;
public:
	Status_Effect_Change(status_and_stats::status_effect_value status_effect, double chance);
	std::string get_status_effect_name();
	double get_status_get_chance();
};

struct Stats_Change {
public:
	static std::string get_stats_value_name(status_and_stats::stats_value);

private:
	status_and_stats::stats_value m_stats_value= status_and_stats::stats_value::ATTACK;
	int m_stages=0;
public:
	Stats_Change(status_and_stats::stats_value, int);
	Stats_Change();
	int get_stats_stages();
	std::string get_stats_value();
};

struct Move {
	bool is_target_enemy = true;
	bool is_status_inflicting = false;
	bool is_stats_changing = false;
	std::string m_name = "";
	int m_pp = 1;
	int m_accuracy = 1;
	Type::Type_Enum m_type = Type::Type_Enum::NORMAL;
	Move();
	Move(std::string, int, int, Type::Type_Enum);
};

/*we must remember moves like dig and fury swipes*/

//attack move has, in addition, a power and a status
struct Attack_Move:public Move {
	int m_power = 0;
	Attack_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, int power);
	void show_move_values();
};

struct Status_Effect_Attack_Move : public Attack_Move {
	Status_Effect_Change m_status_effect_change;
	Status_Effect_Attack_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, int power, Status_Effect_Change stats_effect);
	void show_move_values();
};

struct Stats_Value_Attack_Move : public Attack_Move {
	Stats_Change m_stats_change;
	Stats_Value_Attack_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, int power, Stats_Change stats_change);
	void show_move_values();
};

struct Defence_Move :public Move {
	Stats_Change m_stats_change;
	Defence_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, Stats_Change status);
	void show_move_values();
};