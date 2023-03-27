#ifndef CPU_USAGE_H
#define CPU_USAGE_H

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <cstring>
#include <unistd.h>
#include <thread>

enum proc_stat{
	pIdle = 11,
	uTime,
	sTime,
	cuTime,
	csTime,
	startTime = 20
};

struct cpu_info{
	double utime;
	double stime;
	double cutime;
	double cstime;
	double starttime;
	double uptime;
};

class CPU
{
private:
	std::string pid ;
	double usage;
	std::thread t1;
public:
	CPU();
	void calc_cpu_usage();
	double get_cpu_usage();
	void set_pid(std::string piid);
	void runThread();
	void callUsage();
};

#endif // CPU_USAGE_H
