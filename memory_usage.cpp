#include "memory_usage.h"

Memory::Memory()
{

}
void Memory::set_pid(std::string piid){
	pid=piid;
}
void Memory::calc_memory_usage(){
	std::string aa="/proc/"+pid+"/status";

	std::ifstream f(aa);
	std::string s;

	for (int i = 1; i <= LINE; i++)
		std::getline(f, s);

	mm=s;
}
void Memory::callUsage(){
	while(1){
		calc_memory_usage();
		sleep(1);
	}
}


std::string Memory::get_memory_usage(){
	return mm;
}

void Memory::runThread(){
	t1=std::thread(&Memory::callUsage, this);
}

