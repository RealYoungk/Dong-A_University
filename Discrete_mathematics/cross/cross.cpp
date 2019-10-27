#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;

class Cross {
public:
	int n;	// 숫자의 갯수
	int size;	// 집합의 크기
	int arr[2][10000] = {};	// 집합 저장할 배열
	int index[10000] = {};	// 똑같은 값을가지는 배열 인덱스
	int count = 0;	// 교차점 개수
};

int main() {

	ifstream fin("cross.inp");
	ofstream fout("cross.out");

	Cross cross;
	int testcase;
	fin >> testcase;
	for (int i = 0; i < testcase; i++) {	//	corss 탐색 시작
		fin >> cross.size;
		for (int j = 0; j < cross.size; j++) {	// 배열에 성분넣기
			fin >> cross.arr[0][j];
		}
		for (int k = 0; k < cross.size; k++) {	// 배열에 성분넣기 2
			fin >> cross.arr[1][k];
		}
		// 똑같은값 찾기 시작
		for (int j = 0; j < cross.size; j++) {
			for (int k = 0; k < cross.size; k++) {
				if (cross.arr[0][j] == cross.arr[1][k]) {
					cross.index[j] = k;
				}
			}
		}
		// 교차점 개수 찾기 시작
		for (int j = 0; j < cross.size-1; j++) {
			for (int k = j + 1; k < cross.size; k++) {
				if (cross.index[j] > cross.index[k]) {
					cross.count++;
				}
			}
		}
		fout << "Case " << i+1 << ": " << cross.count << '\n';
		cross.count = 0;
		memset(cross.arr, 0, 10000);
		memset(cross.index, 0, 10000);
	}
}