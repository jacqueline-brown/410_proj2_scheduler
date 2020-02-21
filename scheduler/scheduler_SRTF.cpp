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

//TODO fill in content

//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	sort();
	return Scheduler::time_to_switch_processes(tick_count, p);
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	std::vector<PCB> newReady_Q;
	while(!ready_q->empty()) {
		newReady_Q.push_back(ready_q->front());
		ready_q->pop();
	}
	PCB temp;
	for (int i = 0; i < newReady_Q.size() - 1; i++) {
		for (int j = i + 1; i < newReady_Q.size(); j++) {
			int pcb = newReady_Q[i].remaining_cpu_time;
			int pcb2 = newReady_Q[j].remaining_cpu_time;
			if (pcb >  pcb2) {
				temp = newReady_Q[i];
				newReady_Q[i] = newReady_Q[j];
				newReady_Q[j] = temp;
			}
		}
	}
	for(int i = 0; i < newReady_Q.size(); i++) {
		ready_q->push(newReady_Q.at(i));
	}
}


