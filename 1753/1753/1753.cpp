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
			// 아직 방문하지 않는 노드에 대해서
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
	// 그래프 노드간 거리 2차원 배열 생성
	int** graphDistance = new int*[V];
	for (int i = 0; i < V; i++) {
		graphDistance[i] = new int[V];
	}
	// 2차원 배열 초기화
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			graphDistance[i][j] = INF;
		}
	}
	// 방문 리스트 생성
	bool* visitList = new bool[V];
	for (int i = 0; i < V; i++) {
		visitList[i] = false;
	}
	// 거리 리스트 생성 및 무한대로 초기화
	int* distanceList = new int[V];
	for (int i = 0; i < V; i++) {
		distanceList[i] = INF;
	}
	// 그래프 입력받기
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
	그래프값이 0이라면 fromNode부터 toNode까지 가는 길이 없는 것을 의미한다.
	그래프의 값이 0이 아닌 값이 있으면 fromNode부터 toNode까지 가는 길이 있고 그 값이 경로로 가는 길이다.
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