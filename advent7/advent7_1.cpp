#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<unsigned int> pos;
	std::vector<size_t> dist_vec;
	unsigned int value, answer_i;
	size_t dist, answer;
	

	for(int i=0; i < 1000; i++) {
		std::cin >> value;
		pos.push_back(value);
	}

	unsigned int max = *std::max_element(pos.begin(), pos.end());

	for(int v=0; v < max+1; v++) {
		dist = 0;
		for(int i=0; i < 1000; i++) {
			if(v <= pos[i]) {
				dist += pos[i] - v;
			}

			else {
				dist += v - pos[i];
			}
		}
		dist_vec.push_back(dist);
	}

	answer_i = std::min_element(dist_vec.begin(), dist_vec.end())-dist_vec.begin();
	answer = *std::min_element(dist_vec.begin(), dist_vec.end());

	std::cout << answer_i << ' ' << answer << "\n";

	return 0;
}
