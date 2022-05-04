#include "Battle_Event.h"

using namespace status_and_stats;

Battle_Event::Battle_Event() {

}

bool Battle_Event::isFainted = false;
Battle_Pokemon Battle_Event::user = Battle_Pokemon(Pokedex::gen1_Pokemon_map.at("Missingno"));
Battle_Pokemon Battle_Event::ai = Battle_Pokemon(Pokedex::gen1_Pokemon_map.at("Missingno"));
std::shared_ptr<Battle_Pokemon> Battle_Event::current = std::make_shared<Battle_Pokemon>(Battle_Pokemon(Pokedex::gen1_Pokemon_map.at("Missingno")));
std::shared_ptr<Battle_Pokemon> Battle_Event::opposing = std::make_shared<Battle_Pokemon>(Battle_Pokemon(Pokedex::gen1_Pokemon_map.at("Missingno")));
std::array<std::shared_ptr<Battle_Pokemon>, 2> Battle_Event::turn_order{
	current, opposing
};

void Battle_Event::start_battle() {
	//gen_selection(){};
// gen_selection will return a map
//pass the map from gen_selection to select_pokemon_to_battle etc
	select_pokemon_to_battle();
	while (!isFainted) {
		speed_check();
		turn(turn_order[0], turn_order[1]);
		turn(turn_order[1], turn_order[0]);
	}
}

//void Battle_Event::DEBUG_SET_USER(Gen1_Pokemon b){
//	user = Battle_Pokemon(b);
//}
//
//void Battle_Event::DEBUG_SET_ENEMY(Gen1_Pokemon b) {
//	ai = Battle_Pokemon(b);
//	ai.set_ai();
//}

//std::array<std::shared_ptr<Battle_Pokemon>,2> Battle_Event::DEBUG_get_turn_order() {
//	return turn_order;
//}

void Battle_Event::speed_check() {
	assign_turn_order(compare_speeds());
}

void Battle_Event::random_turn_order() {
	int random_number = rand()%2;
	if (random_number == 0)
		turn_order[0] = std::make_shared<Battle_Pokemon>(&user), turn_order[1] = std::make_shared<Battle_Pokemon>(&ai);
	else
		turn_order[1] = std::make_shared<Battle_Pokemon>(&user), turn_order[0] = std::make_shared<Battle_Pokemon>(&ai);
}

int Battle_Event::compare_speeds() {
	if (user.modified_speed() > ai.modified_speed())
		return 1;
	if (user.modified_speed() < ai.modified_speed())
		return -1;
	if (user.modified_speed() == ai.modified_speed())
		return 0;
	return 99;
}

void Battle_Event::assign_turn_order(int i) {
	if (i == 1)
		turn_order[0] = std::make_shared<Battle_Pokemon>(&user), turn_order[1] = std::make_shared<Battle_Pokemon>(&ai);
	if (i==-1)
		turn_order[1] = std::make_shared<Battle_Pokemon>(&user), turn_order[0] = std::make_shared<Battle_Pokemon>(&ai);
	if (i == 0)
		random_turn_order();
}

//TODO this should be two functions
void Battle_Event::turn(std::shared_ptr<Battle_Pokemon> current, std::shared_ptr<Battle_Pokemon> opposing) {
	Battle_Event::current = current;
	Battle_Event::opposing = opposing;
	if (current->get_is_human())
		human_turn(*current);
	else
	ai_turn(*current);
	//display_moves();
	//select_move();
}

void Battle_Event::human_turn(Battle_Pokemon& bp) {
	int user_move_choice = -1;
	display_moves(bp);
	user_move_choice=select_move(bp);
	const Move& chosen_move = retrieve_move_from_map(bp, user_move_choice);
	if (is_stunned(bp))
		return;
	//break()
	determine_move_class(chosen_move);
	//check_fainted();
}

const Move& Battle_Event::retrieve_move_from_map(Battle_Pokemon& bp, int m) {
	std::string name = bp.get_battle_pokemon_name();
	const Move& move = *(Pokedex::gen1_default_movesets.at(name).at(m));
	if (!is_NULL_MOVE(move))
		return *(Pokedex::gen1_default_movesets.at(name).at(m));
	else
		select_move(bp);
}

void Battle_Event::ai_turn(Battle_Pokemon& bp) {

}

void Battle_Event::do_move(Battle_Pokemon& bp, const Move& chosen_move) {
	determine_move_class(chosen_move);
	//inflict_status_effect();
	//inflict_stats_change();
}

void Battle_Event::determine_move_class(const Move& move) {
	//if (move.is_target_enemy)
	//	move = Pokedex::gen1_moves.at("Growl");
}

//void Battle_Event::determine_attack_move(Battle_Pokemon* bp, const Move* move) {
//	if (move->is_stats_changing)
//		return_stats_changing_move();
//	else if(move->is_status_inflicting)
//	else
//		////
//}
//
//Stats_Value_Attack_Move Battle_Event::return_stats_changing_move()

void Battle_Event::do_defence_move(Battle_Pokemon& bp, const Move& move) {

}

void Battle_Event::inflict_damage(Battle_Pokemon& bp, const Attack_Move& move) {
		//int damage = (move->m_power * bp->modified_attack() / defending.defence) / 50 + 2 * critical() * random() * STAB * type * burn;
}

//TODO we're only couting pointer address
void Battle_Event::display_moves(Battle_Pokemon& bp) {
	std::string name = bp.get_battle_pokemon_name();
	const int MAKE_ARRRAY_HUMAN_READABLE = 1;
	for (int x = 0; x < MAX_MOVES; ++x)
		std::cout << x+MAKE_ARRRAY_HUMAN_READABLE << ": " << Pokedex::gen1_default_movesets.at(name).at(x)->m_name << std::endl;
}

int Battle_Event::select_move(Battle_Pokemon& bp)
{
	int choice;
	const int MAKE_ARRAY_ORDERING_HUMAN_READABLE = -1;
	//TODO probably needs try catch stuff
	std::cin >> choice;
	if(is_valid_move_choice(choice))
	return choice+MAKE_ARRAY_ORDERING_HUMAN_READABLE;
	else
	select_move(bp);
}

bool Battle_Event::is_valid_move_choice(int choice) {
	std::regex r ("[1-4]+");
	std::string string_choice = std::to_string(choice);
	return std::regex_match(string_choice,r);
}

bool Battle_Event::is_NULL_MOVE(const Move& move) {
	if (move.m_name == " ")
		return true;
	return false;
}

bool Battle_Event::is_stunned(Battle_Pokemon& bp){
	if (is_status_effect_a_stun(bp))
		return calculate_if_stunned(bp);
	return false;
}

bool Battle_Event::is_status_effect_a_stun(Battle_Pokemon& bp) {
	if (bp.get_status_effect() == status_effect_value::FREEZE)
		return true;
	if (bp.get_status_effect() == status_effect_value::PARALYSIS)
		return true;
	if (bp.get_status_effect() == status_effect_value::SLEEP)
		return true;
	return false;
}

bool Battle_Event::calculate_if_stunned(Battle_Pokemon& bp) {
	int lower_limit = 1;
	int max_limit = 100;
	int chance = rand() % max_limit + lower_limit;
	if (chance <= bp.get_stun_chance())
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
	const Gen1_Pokemon& pokemon = find_pokemon_from_map(choice);
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

const Gen1_Pokemon& Battle_Event::find_pokemon_from_map(std::string& choice) {
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
	const Gen1_Pokemon pokemon = (find_pokemon_from_map(choice));
	ai = Battle_Pokemon(pokemon);
	ai.set_ai();
}

void Battle_Event::battle() {

}
