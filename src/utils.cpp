#include "./utils.h"

namespace utils{

	std::vector<std::string> split(const std::string& s, char delim) {
		std::stringstream ss(s);
		std::string item;
		std::vector<std::string> elems;
		while (std::getline(ss, item, delim))
			// elems.push_back(item);
			elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
		return elems;
	}

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
		
		// free(timeinfo);
		// timeinfo=nullptr;

		std::string res=buffer;
		return res;
	}

	bool str_ends_with(const std::string& s1,const std::string& s2){
		if(s1.length() < s2.length()) return false;

		for(int i=s1.length()-1,j=s2.length()-1;i>=0 && j>=0;i--,j--)
			if(s1[i]!=s2[j]) return false;

		return true;
	}


};
