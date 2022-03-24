#include "Battle_Event.h"

Battle_Event::Battle_Event() {

}

void Battle_Event::start_battle() {
	//gen_selection(){};
// gen_selection will return a map
//pass the map from gen_selection to select_pokemon_to_battle etc
	select_pokemon_to_battle();
	while (!isFainted) {
		speed_check();
		turn(turn_order[0]);
		turn(turn_order[1]);
	}
}

void Battle_Event::show_turn_order() {
	for (int x = 0; x < 2; ++x)
		turn_order[x]->show_battle_stats();
}

void Battle_Event::speed_check() {
	assign_turn_order(compare_speeds());
}

void Battle_Event::random_turn_order() {
	int random_number = rand()%2;
	if (random_number == 0)
		turn_order[0] = &user, turn_order[1] = &enemy;
	else
		turn_order[1] = &user, turn_order[0] = &enemy;
}

int Battle_Event::compare_speeds() {
	if (user.modified_speed() > enemy.modified_speed())
		return 1;
	if (user.modified_speed() < enemy.modified_speed())
		return -1;
	if (user.modified_speed() == enemy.modified_speed())
		return 0;
	return 99;
}

void Battle_Event::assign_turn_order(int i) {
	if (i == 1)
		turn_order[0] = &user, turn_order[1] = &enemy;
	if (i==-1)
		turn_order[1] = &user, turn_order[0] = &enemy;
	if (i == 0)
		random_turn_order();
}

void Battle_Event::turn(Battle_Pokemon* bp) {
	//select_move();
	if (!is_stunned(bp))
	{
	}
		//do_move();
	//check_fainted();
}

bool Battle_Event::is_stunned(Battle_Pokemon* bp){
	if (is_status_effect_a_stun(bp))
		return calculate_if_stunned(bp);
	return false;
}

bool Battle_Event::is_status_effect_a_stun(Battle_Pokemon* bp) {
	if (bp->get_status_effect() == status_effect_value::FREEZE)
		return true;
	if (bp->get_status_effect() == status_effect_value::PARALYSIS)
		return true;
	if (bp->get_status_effect() == status_effect_value::SLEEP)
		return true;
	return false;
}

bool Battle_Event::calculate_if_stunned(Battle_Pokemon* bp) {
	int lower_limit = 1;
	int max_limit = 100;
	int chance = rand() % max_limit + lower_limit;
	if (chance <= bp->get_stun_chance())
		return true;
	return false;
}

void Battle_Event::select_pokemon_to_battle() {
	//TODO this doesn't seem to work
	select_user_pokemon();
	select_enemy_pokemon();
}

void Battle_Event::select_user_pokemon()
{
	std::cout << "Select user's pokemon: ";
	std::string choice;
	std::cin >> choice;
	if (!is_pokemon_in_map(choice)) {
		select_user_pokemon();
		return;
	}
	Gen1_Pokemon pokemon = find_pokemon_from_map(choice);
	user = Battle_Pokemon(pokemon);
}

bool Battle_Event::is_pokemon_in_map(std::string& choice) {
	try {
		Pokedex::gen1_Pokemon_map.at(choice);
	}
	catch (std::exception e) {
		std::cout << std::endl;
		std::cout << "Pokemon does not exist. Please select another: ";
		return false;
	}
	return true;
}

Gen1_Pokemon Battle_Event::find_pokemon_from_map(std::string& choice) {
	return Pokedex::gen1_Pokemon_map.at(choice);
}

void Battle_Event::select_enemy_pokemon()
{
	std::cout << "Select enemy's pokemon: ";
	std::string choice;
	std::cin >> choice;
	if (!is_pokemon_in_map(choice)) {
		select_enemy_pokemon();
		return;
	}
	Gen1_Pokemon pokemon = find_pokemon_from_map(choice);
	enemy = Battle_Pokemon(pokemon);
}

void Battle_Event::battle() {

}
