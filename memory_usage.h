#ifndef MEMORY_USAGE_H
#define MEMORY_USAGE_H
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <numeric>
#include <unistd.h>

class Memory
{
private:
	std::string pid;
	const int LINE = 22;
	std::string mm;
	std::thread t1;
public:
	Memory();
	void calc_memory_usage();
	void set_pid(std::string);
	std::string get_memory_usage();
	void runThread();
	void callUsage();
};

#endif // MEMORY_USAGE_H

