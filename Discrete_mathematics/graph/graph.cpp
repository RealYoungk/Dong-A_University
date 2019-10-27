#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;

vector< vector< int > > edge;	// Edge 이차원 벡터
int weightArr[10000][10000];	// 가중치를 담을 배열
int visit[10000];	// 방문하면 1 아니면 0

int DFSsum = 0;
int BFSsum = 0;

queue<int> Q;
stack<int> S;

void DFS(int start, int vertex) {	// 시작위치와 정점개수
	if (visit[start] == 1) return;	// 방문이미 한거면 종료
	else {
		S.push(start);
		visit[start] = 1;
		while (!S.empty()) {
			int next = S.top();
			for (int i = 0; i < edge[next].size(); i++) {
				int next2 = edge[next][i];
				if (!visit[next2] && weightArr[next2][next] != 0) {
					DFSsum = DFSsum + weightArr[next2][next];
					visit[next2] = 1;
					S.push(next2);
					break;
				}
				// 엣지의 연결된 수만큼 반복 완료했는데
				// 마지막을 방문한 정점이 방문한경우인경우
				if (i == edge[next].size() - 1 && visit[next2] == 1) {
					S.pop();
				}
			}
		}
	}

}

void BFS(int start, int vertex) {
	if (visit[start] == 1) return;	// 방문 했으면 종료
	else {
		visit[start] = 1;
		Q.push(start);
		while (!Q.empty()) {
			int next = Q.front();
			Q.pop();
			for (int i = 0; i < edge[next].size(); i++) {
				int next2 = edge[next][i];
				if (!visit[next2] && weightArr[next2][next] != 0) {
					BFSsum = BFSsum + weightArr[next2][next];
					visit[next2] = 1;
					Q.push(next2);
				}
			}
		}
		
	}
}


int main() {
	ifstream fin("graph.inp");
	ofstream fout("graph.out");

	int testcase;
	fin >> testcase;
	for (int i = 0; i < testcase; i++) {

		int vertex;	// 정점의 개수
		int edge_num;	// 간선의 개수
		fin >> vertex >> edge_num;
		edge.resize(vertex);	// 정점 1개당 엣지 1개 설정

		int start, end, weight;
		// 간선 데이터 입력받기
		
		for (int j = 0; j < edge_num; j++) {
			fin >> start >> end >> weight;
			// 간선 단방향 연결
			edge[start].push_back(end);
			weightArr[start][end] = weight;
			// 간선 양방향 연결
			edge[end].push_back(start);
			weightArr[end][start] = weight;
		}

		// 정점을 정렬
		for (int j = 0; j < vertex; j++) {
			sort(edge[j].begin(), edge[j].end());
		}

		int count;		// 판독할 정점의 수
		fin >> count;
		for (int c = 0; c < count; c++) {
			int root;	// 순회 시작 정점
			fin >> root;
			DFS(root, vertex);
			memset(visit, 0, sizeof(visit));
			BFS(root, vertex);
			memset(visit, 0, sizeof(visit));
			fout << "n=" << vertex << " m=" << edge_num << " ";
			fout << "start=" << root << " ";
			fout << "DFS:" << DFSsum << " ";
			fout << "BFS:" << BFSsum << " ";
			fout << '\n';
			BFSsum = 0;
			DFSsum = 0;
		}
		edge.clear();
	}
	fin.close();
	fout.close();
	return 0;
}