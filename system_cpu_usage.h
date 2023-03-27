#ifndef SYSTEM_CPU_USAGE_H
#define SYSTEM_CPU_USAGE_H
#include <fstream>
#include <iostream>
#include <numeric>
#include <unistd.h>
#include <vector>
#include <thread>
class SystemCPU{
private:
	float utili=0.0;
	size_t previous_idle_time=0, previous_total_time=0;
	std::thread t1;
public:
	std::vector<size_t> get_cpu_times() ;
	bool get_cpu_times(size_t &idle_time, size_t &total_time);
	void calc_system_usage() ;
	float get_system_usage();
	void runThread();
	void callUsage();
};

#endif // SYSTEM_CPU_USAGE_H
