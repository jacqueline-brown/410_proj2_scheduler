/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */
#include "../includes/scheduler_FIFO.h"
//TODO fill in content


//override base class behaviour if necessary, otherwise call it
bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p) {
	return (0 >= p.remaining_cpu_time);
}

//FIFO - not preemptive - no sorting needed
void Scheduler_FIFO::sort() {

}

