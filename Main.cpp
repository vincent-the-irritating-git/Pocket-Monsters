#include "Type.h"
#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <unordered_map>
#include "Battle_Pokemon.h"
#include "Pokedex.h"
#include "Battle_Event.h"

int main() {
	const Gen1_Pokemon pikachu = Pokedex::gen1_Pokemon_map.at("Pikachu");

	Battle_Pokemon b_pik(pikachu);
	Battle_Event::display_moves(&b_pik);
}