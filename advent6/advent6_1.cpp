#include <iostream>
#include <vector>

int main() {
	unsigned int days;
	size_t population, counter;

	std::vector<unsigned int> fish;

	for(int i=0; i < 300; i++) {
		std::cin >> days;
		fish.push_back(days);
	}

	for(int d=0; d < 80; d++) {

		counter = 0;
		population = fish.size();

		for(size_t i=0; i < population; i++) {
			if(fish[i] == 0) {
				fish[i] = 6;
				counter += 1;
			}

			else {
				fish[i] -= 1;
			}
		}

		for(size_t c=0; c < counter; c++) {
			fish.push_back(8);
		}
	}

	std::cout << fish.size() << "\n";

	return 0;
}
