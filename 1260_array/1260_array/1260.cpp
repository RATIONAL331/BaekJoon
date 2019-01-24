#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
void dfs(std::vector<std::vector<int>>& nodes, bool* visitList, int V) {
	if (visitList[V] == true) return;
	visitList[V] = true;
	std::cout << V + 1 << " ";
	for (int node : nodes[V]) {
		if (!visitList[node]) {
			dfs(nodes, visitList, node);
		}
	}
}
void bfs(std::vector<std::vector<int>>& nodes, bool* visitList, int V) {
	std::queue<int> queue;
	queue.push(V);
	visitList[V] = true;
	while (!queue.empty()) {
		int temp = queue.front();
		queue.pop();
		for (int node : nodes[temp]) {
			if (!visitList[node]) {
				queue.push(node);
				visitList[node] = true;
			}
		}
		std::cout << temp + 1 << " ";
	}
}
void sorting(std::vector<int>& node) {
	std::sort(node.begin(), node.end());
}
int main() {
	int N, M, V;
	std::cin >> N >> M >> V;

	std::vector<std::vector<int>> nodes;
	for (int i = 1; i <= N; i++) {
		std::vector<int> node;
		nodes.push_back(node);
	}

	int node1, node2;
	for (int i = 0; i < M; i++) {
		std::cin >> node1 >> node2;
		nodes.at(node1 - 1).push_back(node2 - 1);
		nodes.at(node2 - 1).push_back(node1 - 1);
	}

	for(int i=0; i<N; i++) sorting(nodes[i]);

	bool * visitList = new bool[N];

	for (int i = 0; i < N; i++) visitList[i] = false;
	dfs(nodes, visitList, V - 1);
	
	std::cout << std::endl;
	
	for (int i = 0; i < N; i++) visitList[i] = false;
	bfs(nodes, visitList, V - 1);
	
	delete[] visitList;
	return 0;
}