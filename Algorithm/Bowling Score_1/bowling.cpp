#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

ifstream fin("bowling.inp");
ofstream fout("bowling.out");

struct score {
	int fir, sec;
	int sum;
	bool strike;
	bool spare;
	int last;
	score() {
		strike = false;
		spare = false;
		last = 0;
	}
};

int main() {
	int testcase;
	fin >> testcase;
	while (testcase--) {	// 볼링 1게임
		int fir = 0, sec = 0, last = 0;
		score s[10];
		// 1~9frame
		for (int i = 0; i < 9; i++) {

			fin >> fir;
			if(fir != 10){
				fin >> sec;
			}
			else {
				sec = 0;
			}
			s[i].fir = fir; s[i].sec = sec;
			s[i].sum = fir + sec;

			if (s[i].sum == 10) {
				if (fir == 10) {	// strike
					s[i].strike = true;
				}
				else {	// spare
					s[i].spare = true;
				}
			}
		}
		// 10frame
		fin >> fir >> sec;
		s[9].fir = fir; s[9].sec = sec;
		s[9].sum = fir + sec;
		if (s[9].sum >= 10) {
			fin >> s[9].last;
		}
		else {
			s[9].last = 0;
		}
		s[9].sum = fir + sec + s[9].last;

		if (s[9].sum == 10) {
			if (fir == 10) {
				s[9].strike = true;
			}
			else {
				s[9].spare = true;
			}
		}

		// 점수계산 시작
		int result = 0;
		for (int i = 0; i < 9; i++) {
			result = result + s[i].sum;
			if (s[i].spare) {
				result = result + s[i + 1].fir;
			}
			else if (s[i].strike) {
				result = result + s[i + 1].fir + s[i + 1].sec;
				//if ((s[i + 1].fir + s[i + 1].sec) > 10) {
				//	result = result - 10;
				//}
				if (s[i + 1].fir == 10 && (i + 1) != 9) {
					result = result + s[i + 1].sec;
					if (s[i + 1].sec == 0) {
						result = result + s[i + 1].last;
						if (s[i + 1].last == 0) {
							result = result + s[i + 2].fir;
						}
					}
				}
			}
		}
		// 9frame


		// 10frame
		result = result + s[9].sum;

		fout << result << '\n';
	}
}