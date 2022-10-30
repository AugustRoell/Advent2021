//something

#include <iostream>
#include <string>
#include <vector>

int common(std::vector<std::string> v, unsigned int j, unsigned int size) {
	unsigned int r = 0;
	for(size_t i=0; i < size; i++) {
		r += (int)v[i][j] - 48; 
	} 

	if(2*r >= size) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	std::string line;
	std::vector<std::string> vector;
	size_t size;

	std::cin >> size;

	for(size_t i=0; i < size; i++) {
		std::cin >> line;
		vector.push_back(line);
	}

	int c = common(vector, 5, size);

	for(size_t i=0; i < size; i++) {
		if((int)vector[i][5] - 48 == c) {
			std::cout << vector[i] << "\n";
		}
	}

	return 0;
}
