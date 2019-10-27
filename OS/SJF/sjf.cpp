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

vector<process> pro;
vector<process> ready;

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

int findWaitingTime(int numberOfProcess) {
	int totalProcessing = pro[0].arriveTime;
	int totalWaitingTime = totalProcessing;

	while(true) {
		for (int i = 0; i < pro.size(); i++) {
			if (pro[i].arriveTime <= totalProcessing) {
				ready.push_back(pro[i]);
				pro.erase(pro.begin() + i); i--;
			}
		}

		if (ready.empty()) {
			ready.push_back(pro[0]);
			totalProcessing = pro[0].arriveTime;
			pro.erase(pro.begin());
		}

		// ready 큐에서 실행순서대로 정렬
		sort(ready.begin(), ready.end(), sjfCompare);
		
		if (ready[0].arriveTime <= totalProcessing) {
			totalWaitingTime = totalWaitingTime + totalProcessing - ready[0].arriveTime;
			totalProcessing = totalProcessing + ready[0].cpuUsingTime;
			ready.erase(ready.begin());
		}

		if (ready.empty() && pro.empty()) break;
	}

	return totalWaitingTime;
}

int main() {

	ifstream fin("sjf.inp");
	ofstream fout("sjf.out");

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