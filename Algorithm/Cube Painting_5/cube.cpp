#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream fin("cube.inp");
ofstream fout("cube.out");

struct Dice {
	char top, front, left, right, back, bottom;
};

Dice dice1, dice2;

void changeSide(Dice &dice) {
	int temp;
	temp = dice.front;
	dice.front = dice.left;
	dice.left = dice.back;
	dice.back = dice.right;
	dice.right = temp;
}

void changeTop(Dice &dice) {
	int temp;
	temp = dice.top;
	dice.top = dice.back;
	dice.back = dice.bottom;
	dice.bottom = dice.front;
	dice.front = temp;
}

void change(Dice & dice) {
	int temp;
	temp = dice.top;
	dice.top = dice.right;
	dice.right = dice.bottom;
	dice.bottom = dice.left;
	dice.left = temp;
}
bool isSame(Dice d1, Dice d2) {
	if (d1.top != d2.top) return false;
	if (d1.front != d2.front) return false;
	if (d1.left != d2.left) return false;
	if (d1.right != d2.right) return false;
	if (d1.back != d2.back) return false;
	if (d1.bottom != d2.bottom) return false;
	return true;
}

void cube() {

}

int main() {
	while(1) {
		
		
		fin >> dice1.top >> dice1.front >> dice1.left >> dice1.right >> dice1.back >> dice1.bottom;
		fin >> dice2.top >> dice2.front >> dice2.left >> dice2.right >> dice2.back >> dice2.bottom;

		if (fin.eof())break;
		//1
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);

		///////////////////////////////////////////////////////////////
		//2
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		////////////////////////////////////////////
		//3
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		//4
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);

		changeSide(dice2);
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);


		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		change(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeSide(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		if (isSame(dice1, dice2)) {
			fout << "TRUE" << '\n';
			continue;
		}
		changeTop(dice2);
		fout << "FALSE" << '\n';
	}
}