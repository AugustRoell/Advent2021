//Advent day 4
//In order to find the first 5x5 board out of
//a set of 100 boards to get bingo, I save all
//the boards in a 3D 100x5x5 vector. Then I loop
//over all draws, and for each I check if it is
//located on a board, by looping over all boards.
//If it is located on a board, I change the value
//of another 100x5x5 vector from 0 to 1 at the
//same indices.

#include <iostream>
#include <vector>
#include <string>

int main() {
	unsigned int sum = 0;
	std::vector<std::vector<std::vector<unsigned int>>> boards (100, 
			std::vector<std::vector<unsigned int>>(5,
			       std::vector<unsigned int>(5))); // 3D vector containing 100 boards	
	
	std::vector<std::vector<std::vector<unsigned int>>> strikes (100, 
			std::vector<std::vector<unsigned int>>(5,
			       std::vector<unsigned int>(5))); // 3D vector that will track strikes
	
	std::vector<unsigned int> draws = {87,12,53,23,31,70,37,79,95,16,72,9,98,92,5,74,17,60,96,80,75,11,
		73,33,3,84,81,2,97,93,59,13,77,52,69,83,51,64,48,82,7,49,20,8,36,66,19,0,99,41,91,78,42,40,
		62,63,57,39,55,47,29,50,58,34,27,43,30,35,22,28,4,14,26,32,10,88,46,65,90,76,38,6,71,67,44,
		68,86,25,21,24,56,94,18,89,61,15,1,45,54,85}; // collection of 100 draws




	for(int i=0; i < 100; i++) {
		for(int j=0; j < 5; j++) {
			for(int k=0; k < 5; k++) {
				std::cin >> boards[i][j][k];
			}
		}
	}

	for(int d=0; d < 100; d++) {
		for(int i=0; i < 100; i++) {
			for(int j=0; j < 5; j++) {
				for(int k=0; k < 5; k++) {
					if(boards[i][j][k] == draws[d]) {
						strikes[i][j][k] = 1;
					}
				}
			}	
		}

		if(d>=4) {
			for(int i=0; i < 100; i++) {
				for(int j=0; j < 5; j++) {
					sum = 0;

					for(int k=0; k < 5; k++) {
						sum += strikes[i][j][k];
					}

					if(sum == 5) {
						std::cout << "Board " << i+1 << " has bingo on row " << j+1 <<
							" after a strike with " << draws[d] << "!\n\n";
						for(int j2=0; j2 < 5; j2++) {
							std::cout << "\n";
							for(int k2=0; k2 < 5; k2++) {
								std::cout << boards[i][j2][k2] << " ";
							}
						}
						std::cout << "\n";
						goto bingo;
					}
				}

				for(int k=0; k < 5; k++) {
					sum = 0;

					for(int j=0; j < 5; j++) {
						sum += strikes[i][j][k];
				
					}

					if(sum == 5) {
						std::cout << "Board " << i+1 << " has bingo on column " << k+1 <<
							" after a strike with " << draws[d] << "!\n\n";
						for(int j2=0; j2 < 5; j2++) {
							std::cout << "\n";
							for(int k2=0; k2 < 5; k2++) {
								std::cout << boards[i][j2][k2] << " ";
							}
						}
						std::cout << "\n";
						goto bingo;
					}
				}
			}
		}

		//Here you have to write some tripple loop over
		//strikes to check if any rows or columns have
		//been filled, and break the iteration if so.
		//Also clarify where the bingo was (specify i
		//and either j or k) and print the last draw


	}


bingo:
	std::cout << "\n\nIt's a bingo!\n\n";

	return 0;
}
