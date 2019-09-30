#include<iostream>
#include<vector>
using namespace std;

struct Node {
	Node* parent;
};

Node* findParent(Node* node) {
	if (node == node->parent) return node;
	else return node->parent = findParent(node->parent);
}

void nodeUnion(Node* parent, Node* child) {
	findParent(child)->parent = findParent(parent);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<Node> nodeVec(n + 1);
	for (int i = 0; i < n + 1; i++)
		nodeVec[i].parent = &nodeVec[i];

	int proceduer, parent, child;
	while (m--) {
		cin >> proceduer >> parent >> child;
		switch (proceduer) {
		case 0:
			// 합집합
			nodeUnion(&nodeVec[parent], &nodeVec[child]);
			break;
		case 1:
			// 포함 확인하기
			if (findParent(&nodeVec[parent]) == findParent(&nodeVec[child]))
				cout << "YES\n";
			else
				cout << "NO\n";
			break;
		}
	}
	return 0;
}