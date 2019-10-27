#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Matrix {
public:
	int n;
	int nByN[300][300] = {};
};

int main() {
	ifstream fin("matrix.inp");
	ofstream fout("matrix.out");

	Matrix m;	// ��Ʈ���� ��ü
	int count;	// testcase��
	int sum;	// 
	int c=0;		// Ȯ���� �迭���� ��
	fin >> count;	// testcase��
	
	for (int i = 0; i < count; i++) {	// testcase �ݺ�
		fin >> m.n;	// ������� n
		for (int j = 0; j < m.n; j++) {	// �迭 ������ �Է¹ޱ�
			for (int k = 0; k < m.n; k++) {
				fin >> m.nByN[j][k];
			}
		}
		for (int j = 0; j < m.n; j++) {	// �迭 ��
			for (int k = 0; k < m.n; k++) {	// �迭 ��
				if(m.nByN[j][k] != 0 && m.nByN[j][k] != 1){	// ���� 0,1�� �ƴϸ�
					for (int l = 0; l < m.n; l++) {	// ��� ���� ���� ���ϴ� �ݺ���
						for (int o = 0; o < m.n; o++) {
							sum = m.nByN[l][k] + m.nByN[j][o];
							if (sum == m.nByN[j][k]) {
								c++;
								goto outerLoop;
							}
						}
					}
				}
				else if(m.nByN[j][k] == 1){
					c++;
				}
			outerLoop:;	// �ݺ��� ���������� ���̺�
			}
		}
		if (c == m.n*m.n) {
			fout << '1' << '\n';
			memset(m.nByN, 0, sizeof(m.nByN));
			c = 0;
		}
		else {
			fout << '0' << '\n';
			memset(m.nByN, 0, sizeof(m.nByN));
			c = 0;
		}
	}
}