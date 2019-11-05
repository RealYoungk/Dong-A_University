#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

ifstream fin("tree.inp");
ofstream fout("tree.out");

vector<string> origin;
vector<string> pre;
vector<string> in;
vector<string> inT;

void Inorder(string s) {
	int index;
	for (int i = 0; i < pre.size(); i++) {
		if (s == pre[i]) {
			index = i;
			break;
		}
	}
	for (int i = index - 1; i >= 0; i--) {
		if (pre[i][0] == 'r') {
			if (pre[i][1] != 'r') {
				in.push_back(pre[i]);
				pre[i] = "rr";
				break;
			}
		}
	}
}

string itos(int num) {
	char result[4];
	int temp = num;
	int i;
	if (num >= 100) {
		result[0] = num / 100 + '0';
		num = num % 100;
		result[1] = num / 10 + '0';
		result[2] = num % 10 + '0';
		result[3] = '\0';
	}
	else if (num >= 10) {
		result[0] = num / 10 + '0';
		result[1] = num % 10 + '0';
		result[2] = '\0';
	}
	else if (num >= 0) {
		result[0] = num % 10 + '0';
		result[1] = '\0';
	}
	return result;
}

int main() {
	string s;
	int testcase;
	fin >> testcase;
	while (testcase--) {
		int tCnt = 0;
		int cnt = -1;
		for (int i = 0;; i++) {
			fin >> s;
			if (s[0] == '(') cnt++;
			else if (s[0] == ')') cnt--;
			origin.push_back(s);
			if (cnt == -1) break;
		}
		for (int i = 0; i < origin.size(); i++) {
			fout << origin[i] << ' ';
		}
		fout << '\n';
		
		// 전위순회
		fout << "Preorder" << '\n';
		for (int i = 0; i < origin.size(); i++) {
			if (origin[i] == "(") {
				++cnt;
				string a1 = itos(cnt);
				string a2 = "r";
				string temp = a2 + a1;
				fout << temp << '\n';
				pre.push_back(temp);
			}
			else if (origin[i] != ")") {
				fout << origin[i] << '\n';
				pre.push_back(origin[i]);
			}
		}

		// 후위순회
		fout << "Inorder" << '\n';
		for (int i = 0; i < pre.size(); i++) {
			if (pre[i][0] != 'r') {
				Inorder(pre[i]);
				inT.push_back(pre[i]);
			}
		}
		for (int i = 0; i < in.size(); i++) {
			fout << inT[i] << '\n';
			fout << in[i] << '\n';
		}
		fout << inT[inT.size() - 1] << '\n';
		
		origin.clear(); pre.clear(); in.clear(); inT.clear();
	}
}