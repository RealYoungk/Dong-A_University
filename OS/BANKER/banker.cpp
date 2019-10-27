#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct Request {
	string command;
	int pid;
	int source[50];
};

ifstream fin("banker.inp");
ofstream fout("banker.out");

int need[50][50], pmax[50][50], alloc[50][50];
int totalAlloc[50], availResource[50];
int resource_num, process_num;
int req_index = 0;
Request re;
vector < Request > wait;
vector < Request > req;
vector < Request >::iterator iter = req.begin();



void setTotalResource() {	
	// 총 사용 자원 개수 설정
	for (int i = 0; i < resource_num; i++) {
		fin >> availResource[i];
	}
}

void totalSubAlloc() {
	for (int i = 0; i < resource_num; i++) {
		availResource[i] -= totalAlloc[i];
	}
}

void setMax() {
	// 프로세스가 최대 요청 가능한 자원 수 설정
	for (int i = 0; i < process_num; i++) {
		for (int j = 0; j < resource_num; j++) {
			fin >> pmax[i][j];
		}
	}
}

void setAlloc() {
	for (int i = 0; i < process_num; i++) {
		for (int j = 0; j < resource_num; j++) {
			fin >> alloc[i][j];
			totalAlloc[j] += alloc[i][j];
		}
	}
}

void renewResource() {
	for (int i = 0; i < resource_num; i++) {
		availResource[i] -= totalAlloc[i];
	}
}

void setCommand() {
	fin >> re.command;
	fin >> re.pid;
	for (int i = 0; i < resource_num; i++) {
		fin >> re.source[i];
	}
	req.push_back(re);
}

void setNeed() {
	for (int i = 0; i < process_num; i++) {
		for (int j = 0; j < resource_num; j++) {
			need[i][j] = pmax[i][j] - alloc[i][j];
		}
	}
}

bool isSafe() {
	bool flag = false;
	int pid = re.pid;
	Request confirm_re;
	int virtual_avail[50];
	int virtual_need[50][50];
	for (int i = 0; i < resource_num; i++) {
		virtual_avail[i] = availResource[i];
	}
	for (int i = 0; i < process_num; i++) {
		for (int j = 0; j < resource_num; j++) {
			virtual_need[i][j] = need[i][j];
		}
	}
	// 현재이용가능 자원보다 요청 자원이 더 큰지 확인
	for (int i = 0; i < resource_num; i++) {
		if (re.source[i] > availResource[i]) {
			return false;
		}
	}
	// 요청을 받아줬다고 가정했을때
	// need에 실행 가능한 프로세스 있어야함
	
	// 이 프로세스를 실행했을때 need 확인
	if (req[req_index].command == "request") {
		confirm_re = req[req_index]; // 
	}
	else if (req[req_index].command == "release") {
		confirm_re = re;
	}
	if (flag == false) {
		for (int k = 0; k < resource_num; k++) {
			virtual_avail[k] -= confirm_re.source[k];
			virtual_need[confirm_re.pid][k] -= confirm_re.source[k];
		}
		flag = true;
	}
	int j;
	for (int i = 0; i < process_num;i++) {
		for (j = 0; j < resource_num ; j++) {
			if (virtual_need[i][j] > virtual_avail[j]) {
				break;
			}
		}
		if (j == resource_num) {
			return true;
		}
	}
	return false;
}

bool  isCorrectRequest() {
	// 필요한 자원보다 큰 요청(잘못된 요청) 거르기
	int pid = re.pid;
	for (int i = 0; i < resource_num; i++) {
		if (need[pid][i] < re.source[i]) {
			return false;
		}
	}
	return true;
}

void pushWait() {
	wait.push_back(re);
}

int isPop(int iter=-1) {	
	// wait큐에서 사용할 request가 있으면 wait index return 아니면 -1
	Request now_re;
	for (int j,i = iter + 1; i < wait.size(); i++) {
		now_re = wait[i];
		for (j = 0; j < resource_num; j++) {
			if (now_re.source[j] > availResource[j]) {
				break;
			}
		}
		if (j == resource_num) {	// 할당할 자원이 충분한경우
			return i;	// 현재 요청의 wait index를 반환
		}
	}
	return -1;
}

void printAvailableResource() {
	for (int i = 0; i < resource_num; i++) {
		fout << availResource[i] << ' ';
	}
	fout << '\n';
}

void allocation() {
	for (int i = 0; i < resource_num; i++) {
		// 현재 사용가능 자원에서 추가 사용자원 차감
		availResource[i] -= re.source[i];
		// 현재 할당된 자원 증가
		alloc[re.pid][i] += re.source[i];
		// 총 할당 자원 증가
		totalAlloc[i] += re.source[i];
	}
	setNeed();	// max - alloc 사용가능한 자원 업데이트
}

void returnResource() {
	for (int i = 0; i < resource_num; i++) {
		// 현재 사용가능 자원에서 반환받은 자원 추가
		availResource[i] += re.source[i];
		// 현재 할당된 자원 감소
		alloc[re.pid][i] -= re.source[i];
		// 총 할당자원 감소
		totalAlloc[i] -= re.source[i];
	}
	setNeed();
	// max - alloc 사용가능한 자원 업데이트
}

void processing() {
	if (re.command == "request") {
		// 프로세스가 자원을 요청한 경우
		if (!isCorrectRequest()) {
			// 올바른 요청이 아니므로 종료
			printAvailableResource();
		}
		else {	// 올바른 요청이 들어왔을때
			if (isSafe()) {
				// 안전상태인경우
				allocation();
				printAvailableResource();
			}
			else {
				// 안전 상태가 아닌경우
				pushWait();
				printAvailableResource();
			}
		}
	}
	else if (re.command == "release") {
		// 프로세스가 자원을 반환한 경우
		returnResource();
		// 자원을 반환받았는데 큐에서 실행시킬 프로세스가 생겼나?
		int wait_index = isPop();
		while (wait_index != -1) {	// 큐에서 실행시킬 프로그램이 있는경우
			re = wait[wait_index];	// 요청 불러옴
			if (isCorrectRequest()) {
				if (isSafe()) {
					allocation();
					wait.erase(wait.begin() + wait_index);
					wait_index--;
				}
			}
			wait_index = isPop(wait_index);
		}
		printAvailableResource();
	}
	else {	// quit 명령을 받은 경우
		return;
	}
}

int main() {

	fin >> process_num >> resource_num;
	setTotalResource();
	setMax();
	setAlloc();
	setNeed();
	totalSubAlloc();
	while (true) {
		setCommand();
		if (re.command == "quit") {	// quit명령시 종료
			break;
		}
	}
	for (int i = 0; i < req.size(); i++) {
		re = req[i];
		processing();
		req_index++;
	}
}
