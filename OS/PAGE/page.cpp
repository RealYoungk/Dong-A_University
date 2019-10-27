
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

ifstream fin("page.inp");
ofstream fout("page.out");
// 참조열
struct refRow {
	int pid;
	int page;
	int arrive;	// flag가 0이면 바꿔도됨 1이면 다음타이밍에
	int use;
	int next;
};

vector < refRow > r;	// 프로세스들의 배열
vector < refRow > memory;	// 메모리 상황
vector < vector < refRow > > memory2;

int use_index;
int frame_num = 0;	// 프레임 수[최대 100]
int page_fault_num = 0;	// 페이지 폴트 수
int replaceIndex;



void readRefRow() {
	refRow temp;
	for (int i = 0;; i++) {
		fin >> temp.pid >> temp.page;
		temp.arrive = i;
		temp.use = -1;
		temp.next = 210000000;
		r.push_back(temp);
		if (r[i].pid == -1 && r[i].page == -1) {
			r.erase(r.begin() + i);
			break;
		}
	}
}

bool isAllocated(int pid) {
	for (int i = 0; i < memory.size(); i++) {
		if (pid == memory[i].pid) {
			return true;
		}
	}
	return false;
}

bool isFull(int pid) {
	int count = 0;
	for (int i = 0; i < memory.size(); i++) {
		if (memory[i].pid == pid) {
			count++;
		}
		if (count == frame_num) {
			return true;
		}
	}
	return false;
}

bool isExist(int pid, int page) {
	for (int i = 0; i < memory.size(); i++) {
		if (memory[i].pid == pid && memory[i].page == page) {
			use_index = i;
			return true;
		}
	}
	return false;
}

int findFifoIndex(int pid) {
	vector < refRow > v;
	int max;
	for (int i = 0; i < memory.size(); i++) {
		if (memory[i].pid == pid) {
			v.push_back(memory[i]);
		}
	}
	max = v[0].arrive;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].arrive < max) {
			max = v[i].arrive;
		}
	}
	for (int i = 0; i < memory.size(); i++) {
		if (max == memory[i].arrive) {
			return i;
		}
	}
	return -1;
}

int findLruIndex(int pid) {
	vector < refRow > v;
	int min;
	for (int i = 0; i < memory.size(); i++) {
		if (memory[i].pid == pid) {
			v.push_back(memory[i]);
		}
	}
	min = v[0].use;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].use < min) {
			min = v[i].use;
		}
	}
	for (int i = 0; i < memory.size(); i++) {
		if (min == memory[i].use) {
			return i;
		}
	}
	return -1;
}

int findOptIndex(int pid, int start) {
	vector < refRow > v;
	vector < refRow > v2;
	int max;
	for (int i = 0; i < memory.size(); i++) {
		if (memory[i].pid == pid) {
			v.push_back(memory[i]);
		}
	}
	for (int i = start; i < r.size(); i++) {
		if (r[i].pid == pid) {
			v2.push_back(r[i]);
		}
	}
	// 이중포문으로 순서대로 v2에있는거 v에서 하나씩 삭제 고고싱
	int temp_arrive;
	bool flag = false;
	for (int i = 0; i < v2.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v2[i].page == v[j].page && v2[i].pid == v[j].pid) {
				v.erase(v.begin() + j);
				if (v.size() == 1) {
					temp_arrive = v[0].arrive; flag = true; break;
				}
			}
		}
		if (flag == true) break;
	}
	if (v.size() != 1) {	// 두개이상 미래에 실행 하지 않는경우
		int compareArrive = v[0].arrive;
		int index = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].arrive < compareArrive) {
				compareArrive = v[i].arrive;
				index = i;
			}
		}
		// 메모리에서 똑같은놈을 찾아서 인덱스반환
		for (int j = 0; j < memory.size(); j++) {
			if (v[index].arrive == memory[j].arrive) {
				return j;
			}
		}
	}
	for (int i = 0; i < memory.size(); i++) {
		if (temp_arrive == memory[i].arrive) {
			return i;
		}
	}
	return -1;
}

