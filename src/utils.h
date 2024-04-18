#ifndef UTILS_H
#define UTILS_H 1

#include "./libs.h"

namespace utils{

	std::string get_currdate_str(){
		time_t rawtime;
		struct tm* timeinfo;
		char buffer[80];
		time (&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(
			buffer,
			sizeof(buffer),
			"%Y-%m-%d",
			timeinfo
		);

		std::string res=buffer;
		return res;
	}
}

#else
// nothing
#endif
