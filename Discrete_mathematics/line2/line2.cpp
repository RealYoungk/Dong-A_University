#include <iostream>
#include <fstream>
using namespace std;

class Line {
public:
	int startLine[1000];	// 처음 학생수 학생수는 최대 1000
	int resultLine[1000];	// 결과 학생수
	int student;			// 학생수
	int moveStudent;		// 움직여야 할 학생수 
	int front, back;		// 앞의 학생 뒤의 학생
	int result[1000];		// 몇번학생이 몇칸 앞으로 갔는지 저장
	
	// 앞에있던사람 changed과 뒤에있던사람 changing를 바꾸는 함수
	void change(int changed);
	// 원래줄에서 마지막에 서있던사람 구하는 함수
	int getLastPeople();
	// 그 학생이 어느 인덱스에 서있는지 구하는 함수
	// int whatLine(int people);
};

/*
int Line::whatLine(int student) {
	for (int i = 0; i < 1000; i++) {
		if (resultLine[i] == student) return i;
	}
}
*/

int Line::getLastPeople() {
	return startLine[--moveStudent];
}

void Line::change(int changed) {
	front = changed;	// 앞에 있는 사람
	int count = 0;
	int tmp;
	for (int i = moveStudent; i <= student; i--) {
		if (front != resultLine[i]) {
			count++;
		}
		else { 
			result[front - 1] = count;
			tmp = resultLine[moveStudent - count];
			for (int j = 0; j < count; j++) {
				resultLine[moveStudent - count + j] = resultLine[moveStudent - count + 1 + j];
				resultLine[moveStudent - count + 1 + j] = tmp;
			}
			break;
		}
	}
}


int main() {

	ifstream fin("line2.inp");
	ofstream fout("line2.out");

	Line line;

	int testcase;
 	fin >> testcase;
	for (int i = 0; i < testcase; i++) {
		fin >> line.moveStudent;
		line.student = line.moveStudent;
		for (int j = 0; j < line.student; j++) {
			fin >> line.startLine[j];
		}
		for (int j = 0; j < line.student; j++) {
			fin >> line.resultLine[j];
		}

		// 움직인 횟수계산 시작
		for (int j = 0; j < line.student; j++) {
			line.change(line.getLastPeople());
		}

		// 출력시작
		for (int j = 0; j < line.student; j++) {
			fout << line.result[j] << ' ' ;
		}

		fout << '\n';
	}
	// 데이터 입력받기 끝

	

	
	
}