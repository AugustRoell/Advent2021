//Advent day 5
//In order to find the last board to get a bingo
//I use almost the same program as before.
//Now, however, instead of outputting the data
//of the first bingo and exiting, I save the
//turn of the first bingo of a board in a vector
//and at the end I output the board and turn
//corresponding to the last board to get a bingo.
//I also print the numbers of that board that are
//left, where the bingoed numbers are replaced
//by 0. Notice, that the loop over draws goes
//over all draws, so that this output is initially
//all zeroes. In order to get the correct output
//of the board, rerun the program, but now only
//looping over the draws until the turn the last
//board gets a bingo.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
	unsigned int max_ind, max, sum = 0;
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

	std::vector<unsigned int> b_turn (100, 0); // keeps track of the turn on which a board gets bingo




	for(int i=0; i < 100; i++) {
		for(int j=0; j < 5; j++) {
			for(int k=0; k < 5; k++) {
				std::cin >> boards[i][j][k];
			}
		}
	}

	for(int d=0; d < 89; d++) {
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

					if(sum == 5 and b_turn[i] == 0) {
						b_turn[i] = d;
					}
				}

				for(int k=0; k < 5; k++) {
					sum = 0;

					for(int j=0; j < 5; j++) {
						sum += strikes[i][j][k];
				
					}

					if(sum == 5 and b_turn[i] == 0) {
						b_turn[i] = d;
					}
				}
			}
		}
	}
	
	max_ind = std::max_element(b_turn.begin(), b_turn.end()) - b_turn.begin();
	max = *std::max_element(b_turn.begin(), b_turn.end());

	std::cout << "\n\nBoard " << max_ind+1 << " bingo's last, on turn " << max+1 << ", striking " <<
		draws[max] << "!\n\nBy then the board looks like: \n";

	for(int j=0; j < 5; j++) {
		std::cout << "\n";
		for(int k=0; k < 5; k++) {
			if(strikes[max_ind][j][k] == 0) {
				std::cout << boards[max_ind][j][k] << " ";
			}
			else {
				std::cout << 0 << " ";
			}
		}
	}
	
	return 0;
}
