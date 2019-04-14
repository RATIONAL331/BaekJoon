#include<iostream>
#include<vector>
#include<queue>
int main() {
	int N;
	std::cin >> N;

	std::vector<int>* graph = new std::vector<int>[N];
	int* degreeList = new int[N];
	for (int i = 0; i < N; i++) {
		degreeList[i] = 0;
	}
	
	int M;
	std::cin >> M;
	int nodeA, nodeB;
	for (int i = 0; i < M; i++) {
		std::cin >> nodeA >> nodeB;
		graph[nodeA - 1].push_back(nodeB - 1);
		degreeList[nodeB - 1]++;
	}

	std::priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		if (degreeList[i] == 0) {
			pq.push(-i);
		}
	}

	while (!pq.empty()) {
		int popNode = pq.top();
		popNode = popNode * -1;
		pq.pop();
		std::cout << popNode + 1 << " ";
		for (int adjacentNode : graph[popNode]) {
			degreeList[adjacentNode]--;
			if (degreeList[adjacentNode] == 0) {
				pq.push(-adjacentNode);
			}
		}
	}

	return 0;
}