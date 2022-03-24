#include "Type.h"
#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <unordered_map>
#include "Battle_Pokemon.h"
#include "Pokedex.h"
#include "Battle_Event.h"

int main() {
	Battle_Pokemon b(Pokedex::gen1_Pokemon_map.at("Pikachu"));
	const Gen1_Pokemon& pikachu = (Pokedex::gen1_Pokemon_map.at("Pikachu"));

	const Gen1_Pokemon* ptr = &(Pokedex::gen1_Pokemon_map.at("Pikachu"));
	const Gen1_Pokemon* ptr2 = &pikachu;
	const Gen1_Pokemon* ptr3 = b.pokemon_ptr;
	std::cout <<"The one in the map: "<< ptr << std::endl; 
	std::cout <<"The pikachu object: "<< ptr2 << std::endl;
	std::cout <<"The battle pokemon pointer: "<< ptr3 << std::endl;

	bool boo = *b.pokemon_ptr == Pokedex::gen1_Pokemon_map.at("Pikachu");
	std::cout << std::boolalpha << boo<<std::endl;
}