#include <iostream>
#include <vector>

int main() {
	std::vector<unsigned int> line (4);

	for(int i=0; i < 500; i++) {
		for(int j=0; j < 4; j++) {
			std::cin >> line[j];
		}

		if(line[0] == line[2] or line[1] == line[3]) {
			std::cout << line[0] << " " << line[1] << " " << line[2] << " " << line[3] << "\n";
		}
	}
	return 0;
}
