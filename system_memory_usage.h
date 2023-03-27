#ifndef SYSTEM_MEMORY_USAGE_H
#define SYSTEM_MEMORY_USAGE_H
#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <unistd.h>
#include <vector>
#include <thread>
class SystemMemory
{
private:
	const int LINE = 7;
	std::string mm;
	std::thread t1;
public:
	SystemMemory();
	void calc_memory_usage();
	std::string get_memory_usage();
	void callUsage();
	void runThread();
};

#endif // SYSTEM_MEMORY_USAGE_H
