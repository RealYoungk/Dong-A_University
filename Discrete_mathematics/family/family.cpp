#include <iostream>
#include <fstream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

stack<int> Stack;
int young[500001];
int parants[500001];

int main() {
	
	ifstream fin("family.inp");
	ofstream fout("family.out");

	int testcase;
	fin >> testcase;
	while (testcase--) {
		vector < vector <int> > family;
		int centry = 1;	// 몇대손인지
		int oldest = 0;	// 1대손
		// 사람수 입력받기
		int people;
		fin >> people;
		// 사람 수만큼 이차원백터 할당
		family.resize(people+1);
		int parant, child;	// 부모, 자식
		for (int i = 1; i < people; i++) {
			fin >> parant >> child;
			parants[child] = parant;
			family[parant].push_back(child);
		}
		// 루트 찾기
		for (int i = 1; i <= people; i++) {
			if (parants[i] == 0) {
				oldest = i;
				break;
			}
		}

		// 단말 대손 찾기
		int j = 0;
		for (int i = 1; i <= people; i++) {
			// 단말 대손 찾기
			if (family[i].size() == 0) {
				young[j] = i;
				j++;
			}
		}
		// 단말대손 하나로 루트까지 쫒아올라가기
		for (int i = 0; i < j; i++) {
			int c = 1;
			int p1 = young[i];
			while (1) {
				if (p1 == oldest) break;
				else {
					c++;	// 대손 증가
					p1 = parants[p1];
				}
			}
			if (centry < c) {
				centry = c;
			}
		}
		// 출력
		fout << centry << '\n';
		
		// 전역변수 초기화
		for (int i = 0; i < 500001; i++) {
			parants[i] = 0;
			young[i] = 0;
		}
	}
	fin.close();
	fout.close();
}