//Day 1 of adventofcode2021
//Out of a .txt file of depth measurements
//how many measurements are greater than
//those directly before.
//Can probably be optimized much more.
//I decided to not save the measurements
//in a container, but rather only save
//two measurements at any time.

#include <iostream>

int main() {
	unsigned int line_new, line_old, result;
	result = 0;
	for(int i=0; i<2000; i++) {
		if(i==0) {
			std::cin >> line_new;
			line_old = line_new;
		}
		else {
			std::cin >> line_new;
				if(line_old < line_new) {
					result += 1;
			} 
			line_old = line_new;
		}
	}
	std::cout << result << "\n";
	return 0;
}
