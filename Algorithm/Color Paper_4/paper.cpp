#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

ifstream fin("paper.inp");
ofstream fout("paper.out");

struct Paper {
	int x, y, dx, dy;
};

Paper paper[2000];
int board[8001][8001], paperNum = 0, all = 0, part = 0, no = 0;
vector < int > origin;
vector < int > press;

void set(ifstream &fin) {
	fin >> paperNum;
	for (int i = 0; i < paperNum; i++) {
		int x, y, w, h;
		fin >> x >> y >> w >> h;
		paper[i] = { x, y, x + w, y + h };
		origin.push_back(paper[i].x); origin.push_back(paper[i].dx);
		origin.push_back(paper[i].y); origin.push_back(paper[i].dy);
	}
}

void compress() {
	origin.push_back(-1);
	for (int i = 0; i < origin.size() - 1; i++) {
		if (origin[i] != origin[i + 1]) {
			press.push_back(origin[i]);
		}
	}
	for (int i = 0; i < paperNum; i++) {
		paper[i].x = lower_bound(press.begin(), press.end(), paper[i].x) - press.begin();
		paper[i].y = lower_bound(press.begin(), press.end(), paper[i].y) - press.begin();
		paper[i].dx = lower_bound(press.begin(), press.end(), paper[i].dx) - press.begin();
		paper[i].dy = lower_bound(press.begin(), press.end(), paper[i].dy) - press.begin();
	}
}

void cover() {
	for (int i = 0; i < paperNum; i++) {
		for (int j = paper[i].x; j < paper[i].dx; j++) {
			for (int k = paper[i].y; k < paper[i].dy; k++) {
				board[j][k] = i;
			}
		}
	}
}

void confirm() {
	int sheet;	// 색종이의 면적
	int fixSheet;
	for (int i = 0; i < paperNum; i++) {
		sheet = (paper[i].dx - paper[i].x) * (paper[i].dy - paper[i].y);
		fixSheet = sheet;
		for (int j = paper[i].x; j < paper[i].dx; j++) {
			for (int k = paper[i].y; k < paper[i].dy; k++) {
				if (board[j][k] == i) {
					sheet--;
				}
			}
		}
		if (sheet == 0) {
			all++;	// 안가려짐
		}
		else if (sheet == fixSheet) {
			no++;	// 다가려짐
		}
		else {
			part++;	// 일부만 가려짐
		}
	}
}

int main() {
	set(fin);
	sort(origin.begin(), origin.end());
	compress();
	cover();
	confirm();
	fout << no << ' ' << part << ' ' << all;
	return 0;
}