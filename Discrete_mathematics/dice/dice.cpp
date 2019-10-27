#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

class Dice {
public:
	
	int a, f;
	int a_fBig;	// af�鿡�� ����ū ���̵尪

	int b, d;
	int b_dBig;	// bd�鿡�� ����ū ���̵尪

	int c, e;
	int c_eBig;	// ce�鿡�� ����ū ���̵尪

	int top;	// �ֻ����� ���m���� ������ ����

	Dice() {
		a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
		a_fBig = 0;
		b_dBig = 0;
		c_eBig = 0;
		top = 0;
	}

	// �ֻ����� ���鿡�� ���� ū ���� �����ϴ� �Լ�
	int side_big(int a, int f) {
		if (a > f) {	// a���� ū���

			if (a != 6) {	// a�� 6�̾ƴҶ�
				return 6;
			}
			else {
				if (f != 5) {	// f �� 5�� �ƴϸ�
					return 5;
				}
				else {	// f�� 5 �̸�
					return 4;
				}
			}

		}
		else {	// f ���� ū���

			if (f != 6) {	// f�� 6�̾ƴҶ�
				return 6;
			}
			else {	// f�� 6�϶�
				if (a != 5) {	// a �� 5�� �ƴϸ�
					return 5;
				}
				else {	// a�� 5�̸�
					return 4;
				}
			}
		}
	}
};

int stack(Dice dice[], int high, int &result) {

	for (int i = 1; i < high; i++) {
		// a�� �ٴڿ� �� ���
		if (dice[i - 1].top == dice[i].a) {
			result = result + dice[i].a_fBig;
			dice[i].top = dice[i].f;
		}
		// f�� �ٴڿ� �� ���
		else if (dice[i - 1].top == dice[i].f) {
			result = result + dice[i].a_fBig;
			dice[i].top = dice[i].a;
		}
		// b�� �ٴڿ� �� ���
		else if (dice[i - 1].top == dice[i].b) {
			result = result + dice[i].b_dBig;
			dice[i].top = dice[i].d;
		}
		// d�� �ٴڿ� �� ���
		else if (dice[i - 1].top == dice[i].d) {
			result = result + dice[i].b_dBig;
			dice[i].top = dice[i].b;
		}
		// c�� �ٴڿ� �� ���
		else if (dice[i - 1].top == dice[i].c) {
			result = result + dice[i].c_eBig;
			dice[i].top = dice[i].e;
		}
		// e�� �ٴڿ� �� ���
		else if (dice[i - 1].top == dice[i].e) {
			result = result + dice[i].c_eBig;
			dice[i].top = dice[i].c;
		}
	}

	return result;

}

// Dice�� ����� 6����

int main() {

	ifstream fin("dice.inp");
	ofstream fout("dice.out");

	int arr[6];
	int high;
	int a, b, c, d, e, f;
	int resultA = 0;	// �����
	int resultB = 0;
	int resultC = 0;
	int resultD = 0;
	int resultE = 0;
	int resultF = 0;

	Dice dice[10000];


	fin >> high;
	// �ֻ��� ���� ���� ����
	for (int i = 0; i < high; i++) {

		fin >> a >> b >> c >> d >> e >> f;

		dice[i].a = a;
		dice[i].b = b;
		dice[i].c = c;
		dice[i].d = d;
		dice[i].e = e;
		dice[i].f = f;

		dice[i].a_fBig = dice[i].side_big(a, f);
		dice[i].b_dBig = dice[i].side_big(b, d);
		dice[i].c_eBig = dice[i].side_big(c, e);

	}
	// ����� 6����

	// A�� ���� ���� ���
	resultA = dice[0].a_fBig;
	dice[0].top = dice[0].f;

	stack(dice, high, resultA);

	// F�� ���� ���� ���
	resultF = dice[0].a_fBig;
	dice[0].top = dice[0].a;

	stack(dice, high, resultF);
	
	// B�� ���� ���� ���
	resultB = dice[0].b_dBig;
	dice[0].top = dice[0].d;

	stack(dice, high, resultB);

	// D�� ���� ���� ���
	resultD = dice[0].b_dBig;
	dice[0].top = dice[0].b;

	stack(dice, high, resultD);

	// C�� ���� ���� ���
	resultC = dice[0].c_eBig;
	dice[0].top = dice[0].e;

	stack(dice, high, resultC);

	// E�� ���� ���� ���
	resultE = dice[0].c_eBig;
	dice[0].top = dice[0].c;

	stack(dice, high, resultE);


	fout << max(max(max(resultA, resultB), resultC), max(resultD, max(resultE, resultF)));

}