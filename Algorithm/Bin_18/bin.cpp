#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#define MAX 987654321
using namespace std;

ifstream fin("bin.inp");
ofstream fout("bin.out");

int T;
int M, N;
int distSum[503][503];	// i��°���� j��° �������� �������� 1���� ī��
int dp[503][503];	// i��° �������� j���� ������������ ī��
int home[503];
// Dp[i][j] = min(dp[n][k], �ñ׸�Ƽ���Ϻ��Ϳ����� dp[n-t][k-1] + dist[n-t][n]

void reset() {
	for (int i = 1; i < 503; i++) {
		for (int j = 0; j < 503; j++) {
			dp[i][j] = MAX;
		}
	}
	for (int i = 0; i < 503; i++) {
		for (int j = 0; j < 503; j++) {
			distSum[i][j] = 0;
		}
	}
	//memset(distSum, 0, sizeof(distSum));
}

void setHome() {
	for (int i = 1; i <= N; i++) {
		fin >> home[i];
	}
	sort(home + 1, home + 1 + N);
}

void bin() {
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			distSum[i][j] = distSum[i][j - 1] + home[j] - home[i + (j - i) / 2];
		}
	}
	
	for (int i = 1; i <= M; i++) {
		dp[0][i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 1; k <= i; k++) {
				dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + distSum[k][i]);
			}
		}
	}
}



int main() {
	int testcase;
	fin >> testcase;
	while (testcase--) {
		fin >> N >> M;
		reset();
		setHome();
		bin();
		fout << dp[N][M] << '\n';
	}
	return 0;
}