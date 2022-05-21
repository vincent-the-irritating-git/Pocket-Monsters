#pragma once
#include <iostream>
#include <array>
#include "Type.h"
#include "Stats_n_Status.h"

struct Move {
	bool is_target_enemy = true;
	bool is_status_inflicting = false;
	bool is_stats_changing = false;
	std::string m_name = "";
	int m_pp = 1;
	int m_accuracy = 1;
	Type_Data::Type_Enum m_type = Type_Data::Type_Enum::NORMAL;
	Move();
	Move(std::string, int, int, Type_Data::Type_Enum);
	//elon musk is a twat
	bool operator==(const Move&)const;
	virtual void show_move_values() { std::cout << "Default"<<std::endl; };
};

/*we must remember moves like dig and fury swipes*/

//attack move has, in addition, a power and a status
struct Attack_Move:public Move {
	int m_power = 0;
	Attack_Move(std::string name, int pp, int accuracy, Type_Data::Type_Enum type, int power);
	void show_move_values() override;
};

struct Status_Effect_Attack_Move : public Attack_Move {
	Status_Effect_Change m_status_effect_change;
	Status_Effect_Attack_Move(std::string name, int pp, int accuracy, Type_Data::Type_Enum type, int power, Status_Effect_Change stats_effect);
	void show_move_values() override;
};

struct Stats_Value_Attack_Move : public Attack_Move {
	Stats_Change m_stats_change;
	Stats_Value_Attack_Move(std::string name, int pp, int accuracy, Type_Data::Type_Enum type, int power, Stats_Change stats_change);
	void show_move_values() override;
};

struct Defence_Move :public Move {
	Stats_Change m_stats_change;
	Defence_Move(std::string name, int pp, int accuracy, Type_Data::Type_Enum type, Stats_Change status);
	void show_move_values() override;
};