/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */
#include <vector>
#include "../includes/stats.h"
//TODO fill in content

Stats::Stats(std::vector<PCB> &finished_vector) {
	vec = &finished_vector;
	av_wait_time = 0.0;
	av_turnaround_time = 0.0;
	av_response_time = 0.0;
}

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo() {
	for (int i = 0; i < vec->size(); i++) {
		std::cout << "Process " << vec->at(i).process_number << " "
				<< "required CPU time:" << vec->at(i).required_cpu_time
				<< " arrived:" << vec->at(i).arrival_time << " started:"
				<< vec->at(i).start_time << " finished:" << vec->at(i).finish_time << std::endl;
	}

}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_response_time() {
	double average = 0;
	for (int i = 0; i < vec->size(); i++) {
		av_response_time = vec->at(i).start_time - vec->at(i).arrival_time;
		average += av_response_time;
	}
	average /= vec->size();
	return average;
}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time() {
	double average = 0;
	for (int i = 0; i < vec->size(); i++) {
		av_turnaround_time = vec->at(i).finish_time - vec->at(i).arrival_time;
		average += av_turnaround_time;
	}
	average /= vec->size();
	return average;
}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time() {
	double average = 0;
	for (int i = 0; i < vec->size(); i++) {
		av_wait_time = vec->at(i).finish_time - vec->at(i).arrival_time - vec->at(i).required_cpu_time;
		average += av_wait_time;
	}
	average /= vec->size();
	return average;
}
