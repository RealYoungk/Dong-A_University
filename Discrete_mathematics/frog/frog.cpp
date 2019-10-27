#include <iostream>
#include <fstream>
using namespace std;

class Stone {
public:
	char kind;
	int point;
	int flag;	// 큰돌이면 2 밟은 돌이면 1 안밟은 돌이면 0
	char trash; // 스래기값 넣을 자료형
	Stone() {
		kind = 'B';
		point = 0;
		flag = 2;
	}
};

int main() {

	ifstream fin("frog.inp");
	ofstream fout("frog.out");

	int testcase;
	fin >> testcase;
	for (int i = 0; i < testcase; i++) {
		char trash;
		int num;	// 돌의 개수
		int river;	// 강의 넓이
		//int flag = 0;	// 직전에 S돌을 밟으면 1 아니면 0
		int start = 0;	// 시작지점
		int interval = 0;	// 최대 점프 거리
		int S_count = 0;	// Small 돌 밟은 개수 초기값 0;
		Stone s[100];
		fin >> num >> river;
		for (int j = 1; j <= num; j++) {
			fin >> s[j].kind >> s[j].trash >> s[j].point;
		}
		s[num + 1].kind = 'B';
		s[num + 1].point = river;

		// S돌 하나 건너서 뛰기 1
		for (int j = 0; j <= num + 1; j++) {
			int temp;
			if (s[j].kind == 'B') {
				temp = s[j].point - start;
				if (temp > interval) {
					interval = temp;
				}
				start = s[j].point;
			}
			else if (s[j].kind == 'S') {
				temp = s[j].point - start;
				if (s[j - 1].kind == 'S') {
					// 전의 돌이 flag가 1이나 2인경우
					// 개구리는 점프를하고 0으로 표시함
					// 이번 턴에선 0인 돌만 밟음
					if ((s[j - 1].flag == 2) || (s[j - 1].flag == 1)) {
						s[j].flag = 0;
						if (temp > interval) {
							interval = temp;
						}
						start = s[j].point;
					}
					else {
						s[j].flag = 1;
					}
				}
				else {	// 전의 돌이 B인경우
					if (temp > interval) {
						interval = temp;
					}
					start = s[j].point;
					s[j].flag = 0;
				}
			}
		}

		// S돌 하나 건너서 뛰기 2
		// 아까 안밟은 S돌 (1로 표시됨)
		// 이번턴에 밟기
		start = 0;
		// 안밟은 S돌을 마저 밟고 B는 무조건 밟고
		for (int j = 0; j <= num + 1; j++) {
			int temp;
			if (s[j].kind == 'B') {
				temp = s[j].point - start;
				if (temp > interval) {
					interval = temp;
				}
				start = s[j].point;
			}
			else if (s[j].kind == 'S') {
				temp = s[j].point - start;
				if (s[j].flag == 1 || s[j].flag == 2) {	// 밟음
					if (temp > interval) {
						interval = temp;
					}
					start = s[j].point;
				}
			}
		}
		fout << "Case " << (i + 1) << ": " << interval << '\n';
	}
}