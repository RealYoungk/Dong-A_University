#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Matrix {
public:
	int n;
	int nByN[300][300] = {};
};

int main() {
	ifstream fin("matrix.inp");
	ofstream fout("matrix.out");

	Matrix m;	// 메트릭스 객체
	int count;	// testcase수
	int sum;	// 
	int c=0;		// 확인한 배열값의 수
	fin >> count;	// testcase수
	
	for (int i = 0; i < count; i++) {	// testcase 반복
		fin >> m.n;	// 정방행렬 n
		for (int j = 0; j < m.n; j++) {	// 배열 데이터 입력받기
			for (int k = 0; k < m.n; k++) {
				fin >> m.nByN[j][k];
			}
		}
		for (int j = 0; j < m.n; j++) {	// 배열 행
			for (int k = 0; k < m.n; k++) {	// 배열 열
				if(m.nByN[j][k] != 0 && m.nByN[j][k] != 1){	// 값이 0,1이 아니면
					for (int l = 0; l < m.n; l++) {	// 행과 열의 합을 구하는 반복문
						for (int o = 0; o < m.n; o++) {
							sum = m.nByN[l][k] + m.nByN[j][o];
							if (sum == m.nByN[j][k]) {
								c++;
								goto outerLoop;
							}
						}
					}
				}
				else if(m.nByN[j][k] == 1){
					c++;
				}
			outerLoop:;	// 반복문 빠져나오는 레이블
			}
		}
		if (c == m.n*m.n) {
			fout << '1' << '\n';
			memset(m.nByN, 0, sizeof(m.nByN));
			c = 0;
		}
		else {
			fout << '0' << '\n';
			memset(m.nByN, 0, sizeof(m.nByN));
			c = 0;
		}
	}
}