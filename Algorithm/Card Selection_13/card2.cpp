#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("card.inp");
ofstream fout("card.out");

int seq[1003];
int arr[1003][3];
bool flag[1003];
int n, result = -987654321;

int big(int index) {
	if (arr[index][0] > arr[index][1]) {
		if (arr[index][0] > arr[index][2]) {
			return arr[index][0];
		}
		else {
			return arr[index][2];
		}
	}
	else if (arr[index][0] <= arr[index][1]) {
		if (arr[index][1] > arr[index][2]) {
			return arr[index][1];
		}
		else {
			return arr[index][2];
		}
	}
}

int big2(int index) {
	if (arr[index][1] > arr[index][2])
		return arr[index][1];
	else {
		return arr[index][2];
	}
}

int main() {

	int testcase;
	fin >> testcase;

	while (testcase--) {

		//	입력
		fin >> n;
		flag[n] = true;
		for (int i = 1; i <= n; i++) {
			fin >> seq[i];
		}

		// 탐색
		arr[n - 1][0] = -987654321; arr[n][0] = seq[n]; arr[n + 1][0] = -987654321; arr[n + 2][0] = -987654321;
		arr[n - 1][1] = -987654321; arr[n][1] = -987654321; arr[n + 1][1] = -987654321; arr[n + 2][1] = -987654321;
		arr[n - 1][2] = -987654321;	arr[n][2] = -987654321; arr[n + 1][2] = -987654321; arr[n + 2][2] = -987654321;
		for (int i = n - 2; i >= 1; i--) {
			if (i != 1) {
				if (flag[i + 2] == true) {
					arr[i][0] = seq[i] + big(i + 2);
					arr[i][1] = seq[i] + big(i + 3);
					arr[i][2] = seq[i] + big(i + 4);
					if (arr[i + 2][0] == big(i + 2) && big(i + 2) != arr[i + 2][1] && big(i + 2) != arr[i + 2][2]) {
						flag[i] = false;
					}
				}
				else if (flag[i + 2] == false) {
					arr[i][0] = seq[i] + big2(i + 2);
					arr[i][1] = seq[i] + big(i + 3);
					arr[i][2] = seq[i] + big(i + 4);
					flag[i + 2] = true;
				}
			}
			else {
				arr[i][0] = -987654321;
				arr[i][1] = seq[i] + big(i + 3);
				arr[i][2] = seq[i] + big(i + 4);
			}
		}


		// 큰값 찾기
		result = -987654321;
		for (int i = 1; i <= 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (arr[i][j] > result) {
					result = arr[i][j];
				}
			}
		}

		// 출력
		fout << result << '\n';

		// 초기화
		for (int i = 0; i < 1003; i++) {
			seq[i] = 0;
			for (int j = 0; j < 3; j++) {
				arr[i][j] = 0;
			}
		}
		for (int i = 0; i < 1003; i++) {
			flag[i] = false;
		}
	}
}