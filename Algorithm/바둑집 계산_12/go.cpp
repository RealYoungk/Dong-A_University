#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

ifstream fin("go.inp");
ofstream fout("go.out");

struct point {
	char p;
	bool black;
	bool white;

	point() {
		black = false;
		white = false;
	}
};

queue< pair< int, int > > Queue;
bool visit[20][20];			// bool값이 확정난경우
point checkerboard[20][20];	// visit-> dfs도중에 갔던데 또 안가기
int k;
int dx[4] = { -1, 0 , 1, 0 }, dy[4] = { 0, -1, 0, 1 };
int blackHouse = 0, whiteHouse = 0;

void set(ifstream &fin) {
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			fin >> checkerboard[i][j].p;
		}
	}
}

bool isRange(int i, int j) {
	return i > 0 && i <= k && j > 0 && j <= k;
}

void bfs(int i, int j) {	// 1이면 흑집 2이면 백집 0이면 암것도아님
	int dot = 1;
	bool black = false, white = false;
	visit[i][j] = true;
	Queue.push({ i, j });
	while (!Queue.empty()) {
		int x = Queue.front().first, y = Queue.front().second;
		if (checkerboard[x][y].p == '.') {
			//dot++;
			for (int i = 0; i < 4; i++) {
				int nextX = x + dx[i], nextY = y + dy[i];
				if (isRange(nextX, nextY) && !visit[nextX][nextY]) {
					if (checkerboard[nextX][nextY].p == '.') {
						visit[nextX][nextY] = true; 
						dot++;
						Queue.push({ nextX,nextY });
					}
					else if (checkerboard[nextX][nextY].p == 'B') {
						black = true;
					}
					else if (checkerboard[nextX][nextY].p == 'W') {
						white = true;
					}
				}
			}
		}
		Queue.pop();
	}
	if (black == true && white == false) {
		blackHouse = blackHouse + dot;
	}
	else if (black == false && white == true) {
		whiteHouse = whiteHouse + dot;
	}
}

void mark() {
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			if (!visit[i][j] && checkerboard[i][j].p == '.')	bfs(i, j);
		}
	}
}
/*
void get() {
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			if (checkerboard[i][j].black == true && checkerboard[i][j].white == true);
			else if (checkerboard[i][j].black == true && checkerboard[i][j].p == '.') blackHouse++;
			else if (checkerboard[i][j].white == true && checkerboard[i][j].p == '.') whiteHouse++;
			else;
		}
	}
}
*/

int main() {
	fin >> k;
	set(fin);
	// 주변 흑돌 백돌 표시하기
	mark();
	//get();
	fout << blackHouse << ' ' << whiteHouse << '\n';
	return 0;
}