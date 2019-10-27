#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

long long int maxInt = 2100000000;
long long int roots[1000000];
long long int childs[1000000];


int main() {

	ifstream fin("tree.inp");
	ofstream fout("tree.out");

	for (int t = 0;; t++) { // -1, -1 이 들어오면 프로그램 종료
		int i, j, k, root = -1, rootCount = 0;
		int childError = 1;	// 나를 가리키는 노드가 두개이상
		int rootError = 1;	// 루트가 2개 이상인경우
		for (i = 0; i < 1000000; i++) {
			roots[i] = maxInt;
			childs[i] = maxInt;
		}
		for (i = 0; i < 1000000; i++) {
			int n1, n2;
			fin >> n1 >> n2;
			if (n1 == 0 && n2 == 0)break;
			if (n1 == -1 && n2 == -1)return 0;
			roots[i] = n1; childs[i] = n2;
		}
		
		// 루트의 크기순으로 정렬(오름차순)
		sort(roots, roots + i);
		sort(childs, childs + i);

		// child 중복이 2개이면 안됨
		for (k = 0; k < i - 1; k++) {
			if (childs[k] == childs[k + 1]) {
				childError = 0;
				break;
			}
		}
		// 루트찾기 시작
		if (childError != 0) {
			for (j = 0, k = 0; j < i;) {
				if (roots[j] < childs[k]) {
					root = roots[j];
					rootCount++;
					while (1) {
						if (roots[j] == roots[j + 1]) {
							j++;
						}
						else {
							j++; break;
						}
					}
					if (rootCount > 1) {
						rootError = 0;
						break;
					}
				}
				else if (roots[j] == childs[k]) {
					while (1) {
						if (roots[j] == roots[j + 1]) {
							j++;
						}
						else {
							j++; break;
						}
					}
					k++;
				}
				else if (roots[j] > childs[k]) {
					k++;
				}
			}
		}
		if (childError == 0 || rootError == 0) {
			fout << "Test Case " << t+1 << ": " << -1 << '\n';
		}
		else {
			fout << "Test Case " << t + 1 << ": " << root << '\n';
		}
	}
	fin.close();
	fout.close();
}

