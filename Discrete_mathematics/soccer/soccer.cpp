#include<iostream>
#include<fstream>
using namespace std;

class Soccer {
public:
	int win;	// �̱� ��
	int lose;	// �� ��
	int draw;	// ��� ��
	int score;	// ����

	int goal;	// �������
	int awayGoal;	// ����������� ���� ���
	int noGoal;		// �� ���� ��
	int totalGoal;	// �� ���

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
		
		// ���� ���
		if (goal > noGoal) {
			this->win++;	// ��������� �����ź��� ������ �¸�+1
		}
		else if (goal < noGoal) {
			this->lose++;	// ��������� �����ź��� ������ �к�+1
		}
		else {
			this->draw++;	// ����,������� ������ ��ο�+1
		}
		// ���ھ� ���
		score = win * 3 + draw;

		// ��� ���
		this->goal = this->goal + goal;	//	���� ��� ���
		this->noGoal = this->noGoal + noGoal;	// ���� ��� ���
		this->totalGoal = this->totalGoal + goal - noGoal;
		// ������ �������ǿ��� ������ - ������
		
		if (away == true) {	// ����� ���϶�
			this->awayGoal = this->awayGoal + goal;	// ����������� ���� ����߰�
		}
	}
};


int main() {

	ifstream fin("soccer.inp");
	if (fin.fail()) {
		cout << "���Ͽ��µ� �����߽��ϴ�.";
	}
	ofstream fout("soccer.out");

	
	
	int round;	//	���� ��
	int team;	//	�� ��
	char trash;	//	�����Ⱚ
	int homeTeam, awayTeam;	// �� �̸�
	int homeTeamGoal, awayTeamGoal;	// ���� ���
	
	int testcase;	// testcase �ݺ� Ƚ��

	fin >> testcase;

	// �׽�Ʈ���̽� �ݺ� ����
	for (int t = 0; t < testcase; t++) {
		
		Soccer s[40];	// ��Ŀ �� ��ü

		fin >> team >> round;
		// ������ ����, ���ھ�, ����, ����� ���
		// ���� ����ŭ �ݺ�
		for (int i = 0; i < round; i++) {
			// ��¥ ����ŭ �ݺ�
			for (int j = 0; j < 2 * (team - 1); j++) {
				// �Ϸ翡 ����
				for (int k = 0; k < team; k = k + 2) {
					fin >> awayTeam >> trash >> homeTeam >> awayTeamGoal >> homeTeamGoal;
					s[awayTeam - 1].set(true, awayTeamGoal, homeTeamGoal);
					s[homeTeam - 1].set(false, homeTeamGoal, awayTeamGoal);
				}
			}
		}

		// ���� ������
		for (int i = 0; i < team; i++) {
			for (int j = (i + 1); j < team; j++) {
				// ���ھ� �� ����
				if (s[i].score < s[j].score) {
					s[i].rank++;
				}
				else if (s[i].score > s[j].score) {
					s[j].rank++;
				}
				// ���ھ ������� ���� ��
				else {
					if (s[i].totalGoal < s[j].totalGoal) {
						s[i].rank++;
					}
					else if (s[i].totalGoal > s[j].totalGoal) {
						s[j].rank++;
					}
					// ������ ������� ����� ��� ��
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
		}	// ���� ��� ��

		// ����� ��� ����
		fout << "Test Case #" << (t + 1) << ": ";
		for (int i = 0; i < team; i++) {
			fout << s[i].rank << ' ';
		}
		fout << '\n';
		
	}

	fin.close();
	fout.close();
}