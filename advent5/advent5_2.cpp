#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	std::vector<std::vector<unsigned int>> floor (1000, std::vector<unsigned int> (1000)); 
	// 2D vector representing the ocean floor

	std::vector<unsigned int> line (4);
	// 1D vector containing the start and end coordinates of every line

	unsigned int x_min, x_max, y_min, y_max, dist, spots=0;

	int x_i, y_i;

	for(int i=0; i < 500; i++) {
		for(int j=0; j < 4; j++) {
			std::cin >> line[j];
		}
		
		if(line[0] == line[2]) {
			if(line[1] < line[3]) {
				y_min = line[1];
				y_max = line[3];
				for(int y=y_min; y < y_max+1; y++) {
					floor[line[0]][y] += 1;
				}
			}

			else if(line[3] < line[1]) {
				y_min = line[3];
				y_max = line[1];
				for(int y=y_min; y < y_max+1; y++) {
					floor[line[0]][y] += 1;
				}
			}
		}
		
		else if(line[1] == line[3]) {
			if(line[0] < line[2]) {
				x_min = line[0];
				x_max = line[2];
				for(int x=x_min; x < x_max+1; x++) {
					floor[x][line[3]] += 1;
				}
			}

			else if(line[2] < line[0]) {
				x_min = line[2];
				x_max = line[0];
				for(int x=x_min; x < x_max+1; x++) {
					floor[x][line[3]] += 1;
				}
			}
		}

		else {
			if(line[0] < line[2]) {
				dist = line[2] - line[0] + 1;
				x_i = 1;
			}

			if(line[2] < line[0]) {
				dist = line[0] - line[2] + 1;
				x_i = -1;
			}

			if(line[1] < line[3]) {
				y_i = 1;
			}

			if(line[3] < line[1]) {
				y_i = -1;
			}

			for(int d=0; d < dist; d++) {
				floor[line[0]+x_i*d][line[1]+y_i*d] += 1;
			}
		}
	}
	
	for(int i=0; i < 1000; i++) {
		for(int j=0; j < 1000; j++) {
			if(floor[i][j] >= 2) {
				spots += 1;
			}
		}
	}

	std::cout << spots << "\n";

	return 0;
}
