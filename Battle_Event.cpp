#include "Battle_Event.h"

Battle_Event::Battle_Event() {

}

bool Battle_Event::isFainted = false;
Battle_Pokemon Battle_Event::user;
Battle_Pokemon Battle_Event::enemy;
std::array<Battle_Pokemon*, 2> Battle_Event::turn_order;

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

void Battle_Event::DEBUG_SET_USER(Gen1_Pokemon b){
	user = Battle_Pokemon(b);
}

void Battle_Event::DEBUG_SET_ENEMY(Gen1_Pokemon b) {
	enemy = Battle_Pokemon(b);
	enemy.set_ai();
}

std::array<Battle_Pokemon*,2> Battle_Event::DEBUG_get_turn_order() {
	return turn_order;
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
	if (bp->get_is_human()) 
		human_turn(bp);
	else
	ai_turn(bp);
	//display_moves();
	//select_move();
}

void Battle_Event::human_turn(Battle_Pokemon* bp) {
	int user_move_choice = -1;
	const Move* chosen_move = nullptr;
	display_moves(bp);
	user_move_choice=select_move(bp);
	chosen_move = retrieve_move_from_map(bp, user_move_choice);
	if (is_stunned(bp))
		return;
	//break()
	do_move(bp, chosen_move);
	//check_fainted();
}

const Move* Battle_Event::retrieve_move_from_map(Battle_Pokemon* bp, int m) {
	std::string name = bp->get_battle_pokemon_name();
	if (!is_NULL_MOVE(Pokedex::gen1_default_movesets.at(name).at(m)))
		return Pokedex::gen1_default_movesets.at(name).at(m);
	else
		select_move(bp);
}

void Battle_Event::ai_turn(Battle_Pokemon* bp) {

}

void Battle_Event::do_move(Battle_Pokemon* bp, const Move* chosen_move) {
	//inflict_damage();
	//inflict_status_effect();
	//inflict_stats_change();
}

void Battle_Event::inflict_damage(Battle_Pokemon* bp, const Attack_Move* move) {
		//int damage = (move->m_power * bp->modified_attack() / defending.defence) / 50 + 2 * critical() * random() * STAB * type * burn;
}

//TODO we're only couting pointer address
void Battle_Event::display_moves(Battle_Pokemon* bp) {
	std::string name = bp->get_battle_pokemon_name();
	for (int x = 0; x < MAX_MOVES; ++x)
		std::cout << x+1 << ": " << Pokedex::gen1_default_movesets.at(name).at(x)->m_name << std::endl;
}

int Battle_Event::select_move(Battle_Pokemon* bp)
{
	int choice;
	//TODO probably needs try catch stuff
	std::cin >> choice;
	if(is_valid_move_choice(choice))
	return choice;
	else
	select_move(bp);
}

bool Battle_Event::is_valid_move_choice(int choice) {
	std::regex r ("[1-4]+");
	std::string string_choice = std::to_string(choice);
	return std::regex_match(string_choice,r);
}

bool Battle_Event::is_NULL_MOVE(const Move* move) {
	if (move->m_name == " ")
		return true;
	return false;
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
	const Gen1_Pokemon* pokemon = find_pokemon_from_map(choice);
	user = Battle_Pokemon(*pokemon);
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

const Gen1_Pokemon* Battle_Event::find_pokemon_from_map(std::string& choice) {
	return &(Pokedex::gen1_Pokemon_map.at(choice));
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
	const Gen1_Pokemon* pokemon = (find_pokemon_from_map(choice));
	enemy = Battle_Pokemon(*pokemon);
	enemy.set_ai();
}

void Battle_Event::battle() {

}
