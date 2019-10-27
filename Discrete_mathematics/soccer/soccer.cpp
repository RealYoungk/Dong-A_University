#include<iostream>
#include<fstream>
using namespace std;

class Soccer {
public:
	int win;	// 이긴 수
	int lose;	// 진 수
	int draw;	// 비긴 수
	int score;	// 승점

	int goal;	// 넣은골수
	int awayGoal;	// 어웨이팀에서 넣은 골수
	int noGoal;		// 골 먹힌 수
	int totalGoal;	// 골 득실

	int rank;

	Soccer() {
		win = 0;
		lose = 0;
		draw = 0;
		score = 0;

		goal = 0;
		awayGoal = 0;
		noGoal = 0;
		totalGoal = 0;

		rank = 1;
	}

	void set(bool away, int goal, int noGoal) {
		
		// 승패 계산
		if (goal > noGoal) {
			this->win++;	// 넣은골수가 먹힌거보다 많으면 승리+1
		}
		else if (goal < noGoal) {
			this->lose++;	// 먹힌골수가 넣은거보다 많으면 패비+1
		}
		else {
			this->draw++;	// 넣은,먹힌골수 같으면 드로우+1
		}
		// 스코어 계산
		score = win * 3 + draw;

		// 골수 계산
		this->goal = this->goal + goal;	//	넣은 골수 계산
		this->noGoal = this->noGoal + noGoal;	// 먹힌 골수 계산
		this->totalGoal = this->totalGoal + goal - noGoal;
		// 골득실은 현제골득실에서 넣은공 - 먹힌공
		
		if (away == true) {	// 어웨이 팀일때
			this->awayGoal = this->awayGoal + goal;	// 어웨이팀에서 넣은 골수추가
		}
	}
};


int main() {

	ifstream fin("soccer.inp");
	if (fin.fail()) {
		cout << "파일여는데 실패했습니다.";
	}
	ofstream fout("soccer.out");

	
	
	int round;	//	라운드 수
	int team;	//	팀 수
	char trash;	//	쓰래기값
	int homeTeam, awayTeam;	// 팀 이름
	int homeTeamGoal, awayTeamGoal;	// 넣은 골수
	
	int testcase;	// testcase 반복 횟수

	fin >> testcase;

	// 테스트케이스 반복 시작
	for (int t = 0; t < testcase; t++) {
		
		Soccer s[40];	// 사커 팀 객체

		fin >> team >> round;
		// 데이터 삽입, 스코어, 골득실, 어웨이 계산
		// 라운드 수만큼 반복
		for (int i = 0; i < round; i++) {
			// 날짜 수만큼 반복
			for (int j = 0; j < 2 * (team - 1); j++) {
				// 하루에 경기수
				for (int k = 0; k < team; k = k + 2) {
					fin >> awayTeam >> trash >> homeTeam >> awayTeamGoal >> homeTeamGoal;
					s[awayTeam - 1].set(true, awayTeamGoal, homeTeamGoal);
					s[homeTeam - 1].set(false, homeTeamGoal, awayTeamGoal);
				}
			}
		}

		// 순위 계산시작
		for (int i = 0; i < team; i++) {
			for (int j = (i + 1); j < team; j++) {
				// 스코어 비교 시작
				if (s[i].score < s[j].score) {
					s[i].rank++;
				}
				else if (s[i].score > s[j].score) {
					s[j].rank++;
				}
				// 스코어가 같은경우 골득실 비교
				else {
					if (s[i].totalGoal < s[j].totalGoal) {
						s[i].rank++;
					}
					else if (s[i].totalGoal > s[j].totalGoal) {
						s[j].rank++;
					}
					// 골득실이 같은경우 어웨이 골수 비교
					else {
						if (s[i].awayGoal < s[j].awayGoal) {
							s[i].rank++;
						}
						else if (s[i].awayGoal > s[j].awayGoal) {
							s[j].rank++;
						}
					}
				}
			}
		}	// 순위 계산 끝

		// 결과값 출력 시작
		fout << "Test Case #" << (t + 1) << ": ";
		for (int i = 0; i < team; i++) {
			fout << s[i].rank << ' ';
		}
		fout << '\n';
		
	}

	fin.close();
	fout.close();
}