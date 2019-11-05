#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

ifstream fin("palindrome.inp");
ofstream fout("palindrome.out");

int lcs[1001][1001];

int main() {
	int testcase;
	fin >> testcase;
	while (testcase--) {

		vector<char> str;
		vector<char> str2;
		string str_temp;
		char c;
		str.push_back(0);

		// 문자열 읽기
		fin >> str_temp;
		for (int i = 0; i < str_temp.size(); i++) {
			c = str_temp[i];
			str.push_back(c); str2.push_back(c);
		}
		str2.push_back(0);
		reverse(str2.begin(), str2.end());

		// 문자열 판독
		for (int i = 1; i < str.size(); i++) {
			for (int j = 1; j < str2.size(); j++) {
				if (str[i] == str2[j]) {
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				}
				else {
					if (lcs[i - 1][j] > lcs[i][j - 1]) {
						lcs[i][j] = lcs[i - 1][j];
					}
					else {
						lcs[i][j] = lcs[i][j - 1];
					}
				}
			}
		}

		// 계산
		int result = (str.size() - 1) - lcs[str.size() - 1][str.size() - 1];
		if (result > 2) { fout << -1 << '\n'; }
		else { fout << result << '\n'; }
	}
	return 0;
}