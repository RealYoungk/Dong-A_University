#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

class Dice {
public:
	
	int a, f;
	int a_fBig;	// af면에서 가장큰 싸이드값

	int b, d;
	int b_dBig;	// bd면에서 가장큰 싸이드값

	int c, e;
	int c_eBig;	// ce면에서 가장큰 싸이드값

	int top;	// 주사위를 세웟을때 결정된 윗면

	Dice() {
		a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
		a_fBig = 0;
		b_dBig = 0;
		c_eBig = 0;
		top = 0;
	}

	// 주사위의 측면에서 가장 큰 값을 리턴하는 함수
	int side_big(int a, int f) {
		if (a > f) {	// a값이 큰경우

			if (a != 6) {	// a가 6이아닐때
				return 6;
			}
			else {
				if (f != 5) {	// f 가 5가 아니면
					return 5;
				}
				else {	// f가 5 이면
					return 4;
				}
			}

		}
		else {	// f 값이 큰경우

			if (f != 6) {	// f가 6이아닐때
				return 6;
			}
			else {	// f가 6일때
				if (a != 5) {	// a 가 5가 아니면
					return 5;
				}
				else {	// a가 5이면
					return 4;
				}
			}
		}
	}
};

int stack(Dice dice[], int high, int &result) {

	for (int i = 1; i < high; i++) {
		// a가 바닥에 온 경우
		if (dice[i - 1].top == dice[i].a) {
			result = result + dice[i].a_fBig;
			dice[i].top = dice[i].f;
		}
		// f가 바닥에 온 경우
		else if (dice[i - 1].top == dice[i].f) {
			result = result + dice[i].a_fBig;
			dice[i].top = dice[i].a;
		}
		// b가 바닥에 온 경우
		else if (dice[i - 1].top == dice[i].b) {
			result = result + dice[i].b_dBig;
			dice[i].top = dice[i].d;
		}
		// d가 바닥에 온 경우
		else if (dice[i - 1].top == dice[i].d) {
			result = result + dice[i].b_dBig;
			dice[i].top = dice[i].b;
		}
		// c가 바닥에 온 경우
		else if (dice[i - 1].top == dice[i].c) {
			result = result + dice[i].c_eBig;
			dice[i].top = dice[i].e;
		}
		// e가 바닥에 온 경우
		else if (dice[i - 1].top == dice[i].e) {
			result = result + dice[i].c_eBig;
			dice[i].top = dice[i].c;
		}
	}

	return result;

}

// Dice의 결과는 6개임

int main() {

	ifstream fin("dice.inp");
	ofstream fout("dice.out");

	int arr[6];
	int high;
	int a, b, c, d, e, f;
	int resultA = 0;	// 결과값
	int resultB = 0;
	int resultC = 0;
	int resultD = 0;
	int resultE = 0;
	int resultF = 0;

	Dice dice[10000];


	fin >> high;
	// 주사위 정보 저장 시작
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
	// 결과는 6개다

	// A를 먼저 쌓은 경우
	resultA = dice[0].a_fBig;
	dice[0].top = dice[0].f;

	stack(dice, high, resultA);

	// F를 먼저 쌓은 경우
	resultF = dice[0].a_fBig;
	dice[0].top = dice[0].a;

	stack(dice, high, resultF);
	
	// B를 먼저 쌓은 경우
	resultB = dice[0].b_dBig;
	dice[0].top = dice[0].d;

	stack(dice, high, resultB);

	// D를 먼저 쌓은 경우
	resultD = dice[0].b_dBig;
	dice[0].top = dice[0].b;

	stack(dice, high, resultD);

	// C를 먼저 쌓은 경우
	resultC = dice[0].c_eBig;
	dice[0].top = dice[0].e;

	stack(dice, high, resultC);

	// E를 먼저 쌓은 경우
	resultE = dice[0].c_eBig;
	dice[0].top = dice[0].c;

	stack(dice, high, resultE);


	fout << max(max(max(resultA, resultB), resultC), max(resultD, max(resultE, resultF)));

}