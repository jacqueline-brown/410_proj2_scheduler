/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */
#include "../includes/scheduler_SRTF.h"
#include <vector>
#include <algorithm>
//TODO fill in content

bool compareRemaining_cpu_time(PCB pcb1, PCB pcb2);

//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	if (0 >= p.remaining_cpu_time) {
			return true;
		}
	if(p.remaining_cpu_time  > ready_q->front().remaining_cpu_time & !ready_q->empty()){
		return true;
	}
	return false;
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	std::vector<PCB> newReady_Q;
	while(!ready_q->empty()) {
		newReady_Q.push_back(ready_q->front());
		ready_q->pop();
	}
	std::sort(newReady_Q.begin(), newReady_Q.end(), compareRemaining_cpu_time);

	for(PCB process:newReady_Q) {
		process.arrival_time;
		ready_q->push(process);
	}
}

bool  compareRemaining_cpu_time(PCB pcb1, PCB pcb2 ) {
	return pcb1.remaining_cpu_time < pcb2.remaining_cpu_time;

}