void fifo() {
	refRow temp;
	for (int i = 0; i < r.size(); i++) {
		temp = r[i];
		// 할당된 프로세스가 있는지 확인
		if (isAllocated(temp.pid)) {
			// 찾는 페이지가 없는 경우
			if (!isExist(temp.pid, temp.page)) {
				// 테이블이 꽉 찬 경우
				if (isFull(temp.pid)) {
					// 테이블이 꽉 찬 경우
					replaceIndex = findFifoIndex(temp.pid);
					memory[replaceIndex].arrive = temp.arrive;
					memory[replaceIndex].page = temp.page;
					memory[replaceIndex].pid = temp.pid;
					page_fault_num++;
				}
				else {
					// 테이블이 덜 찬 경우
					memory.push_back(temp);
					page_fault_num++;	// 페이지폴트
				}
			}
		}
		// 프로세스가 할당되지 않은 경우
		else {
			memory.push_back(temp);
			page_fault_num++;	// 페이지폴트
		}
	}
}

void printFifo() {
	fout << "FIFO: " << page_fault_num << '\n';
	for (int i = 0; i < memory.size(); i++) {
		fout << i << ' ' << memory[i].pid << ' ' << memory[i].page << '\n';
	}
	page_fault_num = 0;
	memory.clear();
}

void opt() {
	refRow temp;
	for (int i = 0; i < r.size(); i++) {
		temp = r[i];
		// 할당된 프로세스가 있는지 확인
		if (isAllocated(temp.pid)) {
			// 찾는 페이지가 없는 경우
			if (!isExist(temp.pid, temp.page)) {
				// 테이블이 꽉 찬 경우
				if (isFull(temp.pid)) {
					// 테이블이 꽉 찬 경우
					replaceIndex = findOptIndex(temp.pid, i + 1);
					memory[replaceIndex].arrive = temp.arrive;
					memory[replaceIndex].page = temp.page;
					memory[replaceIndex].pid = temp.pid;
					memory[replaceIndex].use = i;
					page_fault_num++;
				}
				else {
					// 테이블이 덜 찬 경우
					temp.use = i;
					memory.push_back(temp);
					page_fault_num++;	// 페이지폴트
				}
			}
			// 찾는페이지가 있어서 사용한 경우
			else {
				memory[use_index].use = i;
			}
		}
		// 프로세스가 할당되지 않은 경우
		else {
			memory.push_back(temp);
			page_fault_num++;	// 페이지폴트
			memory[memory.size() - 1].use = i;
		}
	}
}

void printOpt() {
	fout << "OPT: " << page_fault_num << '\n';
	for (int i = 0; i < memory.size(); i++) {
		fout << i << ' ' << memory[i].pid << ' ' << memory[i].page << '\n';
	}
	page_fault_num = 0;
	memory.clear();
}

void lru() {
	refRow temp;
	for (int i = 0; i < r.size(); i++) {
		temp = r[i];
		// 할당된 프로세스가 있는지 확인
		if (isAllocated(temp.pid)) {
			// 찾는 페이지가 없는 경우
			if (!isExist(temp.pid, temp.page)) {
				// 테이블이 꽉 찬 경우
				if (isFull(temp.pid)) {
					// 테이블이 꽉 찬 경우
					replaceIndex = findLruIndex(temp.pid);
					memory[replaceIndex].arrive = temp.arrive;
					memory[replaceIndex].page = temp.page;
					memory[replaceIndex].pid = temp.pid;
					memory[replaceIndex].use = i;
					page_fault_num++;
				}
				else {
					// 테이블이 덜 찬 경우
					temp.use = i;
					memory.push_back(temp);
					page_fault_num++;	// 페이지폴트
				}
			}
			// 찾는페이지가 있어서 사용한 경우
			else {
				memory[use_index].use = i;
			}
		}
		// 프로세스가 할당되지 않은 경우
		else {
			memory.push_back(temp);
			page_fault_num++;	// 페이지폴트
			memory[memory.size() - 1].use = i;
		}
	}
}

void printLru() {
	fout << "LRU: " << page_fault_num << '\n';
	for (int i = 0; i < memory.size(); i++) {
		fout << i << ' ' << memory[i].pid << ' ' << memory[i].page << '\n';
	}
	page_fault_num = 0;
	memory.clear();
}

int main() {

	fin >> frame_num;

	readRefRow();

	fifo();
	printFifo();

	lru();
	printLru();

	opt();
	printOpt();
}