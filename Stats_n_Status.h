#pragma once
#include <iostream>
#include <array>
#include <unordered_map>

namespace status_and_stats {
	enum class status_effect_value {
		NORMAL, PARALYSIS, BURN, POISON, FREEZE, SLEEP
	};

	enum class stats_value {
		HP, ATTACK, DEFENCE, SPEED, SPECIAL, SPECIAL_ATTACK, SPECIAL_DEFENCE, CRITICAL_HIT_RATIO
	};
}

std::ostream& operator<<(std::ostream& out, status_and_stats::status_effect_value status);
std::ostream& operator<<(std::ostream& out, status_and_stats::stats_value stats);

struct Stats_Change {
private:
	status_and_stats::stats_value m_stats_value = status_and_stats::stats_value::ATTACK;
	float m_stages_or_per_cent = 0.00f;
public:
	Stats_Change(status_and_stats::stats_value, float);
	Stats_Change();
	int get_stats_stages();
	std::string get_stats_value();
	static std::string get_stats_value_name(status_and_stats::stats_value);
};

struct Status_Effect_Change {
private:
	status_and_stats::status_effect_value m_status_effect = status_and_stats::status_effect_value::NORMAL;
public:
	Status_Effect_Change(status_and_stats::status_effect_value status_effect);
	std::string get_status_effect_name();
};

struct Stun_Status_Effect :Status_Effect_Change {
private:
	uint8_t m_stun_or_counter=0;
	status_and_stats::stats_value m_stat=status_and_stats::stats_value::ATTACK;
public:
	Stun_Status_Effect(status_and_stats::status_effect_value status_effect, uint8_t stun);
	Stun_Status_Effect(status_and_stats::status_effect_value status_effect, status_and_stats::stats_value stats, uint8_t stun_or_counter);
};

struct Damage_Status_Effect :Status_Effect_Change {
private:
	Stats_Change m_stats;
public:
	Damage_Status_Effect(status_and_stats::status_effect_value status_effect, Stats_Change stat);
};

namespace status_effect {
	//where we put them all
	Status_Effect_Change*FREEZE=
}