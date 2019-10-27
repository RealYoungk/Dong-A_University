#include<iostream>
#include<fstream>
using namespace std;

int main() {
	
	ifstream fin("numgame.inp");
	ofstream fout("numgame.out");

	int count = 0;	// ������ ����
	int result[9877];	// 1�̸� ��
	int a[4], b[4];	// ������ ��, ��� ��
	int strike, ball;	// ���� ��Ʈ����ũ, ��
	int st, ba;		// ������ ���� ��Ʈ����ũ, ��
	int testcase;

	fin >> testcase;
	// �߱����� �ݺ� ����
	for (int i = 0; i < testcase; i++) {
		//int p[9876 - 1234 + 1];	// ������ ��
		// ������ ���̸� 1 �ֱ�
		for (int num = 1234; num <= 9876; num++) {
			a[0] = num / 1000, a[1] = num / 100 % 10;
			a[2] = num / 10 % 10, a[3] = num % 10;
			if (!a[0] || !a[1] || !a[2] || !a[3]) continue;
			if (a[0] == a[1] || a[0] == a[2] || a[0] == a[3]) continue;
			if (a[1] == a[2] || a[1] == a[3] || a[2] == a[3]) continue;
			result[num] = 1;
		}

		int question_num;	// ������ ��
		fin >> question_num;

		for (int j = 0; j < question_num; j++) {
			int question;
			fin >> question >> strike >> ball;
			b[0] = question / 1000, b[1] = question / 100 % 10;
			b[2] = question / 10 % 10, b[3] = question % 10;
			for (int num = 1234; num <= 9876; num++) {
				if (result[num]) {
					a[0] = num / 1000, a[1] = num / 100 % 10;
					a[2] = num / 10 % 10, a[3] = num % 10;
					st = 0, ba = 0;
					for (int m = 0; m < 4; m++) {
						for (int n = 0; n < 4; n++) {
							if (m == n && a[m] == b[n]) st++;
							if (m != n && a[m] == b[n]) ba++;
						}
					}
					if ((strike != st) || (ball != ba)) result[num] = 0;
				}
			}
		}

		// ���� ���
		for (int j = 1234; j < 9877;  j++) {
			if (result[j] == 1) count++;
		}
		fout << count << '\n';
		int temp = count;
		if (temp <= 6) {
			for (int j = 1234; j < 9877; j++) {
				if (result[j] == 1) {
					fout << j << '\n';
				}
			}
		}
		else {
			int minCount = 0;
			int maxCount = 0;
			int maxArr[3] = {};
			for (int j = 1234; j < 9877; j++) {
				if (result[j] == 1) {
					fout << j << '\n';
					minCount++;
				}
				if (minCount == 3) break;
			}
			for (int j = 9876; j > 1233; j--) {
				if (result[j] == 1) {
					maxArr[maxCount] = j;
					maxCount++;
				}
				if (maxCount == 3) break;
			}
			
			fout << maxArr[2] << '\n';
			fout << maxArr[1] << '\n';
			fout << maxArr[0] << '\n';
		}
		
		count = 0;
	}
}