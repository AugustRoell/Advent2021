//something

#include <iostream>
#include <string>

int main() {
	std::string line;
	unsigned int gamma[12] = {}, epsilon[12] = {}, tally[12] = {};

	for(int i=0; i < 1000; i++) {
		std::cin >> line;
		for(int j=0; j<12; j++) {
			tally[j] += line[j] - '0';
		}
	}

	for(int i=0; i < 12; i++) {
		if(tally[i] < 500) {
			gamma[i] = 0;
			epsilon[i] = 1;
		}
		else {
			gamma[i] = 1;
			epsilon[i] = 0;
		}
	}
	
	for(int i=0; i < 12; i++) {
		std::cout << gamma[i] << " ";
	}

	std::cout << "\n";
	
	for(int i=0; i < 12; i++) {
		std::cout << epsilon[i] << " ";
	}

	std::cout << "\n";

	return 0;
}
