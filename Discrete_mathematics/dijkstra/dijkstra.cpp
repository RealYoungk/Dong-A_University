#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stack>
using namespace std;

stack<int> Stack;
stack<int> Stack2;

int shortest[10000] = {0};	// 최단거리를 저장할 배열
int path[10000] = {};
int finish[10000] = {};	// 끝난 노드이면 1

int findLittlePath(int vertex) {
	int min = 10000000;
	int minIndex=0;
	for (int i = 0; (i < vertex); i++) {
		if (shortest[i] < min && finish[i] != 1) {
			min = shortest[i];
			minIndex = i;
		}
	}
	return minIndex;
}

typedef struct edge {
	int start;
	int end;
	int weight;
	int piriot;	// 우선순위 0 ,1 ,2 ,3 .....
}edge;

vector< vector<edge> > E;

bool compare(edge a, edge b) {
	if (a.weight <= b.weight) {
		return true;
	}
	else return false;
}

int main() {

	ifstream fin("dijkstra.inp");
	ofstream fout("dijkstra.out");

	// 각 간선의 출발지, 목적지, 가중치, 이름은 인덱스로 쓰자

	int v;	// 정점의 개수
	int e;	// 간선의 개수

	// 정점, 간선의 개수 입력받기
	fin >> v >> e;
	E.resize(e);	// 간선을 저장할 백터 동적할당

	// 간선 출발지,목적지,가중치 입력받기
	for (int i = 0; i < e; i++) {
		edge a;
		int source, dest, weight;
		fin >> source >> dest >> weight;
		a.start = source; a.end = dest; 
		a.weight = weight; a.piriot = i;
		E[source].push_back(a);	// 연결
	}
	

	for (int i = 1; i < 10000; i++) {
		shortest[i] = 100000000;
	}

	// 경로의 길이 계산
	for (int i = 0; i < v; i++) {
		// 최단거리 노드 구하기
		int node = findLittlePath(v);	
		for (int j = 0; j < E[node].size(); j++) {
			int tmp = shortest[E[node][j].start] + E[node][j].weight;
			if (shortest[E[node][j].end] > tmp) {
				// 경로수정
				path[E[node][j].end] = E[node][j].start;
				// 최단거리 수정
				shortest[E[node][j].end] = tmp;
			}
			else if (shortest[E[node][j].end] == tmp) {
				// 이전 엣지의 출발지
				int temp = path[E[node][j].end];
				int k;
				for (k = 0; k < E[temp].size(); k++) {
					if (E[temp][k].end == E[node][j].end)
						break;
				}
				if (E[node][j].piriot > E[temp][k].piriot) {
					path[E[node][j].end] = E[node][j].start;
				}
			}
		}
		finish[node] = 1;	// 노드 1개 탐색 끝
	}

	for (int i = 1; i < 10000; i++) {
		if (shortest[i] == 100000000) {
			shortest[i] = -1;
		}
	}

	// 결과값 출력
	for (int i = 1; i < v; i++) {
		fout << "V0 ";
		int temp = i;
		while (1) {
			Stack.push(temp);
			if (path[temp] == 0) break;
			else {
				temp = path[temp];
			}
		}
		while (!Stack.empty()) {
			fout << "V" << Stack.top() << " ";
			Stack.pop();
		}
		fout << "(" << shortest[i] << ")\n";
	}
	

	fin.close();
	fout.close();
}