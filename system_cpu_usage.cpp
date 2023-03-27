#include "system_cpu_usage.h"

std::vector<size_t> SystemCPU::get_cpu_times() {
	std::ifstream proc_stat("/proc/stat");
	proc_stat.ignore(5, ' ');
	std::vector<size_t> times;
	for (size_t time; proc_stat >> time; times.push_back(time));
	return times;
}

bool SystemCPU::get_cpu_times(size_t &idle_time, size_t &total_time) {
	const std::vector<size_t> cpu_times = get_cpu_times();
	if (cpu_times.size() < 4)
		return false;
	idle_time = cpu_times[3];
	total_time = std::accumulate(cpu_times.begin(), cpu_times.end(), 0);
	return true;
}

void SystemCPU::calc_system_usage() {
	int i=0;
	for (size_t idle_time, total_time; get_cpu_times(idle_time, total_time); sleep(1)) {
		++i;
		const float idle_time_delta = idle_time - previous_idle_time;
		const float total_time_delta = total_time - previous_total_time;
		const float utilization = 100.0 * (1.0 - idle_time_delta / total_time_delta);
		previous_idle_time = idle_time;
		previous_total_time = total_time;
		utili=utilization;
		if(i==2){
			i=0;
			break;
		}
	}
}

void SystemCPU::callUsage(){
	while(1){
		calc_system_usage();
		sleep(1);
	}
}

float SystemCPU::get_system_usage(){
	return utili;
}

void SystemCPU::runThread(){
	t1=std::thread(&SystemCPU::callUsage, this);
}

