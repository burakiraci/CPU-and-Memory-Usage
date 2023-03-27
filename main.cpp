#include <numeric>
#include <unistd.h>
#include <thread>
#include "cpu_usage.h"
#include "system_cpu_usage.h"
#include "memory_usage.h"
#include "system_memory_usage.h"
int main(int argc, char* argv[])
{
	CPU cpu;
	SystemCPU sys_cpu;
	Memory mem;
	SystemMemory sys_mem;
	if(argc<=1) {}
	else{
		cpu.set_pid(argv[1]);
		mem.set_pid(argv[1]);
	}
	sys_mem.runThread();
	sys_cpu.runThread();
	cpu.runThread();
	mem.runThread();
	while (true) {
		if(argc<=1){;
			std::cout<<"Memory Usage: "<<sys_mem.get_memory_usage()<<std::endl;
			std::cout<<"System CPU Usage: %"<<sys_cpu.get_system_usage()<<std::endl;
		}
		else{
			std::cout<<"Application CPU Usage: %"<<cpu.get_cpu_usage()<<std::endl;
			std::cout<<mem.get_memory_usage()<<std::endl;
		}
		sleep(1);
	}
	return 0;
}

