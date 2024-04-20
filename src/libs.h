#ifndef LIBS_H
#define LIBS_H 1
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>

#ifdef __WIN32
	#define PATH_SEPARATOR '\\'
#else
	#define PATH_SEPARATOR '/'
#endif

// short-hand
#define PSEP PATH_SEPARATOR

// make program verbose
#define DEBUG 

#endif
