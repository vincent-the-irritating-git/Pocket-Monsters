#include "Stats_n_Status.h"

using namespace status_and_stats;

const std::array<std::string, 8> stat_names{ "HP","Attack","Defence","Speed", "Special", "Special Attack", "Special Defence", "Critical Hit Ratio" };
const std::array<std::string, 6> Status_Effect_Change::effect_names{ "Normal","Paralysis","Burn","Poison","Freeze","Sleep" };

std::string Stats_Change::get_stats_value_name(stats_value stats_value) {
	return stat_names[static_cast<int>(stats_value)];
}

int Stats_Change::get_stats_stages() {
	return m_stages;
}

Status_Effect_Change::Status_Effect_Change(status_effect_value status, double chance) :m_status_effect(status), m_chance(chance) {
	m_status_effect = status;
	m_chance = chance;
}

std::string Status_Effect_Change::get_status_effect_name() {
	return effect_names[static_cast<int>(m_status_effect)];
}

double Status_Effect_Change::get_status_get_chance() {
	return m_chance;
}

Stats_Change::Stats_Change(stats_value status, int stages) : m_stats_value(status), m_stages(stages)
{
	m_stats_value = status;
	m_stages = stages;
}

Stats_Change::Stats_Change() {};

std::string Stats_Change::get_stats_value() {
	return get_stats_value_name(m_stats_value);
}