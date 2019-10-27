#include<iostream>
#include<fstream>
using namespace std;

class Line {
public:
	int q, a;
	int min;	// min <= k <= max
	int max;
	int k;
	int x_min;
	int x_max;
	int y_min;
	int y_max;
	Line() {

	}

};

int main() {
	
	ifstream fin("line.inp");
	ofstream fout("line.out");

	Line L[100];

	int can = 0;	// 질문으로 k를 결정할수 있는지? -1 이면 불가
	int min_max = 0, max_min = 1000000000;	// min <= k <= max에서 min중 가장큰값
	int testcase;			// max 중 가장 작은값 넣는 변수
	fin >> testcase;

	// 테스트케이스 반복 시작
	for (int t = 0; t < testcase; t++) {

		// 질문 1개당 반복 시작
		int question;
		fin >> question;

		for (int i = 0; i < question; i++) {
			fin >> L[i].q >> L[i].a;
			if (L[i].a != 1) {
				// (x)k+(y) 에서 y값
				L[i].y_min = ((L[i].a - 1)*(L[i].a) / 2);
				L[i].y_max = ((L[i].a - 2)*(L[i].a - 1) / 2) + 1;
				// (x)k+(y) 에서 x값
				L[i].x_min = L[i].a;
				L[i].x_max = L[i].a - 1;
				// min <= k <= max
				// min
				if (((L[i].q - L[i].y_min) % L[i].x_min) == 0) {
					L[i].min = ((L[i].q - L[i].y_min) / L[i].x_min);
				}
				else {
					L[i].min = (((L[i].q - L[i].y_min) / L[i].x_min) + 1);
				}
				// max
				if (((L[i].q - L[i].y_max) % L[i].x_max) == 0) {
					L[i].max = ((L[i].q - L[i].y_max) / L[i].x_max);
				}
				else {
					L[i].max = ((L[i].q - L[i].y_max) / L[i].x_max);
				}
			}
			else {
				L[i].min = L[i].q;
				L[i].max = 1000000000;
			}
			
		}

		for (int i = 0; i < question; i++) {
			if (min_max < L[i].min) {
				min_max = L[i].min;
			}
			if (max_min > L[i].max) {
				max_min = L[i].max;
			}
			if (max_min == min_max) {
				fout << (i + 1) << ' ' << min_max << '\n';
				can = 1, max_min = 1000000000, min_max = 0;
				break;
			}
			else
				can = -1;
		}
		
		if (can == -1) {
			max_min = 1000000000, min_max = 0;
			fout << -1 << '\n';
		}
	}

}