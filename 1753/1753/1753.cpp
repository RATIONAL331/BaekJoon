#include<iostream>
#include<vector>
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

	return 0;
}