#include "Type.h"
#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <unordered_map>
#include "Battle_Pokemon.h"
#include "Pokedex.h"
#include "Battle_Event.h"

using namespace status_and_stats;



int main() {
	Status_Effect_Attack_Move thundershock("Thunder Shock", 30, 100, Type::Type_Enum::ELECTRIC, 40, Status_Effect_Change(status_effect_value::PARALYSIS, 10));
	Move* m = &thundershock;
	thundershock.show_move_values();
	m->show_move_values();
	const Move* mm = &(Pokedex::get_gen1_moves("Thunder Shock"));
	
	return 0;
}