#include <iostream>
#include <fstream>
#include <functional>
#include <queue>
using namespace std;

int main() {
	
	ifstream fin("add.inp");
	ofstream fout("add.out");

	priority_queue< int, vector<int>, greater<int> >pq;	// 우선순위 큐 들어갈때 순서가 정해지는 큐

	long long total = 0;
	int howMany;	// 정수의 개수
	int num, n1, n2;

	while (1) {

		// 종료조건

		fin >> howMany;
		if (howMany == 0) break;

		// 데이터 입력
		for (int i = 0; i < howMany; i++) {
			fin >> num;
			pq.push(num);
		}

		for (int i = 0; i < howMany - 1; i++) {
			n1 = pq.top(); pq.pop();
			n2 = pq.top(); pq.pop();
			total = total + n1 + n2;
			pq.push(n1 + n2);
		}

		fout << total << '\n';
		total = 0;
		while (!pq.empty()) {
			pq.pop();
		}
	}


}