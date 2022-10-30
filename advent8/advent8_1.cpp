#include <iostream>
#include <string>
#include <vector>

int main() {
	
	unsigned int count = 0, File_Length = 200;
	std::string line;
	std::vector<std::vector<std::string>> DOV (File_Length, std::vector<std::string> (4));

	for(int i=0; i<File_Length; i++) {
		for(int j=0; j<15; j++) {
			std::cin >> line;
			if(j>10) {
				//DOV[i][j-11] = line;
				if (line.length() == 2 || line.length() == 3 || 
						line.length() == 4 || line.length() == 7) {
					count += 1;
				}
			}
		}
	}

	std::cout << "The numbers 1, 4, 7, and 8 occured " << count << " times\n";

	return 0;
}
