#include<iostream>
#include<vector>
<<<<<<< HEAD
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
			if (distanceList[curNode.node] + adjacentNode.cost < distanceList[adjacentNode.node]) {
				distanceList[adjacentNode.node] = distanceList[curNode.node] + adjacentNode.cost;
				pqNode.push(adjacentNode);
			}
		}
	}
	
}
int main() {
	int V, E, startNode;
	std::cin >> V >> E >> startNode;

	int* distanceList = new int[V];
	std::vector<Node>* graph = new std::vector<Node>[V];

	int u, v, w;
	
	for (int i = 0; i < E; i++) {
		scanf_s("%d %d %d", &u, &v, &w);
		graph[u - 1].push_back(Node(v - 1, w));
			
	}
	for (int i = 0; i < V; i++) {
		distanceList[i] = INF;
	}
	dijkstra(graph, distanceList, startNode - 1, V);
=======
const int INF = 987654321;
int getMinNode(int* distanceList, bool* visitList, int length) {
	int min = INF;
	int index = 0;
	for (int i = 0; i < length; i++) {
		if (!visitList[i] && distanceList[i] < min) {
			min = distanceList[i];
			index = i;
		}
	}
	return index;
}
void dijkstra(int** graphList, bool* visitList, int* distanceList, int startNode, int nodeCount) {
	for (int i = 0; i < nodeCount; i++) {
		if (i == startNode) continue;
		distanceList[i] = graphList[startNode][i];
	}
	visitList[startNode] = true;
	for (int i = 0; i < nodeCount - 2; i++) {
		int curNode = getMinNode(distanceList, visitList, nodeCount);
		visitList[curNode] = true;
		for (int j = 0; j < nodeCount; j++) {
			// ���� �湮���� �ʴ� ��忡 ���ؼ�
			if (!visitList[j]) {
				if (distanceList[curNode] + graphList[curNode][j] < distanceList[j]) {
					distanceList[j] = distanceList[curNode] + graphList[curNode][j];
				}
			}
		}
	}
}
int main() {
	int V, E;
	int startNode;

	std::cin >> V >> E >> startNode;
	// �׷��� ��尣 �Ÿ� 2���� �迭 ����
	int** graphDistance = new int*[V];
	for (int i = 0; i < V; i++) {
		graphDistance[i] = new int[V];
	}
	// 2���� �迭 �ʱ�ȭ
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			graphDistance[i][j] = INF;
		}
	}
	// �湮 ����Ʈ ����
	bool* visitList = new bool[V];
	for (int i = 0; i < V; i++) {
		visitList[i] = false;
	}
	// �Ÿ� ����Ʈ ���� �� ���Ѵ�� �ʱ�ȭ
	int* distanceList = new int[V];
	for (int i = 0; i < V; i++) {
		distanceList[i] = INF;
	}
	// �׷��� �Է¹ޱ�
	int fromNode, toNode, distance;
	for (int i = 0; i < E; i++) {
		std::cin >> fromNode;
		std::cin >> toNode;
		std::cin >> distance;

		if (graphDistance[fromNode - 1][toNode - 1] == 0) {
			graphDistance[fromNode - 1][toNode - 1] = distance;
		}
		else {
			if (distance < graphDistance[fromNode - 1][toNode - 1]) {
				graphDistance[fromNode - 1][toNode - 1] = distance;
			}
		}
	}
	/*
	�׷������� 0�̶�� fromNode���� toNode���� ���� ���� ���� ���� �ǹ��Ѵ�.
	�׷����� ���� 0�� �ƴ� ���� ������ fromNode���� toNode���� ���� ���� �ְ� �� ���� ��η� ���� ���̴�.
	*/
	distanceList[startNode - 1] = 0;
	dijkstra(graphDistance, visitList, distanceList, startNode - 1, V);

	for (int i = 0; i < V; i++) {
		if (distanceList[i] == INF)
			std::cout << "INF" << std::endl;
		else 
			std::cout << distanceList[i] << std::endl;
	}
>>>>>>> 4fd25d3294978e3af2fe3d47f95554f5897f6a2b

	for (int i = 0; i < V; i++) {
		if (distanceList[i] == INF) printf("INF\n");
		else printf("%d\n", distanceList[i]);
	}
	delete[] distanceList;
	delete[] graph;
	return 0;
}