#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream fin("bitmap.inp");
ofstream fout("bitmap.out");
char bitmap[201][201];
string s;

bool isD(int x, int y, int x2, int y2) {
	char temp = bitmap[x][y];
	bool result = true;
	for (int i = x; i <= x2; i++) {
		for (int j = y; j <= y2; j++) {
			if (temp == bitmap[i][j] && result != false)
				result = true;
			else result = false;
		}
	}
	return result;
}

void bToD(int x, int y, int x2, int y2, int &count) {

	int xMid = (x + x2) / 2;
	int yMid = (y + y2) / 2;

	if (isD(x, y, x2, y2)) {
		if (bitmap[x][y] == '1' || bitmap[x][y] == '0') {
			fout << bitmap[x][y];	count++;	if ((count % 50) == 0)fout << '\n';
		}
	}
	else {
		fout << 'D'; count++;	if ((count % 50) == 0)fout << '\n';
		bToD(x, y, xMid, yMid, count);
		if(xMid >=x && y2 >= yMid + 1) bToD(x, yMid + 1, xMid, y2, count);
		if(xMid + 1 <= x2 && y <= yMid)	bToD(xMid + 1, y, x2, yMid, count);
		if(xMid + 1 <= x2 && yMid + 1 <= y2)	bToD(xMid + 1, yMid + 1, x2, y2, count);
	}
}

void dToB(int x, int y, int x2, int y2, int &index) {
	if (x <= x2 && y <= y2) {
		int xMid = (x + x2) / 2;
		int yMid = (y + y2) / 2;

		if (s[index] == 'D') {
			dToB(x, y, xMid, yMid, ++index);
			dToB(x, yMid + 1, xMid, y2, index);
			dToB(xMid + 1, y, x2, yMid, index);
			dToB(xMid + 1, yMid + 1, x2, y2, index);
		}
		else if (s[index] == '1') {
			index++;
			for (int i = x; i <= x2; i++) {
				for (int j = y; j <= y2; j++) {
					bitmap[i][j] = '1';
				}
			}
		}
		else if (s[index] == '0') {
			index++;
			for (int i = x; i <= x2; i++) {
				for (int j = y; j <= y2; j++) {
					bitmap[i][j] = '0';
				}
			}
		}
	}
}

 int main() {
	while (true) {
		char type;
		fin >> type;
		if (type == '#') break;

		gooo:	// goto문 레이블

		int x, y;
		fin >> x >> y;

		// input
		if (type == 'B') {
			char c;
			int i, j, count = 0;
			for (i= 1; i <= x; i++) {
				for (j = 1; j <= y; j++) {
					fin >> c;
					bitmap[i][j] = c;
				}
			}
			fout << "D " << x << ' ' << y << '\n';
			bToD(1, 1, x, y, count);
			if (count % 50 != 0) fout << '\n';
		}
		else if (type == 'D') {
			string temp;
			int index = 0;
			while (true) {
				fin >> temp;
				if (temp.size() < 50) {
					if (temp[1] != ' ') {
						s.append(temp);
						break;
					}
					else {	// 딱 50자 온 경우
						type = temp[0];
						goto gooo;
					}
				}
				else {
					s.append(temp);
				}
			}
			dToB(1, 1, x, y, index);
			fout << "B " << x << ' ' << y << '\n';
			int count = 0;
			for (int i = 1; i <= x; i++) {
				for (int j = 1; j <= y; j++) {
					fout << bitmap[i][j];	count++;
					if (count % 50 == 0) fout << '\n';
				}
			}
			if(count%50 != 0) fout << '\n';
			s.clear();
		}
	}
}