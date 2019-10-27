#include <iostream>
#include <fstream>
using namespace std;

class Stone {
public:
	char kind;
	int point;
	int flag;	// ū���̸� 2 ���� ���̸� 1 �ȹ��� ���̸� 0
	char trash; // �����Ⱚ ���� �ڷ���
	Stone() {
		kind = 'B';
		point = 0;
		flag = 2;
	}
};

int main() {

	ifstream fin("frog.inp");
	ofstream fout("frog.out");

	int testcase;
	fin >> testcase;
	for (int i = 0; i < testcase; i++) {
		char trash;
		int num;	// ���� ����
		int river;	// ���� ����
		//int flag = 0;	// ������ S���� ������ 1 �ƴϸ� 0
		int start = 0;	// ��������
		int interval = 0;	// �ִ� ���� �Ÿ�
		int S_count = 0;	// Small �� ���� ���� �ʱⰪ 0;
		Stone s[100];
		fin >> num >> river;
		for (int j = 1; j <= num; j++) {
			fin >> s[j].kind >> s[j].trash >> s[j].point;
		}
		s[num + 1].kind = 'B';
		s[num + 1].point = river;

		// S�� �ϳ� �ǳʼ� �ٱ� 1
		for (int j = 0; j <= num + 1; j++) {
			int temp;
			if (s[j].kind == 'B') {
				temp = s[j].point - start;
				if (temp > interval) {
					interval = temp;
				}
				start = s[j].point;
			}
			else if (s[j].kind == 'S') {
				temp = s[j].point - start;
				if (s[j - 1].kind == 'S') {
					// ���� ���� flag�� 1�̳� 2�ΰ��
					// �������� �������ϰ� 0���� ǥ����
					// �̹� �Ͽ��� 0�� ���� ����
					if ((s[j - 1].flag == 2) || (s[j - 1].flag == 1)) {
						s[j].flag = 0;
						if (temp > interval) {
							interval = temp;
						}
						start = s[j].point;
					}
					else {
						s[j].flag = 1;
					}
				}
				else {	// ���� ���� B�ΰ��
					if (temp > interval) {
						interval = temp;
					}
					start = s[j].point;
					s[j].flag = 0;
				}
			}
		}

		// S�� �ϳ� �ǳʼ� �ٱ� 2
		// �Ʊ� �ȹ��� S�� (1�� ǥ�õ�)
		// �̹��Ͽ� ���
		start = 0;
		// �ȹ��� S���� ���� ��� B�� ������ ���
		for (int j = 0; j <= num + 1; j++) {
			int temp;
			if (s[j].kind == 'B') {
				temp = s[j].point - start;
				if (temp > interval) {
					interval = temp;
				}
				start = s[j].point;
			}
			else if (s[j].kind == 'S') {
				temp = s[j].point - start;
				if (s[j].flag == 1 || s[j].flag == 2) {	// ����
					if (temp > interval) {
						interval = temp;
					}
					start = s[j].point;
				}
			}
		}
		fout << "Case " << (i + 1) << ": " << interval << '\n';
	}
}