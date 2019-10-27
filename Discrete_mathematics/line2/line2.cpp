#include <iostream>
#include <fstream>
using namespace std;

class Line {
public:
	int startLine[1000];	// ó�� �л��� �л����� �ִ� 1000
	int resultLine[1000];	// ��� �л���
	int student;			// �л���
	int moveStudent;		// �������� �� �л��� 
	int front, back;		// ���� �л� ���� �л�
	int result[1000];		// ����л��� ��ĭ ������ ������ ����
	
	// �տ��ִ���� changed�� �ڿ��ִ���� changing�� �ٲٴ� �Լ�
	void change(int changed);
	// �����ٿ��� �������� ���ִ���� ���ϴ� �Լ�
	int getLastPeople();
	// �� �л��� ��� �ε����� ���ִ��� ���ϴ� �Լ�
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
	front = changed;	// �տ� �ִ� ���
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

		// ������ Ƚ����� ����
		for (int j = 0; j < line.student; j++) {
			line.change(line.getLastPeople());
		}

		// ��½���
		for (int j = 0; j < line.student; j++) {
			fout << line.result[j] << ' ' ;
		}

		fout << '\n';
	}
	// ������ �Է¹ޱ� ��

	

	
	
}