#include <iostream>
#include <fstream>
#include <string>
#include <cmath>	// pow함수 쓸것
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<cstring>
using namespace std;

class Type1 {
public:
	char first[10];
	int	second;
	int first_length;	// first의 길이
	int second_length;	// second의 길이 필요없을듯?
	int tmp;

	Type1() {
		for (int i = 0; i < 10; i++) {
			first[i] = 0;
			second = 0;
			first_length = 0;
			second_length = 0;
			tmp = 0;
		}
	}

	void set_first_length() {
		for (int i = 0; first[i] >= 'A' && first[i] <= 'Z'; i++) {
			first_length++;	// 길이 증가
		}
	}

	int convert_to_2fourth() {
		for (int i = first_length - 1, j = 0; i >= 0; i--, j++) {
			tmp = tmp + (pow(26, i)*(first[j] - 64));
		}
		return tmp;
	}
};

class Type2 {
public:
	char first;
	int	second;
	char third;
	int	fourth;
	char tmp[10];
	int length;
	int ltmp, temp;

	Type2() {
		first = 'R';
		second = 0;
		third = 'C';
		fourth = 0;
		for (int i = 0; i < 10; i++) {
			tmp[i] = 0;
		}
	}

	// 자리수 구하는 함수
	void get_length() {
		ltmp = 1;
		length = 0;
		if (fourth > 456976) {
			length = 5;
		}
		else if (fourth > 18278) {
			length = 4;
		}
		else if (fourth > 702) {
			length = 3;
		}
		else if (fourth > 26) {
			length = 2;
		}
		else {
			length = 1;
		}

	}
/*
	char* convert_to_1first() {
		temp = fourth;
		for (int i = 1; i <= length; i++) {	// 글자수만큼 반복시작

		}
		return tmp;
	}
	*/
	
	char* convert_to_1first() {
		int tmp[10];
		for (int i = 0; i < 10; i++) {
			tmp[i] = 0;
		}
		temp = fourth;
		for (int i = 0, j = 1; i < fourth; i++) {
			tmp[0]++;
			if (tmp[0] == 27) {
				tmp[1]++;
				tmp[0] = 1;
			}
			if (tmp[1] == 27) {
				tmp[2]++;
				tmp[1] = 1;
			}
			if (tmp[2] == 27) {
				tmp[3]++;
				tmp[2] = 1;
			}
			if (tmp[3] == 27) {
				tmp[4]++;
				tmp[3] = 1;
			}
			if (tmp[4] == 27) {
				tmp[5]++;
				tmp[4] = 1;
			}
			if (tmp[5] == 27) {
				tmp[6]++;
				tmp[5] = 1;
			}
			if (tmp[6] == 27) {
				tmp[7]++;
				tmp[6] = 1;
			}
			if (tmp[7] == 27) {
				tmp[8]++;
				tmp[7] = 1;
			}
		}
		for (int i = 0; i < length; i++) {
			this->tmp[length - (i + 1)] = (char)(tmp[i] + 64);
		}
		return this->tmp;
	}
	
	/*
	char* convert_to_1first() {
		temp = fourth;
		for (int i = 1; i <= length; i++) {	// 글자수만큼 반복시작
			tmp[i - 1] = (temp / pow(26, length - i));
			if (tmp[i - 1] == 0) {
				tmp[i - 2]--;
				temp = temp + pow(26, length - (i + 1));
			}
			temp = temp - (tmp[i - 1] * pow(26, length - i));
			tmp[i - 1] = tmp[i - 1] + 64;
		}
		return tmp;
	}
	*/
};

int main() {

	ifstream fin("spreadsheet.inp");
	ofstream fout("spreadsheet.out");

	Type1 t1;	// type1 객체
	Type2 t2;	// type2 객체

	int n = 0;	// 바꿀 갯수
	char coordinate[20];	// 좌표 
	bool type = false;			// true면 2 false면 1		

	fin >> n;

	for (int testcase = 0; testcase < n; testcase++) {	// 변환 시작

		fin >> coordinate;

		for (int i = 2; i < strlen(coordinate); i++) {
			//type2 판별중
			if (coordinate[0] == 'R') {	// 첫글자가 R일때
				if (isdigit(coordinate[1])) {	// 그다음수로 숫자가나오고
					if (coordinate[i] == 'C') {	// 'C'가 있으면
						type = true;
						break;
					}// type2 이다
					else {
						type = false;
					}
				}
				else {
					type = false;
				}
			}
			// type1 확정
			else {
				type = false;
				break;
			}
		}

		// 타입 1인경우 
		if (type == false) {
			// 타입 1로 읽기 시작
			for (int i = 0, k = strlen(coordinate); i < k; i++) {
				// 알파벳 대문자인경우
				if (isupper(coordinate[i])) {
					t1.first[i] = coordinate[i];
					coordinate[i] = '0';
				}
				// 숫자인경우
				else {
					t1.second = atoi(coordinate);
					break;
				}
			}
		}

		// 타입 2인경우
		else {
			// 타입 2로 읽기 시작
			for (int i = 0, k = strlen(coordinate); i < k; i++) {
				// R, C 인경우
				if (coordinate[i] == 'R') {
					coordinate[i] = '0';
					t2.second = atoi(coordinate);
				}
				else if (coordinate[i] == 'C') {
					coordinate[i] = '0';
					t2.fourth = atoi(coordinate);
				}
				else {
					coordinate[i] = '0';
				}
			}
		}


		// 데이터를 가지고 변환 시작.
		if (type == false) {	// 타입 1인경우 ex>AA112
			t1.set_first_length();
			fout << "R" << t1.second << "C" << t1.convert_to_2fourth() << '\n';
			t1.first_length = 0;
			t1.tmp = 0;
			for (int i = 0; i < 10; i++) {
				t1.first[i] = 0;
			}

		}
		else {
			t2.get_length();
			fout << t2.convert_to_1first() << t2.second << '\n';
			for (int i = 0; i < 10; i++) {
				t2.tmp[i] = 0;
			}
		}
	}



}