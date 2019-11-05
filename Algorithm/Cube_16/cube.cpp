#include<iostream>
#include<algorithm>
#include<fstream>
#define MAX 987654321
using namespace std;

ifstream fin("cube.inp");
ofstream fout("cube.out");

int w, l, h;

int dp[201][201][201];

void setting() {
	for (int i = 1; i < 201; i++) {
		for (int j = 1; j < 201; j++) {
			for (int k = 1; k < 201; k++) {
				dp[i][j][k] = MAX;
			}
		}
	}
}

void slice() {
	
	for (int w = 1; w < 201; w++) {
		for (int l = 1; l < 201; l++) {
			for (int h = 1; h < 201; h++) {
				if (w == l && l == h && h == w) {
					dp[w][l][h] = 1;
				}
				else if (dp[w][l][h] == MAX) {
					for (int i = 1; i <= w / 2; i++) {
						dp[w][l][h] = min(dp[w][l][h], dp[w - i][l][h] + dp[i][l][h]);
					}
					for (int j = 1; j <= l / 2; j++) {
						dp[w][l][h] = min(dp[w][l][h], dp[w][l - j][h] + dp[w][j][h]);
					}
					for (int k = 1; k <= h / 2; k++) {
						dp[w][l][h] = min(dp[w][l][h], dp[w][l][h - k] + dp[w][l][k]);
					}
				}
				dp[l][w][h] = dp[l][h][w] = dp[h][l][w] = dp[h][w][l] = dp[w][h][l] = dp[w][l][h];
			}
		}
	}
}

int main() {

	int testcase;
	fin >> testcase;

	setting();
	slice();

	for (int t = 0; t < testcase; t++) {
		fin >> w >> l >> h;
		fout << dp[w][l][h] << '\n';
	}
	fout.close(); fin.close();
	return 0;
}