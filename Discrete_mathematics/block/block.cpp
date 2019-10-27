#include <iostream>
#include <fstream>

using namespace std;

int arr[1000][1000] = {};

void botBlock(int &t, int &l, int &r) {
	
	// top을 모를때
	if ((t == -1) && (l != -1) && (r != -1)) {
		t = (l + r) % 100;
	}
	// left를 모를때
	else if ((t != -1) && (l == -1) && (r != -1)) {
		l = (t - r);
		if (l < 0) {
			l = l + 100;
		}
	}
	// right를 모를때
	else if ((t != -1) && (l != -1) && (r == -1)) {
		r = (t - l);
		if (r < 0) {
			r = r + 100;
		}
	}
}

void block(int &t, int &l, int &r) {

	// top을 모를때
	if ((t == -1) && (l != -1) && (r != -1)) {
		t = (l + r) % 100;
	}
	// left를 모를때
	else if ((t != -1) && (l == -1) && (r != -1)) {
		l = (t - r);
		if (l < 0) {
			l = l + 100;
		}
	}
	// right를 모를때
	else if ((t != -1) && (l != -1) && (r == -1)) {
		r = (t - l);
		if (r < 0) {
			r = r + 100;
		}
	}
	// 2개 이상 모를때는 일단 암것도안함
}

int main() {

	ifstream fin("block.inp");
	ofstream fout("block.out");

	int testcase;	// 테스트케이스 수
	int high;		// 배열 높이

	fin >> testcase;

	for (int i = 0; i < testcase; i++) {
		
		fin >> high;

		// 배열값 입력받기
		for (int j = 0; j < high; j++) {
			for (int k = 0; k <=j; k++) {
				fin >> arr[j][k];
			}
		}

		// 계산
		for (int o = 0; o < high; o++) {
			for (int j = 0; j < high - 1; j++) {
				for (int k = 0; k <= j; k++) {
					block(arr[j][k], arr[j + 1][k], arr[j + 1][k + 1]);
				}
			}
		}
		// 밑줄 계산
		for (int o = 0; o < high; o++) {
			for (int k = 0; k < high - 1; k++) {
				botBlock(arr[high - 2][k], arr[high - 1][k], arr[high - 1][k + 1]);
			}
		}

		// 배열값 출력
		for (int j = 0; j < high; j++) {
			for (int k = 0; k <= j; k++) {
				fout << arr[j][k] << ' ';
			}
			fout << '\n';
		}
	}

}