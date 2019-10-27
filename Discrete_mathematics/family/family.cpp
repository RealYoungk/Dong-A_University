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
		int centry = 1;	// ��������
		int oldest = 0;	// 1���
		// ����� �Է¹ޱ�
		int people;
		fin >> people;
		// ��� ����ŭ ���������� �Ҵ�
		family.resize(people+1);
		int parant, child;	// �θ�, �ڽ�
		for (int i = 1; i < people; i++) {
			fin >> parant >> child;
			parants[child] = parant;
			family[parant].push_back(child);
		}
		// ��Ʈ ã��
		for (int i = 1; i <= people; i++) {
			if (parants[i] == 0) {
				oldest = i;
				break;
			}
		}

		// �ܸ� ��� ã��
		int j = 0;
		for (int i = 1; i <= people; i++) {
			// �ܸ� ��� ã��
			if (family[i].size() == 0) {
				young[j] = i;
				j++;
			}
		}
		// �ܸ���� �ϳ��� ��Ʈ���� �i�ƿö󰡱�
		for (int i = 0; i < j; i++) {
			int c = 1;
			int p1 = young[i];
			while (1) {
				if (p1 == oldest) break;
				else {
					c++;	// ��� ����
					p1 = parants[p1];
				}
			}
			if (centry < c) {
				centry = c;
			}
		}
		// ���
		fout << centry << '\n';
		
		// �������� �ʱ�ȭ
		for (int i = 0; i < 500001; i++) {
			parants[i] = 0;
			young[i] = 0;
		}
	}
	fin.close();
	fout.close();
}