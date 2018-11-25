/*
#ifndef LOG_H
#define LOG_H

#include <initializer_list>
#include <string>
#include <iostream>
#include <fstream>
#include "Path.hpp"

const char *LogIn = "data/meetings.csv";
const char *LogOut;

class Log {
public:
	Log();
private:
	std::ifstream inLog(LogIn, std::ios::in);
	std::ofstream outLog;
};


#endif // !LOG_H
*/