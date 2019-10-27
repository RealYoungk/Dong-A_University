#include<iostream>
#include<fstream>
using namespace std;

// ���̴� �� point�� �������� ���� 3or1�� ��Ģ�� ����
class Paper {
public:
	int N, M;	// N x M
	int column[50][50];	// ���� ������ �Է°��� ������ �迭
	int width[50][50];	// ���� ������ �Է°��� ������ �迭
	int sum;	// sum�� 1 or 3 �̸� ��
	bool isPaper;	// ������ �ִ� �������� �Ǻ� �ϴ°�

	int f() {	// �� ���� �������� �ѷ����� ������ ���� ���ϴ� �Լ�
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M - 1; j++) {
				sum = column[i][j] + column[i + 1][j] + width[i][j + 1] + width[i][j];
				if (sum != 1 && sum != 3) {	// ���� �ƴѰ��
					isPaper = false;
					return 0;
				}
				else isPaper = true;
			}
		}
		if (isPaper) return 1;
	}
};

int main() {

	ifstream fin("paper.inp");
	ofstream fout("paper.out");

	Paper p;

	int t;

	fin >> t;

	for (int testcase = 0; testcase < t; testcase++) {
		// N M �Է¹ޱ�
		fin >> p.N >> p.M;

		// ���� ������ �Է�
		for (int i = 0; i < p.N; i++) {
			for (int j = 0; j < p.M - 1; j++) {
				fin >> p.column[i][j];
			}
		}
		// ���� ������ �Է�
		for (int i = 0; i < p.N - 1; i++) {
			for (int j = 0; j < p.M; j++) {
				fin >> p.width[i][j];
			}

		}
		// ���̸� �Ǻ��Ѵ�.
		fout << p.f() << ' ';
	}
}