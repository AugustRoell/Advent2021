//Advent day 2
//I change the Submarine class
//so that, now, up and down influence
//the aim of the submarine.
//Nothing else changes!

#include "advent2_2.hpp"


int main () {
	std::string line, direction;
	int amount;

	Submarine submarine;

	for(int i=0; i < 2000; i++) {
		std::cin >> line;
		if(i%2 == 0) {
			direction = line;
		}
		else {
			amount = stoi(line);
			submarine.change_position(direction, amount);
		}
	}

	submarine.print_position();

	return 0;
}
