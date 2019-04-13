#include<iostream>
#include<vector>
#include<queue>

const int INF = 987654321;

class Node {
public:
	int node;
	int cost;

	Node() : Node(0, 0) {}
	Node(int node, int cost) {
		this->node = node;
		this->cost = cost;
	}

	bool operator< (const Node& linkedNode) const {
		return cost > linkedNode.cost;
	}
};
void dijkstra(std::vector<Node>* graph, int* distanceList, int startNode, int nodeCount) {
	std::priority_queue<Node> pqNode;
	pqNode.push(Node(startNode, 0));
	distanceList[startNode] = 0;

	while (!pqNode.empty()) {
		Node curNode = pqNode.top();
		pqNode.pop();
		for (Node adjacentNode : graph[curNode.node]) {
			int newCost = distanceList[curNode.node] + adjacentNode.cost;
			int oldCost = distanceList[adjacentNode.node];
			if (newCost < oldCost) {
				distanceList[adjacentNode.node] = newCost;
				pqNode.push(adjacentNode);
			}
		}
	}

}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int V, E, startNode;
	scanf("%d %d %d", &V, &E, &startNode);

	int* distanceList = new int[V];
	std::vector<Node>* graph = new std::vector<Node>[V];

	int u, v, w;

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		graph[u - 1].push_back(Node(v - 1, w));

	}
	for (int i = 0; i < V; i++) {
		distanceList[i] = INF;
	}
	dijkstra(graph, distanceList, startNode - 1, V);

	for (int i = 0; i < V; i++) {
		if (distanceList[i] == INF) printf("INF\n");
		else printf("%d\n", distanceList[i]);
	}
	delete[] distanceList;
	delete[] graph;
	return 0;
}