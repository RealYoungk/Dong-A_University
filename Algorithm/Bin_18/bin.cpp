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
int distSum[503][503];	// i번째에서 j번째 마을까지 쓰래기통 1개로 카바
int dp[503][503];	// i번째 마을까지 j개의 쓰레기통으로 카바
int home[503];
// Dp[i][j] = min(dp[n][k], 시그마티는일부터엠까지 dp[n-t][k-1] + dist[n-t][n]

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