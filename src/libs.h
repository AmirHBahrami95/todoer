#ifndef LIBS_H
#define LIBS_H 1
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#ifdef __WIN32
	
	// TODO test this program on some windows dude
	#define PATH_SEPARATOR '\\'
	#define PLATFORM_ENDLINE "\r\n"
	#define USER_HOME getenv("HOMEDRIVE")+getenv("HOMEPATH")
#else
	#define PATH_SEPARATOR '/'
	#define PLATFORM_ENDLINE "\n"
	#define USER_HOME getenv("HOME")
#endif

#define VALUE_SEPARATOR ','
#define VALSEP VALUE_SEPARATOR

// short-hand
#define PSEP PATH_SEPARATOR
#define PL_ENDL PLATFORM_ENDLINE

#endif
