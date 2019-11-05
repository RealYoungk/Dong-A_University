#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream fin("pandora.inp");
ofstream fout("pandora.out");

string s;

bool isEnd(int i) {
	if (i > s.size()) { return true; }
	else return false;
}

int pandora() {
	int result = 2;
	int lcount = 0, rcount = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'L') lcount++;
		if (s[i] == 'R') rcount++;
	}


	if (lcount >= rcount) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'R') {
				if (!isEnd(i + 1) && (s[i + 1] == 'R')) {
					result = 1;
					if (!isEnd(i + 2) && s[i + 2] == 'R') {
						result = 0;
						return result;
					}
					for (int j = i + 3; j < s.size(); j++) {
						if (s[j] == 'R') {
							if (!isEnd(j + 1) && s[j + 1] == 'R') {
								if ((j - i) % 2 == 1) {
									result = 0;
									return result;
								}
							}
						}
					}
				}
			}
		}
		return result;
	}


	else if (lcount < rcount) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'L') {
				if (!isEnd(i + 1) && (s[i + 1] == 'L')) {
					result = 1;
					if (!isEnd(i + 2) && s[i + 2] == 'L') {
						result = 0;
						return result;
					}
					for (int j = i + 3; j < s.size(); j++) {
						if (s[j] == 'L') {
							if (!isEnd(j + 1) && s[j + 1] == 'L') {
								if ((j - i) % 2 == 1) {
									result = 0;
									return result;
								}
							}
						}
					}
				}
			}
		}
		return result;
	}
}

int main() {
	int testcase;
	fin >> testcase;
	while (testcase--) {
		fin >> s;
		s.append(s.begin(), s.begin() + 2);
		fout << pandora() << '\n';
	}
}