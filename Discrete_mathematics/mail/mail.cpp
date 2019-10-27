#include <iostream>
#include <fstream>
using namespace std;

class Mail {
public:
	char a[6] = { '0','0','0','0','0','0' };
	char b[6] = { '0','0','1','1','1','1' };
	char c[6] = { '0','1','0','0','1','1' };
	char d[6] = { '0','1','1','1','0','0' };
	char e[6] = { '1','0','0','1','1','0' };
	char f[6] = { '1','0','1','0','0','1' };
	char g[6] = { '1','1','0','1','0','1' };
	char h[6] = { '1','1','1','0','1','0' };
	char arr[6] = {};
	int length = 0;
	int count = 0;
	char verify() {
		for (int i = 0; i < 6; i++) {
			if (a[i] == arr[i]) {
				count++;
			}
			if (count >= 5) {
				count = 0;
				return 'A';
			}
		}
		count = 0;
		for (int i = 0; i < 6; i++) {
			if (b[i] == arr[i]) {
				count++;
			}
			if (count >= 5) {
				count = 0;
				return 'B';
			}
		}
		count = 0;
		for (int i = 0; i < 6; i++) {
			if (c[i] == arr[i]) {
				count++;
			}
			if (count >= 5) {
				count = 0;
				return 'C';
			}
		}
		count = 0;
		for (int i = 0; i < 6; i++) {
			if (d[i] == arr[i]) {
				count++;
			}
			if (count >= 5) {
				count = 0;
				return 'D';
			}
		}
		count = 0;
		for (int i = 0; i < 6; i++) {
			if (e[i] == arr[i]) {
				count++;
			}
			if (count >= 5) {
				count = 0;
				return 'E';
			}
		}
		count = 0;
		for (int i = 0; i < 6; i++) {
			if (f[i] == arr[i]) {
				count++;
			}
			if (count >= 5) {
				count = 0;
				return 'F';
			}
		}
		count = 0;
		for (int i = 0; i < 6; i++) {
			if (g[i] == arr[i]) {
				count++;
			}
			if (count >= 5) {
				count = 0;
				return 'G';
			}
		}
		count = 0;
		for (int i = 0; i < 6; i++) {
			if (h[i] == arr[i]) {
				count++;
			}
			if (count >= 5) {
				count = 0;
				return 'H';
			}
		}
		count = 0;
		return 'X';
	}
};
	
	
int main() {

	ifstream fin("mail.inp");
	ofstream fout("mail.out");
	int testcase;	//	테스트케이스 수
	Mail m;

	fin >> testcase;
	for (int i = 0; i < testcase; i++) {
		fin >> m.length;
		for (int j = 0; j < m.length; j++) {
			for (int k = 0; k < 6; k++) {
				fin >> m.arr[k];
			}
			// 비교시작
			fout << m.verify();
		}
		fout << '\n';
	}
}