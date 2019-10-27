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
			point = 0;
			move = 0;
			break;
		case 2:
			point = 0;
			move = 0;
			break;
		case 3:
			point = (wide * high + 1);
			move = 0;
			break;
		case 4:
			point = (1 + (wide * high));
			move = 0;
			break;
		case 5:	// 타입 4 좌상
			point = -(wide - 1);
			move = 0;
			break;
		case 6:	// 타입 4 우상
			point = wide + 1;
			move = 0;
			break;
		case 7:	// 타입 4 우하
			point = (wide * high) + wide;
			move = 0;
			break;
		case 8:	// 타입 4 좌하
			point = wide * (high - 1);
			move = 0;
			break;
		default:
			break;
		}
	}
};

int main() {

	ifstream fin("grid2.inp");
	ofstream fout("grid2.out");

	int wide, high;
	int testCase;
	fin >> testCase;

	Grid g;

	for (int i = 0; i < testCase; i++) {	// 프로그램 시작
		fin >> g.high >> g.wide >> g.type >> g.position >> g.moves;
		wide = g.wide;
		high = g.high;
		if (g.type == 3) {	// type1일때
			if (g.position == 1) {
				g.setPoint(1);	//	 시작
				while (1) {
					// 오른쪽으로 이동
					for (int j = 0; j < wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;
					// 밑으로 이동
					for (int j = 1; j < high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
					// 왼쪽으로 이동
					for (int j = 0; j < wide; j++) {
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;
					// 위로 이동
					for (int j = 1; j < high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
				}
			}
			else if (g.position == 2) {
				g.setPoint(2);
				while (1) {
					// 아래로 이동
					for (int j = 0; j < high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
					// 좌로 이동
					for (int j = 1; j < wide; j++) {
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;
					// 위로 이동
					for (int j = 0; j < high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
					// 우로 이동
					for (int j = 1; j < wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;
				}
			}
			else if (g.position == 3) {
				g.setPoint(3);
				
				while (1) {
					// 왼쪽으로 이동
					for (int j = 0; j < wide; j++) {
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;
					// 위로 이동
					for (int j = 1; j < high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
					// 오른쪽으로 이동
					for (int j = 0; j < wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;
					// 아래로 이동
					for (int j = 1; j < high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
				}
			}
			else {
				g.setPoint(4);
				
				while (1) {
					// 위로 이동
					for (int j = 0; j < high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
					// 오른쪽으로 이동
					for (int j = 1; j < wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;
					// 아래로 이동
					for (int j = 0; j < high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
					// 왼쪽으로 이동
					for (int j = 1; j < wide; j++) {
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;
				}
			}
		}
		else {	// type2 일때
			if (g.position == 1) {
				g.setPoint(5);
				while (1) {
					// 아래로 이동
					for (int j = 0; j < high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
					// 오른쪽으로 이동
					for (int j = 1; j < wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;
					// 위로 이동
					for (int j = 0; j < high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
					// 좌로 이동
					for(int j=1;j<wide;j++){
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;
				}

			}
			else if (g.position == 2) {
				g.setPoint(6);
				
				while (1) {
					// 좌로 이동
					for (int j = 0; j < wide; j++) {
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;

					// 아래로 이동
					for (int j = 1; j < high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
					
					// 우로 이동
					for (int j = 0; j < wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;

					// 위로 이동
					for (int j = 1; j < high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
					
					
				}
			}
			else if (g.position == 3) {
				g.setPoint(7);
				
				while (1) {
					// 위로 이동
					for (int j = 0; j < high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
					// 좌로 이동
					for (int j = 1; j < wide; j++) {
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;
					// 아래로 이동
					for (int j = 0; j < high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
					// 우로 이동
					for (int j = 1; j < wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;
				}
			}
			else {
				g.setPoint(8);
				
				while (1) {
					// 우로 이동
					for (int j = 0; j < wide; j++) {
						g.moveRight();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;

					// 위로 이동
					for (int j = 1; j < high; j++) {
						g.moveUp();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
					// 좌로 이동
					for (int j = 0; j < wide; j++) {
						g.moveLeft();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					wide = wide - 1;
					// 아래로 이동
					for (int j = 1; j < high; j++) {
						g.moveDown();
						if (g.move == g.moves) {
							fout << g.point << '\n';
							goto outerLoop;
						}
					}
					high = high - 1;
				}
			}
		}
	outerLoop:; // 이중포문 빠져나오는 레이블
	}
}