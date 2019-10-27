#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main() {

	ifstream fin("exam.inp");
	ofstream fout("exam.out");

	int check;	// check가 거짓이면 0
	int testcase;
	fin >> testcase;
	for (int t = 0; t < testcase; t++) {
		char goodArr[26];	// 좋은 문자열
		char mainArr[1000];	// 케이스 배열
		fin >> goodArr >> mainArr;

		fout << "Test Case: #" << (t + 1) << '\n';
		// 판독 시작
		int count;	// 질의어 수
		fin >> count;
		for (int i = 0; i < count; i++) {
			// 판독할 문자열 받기
			char arr[1000];
			fin >> arr;
			for (int j = 0, n = 0; j < strlen(mainArr); j++,n++) {
				// 문자가 ? 인경우
				if (mainArr[j] == '?') {
					for (int k = 0; k < strlen(goodArr); k++) {
						if (arr[n] == goodArr[k]) {
							check = 1;
							break;
						}
						else
							check = 0;
					}
				}
				// 문자가 * 인경우
				else if (mainArr[j] == '*') {
					int goodNum = 0;	// 좋은문자의 개수
					int starSize = strlen(arr) - strlen(mainArr) + 1;
					for (int k = 0; k < starSize; k++) {
						char temp = arr[n + k];
						for (int m = 0; m < strlen(goodArr); m++) {
							if (temp == goodArr[m]) {
								goodNum++;
								break;
							}
						}
					}

					if (goodNum >= starSize && (starSize != 0)) {
						check = 0;
						n = n + starSize - 1;
					}
					else {
						n = n + starSize - 1;
						check = 1;
					}
					
					
					
					
					
					
					/*int goodNum = 0;
					int starSize = strlen(arr) - strlen(mainArr) + 1;
					for (int k = 0; k < starSize; k++) {
						check = 0;
						char temp = arr[n + k];
						for (int m = 0; m < strlen(goodArr); m++) {
							if (temp == goodArr[m]) {
								check = 0;
								goodNum++;
							}
							else {
								check = 1;
							}
						}
						if (check == 1 && (goodNum != starSize)) {
							n = n + starSize - (k + 1);
							break;
						}
					}
					if (starSize < 1) {
						n--;
					}
					*/
				}
				// 문자가 소,대문자인경우
				else {
					if (mainArr[j] == arr[n]) {
						check = 1;
					}
					else check = 0;
				}

				// check 판별
				if (check == 0) {
					fout << "No\n";
					break;
				}
			}
			if (check == 1) {
				fout << "Yes\n";
			}
		}
	}

}