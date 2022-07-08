#include "Type.h"
#include <iostream>
#include <unordered_map>

int main() {
	std::cout << Type::BUG->get_type_name() << std::endl;
	std::cout << Type::NONE->get_type_name() << std::endl;
	for (auto x : Type::BUG->get_attack_matchups_map()) {
		std::cout << x.first<<", "<<*x.second;
		std::cout << std::endl;
	}
	for (auto x : Type::BUG->get_defence_matchups_map()) {
		std::cout << x.first << ", " << *x.second;
		std::cout << std::endl;
	}
	return 0;
}