#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#define MAX 987654321
using namespace std;

int totalProcessing;
int totalWaitingTime;
int presentTime = 0;

struct process {
	int pid;
	int arriveTime;
	int cpuUsingTime;
	int waitTime;
	process() {
		waitTime = 0;
	}
};

vector < process > wait;
vector < process > ready;
vector < process > eend;

void plusWaitTime() {
	for (int i = 1; i < ready.size(); i++) {
		ready[i].waitTime++;
	}
}

int getSumOfWaitingTime() {
	int result = 0;
	for (int i = 0; i < eend.size(); i++) {
		result = result + eend[i].waitTime;
	}
	return result;
}

void waitToReady() {
	for (int i = 0; i < wait.size(); i++) {
		if (wait[i].arriveTime <= totalProcessing) {
			ready.push_back(wait[i]);
			wait.erase(wait.begin() + i); i--;
		}
	}
}

bool compare(process p1, process p2) {
	if (p1.arriveTime < p2.arriveTime) {
		return true;
	}
	else if (p1.arriveTime > p2.arriveTime) {
		return false;
	}
	else {
		if (p1.pid < p2.pid) {
			return true;
		}
		else return false;
	}
}

bool sjfCompare(process p1, process p2) {
	if (p1.cpuUsingTime < p2.cpuUsingTime) {
		return true;
	}
	else if (p1.cpuUsingTime > p2.cpuUsingTime) {
		return false;
	}
	else {
		if (p1.arriveTime < p2.arriveTime) {
			return true;
		}
		else if (p1.arriveTime > p2.arriveTime) {
			return false;
		}
		else {
			if (p1.pid < p2.pid) {
				return true;
			}
			else return false;
		}
	}
}

void processRun() {

	while (true) {
		ready[0].cpuUsingTime--;
		plusWaitTime();
		totalProcessing++;

		if (ready[0].cpuUsingTime <= 0) {
			eend.push_back(ready[0]);
			ready.erase(ready.begin());
			waitToReady();
			sort(ready.begin(), ready.end(), sjfCompare);
		}

		if (!ready.empty()) {
			waitToReady();
			sort(ready.begin(), ready.end(), sjfCompare);
		}
		else if (!wait.empty() && ready.empty()) {
			totalProcessing = wait[0].arriveTime;
			waitToReady();
		}

		if (ready.empty() && wait.empty()) {
			return;
		}
	}
}

int main() {

	ifstream fin("srtf.inp");
	ofstream fout("srtf.out");

	int numberOfProcess;
	process p;

	fin >> numberOfProcess;
	for (int i = 0; i < numberOfProcess; i++) {
		fin >> p.pid >> p.arriveTime >> p.cpuUsingTime;
		wait.push_back(p);
	}

	sort(wait.begin(), wait.end(), compare);

	waitToReady();

	processRun();

	int result = getSumOfWaitingTime();

	fout << result;

	return 0;
}