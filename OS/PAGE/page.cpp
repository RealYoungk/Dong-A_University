
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

ifstream fin("page.inp");
ofstream fout("page.out");
// ������
struct refRow {
	int pid;
	int page;
	int arrive;	// flag�� 0�̸� �ٲ㵵�� 1�̸� ����Ÿ�ֿ̹�
	int use;
	int next;
};

vector < refRow > r;	// ���μ������� �迭
vector < refRow > memory;	// �޸� ��Ȳ
vector < vector < refRow > > memory2;

int use_index;
int frame_num = 0;	// ������ ��[�ִ� 100]
int page_fault_num = 0;	// ������ ��Ʈ ��
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
	// ������������ ������� v2���ִ°� v���� �ϳ��� ���� ����
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
	if (v.size() != 1) {	// �ΰ��̻� �̷��� ���� ���� �ʴ°��
		int compareArrive = v[0].arrive;
		int index = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].arrive < compareArrive) {
				compareArrive = v[i].arrive;
				index = i;
			}
		}
		// �޸𸮿��� �Ȱ������� ã�Ƽ� �ε�����ȯ
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
		// �Ҵ�� ���μ����� �ִ��� Ȯ��
		if (isAllocated(temp.pid)) {
			// ã�� �������� ���� ���
			if (!isExist(temp.pid, temp.page)) {
				// ���̺��� �� �� ���
				if (isFull(temp.pid)) {
					// ���̺��� �� �� ���
					replaceIndex = findFifoIndex(temp.pid);
					memory[replaceIndex].arrive = temp.arrive;
					memory[replaceIndex].page = temp.page;
					memory[replaceIndex].pid = temp.pid;
					page_fault_num++;
				}
				else {
					// ���̺��� �� �� ���
					memory.push_back(temp);
					page_fault_num++;	// ��������Ʈ
				}
			}
		}
		// ���μ����� �Ҵ���� ���� ���
		else {
			memory.push_back(temp);
			page_fault_num++;	// ��������Ʈ
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
		// �Ҵ�� ���μ����� �ִ��� Ȯ��
		if (isAllocated(temp.pid)) {
			// ã�� �������� ���� ���
			if (!isExist(temp.pid, temp.page)) {
				// ���̺��� �� �� ���
				if (isFull(temp.pid)) {
					// ���̺��� �� �� ���
					replaceIndex = findOptIndex(temp.pid, i + 1);
					memory[replaceIndex].arrive = temp.arrive;
					memory[replaceIndex].page = temp.page;
					memory[replaceIndex].pid = temp.pid;
					memory[replaceIndex].use = i;
					page_fault_num++;
				}
				else {
					// ���̺��� �� �� ���
					temp.use = i;
					memory.push_back(temp);
					page_fault_num++;	// ��������Ʈ
				}
			}
			// ã���������� �־ ����� ���
			else {
				memory[use_index].use = i;
			}
		}
		// ���μ����� �Ҵ���� ���� ���
		else {
			memory.push_back(temp);
			page_fault_num++;	// ��������Ʈ
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
		// �Ҵ�� ���μ����� �ִ��� Ȯ��
		if (isAllocated(temp.pid)) {
			// ã�� �������� ���� ���
			if (!isExist(temp.pid, temp.page)) {
				// ���̺��� �� �� ���
				if (isFull(temp.pid)) {
					// ���̺��� �� �� ���
					replaceIndex = findLruIndex(temp.pid);
					memory[replaceIndex].arrive = temp.arrive;
					memory[replaceIndex].page = temp.page;
					memory[replaceIndex].pid = temp.pid;
					memory[replaceIndex].use = i;
					page_fault_num++;
				}
				else {
					// ���̺��� �� �� ���
					temp.use = i;
					memory.push_back(temp);
					page_fault_num++;	// ��������Ʈ
				}
			}
			// ã���������� �־ ����� ���
			else {
				memory[use_index].use = i;
			}
		}
		// ���μ����� �Ҵ���� ���� ���
		else {
			memory.push_back(temp);
			page_fault_num++;	// ��������Ʈ
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