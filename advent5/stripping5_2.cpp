//A little program that selects, out of a set of coordinate pairs
//of integers, all those pairs that describe lines that travel
//vertically, horizontally, or diagonally (45 degrees).
//However, turns out this is not at all necessary!
//The data file already only contains such lines.

#include <iostream>
#include <vector>

int main() {
	std::vector<unsigned int> line (4);

	unsigned int x_min, x_max, y_min, y_max;

	for(int i=0; i < 500; i++) {
		for(int j=0; j < 4; j++) {
			std::cin >> line[j];
		}
		
		if(line[0] == line[2] or line[1] == line[3]) {
			std::cout << line[0] << " " << line[1] << " " << line[2] << " " << line[3] << "\n";
		}

		else {
			if(line[0] < line[2]) {
				x_min = line[0];
				x_max = line[2];
			}
		
			if(line[2] < line[0]) {
				x_min = line[2];
				x_max = line[0];
			}

			if(line[1] < line[3]) {
				y_min = line[1];
				y_max = line[3];
			}
		
			if(line[3] < line[1]) {
				y_min = line[3];
				y_max = line[1];
			}


			if(x_max-x_min == y_max-y_min) {
				std::cout << line[0] << " " << line[1] << " " << line[2] << " " << line[3] << "\n";
			}
		}
	}
	return 0;
}
