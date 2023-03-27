#include "cpu_usage.h"

CPU::CPU()
{

}
void CPU::set_pid(std::string piid){
	pid=piid;
}

void CPU::calc_cpu_usage()
{
	cpu_info inf;
	int i=0;
	char filePath[50] = "/proc/";
	strcat(filePath, pid.c_str());
	strcat(filePath, "/stat");

	std::ifstream fileStat;
	fileStat.open(filePath, std::ios_base::in);
	std::string word;

	int count = 0;
	fileStat.ignore(256, ')');

	while(fileStat >> word){
		count++;
		if(count == proc_stat::uTime){
			inf.utime = std::stod(word) ;
		}
		else if(count == proc_stat::sTime){
			inf.stime = std::stod(word);
		}
		else if(count == proc_stat::cuTime){
			inf.cutime = std::stod(word);
		}
		else if(count == proc_stat::csTime){
			inf.cstime = std::stod(word);
		}
		else if(count == proc_stat::startTime){
			inf.starttime = std::stod(word);
		}
		else{

		}
	}
	fileStat.close();

	char uptimePath[50] = "/proc/uptime";
	std::ifstream fileUptime;
	fileUptime.open(uptimePath);
	std::string uptime_str;
	fileUptime >> uptime_str;
	inf.uptime = std::stod(uptime_str);
	fileUptime.close();
	double hertz = sysconf(_SC_CLK_TCK);

	double total_time = inf.utime + inf.stime;
	total_time = total_time + inf.cstime+inf.cutime;
	double seconds = inf.uptime - (inf.starttime / hertz);
	double cpu_usage = 100 * ((total_time / hertz) / seconds);
	usage=cpu_usage;
}
void CPU::callUsage(){
	while(1){
		calc_cpu_usage();
		sleep(1);
	}
}


double CPU::get_cpu_usage(){
	return usage;
}


void CPU::runThread(){
	t1=std::thread(&CPU::callUsage, this);
}
