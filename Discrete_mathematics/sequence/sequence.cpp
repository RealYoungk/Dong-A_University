#include<iostream>
#include<fstream>
using namespace std;

class Sequence {
public:
	long long A;
	long long L;
	long long term;
	Sequence() {
		term = 0;
	}
};

int main() {
	
	ifstream fin("sequence.inp");
	ofstream fout("sequence.out");

	Sequence s;

	for (int i = 0;; i++) {
		
		fin >> s.A >> s.L;

		if (s.A == -1 && s.L == -1) break;	// -1인경우 testcase종료

		for (long long tmp = s.A;;) {

			if (tmp == 1) {
				s.term++;
				break;				// step2에 의해 멈춤
			}

			if (tmp > s.L) {
				//s.term++;
				break;
			}				// limit보다 크면 종료

			if (tmp % 2 == 0) {
				tmp = tmp / 2;
				s.term++;
			}
			else if (tmp % 2 == 1) {
				tmp = (tmp * 3) + 1;
				s.term++;
			}

		}

		fout << "Case " << (i + 1) << ": A = " << s.A << ", limit = " << s.L << ", number of terms = " << s.term << '\n';
		s.term = 0;
	}
}
	
	