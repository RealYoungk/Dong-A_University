#include<iostream>
#include<fstream>
using namespace std;

class Grid {
public:
	int high, wide;	// high : 행 wide : 열
	int type;	// type 
	int point;	// 현재위치
	int position;	// 시작위치
	int move;	// 움직인 횟수
	int moves;	// 움직여야하는 횟수


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

	for (int i = 0; i < testCase; i++) {	// 프로그램 시작
		fin >> g.high >> g.wide >> g.type >> g.position >> g.moves;
		
		if (g.type == 1) {	// type1일때
			if (g.position == 1) {
				g.setPoint(1);	//	 시작
				if (g.moves == 1) {
					fout << g.point << '\n';
				}
				while (g.moves != 1) {
					// 오른쪽으로 이동
					for (int j = 1; j < g.wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 밑으로 이동
					g.moveDown();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// 왼쪽으로 이동
					for (int j = 1; j < g.wide; j++) {
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 밑으로 이동
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
					// 왼쪽으로 이동
					for (int j = 1; j < g.wide; j++) {
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 밑으로 이동
					g.moveDown();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// 오른쪽으로 이동
					for (int j = 1; j < g.wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 밑으로 이동
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
					// 왼쪽으로 이동
					for (int j = 1; j < g.wide; j++) {
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 위로 이동
					g.moveUp();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// 오른쪽으로 이동
					for (int j = 1; j < g.wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 위로 이동
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
					// 오른쪽으로 이동
					for (int j = 1; j < g.wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 위로 이동
					g.moveUp();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// 왼쪽으로 이동
					for (int j = 1; j < g.wide; j++) {
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 위로 이동
					g.moveUp();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
				}
			}
		}
		else {	// type2 일때
			if (g.position == 1) {
				g.setPoint(1);
				if (g.moves == 1) {
					fout << g.point << '\n';
				}
				while (g.moves != 1) {
					// 아래로 이동
					for (int j = 1; j < g.high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 오른쪽으로 이동
					g.moveRight();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// 위로 이동
					for (int j = 1; j < g.high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 우로 이동
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
					// 아래로 이동
					for (int j = 1; j < g.high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 좌로 이동
					g.moveLeft();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// 위로 이동
					for (int j = 1; j < g.high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 좌로 이동
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
					// 위로 이동
					for (int j = 1; j < g.high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 좌로 이동
					g.moveLeft();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// 아래로 이동
					for (int j = 1; j < g.high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 좌로 이동
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
					// 위로 이동
					for (int j = 1; j < g.high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 우로 이동
					g.moveRight();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
					// 아래로 이동
					for (int j = 1; j < g.high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					// 우로 이동
					g.moveRight();
					if (g.move == g.moves) {
						fout << g.point << '\n';
						goto outerLoop;
					}
				}
			}
		}
	outerLoop:; // 이중포문 빠져나오는 레이블
	}
	// 깃허브 실험용~!!~!
}