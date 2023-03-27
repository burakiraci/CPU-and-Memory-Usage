#include "system_memory_usage.h"

SystemMemory::SystemMemory()
{

}

void SystemMemory::calc_memory_usage(){

	std::string aa="/proc/meminfo";

	std::ifstream f(aa);
	std::string s;

	for (int i = 1; i <= LINE; i++)
		std::getline(f, s);

	mm=s;

}

void SystemMemory::callUsage(){
	while(1){
	calc_memory_usage();
	sleep(1);
}
}

std::string SystemMemory::get_memory_usage(){
	return mm;
}

void SystemMemory::runThread()
{
	t1=std::thread(&SystemMemory::callUsage, this);
}
