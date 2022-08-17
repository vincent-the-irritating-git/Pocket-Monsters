#include "Stats_n_Status.h"

using namespace status_and_stats;

namespace {
	namespace status_effects {
		Damage_Status_Effect BURN(status_effect_value::BURN, { Stats_Change(stats_value::ATTACK,6.25f) });
		Damage_Status_Effect POISON(status_effect_value::POISON, Stats_Change(stats_value::HP, 6.25f));
		Stun_Status_Effect PARALYSIS(status_effect_value::PARALYSIS, stats_value::SPEED, 25);
		Stun_Status_Effect FREEZE(status_effect_value::FREEZE, 100);
		Stun_Status_Effect SLEEP(status_effect_value::SLEEP, 100, 1, 7);
	}
}

Status_Effect_Change* status_effect::BURN = &status_effects::BURN;
Status_Effect_Change* status_effect::POISON = &status_effects::POISON;
Status_Effect_Change* status_effect::PARALYSIS = &status_effects::PARALYSIS;
Status_Effect_Change* status_effect::FREEZE = &status_effects::FREEZE;
Status_Effect_Change* status_effect::SLEEP = &status_effects::SLEEP;

Status_Effect_Change::Status_Effect_Change(status_effect_value status) :m_status_effect(status){
	m_status_effect = status;
}

Stun_Status_Effect::Stun_Status_Effect(status_and_stats::status_effect_value status_effect, uint8_t stun): Status_Effect_Change(status_effect), m_stun(stun) {
	m_stun = stun;
}

Stun_Status_Effect::Stun_Status_Effect(status_and_stats::status_effect_value status_effect, uint8_t stun, uint8_t lower_limit, uint8_t upper_limit): Status_Effect_Change(status_effect), m_stun(stun), m_lower_limit(lower_limit), m_upper_limit(upper_limit) {
	m_stun = stun;
	m_lower_limit = lower_limit;
	m_upper_limit = upper_limit;
}

Stun_Status_Effect::Stun_Status_Effect(status_and_stats::status_effect_value status_effect, status_and_stats::stats_value stats_value, uint8_t stun) : Status_Effect_Change(status_effect), m_stat(stats_value), m_stun(stun){
	m_stat = stats_value;
	m_stun = stun;
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