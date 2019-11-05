#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

ifstream fin("card.inp");
ofstream fout("card.out");

int n;
int seq[1000];
int alice[1000][1000], com[1000][1000];

int seqCompare(int i, int j) {
	if (seq[i] > seq[j]) {
		return i;
	}
	else if (seq[i] < seq[j]) {
		return j;
	}
	else {
		return i;
	}
}

int big(int i, int j, int &index) {
	int a = com[i + 1][j] + seq[i];
	int b = com[i][j - 1] + seq[j];
	if (a > b) {
		index = i;
		return a;
	}
	else if (a < b) {
		index = j;
		return b;
	}
	else {
		index = seqCompare(i, j);
		if (index == i) {
			return a;
		}
		else if (index == j) {
			return b;
		}
	}
}

int small(int i, int j, int &index) {

	int a = alice[i + 1][j] ;
	int b = alice[i][j - 1];

	if (a < b) {
		index = i;
		return a;
	}
	else if (a > b) {
		index = j;
		return b;
	}
	else {
		index = seqCompare(i, j);
		if (index == i) {
			return a;
		}
		else if (index == j) {
			return b;
		}
	}
}

void card() {
	
	int index, temp1, temp2;
	
	// 초기화
	for (int i = 0, j = 0; i < n; i++, j++) {
		alice[i][j] = seq[i];
		com[i][j] = 0;
	}

	// 계산
	for (int k = 1; k < n; k++) {
		for (int i = 0, j = k; j < n; i++, j++) {

			alice[i][j] = big(i, j, index);

			com[i][j] = small(i, j, index);


		}
	}
}

int main() {
	
	int testcase;
	fin >> testcase;

	while (testcase--) {

		int temp;
		fin >> n;
		for (int i = 0; i < n; i++) {
			fin >> temp;
			seq[i] = temp;
		}

		card();
		
		fout << alice[0][n - 1] << '\n';

	}
}