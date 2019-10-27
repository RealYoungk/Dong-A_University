#include <iostream>
#include <fstream>
#include <functional>
#include <queue>
using namespace std;

int main() {
	
	ifstream fin("add.inp");
	ofstream fout("add.out");

	priority_queue< int, vector<int>, greater<int> >pq;	// �켱���� ť ���� ������ �������� ť

	long long total = 0;
	int howMany;	// ������ ����
	int num, n1, n2;

	while (1) {

		// ��������

		fin >> howMany;
		if (howMany == 0) break;

		// ������ �Է�
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