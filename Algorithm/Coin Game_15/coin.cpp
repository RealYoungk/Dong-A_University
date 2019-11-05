#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

ifstream fin("coin.inp");
ofstream fout("coin.out");

int top[4][4][4];


void store(int i, int j, int k, int l) {
	top[i][j][k] = l;
}

void set() {
	store(0, 0, 0, 1); store(0, 2, 0, 1);
	store(0, 0, 1, -1); store(0, 2, 1, 1);
	store(0, 0, 2, 1); store(0, 2, 2, -1);
	store(0, 0, 3, 1); store(0, 2, 3, 1);
	store(0, 1, 0, -1); store(0, 3, 0, 1);
	store(0, 1, 1, 1); store(0, 3, 1, 1);
	store(0, 1, 2, 1); store(0, 3, 2, 1);
	store(0, 1, 3, 1); store(0, 3, 3, -1);

	store(1, 0, 0, -1); store(1, 2, 0, 1);
	store(1, 0, 1, 1); store(1, 2, 1, 1);
	store(1, 0, 2, 1); store(1, 2, 2, 1);
	store(1, 0, 3, 1); store(1, 2, 3, -1);
	store(1, 1, 0, 1); store(1, 3, 0, 1);
	store(1, 1, 1, -1); store(1, 3, 1, 1);
	store(1, 1, 2, 1); store(1, 3, 2, -1);
	store(1, 1, 3, 1); store(1, 3, 3, 1);

	store(2, 0, 0, 1); store(2, 2, 0, -1);
	store(2, 0, 1, 1); store(2, 2, 1, 1);
	store(2, 0, 2, -1); store(2, 2, 2, 1);
	store(2, 0, 3, 1); store(2, 2, 3, 1);
	store(2, 1, 0, 1); store(2, 3, 0, 1);
	store(2, 1, 1, 1); store(2, 3, 1, -1);
	store(2, 1, 2, 1); store(2, 3, 2, 1);
	store(2, 1, 3, -1); store(2, 3, 3, 1);

	store(3, 0, 0, 1); store(3, 2, 0, 1);
	store(3, 0, 1, 1); store(3, 2, 1, -1);
	store(3, 0, 2, 1); store(3, 2, 2, 1);
	store(3, 0, 3, -1); store(3, 2, 3, 1);
	store(3, 1, 0, 1); store(3, 3, 0, -1);
	store(3, 1, 1, 1); store(3, 3, 1, 1);
	store(3, 1, 2, -1); store(3, 3, 2, 1);
	store(3, 1, 3, 1); store(3, 3, 3, 1);
}

int coin(int i, int j, int k) {
	i = i % 4;	j = j % 4;	k = k % 4;
	return top[i][j][k];
}

int main() {
	int testcase;
	fin >> testcase;

	set();
	int i, j, k;
	for (int cnt = 0; cnt < testcase; cnt++) {
		fin >> i >> j >> k;
		fout << "(" << i << ' ' << j << ' ' << k << ") : " << coin(i, j, k) << '\n';
	}
}