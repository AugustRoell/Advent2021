#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

bool length_compare(std::string a, std::string b) {  return(a.length() < b.length());  }

std::unordered_map<std::string,unsigned int> decoder(std::vector<std::string> signal) {
	std::unordered_map<std::string,unsigned int> decoded_map;
	std::sort(signal.begin(), signal.end(), length_compare);

//output an unordered map e.g.  (a:c, d:g, ...), containing the decoding of intput fragments to the original order.
//


}

