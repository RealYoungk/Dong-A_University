#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;

vector< vector< int > > edge;	// Edge ������ ����
int weightArr[10000][10000];	// ����ġ�� ���� �迭
int visit[10000];	// �湮�ϸ� 1 �ƴϸ� 0

int DFSsum = 0;
int BFSsum = 0;

queue<int> Q;
stack<int> S;

void DFS(int start, int vertex) {	// ������ġ�� ��������
	if (visit[start] == 1) return;	// �湮�̹� �ѰŸ� ����
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
				// ������ ����� ����ŭ �ݺ� �Ϸ��ߴµ�
				// �������� �湮�� ������ �湮�Ѱ���ΰ��
				if (i == edge[next].size() - 1 && visit[next2] == 1) {
					S.pop();
				}
			}
		}
	}

}

void BFS(int start, int vertex) {
	if (visit[start] == 1) return;	// �湮 ������ ����
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

		int vertex;	// ������ ����
		int edge_num;	// ������ ����
		fin >> vertex >> edge_num;
		edge.resize(vertex);	// ���� 1���� ���� 1�� ����

		int start, end, weight;
		// ���� ������ �Է¹ޱ�
		
		for (int j = 0; j < edge_num; j++) {
			fin >> start >> end >> weight;
			// ���� �ܹ��� ����
			edge[start].push_back(end);
			weightArr[start][end] = weight;
			// ���� ����� ����
			edge[end].push_back(start);
			weightArr[end][start] = weight;
		}

		// ������ ����
		for (int j = 0; j < vertex; j++) {
			sort(edge[j].begin(), edge[j].end());
		}

		int count;		// �ǵ��� ������ ��
		fin >> count;
		for (int c = 0; c < count; c++) {
			int root;	// ��ȸ ���� ����
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