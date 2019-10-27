#include<iostream>
#include<fstream>
using namespace std;

class Line {
public:
	int q, a;
	int min;	// min <= k <= max
	int max;
	int k;
	int x_min;
	int x_max;
	int y_min;
	int y_max;
	Line() {

	}

};

int main() {
	
	ifstream fin("line.inp");
	ofstream fout("line.out");

	Line L[100];

	int can = 0;	// �������� k�� �����Ҽ� �ִ���? -1 �̸� �Ұ�
	int min_max = 0, max_min = 1000000000;	// min <= k <= max���� min�� ����ū��
	int testcase;			// max �� ���� ������ �ִ� ����
	fin >> testcase;

	// �׽�Ʈ���̽� �ݺ� ����
	for (int t = 0; t < testcase; t++) {

		// ���� 1���� �ݺ� ����
		int question;
		fin >> question;

		for (int i = 0; i < question; i++) {
			fin >> L[i].q >> L[i].a;
			if (L[i].a != 1) {
				// (x)k+(y) ���� y��
				L[i].y_min = ((L[i].a - 1)*(L[i].a) / 2);
				L[i].y_max = ((L[i].a - 2)*(L[i].a - 1) / 2) + 1;
				// (x)k+(y) ���� x��
				L[i].x_min = L[i].a;
				L[i].x_max = L[i].a - 1;
				// min <= k <= max
				// min
				if (((L[i].q - L[i].y_min) % L[i].x_min) == 0) {
					L[i].min = ((L[i].q - L[i].y_min) / L[i].x_min);
				}
				else {
					L[i].min = (((L[i].q - L[i].y_min) / L[i].x_min) + 1);
				}
				// max
				if (((L[i].q - L[i].y_max) % L[i].x_max) == 0) {
					L[i].max = ((L[i].q - L[i].y_max) / L[i].x_max);
				}
				else {
					L[i].max = ((L[i].q - L[i].y_max) / L[i].x_max);
				}
			}
			else {
				L[i].min = L[i].q;
				L[i].max = 1000000000;
			}
			
		}

		for (int i = 0; i < question; i++) {
			if (min_max < L[i].min) {
				min_max = L[i].min;
			}
			if (max_min > L[i].max) {
				max_min = L[i].max;
			}
			if (max_min == min_max) {
				fout << (i + 1) << ' ' << min_max << '\n';
				can = 1, max_min = 1000000000, min_max = 0;
				break;
			}
			else
				can = -1;
		}
		
		if (can == -1) {
			max_min = 1000000000, min_max = 0;
			fout << -1 << '\n';
		}
	}

}