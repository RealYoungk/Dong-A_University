#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Calendar {
public:
	int t0[6];

	int t1[7];
	char ct1[4];
	
	int t2[7];
	char ct2[4];
	
	int t3[8];
	char ct31[4];
	char ct32[4];	

	bool confirm;

	Calendar() {
		confirm = true;
	}
};

int allDays(int year, int month, int th, int date) {
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int i, leap, y, total, day;

	y = year - 1;
	total = y * 365 + y / 4 - y / 100 + y / 400;
	leap = (year % 4 == 0) - (year % 100 == 0) + (year % 400 == 0);
	days[2] = days[2] + leap;
	for (i = 0; i < month; i++) {
		total = total + days[i];
	}
	// day계산
	day = total % 7; // 0이면 월요일 시작
	if (day == 1) { date = date - 1; if (date < 1) { date += 7; } }
	if (day == 2) {	date = date - 2; if (date < 1) { date += 7; }
	}
	if (day == 3) {	date = date - 3; if (date < 1) { date += 7; }
	}
	if (day == 4) { date = date - 4; if (date < 1) { date += 7; }
	}
	if (day == 5) { date = date - 5; if (date < 1) { date += 7; }
	}
	if (day == 6) { date = date - 6; if (date < 1) { date += 7; }
	}
	if (day == 0) { date = date ; if (date < 1) { date += 7; }
	}
	day = ((th - 1) * 7) + (date);
	total = total + day;

	// 유효값인지 확인
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ) {
		if (day > 31) {
			return -1;
		}
	}
	if (month == 2) {
		if (day > days[2]) {
			return -1;
		}
	}
	if(month == 4 || month == 6 || month == 9 || month == 11 ){
		if (day > 30) {
			return -1;
		}
	}

	return total;
}

int allDays(int year, int month, int day) {
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int i, leap, y, total;

	y = year - 1;
	total = y * 365 + y / 4 - y / 100 + y / 400;
	leap = (year % 4 == 0) - (year % 100 == 0) + (year % 400 == 0);
	days[2] = days[2] + leap;
	for (i = 0; i < month; i++) {
		total = total + days[i];
	}
	// day계산
	if (month == 2) {
		if (day > days[2]) {
			return -1;
		}
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day > 31) {
			return -1;
		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) {
			return -1;
		}
	}
	total += day;
	return total;
}

int main() {

	ifstream fin("calendar.inp");
	ofstream fout("calendar.out");

	Calendar c;

	while (1) {
		int type, a, b, result;
		char trash;
		fin >> type;
		if (type == -1) break;
		// 데이터 입력받기
		if (type == 0) {
			fin >> c.t0[0] >> trash >> c.t0[1] >> trash >> c.t0[2];
			fin >> c.t0[3] >> trash >> c.t0[4] >> trash >> c.t0[5];
		}
		else if (type == 1){
			fin >> c.t1[0] >> trash >> c.t1[1] >> trash >> c.t1[2];
			fin >> c.t1[3] >> trash >> c.t1[4] >> trash >> c.t1[5] >> trash >> c.ct1;
			if (!strcmp(c.ct1, "Mon")) {
				c.t1[6] = 1;
			}
			else if (!strcmp(c.ct1, "Tue")) {
				c.t1[6] = 2;
			}
			else if (!strcmp(c.ct1, "Wed")) {
				c.t1[6] = 3;
			}
			else if (!strcmp(c.ct1, "Thu")) {
				c.t1[6] = 4;
			}
			else if (!strcmp(c.ct1, "Fri")) {
				c.t1[6] = 5;
			}
			else if (!strcmp(c.ct1, "Sat")) {
				c.t1[6] = 6;
			}
			else if (!strcmp(c.ct1, "Sun")) {
				c.t1[6] = 0;
			}
		}
		else if (type == 2) {
			fin >> c.t2[0] >> trash >> c.t2[1] >> trash >> c.t2[2] >> trash >> c.ct2;
			fin >> c.t2[4] >> trash >> c.t2[5] >> trash >> c.t2[6];
			if (!strcmp(c.ct2, "Mon")) {
				c.t2[3] = 1;
			}
			else if (!strcmp(c.ct2, "Tue")) {
				c.t2[3] = 2;
			}
			else if (!strcmp(c.ct2, "Wed")) {
				c.t2[3] = 3;
			}
			else if (!strcmp(c.ct2, "Thu")) {
				c.t2[3] = 4;
			}
			else if (!strcmp(c.ct2, "Fri")) {
				c.t2[3] = 5;
			}
			else if (!strcmp(c.ct2, "Sat")) {
				c.t2[3] = 6;
			}
			else if (!strcmp(c.ct2, "Sun")) {
				c.t2[3] = 0;
			}
		}
		else if (type == 3) {
			fin >> c.t3[0] >> trash >> c.t3[1] >> trash >> c.t3[2] >> trash >> c.ct31;
			fin >> c.t3[4] >> trash >> c.t3[5] >> trash >> c.t3[6] >> trash >> c.ct32;
			if (!strcmp(c.ct31, "Mon")) {
				c.t3[3] = 1;
			}
			else if (!strcmp(c.ct31, "Tue")) {
				c.t3[3] = 2;
			}
			else if (!strcmp(c.ct31, "Wed")) {
				c.t3[3] = 3;
			}
			else if (!strcmp(c.ct31, "Thu")) {
				c.t3[3] = 4;
			}
			else if (!strcmp(c.ct31, "Fri")) {
				c.t3[3] = 5;
			}
			else if (!strcmp(c.ct31, "Sat")) {
				c.t3[3] = 6;
			}
			else if (!strcmp(c.ct31, "Sun")) {
				c.t3[3] = 0;
			}

			if (!strcmp(c.ct32, "Mon")) {
				c.t3[7] = 1;
			}
			else if (!strcmp(c.ct32, "Tue")) {
				c.t3[7] = 2;
			}
			else if (!strcmp(c.ct32, "Wed")) {
				c.t3[7] = 3;
			}
			else if (!strcmp(c.ct32, "Thu")) {
				c.t3[7] = 4;
			}
			else if (!strcmp(c.ct32, "Fri")) {
				c.t3[7] = 5;
			}
			else if (!strcmp(c.ct32, "Sat")) {
				c.t3[7] = 6;
			}
			else if (!strcmp(c.ct32, "Sun")) {
				c.t3[7] = 0;
			}
		}
		

		// 날짜 계산하기
		if (type == 0) {
			a = allDays(c.t0[0], c.t0[1], c.t0[2]);
			b = allDays(c.t0[3], c.t0[4], c.t0[5]);
		}
		else if (type == 1) {
			a = allDays(c.t1[0], c.t1[1], c.t1[2]);
			b = allDays(c.t1[3], c.t1[4], c.t1[5], c.t1[6]);
		}
		else if (type == 2) {
			a = allDays(c.t2[0], c.t2[1], c.t2[2], c.t2[3]);
			b = allDays(c.t2[4], c.t2[5], c.t2[6]);
		}
		else if (type == 3) {
			a = allDays(c.t3[0], c.t3[1], c.t3[2], c.t3[3]);
			b = allDays(c.t3[4], c.t3[5], c.t3[6], c.t3[7]);
		}

		// 날짜 출력하기
		if (a == -1 || b == -1) {
			fout << "-1" << '\n';
		}
		else {
			result = a - b;
			if (a - b < 0) {
				result = -result;
			}

			fout << result << '\n';
		}
		
	}
	
}