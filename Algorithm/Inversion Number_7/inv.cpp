#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("inv.inp");
ofstream fout("inv.out");

int testcase, N;
long long result = 0;
int seq[200000];
int seq2[200000];

void merge(int left, int right){
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (seq[i] <= seq[j])
			seq2[k++] = seq[i++];
		else {
			seq2[k++] = seq[j++];
			result = result + ((mid + 1) - i);
		}
	}

	int temp = i > mid ? j : i;
	
	while (k <= right) seq2[k++] = seq[temp++];
	
	for (int i = left; i <= right; i++) {
		seq[i] = seq2[i];
	}

}

void partition(int left, int right) {
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}

void set(ifstream &fin) {
	for (int i = 0; i < N; i++) {
		fin >> seq[i];
	}
}

int main() {
	fin >> testcase;
	while (testcase--) {
		fin >> N;
		set(fin);
		partition(0, N - 1);
		fout << result << '\n';
		result = 0;
	}
}