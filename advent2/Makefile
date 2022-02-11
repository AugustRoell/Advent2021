CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all: advent2_1 advent2_2

advent2_1: advent2_1.cpp advent2_1.hpp
	$(CXX) $(CXXFLAGS) $@.cpp -o $@

advent2_2: advent2_2.cpp advent2_2.hpp
	$(CXX) $(CXXFLAGS) $@.cpp -o $@

.PHONY: clean
clean:
	rm -f advent2_1 advent2_2
