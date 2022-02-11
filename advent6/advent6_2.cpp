#include <iostream>
#include <vector>

int main() {
	unsigned int days;
	size_t population, temp;

	std::vector<size_t> fish_count(9, 0);

	for(int i=0; i < 300; i++) {
		std::cin >> days;
		fish_count[days] += 1;
	}
	
	for(int d=0; d < 256; d++) {

		temp = fish_count[0];
		fish_count[0] = fish_count[1];
		fish_count[1] = fish_count[2];
		fish_count[2] = fish_count[3];
		fish_count[3] = fish_count[4];
		fish_count[4] = fish_count[5];
		fish_count[5] = fish_count[6];
		fish_count[6] = fish_count[7] + temp;
		fish_count[7] = fish_count[8];
		fish_count[8] = temp;
	}


	temp = 0;

	for(int i=0; i < 9; i++) {
		temp += fish_count[i];
	}

	std::cout << temp << "\n";

	return 0;
}
