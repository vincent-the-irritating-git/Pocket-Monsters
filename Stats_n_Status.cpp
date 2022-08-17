#include "Stats_n_Status.h"

using namespace status_and_stats;

uint8_t sleep_counter() {
	uint8_t LOWER_LIMIT = 1;
	uint8_t MAX_LIMIT = 7;
	return rand() % MAX_LIMIT + LOWER_LIMIT;
}

namespace {
	namespace status_effects {
		Damage_Status_Effect BURN(status_effect_value::BURN, { Stats_Change(stats_value::ATTACK,6.25f) });
		 Damage_Status_Effect POISON(status_effect_value::POISON, Stats_Change(stats_value::HP, 6.25f));
		 Stun_Status_Effect PARALYSIS(status_effect_value::PARALYSIS, stats_value::SPEED, 25);
		 Stun_Status_Effect FREEZE(status_effect_value::FREEZE, 100);
		 Stun_Status_Effect SLEEP(status_effect_value::SLEEP, sleep_counter());
	}
}

Status_Effect_Change* BURN = &status_effects::BURN;
Status_Effect_Change* POISON = &status_effects::POISON;
Status_Effect_Change* PARALYSIS = &status_effects::PARALYSIS;
Status_Effect_Change* FREEZE = &status_effects::FREEZE;
Status_Effect_Change* SLEEP = &status_effects::SLEEP;

Status_Effect_Change::Status_Effect_Change(status_effect_value status) :m_status_effect(status){
	m_status_effect = status;
}

Stun_Status_Effect::Stun_Status_Effect(status_and_stats::status_effect_value status_effect, uint8_t stun_or_counter): Status_Effect_Change(status_effect), m_stun_or_counter(stun_or_counter) {
	m_stun_or_counter = stun_or_counter;
}

Stun_Status_Effect::Stun_Status_Effect(status_and_stats::status_effect_value status_effect, status_and_stats::stats_value stats_value, uint8_t stun_or_counter) : Status_Effect_Change(status_effect), m_stat(stats_value), m_stun_or_counter(stun_or_counter){
	m_stat = stats_value;
	m_stun_or_counter = stun_or_counter;
}

Damage_Status_Effect::Damage_Status_Effect(status_and_stats::status_effect_value status_effect, Stats_Change stat):Status_Effect_Change(status_effect), m_stats(stat){
	m_stats = stat;
}

Stats_Change::Stats_Change(stats_value status, float stages_or_per_cent) : m_stats_value(status), m_stages_or_per_cent(stages_or_per_cent)
{
	m_stats_value = status;
	m_stages_or_per_cent = stages_or_per_cent;
}

Stats_Change::Stats_Change() {};

std::string Stats_Change::get_stats_value() {
	return get_stats_value_name(m_stats_value);
}