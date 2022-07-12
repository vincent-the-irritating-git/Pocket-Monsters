#pragma once
#include <iostream>
#include <array>

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
	status_and_stats::status_effect_value m_status_effect = status_and_stats::status_effect_value::NORMAL;
	double m_chance = 0;
	static const std::array<std::string, 6>effect_names;
public:
	Status_Effect_Change(status_and_stats::status_effect_value status_effect, double chance);
	std::string get_status_effect_name();
	double get_status_get_chance();
};

struct Stats_Change {
private:
	status_and_stats::stats_value m_stats_value = status_and_stats::stats_value::ATTACK;
	int m_stages = 0;
public:
	Stats_Change(status_and_stats::stats_value, int);
	Stats_Change();
	int get_stats_stages();
	std::string get_stats_value();
	static std::string get_stats_value_name(status_and_stats::stats_value);
};