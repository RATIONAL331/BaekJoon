#include<iostream>
#include<vector>
void visitListInit(bool* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = false;
	}
}
// bfs�� Ǯ���
void dfs(std::vector<int>* vec, bool* visitList, int* buildingList, int visitNode, int* retList, int original) {
	if (visitList[visitNode]) return;
	visitList[visitNode] = true;
	for (int adjacentNode : vec[visitNode]) {
		if (!visitList[adjacentNode]) {
			dfs(vec, visitList, buildingList, adjacentNode, retList, original);
		}
	}
	retList[original] += buildingList[visitNode];
}
int main() {
	int N;
	std::cin >> N;

	bool* visitList = new bool[N];
	int* buildingTimeList = new int[N];
	int* retList = new int[N];
	std::vector<int>* buildingVec = new std::vector<int>[N];

	// ��� �迭 �ʱ�ȭ
	for (int i = 0; i < N; i++)
		retList[i] = 0;

	// �Է� �ޱ�
	int buildingTime, linkNode;
	for(int i=0; i<N; i++) {
		// ��ġ�ð� �Է¹ޱ�
		std::cin >> buildingTime;
		buildingTimeList[i] = buildingTime;
		// ����� ��� �Է¹ޱ�
		while (true) {
			std::cin >> linkNode;
			if (linkNode == -1) break;
			buildingVec[i].push_back(linkNode - 1);
		}
	}
	for (int i = 0; i < N; i++) {
		visitListInit(visitList, N);
		dfs(buildingVec, visitList, buildingTimeList, i, retList, i);
	}
		
	for (int i = 0; i < N; i++) {
		std::cout << retList[i] << std::endl;
	}

	delete[] visitList;
	delete[] buildingVec;
	return 0;
}