#include<iostream>
#include<fstream>
using namespace std;

class Grid {
public:
	int high, wide;	// high : �� wide : ��
	int type;	// type 
	int point;	// ������ġ
	int position;	// ������ġ
	int move;	// ������ Ƚ��
	int moves;	// ���������ϴ� Ƚ��


	int moveRight() {
		point++;
		move++;
		if (move == moves) {
			return point;
		}
	}
	int moveLeft() {
		point--;
		move++;
		if (moves == move) {
			return point;
		}
	}
	int moveUp() {
		point = point - wide;
		move++;
		if (moves == move) {
			return point;
		}
	}
	int moveDown() {
		point = point + wide;
		move++;
		if (moves == move) {
			return point;
		}
	}
	
	Grid() { }
	void setPoint(int position) {
		switch (position)
		{
		case 1:
			point = 1;
			move = 1;
			break;
		case 2:
			point = wide;
			move = 1;
			break;
		case 4:
			point = 1 + (wide * (high - 1));
			move = 1;
			break;
		case 3:
			point = wide * high;
			move = 1;
			break;
		default:
			break;
		}
	}
};

int main() {

	ifstream fin("grid1.inp");
	ofstream fout("grid1.out");

	int testCase;
	fin >> testCase;

	Grid g;

	for (int i = 0; i < testCase; i++) {	// ���α׷� ����
		fin >> g.high >> g.wide >> g.type >> g.position >> g.moves;
		
		if (g.type == 1) {	// type1�϶�
			if (g.position == 1) {
				g.setPoint(1);	//	 ����
				if (g.moves == 1) {
					fout << g.point << '\n';
				}
				while (g.moves != 1) {
					// ���������� �̵�
					for (int j = 1; j < g.wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// ������ �̵�
					g.moveDown();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// �������� �̵�
					for (int j = 1; j < g.wide; j++) {
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// ������ �̵�
					g.moveDown();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
				}
			}
			else if (g.position == 2) {
				g.setPoint(2);
				if (g.moves == 1) {
					fout << g.point << '\n';
				}
				while (g.moves != 1) {
					// �������� �̵�
					for (int j = 1; j < g.wide; j++) {
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// ������ �̵�
					g.moveDown();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// ���������� �̵�
					for (int j = 1; j < g.wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// ������ �̵�
					g.moveDown();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
				}
			}
			else if (g.position == 3) {
				g.setPoint(3);
				if (g.moves == 1) {
					fout << g.point << '\n';
				}
				while (g.moves != 1) {
					// �������� �̵�
					for (int j = 1; j < g.wide; j++) {
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// ���� �̵�
					g.moveUp();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// ���������� �̵�
					for (int j = 1; j < g.wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// ���� �̵�
					g.moveUp();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
				}
			}
			else {
				g.setPoint(4);
				if (g.moves == 1) {
					fout << g.point << '\n';
				}
				while (g.moves != 1) {
					// ���������� �̵�
					for (int j = 1; j < g.wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// ���� �̵�
					g.moveUp();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// �������� �̵�
					for (int j = 1; j < g.wide; j++) {
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// ���� �̵�
					g.moveUp();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
				}
			}
		}
		else {	// type2 �϶�
			if (g.position == 1) {
				g.setPoint(1);
				if (g.moves == 1) {
					fout << g.point << '\n';
				}
				while (g.moves != 1) {
					// �Ʒ��� �̵�
					for (int j = 1; j < g.high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// ���������� �̵�
					g.moveRight();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// ���� �̵�
					for (int j = 1; j < g.high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// ��� �̵�
					g.moveRight();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
				}
			
			}
			else if (g.position == 2) {
				g.setPoint(2);
				if (g.moves == 1) {
					fout << g.point << '\n';
				}
				while (g.moves != 1) {
					// �Ʒ��� �̵�
					for (int j = 1; j < g.high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// �·� �̵�
					g.moveLeft();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// ���� �̵�
					for (int j = 1; j < g.high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// �·� �̵�
					g.moveLeft();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
				}
			}
			else if (g.position == 3) {
				g.setPoint(3);
				if (g.moves == 1) {
					fout << g.point << '\n';
				}
				while (g.moves != 1) {
					// ���� �̵�
					for (int j = 1; j < g.high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// �·� �̵�
					g.moveLeft();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// �Ʒ��� �̵�
					for (int j = 1; j < g.high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// �·� �̵�
					g.moveLeft();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
				}
			}
			else {
				g.setPoint(4);
				if (g.moves == 1) {
					fout << g.point << '\n';
				}
				while (g.moves != 1) {
					// ���� �̵�
					for (int j = 1; j < g.high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// ��� �̵�
					g.moveRight();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// �Ʒ��� �̵�
					for (int j = 1; j < g.high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// ��� �̵�
					g.moveRight();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
				}
			}
		}
	outerLoop:; // �������� ���������� ���̺�
	}
	// ����� �����~!!~!
}