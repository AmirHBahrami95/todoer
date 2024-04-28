#ifndef UTILS_H
#define UTILS_H 1

#include "./libs.h"

namespace utils{

	// for string delimiter
	std::vector<std::string> split(const std::string& s, char delim);
	std::string get_currdate_str();
	bool str_ends_with(const std::string& s1,const std::string& s2);
}

#else
// nothing
#endif
