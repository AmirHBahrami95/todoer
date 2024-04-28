#ifndef LIBS_H
#define LIBS_H 1
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#ifdef __WIN32
	#define PATH_SEPARATOR '\\'
	#define PLATFORM_ENDLINE "\r\n"
#else
	#define PATH_SEPARATOR '/'
	#define PLATFORM_ENDLINE "\n"
#endif

#define VALUE_SEPARATOR ','
#define VALSEP VALUE_SEPARATOR

// short-hand
#define PSEP PATH_SEPARATOR
#define PL_ENDL PLATFORM_ENDLINE

#endif
