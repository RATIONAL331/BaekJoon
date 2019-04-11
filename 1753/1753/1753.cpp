#include<iostream>
#include<vector>
int main() {
	int V, E;
	int startNode;

	std::cin >> V >> E >> startNode;
	// �׷��� ����
	int** graph = new int* [V];
	for (int i = 0; i < V; i++) {
		graph[i] = new int[V];
	}
	// �湮 ����Ʈ ���� �� ���Ѵ�� �ʱ�ȭ
	int* visitList = new int[V];
	for (int i = 0; i < V; i++) {
		visitList[i] = INT32_MAX;
	}
	// �׷��� 0���� �ʱ�ȭ 
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			graph[i][j] = 0;
		}
	}
	// �׷��� �Է¹ޱ�
	int fromNode, toNode, distance;
	for (int i = 0; i < E; i++) {
		std::cin >> fromNode;
		std::cin >> toNode;
		std::cin >> distance;

		if (graph[fromNode - 1][toNode - 1] == 0) {
			graph[fromNode - 1][toNode - 1] = distance;
		}
		else {
			if (distance < graph[fromNode - 1][toNode - 1]) {
				graph[fromNode - 1][toNode - 1] = distance;
			}
		}
	}
	/*
	�׷������� 0�̶�� fromNode���� toNode���� ���� ���� ���� ���� �ǹ��Ѵ�.
	�׷����� ���� 0�� �ƴ� ���� ������ fromNode���� toNode���� ���� ���� �ְ� �� ���� ��η� ���� ���̴�.
	*/

	//�湮 ����Ʈ�� ù��° �������� 0���� �Ѵ�.
	visitList[startNode - 1] = 0;

	return 0;
}