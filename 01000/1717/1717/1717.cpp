#include<cstdio>
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
	int n, m;
	scanf("%d %d", &n, &m);

	vector<Node> nodeVec(n + 1);
	for (int i = 0; i < n + 1; i++)
		nodeVec[i].parent = &nodeVec[i];

	int proceduer, parent, child;
	while (m--) {
		scanf("%d %d %d", &proceduer, &parent, &child);
		switch (proceduer) {
		case 0:
			// ������
			nodeUnion(&nodeVec[parent], &nodeVec[child]);
			break;
		case 1:
			// ���� Ȯ���ϱ�
			if (findParent(&nodeVec[parent]) == findParent(&nodeVec[child]))
				printf("YES\n");
			else
				printf("NO\n");
			break;
		}
	}
	return 0;
}