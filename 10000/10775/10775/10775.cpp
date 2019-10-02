#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int data;
	Node* parent;
};

Node* findParent(Node* node) {
	if (node == node->parent) return node;
	return node->parent = findParent(node->parent);
}

void unionNode(Node* parent, Node* child) {
	findParent(child)->parent = findParent(parent);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int G, P;
	cin >> G >> P;

	vector<Node> nodeVec(G + 1);
	for (int i = 0; i < G + 1; i++) {
		nodeVec[i].data = i;
		nodeVec[i].parent = &nodeVec[i];
	}

	int gi;
	int cnt = 0;
	while (P--) {
		cin >> gi;
		Node* tempNode = findParent(&nodeVec[gi]);
		if (tempNode->data == 0) break;

		unionNode(&nodeVec[tempNode->data - 1], &nodeVec[gi]);
		cnt++;
	}

	cout << cnt;

	return 0;
}