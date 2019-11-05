#include<iostream>
#include<algorithm>
#include<fstream>
#include<cstring>
using namespace std;

ifstream fin("coinmove.inp");
ofstream fout("coinmove.out");

bool dp[1000001][8];
int p, k, s;	// p�� x�ֱ�, k�� �̵�ũ��, s�� ������ġ

void reset() {
	memset(dp, false, sizeof(dp));
	// 1�϶� ���°� ����
	for (int i = 1; i <= k; i++) {
		dp[1][i] = false;
	}
}

bool canWin(int index, int back) {	// back�� �ڿ��� ���°���� �Դ���
	if (index != 0 && index%p == 0) {
		return false;
	}
	for (int i = 1; i <= k; i++) {
		if (i != back && dp[index][i]) {
			return false;
		}
	}
	return true;
}

void coinmove() {
	for (int i = 1; i <= s; i++) {
		if (i%p != 0 || i == s) {
			for (int j = 1; j <= k; j++) {
				if (i - j >= 0) {
					dp[i][j] = canWin(i - j, j);
				}
			}
		}
	}
}

void find() {
	for (int i = 1; i <= k; i++) {
		if (dp[s][i]) {
			fout << s - i << '\n';
			return;
		}
	}
	fout << "-1" << '\n';
	return;
}

int main() {
	int testcase;
	fin >> testcase;
	while (testcase--) {
		fin >> p >> k >> s;
		reset();
		coinmove();
		find();
	}
	return 0;
}