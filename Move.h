#pragma once
#include <iostream>
#include <array>
#include "Type.h"

struct Status_Effect {
public:
	enum class status_effect {
		NORMAL, PARALYSIS, BURN, POISON, FREEZE, SLEEP
	};
private:
	status_effect m_status_effect;
	double m_chance;
public:
	Status_Effect(Status_Effect::status_effect status_effect, double chance);
};

struct Status_Change {
public:
	enum class status_change {
			HP, ATTACK, DEFENCE, SPEED, SPECIAL
	};
private:
	status_change m_status_change;
	int m_stages;
	static const std::array<std::string, 5> stat_names;
public:
	Status_Change(Status_Change::status_change, int);
	std::string get_status_change_names();
	std::string get_status_stages();
};

struct Move {
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

struct Attack_Move_Stats_Effect : public Attack_Move {
	Status_Effect::status_effect m_stats;
	Attack_Move_Stats_Effect(std::string name, int pp, int accuracy, Type::Type_Enum type, int power, Status_Effect::status_effect stats_effect);
};

struct Attack_Move_Stats_Change : public Attack_Move {
	Status_Change::status_change m_stats_change;
	Attack_Move_Stats_Change(std::string name, int pp, int accuracy, Type::Type_Enum type, int power, Status_Change::status_change stats_change);
};

struct Defence_Move :public Move {
	Status_Change m_status;
	Defence_Move(std::string name, int pp, int accuracy, Type::Type_Enum type, Status_Change status);
};