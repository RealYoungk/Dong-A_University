#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

ifstream fin("ladder.inp");
ofstream fout("ladder.out");

struct line {
	int x;
	int y;
	
	int x2;
	int y2;
};

int result[50];
vector < vector < line > > ladder;

bool compare(line a, line b) {
	return a.y > b.y;
}

void down(int v, int y) {
	int start = v;
	for (int i = 0; i < ladder[v].size(); i++) {
		if (ladder[v][i].y < y && ladder[v][i].x == v) {
			y = ladder[v][i].y2;
			v = ladder[v][i].x2;
			i = 0;
			continue;
		}
	}
	result[v] = start;
}

int main() {
	// 입력
	int vertical;	// 세로
	fin >> vertical;
	ladder.resize(vertical);
	for (int i = 0;; i++) {
		int x, y, x2, y2;
		line temp;
		fin >> x >> y >> x2 >> y2;
		if (x == 0 && y == 0 && x2 == 0 && y2 == 0) break;
		temp = { x, y, x2, y2 };
		ladder[temp.x].push_back(temp);
		temp = { x2, y2, x, y };
		ladder[temp.x].push_back(temp);
	}
	// 정렬
	for (int i = 0; i < vertical; i++) {
		sort(ladder[i].begin(), ladder[i].end(), compare);
	}
	// 사다리타기
	for (int i = 0; i < vertical; i++) {
		down(i, 10001);
	}
	// 출력
	for (int i = 0; i < vertical; i++) {
		fout << result[i] << ' ';
	}
	return 0;
}