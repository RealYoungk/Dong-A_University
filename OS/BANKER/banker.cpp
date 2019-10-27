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
	// �� ��� �ڿ� ���� ����
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
	// ���μ����� �ִ� ��û ������ �ڿ� �� ����
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
	// �����̿밡�� �ڿ����� ��û �ڿ��� �� ū�� Ȯ��
	for (int i = 0; i < resource_num; i++) {
		if (re.source[i] > availResource[i]) {
			return false;
		}
	}
	// ��û�� �޾���ٰ� ����������
	// need�� ���� ������ ���μ��� �־����
	
	// �� ���μ����� ���������� need Ȯ��
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
	// �ʿ��� �ڿ����� ū ��û(�߸��� ��û) �Ÿ���
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
	// waitť���� ����� request�� ������ wait index return �ƴϸ� -1
	Request now_re;
	for (int j,i = iter + 1; i < wait.size(); i++) {
		now_re = wait[i];
		for (j = 0; j < resource_num; j++) {
			if (now_re.source[j] > availResource[j]) {
				break;
			}
		}
		if (j == resource_num) {	// �Ҵ��� �ڿ��� ����Ѱ��
			return i;	// ���� ��û�� wait index�� ��ȯ
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
		// ���� ��밡�� �ڿ����� �߰� ����ڿ� ����
		availResource[i] -= re.source[i];
		// ���� �Ҵ�� �ڿ� ����
		alloc[re.pid][i] += re.source[i];
		// �� �Ҵ� �ڿ� ����
		totalAlloc[i] += re.source[i];
	}
	setNeed();	// max - alloc ��밡���� �ڿ� ������Ʈ
}

void returnResource() {
	for (int i = 0; i < resource_num; i++) {
		// ���� ��밡�� �ڿ����� ��ȯ���� �ڿ� �߰�
		availResource[i] += re.source[i];
		// ���� �Ҵ�� �ڿ� ����
		alloc[re.pid][i] -= re.source[i];
		// �� �Ҵ��ڿ� ����
		totalAlloc[i] -= re.source[i];
	}
	setNeed();
	// max - alloc ��밡���� �ڿ� ������Ʈ
}

void processing() {
	if (re.command == "request") {
		// ���μ����� �ڿ��� ��û�� ���
		if (!isCorrectRequest()) {
			// �ùٸ� ��û�� �ƴϹǷ� ����
			printAvailableResource();
		}
		else {	// �ùٸ� ��û�� ��������
			if (isSafe()) {
				// ���������ΰ��
				allocation();
				printAvailableResource();
			}
			else {
				// ���� ���°� �ƴѰ��
				pushWait();
				printAvailableResource();
			}
		}
	}
	else if (re.command == "release") {
		// ���μ����� �ڿ��� ��ȯ�� ���
		returnResource();
		// �ڿ��� ��ȯ�޾Ҵµ� ť���� �����ų ���μ����� ���峪?
		int wait_index = isPop();
		while (wait_index != -1) {	// ť���� �����ų ���α׷��� �ִ°��
			re = wait[wait_index];	// ��û �ҷ���
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
	else {	// quit ����� ���� ���
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
		if (re.command == "quit") {	// quit��ɽ� ����
			break;
		}
	}
	for (int i = 0; i < req.size(); i++) {
		re = req[i];
		processing();
		req_index++;
	}
}
