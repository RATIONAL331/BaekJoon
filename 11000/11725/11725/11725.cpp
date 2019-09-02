#include<iostream>
#include<vector>
void getParent(std::vector<int>* tree, bool* visitNode, int visitNum, int* retArr) {
	visitNode[visitNum] = true;
	for (int next : tree[visitNum]) {
		if (!visitNode[next]) {
			retArr[next] = visitNum;
			getParent(tree, visitNode, next, retArr);
		}
	}
}

int main() {
	int N;
	std::cin >> N;
	
	bool* visitNode = new bool[N];
	int* retArr = new int[N];
	std::vector<int>* treeArr = new std::vector<int>[N];

	for (int i = 0; i < N; i++) {
		visitNode[i] = false;
	}

	int node1, node2;
	for (int i = 0; i < N - 1; i++) {
		std::cin >> node1 >> node2;
		treeArr[node1 - 1].push_back(node2 - 1);
		treeArr[node2 - 1].push_back(node1 - 1);
	}

	getParent(treeArr, visitNode, 0, retArr);

	for (int i = 1; i < N; i++) {
		std::cout << retArr[i] + 1 << "\n";
	}

	delete[] retArr;
	delete[] visitNode;
	delete[] treeArr;

	return 0;
}