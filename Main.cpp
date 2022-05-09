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
	Battle_Pokemon bp(Pokedex::get_gen1_pokemon("Pikachu")); 
	Battle_Event::show_stun_message(bp);
	bp.DEBUG_set_status(status_effect_value::FREEZE);
	Battle_Event::show_stun_message(bp);
	bp.DEBUG_set_status(status_effect_value::PARALYSIS);
	Battle_Event::show_stun_message(bp);
	return 0;
}