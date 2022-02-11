//Day 1 of adventofcode2021
//Similar to the first challenge.
//However, now we compare sequences
//of three deapth measurements with
//the next..

#include <iostream>

void array_shift(int arr[4], int line) {
	arr[0] = arr[1];
	arr[1] = arr[2];
	arr[2] = arr[3];
	arr[3] = line;
}

int array_sum_old (int arr[4]) {
	int sum = arr[0] + arr[1] + arr[2];
	return sum;
}

int array_sum_new (int arr[4]) {
	int sum = arr[1] + arr[2] + arr[3];
	return sum;
}

int main() {
	unsigned int result = 0;
	int line_new;
	int array[4];
	for(int i=0; i < 2000; i++) {
		if(i < 4) {
			std::cin >> array[i];
		}

		else {
			if(array_sum_old(array) < array_sum_new(array)) {
				result += 1;
			} 
			std::cin >> line_new;
			array_shift(array, line_new);
		}
	}

	if(array_sum_old(array) < array_sum_new(array)) {
		result += 1;
	}

	std::cout << result << "\n";
	return 0;
}
