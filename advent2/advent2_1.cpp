//Advent day 2
//I create a Submarine class
//wich has properties of horizontal
//position and depth, as well as methods
//to return those values as a pair,
//print the values, and change them.

#include "advent2_1.hpp"


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
