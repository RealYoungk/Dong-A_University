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

	for (int t = 0;; t++) { // -1, -1 �� ������ ���α׷� ����
		int i, j, k, root = -1, rootCount = 0;
		int childError = 1;	// ���� ����Ű�� ��尡 �ΰ��̻�
		int rootError = 1;	// ��Ʈ�� 2�� �̻��ΰ��
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
		
		// ��Ʈ�� ũ������� ����(��������)
		sort(roots, roots + i);
		sort(childs, childs + i);

		// child �ߺ��� 2���̸� �ȵ�
		for (k = 0; k < i - 1; k++) {
			if (childs[k] == childs[k + 1]) {
				childError = 0;
				break;
			}
		}
		// ��Ʈã�� ����
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

