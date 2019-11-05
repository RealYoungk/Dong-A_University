#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

ifstream fin("tree2.inp");
ofstream fout("tree2.out");

struct node {
	int id;
	bool visit;
	node(){
		visit = false;
	}
};

vector < node > pre;
vector < node > in;
vector < node > post;
int nodeNum;

void postorder(int r, int s, int e) {
	int rootIndex;
	for (int i = s; i < nodeNum; i++) {
		if (pre[r].id == in[i].id) {
			rootIndex = i;
			break;
		}
	}
	if (s != rootIndex) postorder(r + 1, s, rootIndex - 1);
	if (rootIndex != e) postorder(r + ((rootIndex - s) + 1), rootIndex + 1, e);
	fout << in[rootIndex].id << '\n';
}

void preorder(int r, int s, int e) {
	int rootIndex;
	for (int i = s; i < nodeNum; i++) {
		if (post[r].id == in[i].id) {
			rootIndex = i;
			break;
		}
	}
	fout << in[rootIndex].id << '\n';
	if (s != rootIndex) preorder(r - ((e - rootIndex) + 1), s, rootIndex - 1);
	if (rootIndex != e) preorder(r - 1, rootIndex + 1, e);
}

int main() {
	
	fin >> nodeNum;
	int k1, k2;
	node temp;
	
	fin >> k1;
	if (k1 == -1) {
		for (int i = 0; i < nodeNum; i++) {
			fin >> temp.id;
			pre.push_back(temp);
		}
	}

	else if (k1 == 0) {
		for (int i = 0; i < nodeNum; i++) {
			fin >> temp.id;
			in.push_back(temp);
		}
	}

	else if (k1 == 1) {
		for (int i = 0; i < nodeNum; i++) {
			fin >> temp.id;
			post.push_back(temp);
		}
	}
	////////////////////////////////////////////////////////////////////////
	fin >> k2;
	if (k2 == -1) {
		for (int i = 0; i < nodeNum; i++) {
			fin >> temp.id;
			pre.push_back(temp);
		}
	}

	else if (k2 == 0) {
		for (int i = 0; i < nodeNum; i++) {
			fin >> temp.id;
			in.push_back(temp);
		}
	}

	else if (k2 == 1) {
		for (int i = 0; i < nodeNum; i++) {
			fin >> temp.id;
			post.push_back(temp);
		}
	}

	if (pre.empty()) {	// 전위순회 구하기
		preorder(nodeNum - 1, 0, nodeNum - 1);
	}
	else if (post.empty()) {	// 후위순회 구하기
		postorder(0, 0, nodeNum - 1);
	}

}