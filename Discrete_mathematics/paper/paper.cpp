#include<iostream>
#include<fstream>
using namespace std;

// 종이는 한 point를 기준으로 합이 3or1인 규칙이 있음
class Paper {
public:
	int N, M;	// N x M
	int column[50][50];	// 세로 데이터 입력값을 저장할 배열
	int width[50][50];	// 가로 데이터 입력값을 저장할 배열
	int sum;	// sum이 1 or 3 이면 됨
	bool isPaper;	// 접을수 있는 종이인지 판별 하는것

	int f() {	// 한 점을 기준으로 둘러쌓인 값들의 합을 구하는 함수
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M - 1; j++) {
				sum = column[i][j] + column[i + 1][j] + width[i][j + 1] + width[i][j];
				if (sum != 1 && sum != 3) {	// 참이 아닌경우
					isPaper = false;
					return 0;
				}
				else isPaper = true;
			}
		}
		if (isPaper) return 1;
	}
};

int main() {

	ifstream fin("paper.inp");
	ofstream fout("paper.out");

	Paper p;

	int t;

	fin >> t;

	for (int testcase = 0; testcase < t; testcase++) {
		// N M 입력받기
		fin >> p.N >> p.M;

		// 세로 데이터 입력
		for (int i = 0; i < p.N; i++) {
			for (int j = 0; j < p.M - 1; j++) {
				fin >> p.column[i][j];
			}
		}
		// 가로 데이터 입력
		for (int i = 0; i < p.N - 1; i++) {
			for (int j = 0; j < p.M; j++) {
				fin >> p.width[i][j];
			}

		}
		// 종이를 판별한다.
		fout << p.f() << ' ';
	}
}