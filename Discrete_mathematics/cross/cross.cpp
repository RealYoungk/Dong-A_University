#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;

class Cross {
public:
	int n;	// ������ ����
	int size;	// ������ ũ��
	int arr[2][10000] = {};	// ���� ������ �迭
	int index[10000] = {};	// �Ȱ��� ���������� �迭 �ε���
	int count = 0;	// ������ ����
};

int main() {

	ifstream fin("cross.inp");
	ofstream fout("cross.out");

	Cross cross;
	int testcase;
	fin >> testcase;
	for (int i = 0; i < testcase; i++) {	//	corss Ž�� ����
		fin >> cross.size;
		for (int j = 0; j < cross.size; j++) {	// �迭�� ���гֱ�
			fin >> cross.arr[0][j];
		}
		for (int k = 0; k < cross.size; k++) {	// �迭�� ���гֱ� 2
			fin >> cross.arr[1][k];
		}
		// �Ȱ����� ã�� ����
		for (int j = 0; j < cross.size; j++) {
			for (int k = 0; k < cross.size; k++) {
				if (cross.arr[0][j] == cross.arr[1][k]) {
					cross.index[j] = k;
				}
			}
		}
		// ������ ���� ã�� ����
		for (int j = 0; j < cross.size-1; j++) {
			for (int k = j + 1; k < cross.size; k++) {
				if (cross.index[j] > cross.index[k]) {
					cross.count++;
				}
			}
		}
		fout << "Case " << i+1 << ": " << cross.count << '\n';
		cross.count = 0;
		memset(cross.arr, 0, 10000);
		memset(cross.index, 0, 10000);
	}
}