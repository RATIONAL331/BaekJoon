#include<iostream>
#include<vector>
#include<queue>
int main() {
	int N;
	std::cin >> N;

	int* degreeNode = new int[N];
	int* buildingTimeList = new int[N];
	int* retList = new int[N];
	std::vector<int>* buildingVec = new std::vector<int>[N];
	// �迭 �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		degreeNode[i] = 0;
		retList[i] = 0;
	}

	// �Է� �ޱ�
	int buildingTime, linkNode;
	for (int i = 0; i < N; i++) {
		// ��ġ�ð� �Է¹ޱ�
		std::cin >> buildingTime;
		buildingTimeList[i] = buildingTime;
		// ����� ��� �Է¹ޱ�
		while (true) {
			std::cin >> linkNode;
			if (linkNode == -1) break;
			buildingVec[linkNode - 1].push_back(i);
			degreeNode[i]++;
		}
	}
	// bfs ����
	std::queue<int> que;
	for (int i = 0; i < N; i++) {
		// ���������� 0�� ��� ���� Ž��
		if (degreeNode[i] == 0)
			que.push(i);
		retList[i] += buildingTimeList[i];
	}

	int popNode;
	while (!que.empty()) {
		popNode = que.front();
		que.pop();

		for (int adjacentNode : buildingVec[popNode]) {
			retList[adjacentNode] = std::max(retList[adjacentNode], retList[popNode] + buildingTimeList[adjacentNode]);
			degreeNode[adjacentNode]--;
			if (degreeNode[adjacentNode] == 0) {
				que.push(adjacentNode);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		std::cout << retList[i] << std::endl;
	}

	delete[] retList;
	delete[] buildingTimeList;
	delete[] degreeNode;
	delete[] buildingVec;
	return 0;
}