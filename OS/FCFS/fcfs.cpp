#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

struct process {
	int pid;
	int arriveTime;
	int cpuUsingTime;
};

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

vector<process> pro;

int findWaitingTime(int numberOfProcess) {
	int totalProcessing = pro[0].arriveTime;
	int totalWaitingTime = totalProcessing;
	for (int i = 0; i < numberOfProcess - 1; i++) {
		totalProcessing = totalProcessing + pro[i].cpuUsingTime;
		if (totalProcessing >= pro[i + 1].arriveTime) {
			totalWaitingTime = totalWaitingTime + totalProcessing - pro[i + 1].arriveTime;
		}
		else {
			totalProcessing = pro[i + 1].arriveTime;
		}
	}
	return totalWaitingTime;
}

int main() {
	
	ifstream fin("fcfs.inp");
	ofstream fout("fcfs.out");

	int numberOfProcess;
	process p;
	
	fin >> numberOfProcess;
	for (int i = 0; i < numberOfProcess; i++) {
		fin >> p.pid >> p.arriveTime >> p.cpuUsingTime;
		pro.push_back(p);
	}

	sort(pro.begin(), pro.end(), compare);

	int result = findWaitingTime(numberOfProcess);

	fout << result;

	return 0;
}