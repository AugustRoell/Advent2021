#ifndef ADVENT2_2_HPP
#define ADVENT2_2_HPP

#include <utility>
#include <string>
#include <iostream>

class Submarine {
	public:
		Submarine(const int x = 0, const int d = 0, const int aim = 0) :
			x_(x), d_(d), aim_(aim) {}
		
		std::pair<int, int> get_position() {
			std::pair<int, int> position = std::make_pair(x_, d_);
			return position;
		}

		int get_aim() {
			return aim_;
		}

		void print_position() {
			std::cout << "(" << x_ << ", " << d_ << ")\n";
		}


		void change_position(const std::string direction, const int amount) {
			
			if(direction == "forward") {
				x_ += amount;
				d_ += amount*aim_;
			}

			else if(direction == "down") {
				aim_ += amount;
			}
			
			else if(direction == "up") {
				aim_ -= amount;
			}
			
			else {
				std::cout << "Something went wrong with reading directions!\n";
			}	
			
			
		} 

	private:
		int x_;
		int d_;
		int aim_;
};

#endif
