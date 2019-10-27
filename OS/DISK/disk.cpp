#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

ifstream fin("disk.inp");
ofstream fout("disk.out");

struct request{
	int arrive;
	int track;
};

vector <request> r;
int disktime = 0;
int set = 0;
int s;	// 서비스시간

void FCFS() {
	for (int i = 0; i < r.size(); i++) {
		if (r[i].arrive > disktime) {
			disktime = r[i].arrive;
		}
		disktime = disktime + abs(r[i].track - set) + s;
		set = r[i].track;
	}
}

void SSTF() {
	vector < request > wait;
	request req;
	int num = r.size();
	for (int j = 0; j < num; j++) {
		// 도착해서 대기하는애들 다 찾기
		for (int i = 0; i < r.size(); i++) {
			if (disktime >= r[i].arrive) {
				wait.push_back(r[i]);
			}
		}
		// wait 중 젤 가까운놈 찾기
		int length = 987654321, temp, index;
		for (int i = 0; i < wait.size(); i++) {
			temp = abs(set - wait[i].track);
			if (temp < length) { 
				length = temp; 
				index = i;
				req = wait[i];
			}
		}
		// 이제 실행
		if(wait.size() == 0) {	
			// wait에 없는경우 도착시간으로 초기화
			disktime = r[0].arrive;
			j--; continue;
		}
		disktime = disktime + abs(req.track - set) + s;
		set = req.track;

		// 실행한 req를 r벡터에서 삭제해주기
		for (int i = 0; i < r.size(); i++) {
			if (r[i].arrive == req.arrive && r[i].track == req.track) {
				r.erase(r.begin() + i);
				break;
			}
		}
		wait.clear();
	}
}

void LOOK() {
	vector < request > wait;
	request req;
	int num = r.size();
	bool turn = false;
	int count = 0;
	for (int j = 0; j < num; j++) {
		// 도착해서 대기하는애들 다 찾기
		for (int i = 0; i < r.size(); i++) {
			if (turn == false) {// 순방향일때
				if (disktime >= r[i].arrive && set <= r[i].track) {
					wait.push_back(r[i]);
				}
			}
			else if (turn == true) {// 역방향일때
				if (disktime >= r[i].arrive && set >= r[i].track) {
					wait.push_back(r[i]);
				}
			}
		}
		if ((wait.size() == 0) && (r.size() != 0)) {
			if (turn == false) {
				turn = true;
				count++;
			}
			else {
				turn = false;
				count++;
			}
			if (count >= 3) {
				int min_arrive = 987654321;
				for (int k = 0; k < r.size(); k++) {
					if (min_arrive > r[k].arrive) {
						min_arrive = r[k].arrive;
					}
				}
				disktime = min_arrive;
				count = 0;
			}
			j--;
			continue;
		}

		// wait 중 젤 가까운놈 찾기
		int length = 987654321, temp, index;
		for (int i = 0; i < wait.size(); i++) {
			temp = abs(set - wait[i].track);
			if (temp < length) {
				length = temp;
				index = i;
				req = wait[i];
			}
		}
		// 이제 실행
		if (req.arrive > disktime) {
			disktime = req.arrive;
		}
		disktime = disktime + abs(req.track - set) + s;
		set = req.track;

		// 실행한 req를 r벡터에서 삭제해주기
		for (int i = 0; i < r.size(); i++) {
			if (r[i].arrive == req.arrive && r[i].track == req.track) {
				r.erase(r.begin() + i);
				break;
			}
		}
		wait.clear();
	}
}

int main() {
	string kind;	// 알고리즘 종류
	int a, t;	// 도착시간, 트랙위치, 처리시간
	fin >> kind >> s;
	request req;	// 요청
	while (true) {
		fin >> a >> t;
		req.arrive = a, req.track = t;
		if (a == -1 && t == -1)break;
		r.push_back(req);
	}

	if (kind == "FCFS") {
		FCFS();
		fout << disktime << ' ' << set;
	}
	else if (kind == "SSTF") {
		SSTF();
		fout << disktime << ' ' << set;
	}
	else if (kind == "LOOK") {
		LOOK();
		fout << disktime << ' ' << set;
	}
	else {
		return -1;
	}
}

