#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("pole.inp");
ofstream fout("pole.out");

long long pole[21][21][21];

void set() {
	for (int i = 0; i < 21; i++) {
		pole[i][i][1] = pole[i][1][i] = 1;
	}
}

void cal() {
	for (int i = 2; i < 21; i++) {
		for (int j = 1; j < 21; j++) {
			for (int k = 1; k < 21; k++) {
				pole[i][j][k] = pole[i - 1][j - 1][k] + pole[i - 1][j][k - 1] + (i - 2)*pole[i - 1][j][k];
			}
		}
	}
}

int main() {
	int testcase;
	fin >> testcase;
	set();
	cal();
	while (testcase--) {
		int n, l, r;
		fin >> n >> l >> r;
		fout << pole[n][l][r] << '\n';
	}
}