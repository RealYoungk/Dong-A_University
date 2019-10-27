#include <iostream>
#include <fstream>

using namespace std;

int arr[1000][1000] = {};

void botBlock(int &t, int &l, int &r) {
	
	// top�� �𸦶�
	if ((t == -1) && (l != -1) && (r != -1)) {
		t = (l + r) % 100;
	}
	// left�� �𸦶�
	else if ((t != -1) && (l == -1) && (r != -1)) {
		l = (t - r);
		if (l < 0) {
			l = l + 100;
		}
	}
	// right�� �𸦶�
	else if ((t != -1) && (l != -1) && (r == -1)) {
		r = (t - l);
		if (r < 0) {
			r = r + 100;
		}
	}
}

void block(int &t, int &l, int &r) {

	// top�� �𸦶�
	if ((t == -1) && (l != -1) && (r != -1)) {
		t = (l + r) % 100;
	}
	// left�� �𸦶�
	else if ((t != -1) && (l == -1) && (r != -1)) {
		l = (t - r);
		if (l < 0) {
			l = l + 100;
		}
	}
	// right�� �𸦶�
	else if ((t != -1) && (l != -1) && (r == -1)) {
		r = (t - l);
		if (r < 0) {
			r = r + 100;
		}
	}
	// 2�� �̻� �𸦶��� �ϴ� �ϰ͵�����
}

int main() {

	ifstream fin("block.inp");
	ofstream fout("block.out");

	int testcase;	// �׽�Ʈ���̽� ��
	int high;		// �迭 ����

	fin >> testcase;

	for (int i = 0; i < testcase; i++) {
		
		fin >> high;

		// �迭�� �Է¹ޱ�
		for (int j = 0; j < high; j++) {
			for (int k = 0; k <=j; k++) {
				fin >> arr[j][k];
			}
		}

		// ���
		for (int o = 0; o < high; o++) {
			for (int j = 0; j < high - 1; j++) {
				for (int k = 0; k <= j; k++) {
					block(arr[j][k], arr[j + 1][k], arr[j + 1][k + 1]);
				}
			}
		}
		// ���� ���
		for (int o = 0; o < high; o++) {
			for (int k = 0; k < high - 1; k++) {
				botBlock(arr[high - 2][k], arr[high - 1][k], arr[high - 1][k + 1]);
			}
		}

		// �迭�� ���
		for (int j = 0; j < high; j++) {
			for (int k = 0; k <= j; k++) {
				fout << arr[j][k] << ' ';
			}
			fout << '\n';
		}
	}

}