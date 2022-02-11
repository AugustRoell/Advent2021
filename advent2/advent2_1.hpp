#ifndef ADVENT2_1_HPP
#define ADVENT2_1_HPP

#include <utility>
#include <string>
#include <iostream>

class Submarine {
	public:
		Submarine(const int x = 0, const int d = 0) :
			x_(x), d_(d) {}
		
		std::pair<int, int> get_position() {
			std::pair<int, int> position = std::make_pair(x_, d_);
			return position;
		}

		void print_position() {
			std::cout << "(" << x_ << ", " << d_ << ")\n";
		}

		void change_position(const std::string direction, const int amount) {
			
			if(direction == "forward") {
				x_ += amount;
			}

			else if(direction == "down") {
				d_ += amount;
			}
			
			else if(direction == "up") {
				d_ -= amount;
			}
			
			else {
				std::cout << "Something went wrong with reading directions!\n";
			}	
			
			
		} 

	private:
		int x_;
		int d_;
};

#endif
