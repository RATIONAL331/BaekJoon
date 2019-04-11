#include<iostream>
#include<vector>
int main() {
	int V, E;
	int startNode;

	std::cin >> V >> E >> startNode;
	// 그래프 생성
	int** graph = new int* [V];
	for (int i = 0; i < V; i++) {
		graph[i] = new int[V];
	}
	// 방문 리스트 생성 및 무한대로 초기화
	int* visitList = new int[V];
	for (int i = 0; i < V; i++) {
		visitList[i] = INT32_MAX;
	}
	// 그래프 0으로 초기화 
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			graph[i][j] = 0;
		}
	}
	// 그래프 입력받기
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
	그래프값이 0이라면 fromNode부터 toNode까지 가는 길이 없는 것을 의미한다.
	그래프의 값이 0이 아닌 값이 있으면 fromNode부터 toNode까지 가는 길이 있고 그 값이 경로로 가는 길이다.
	*/

	//방문 리스트의 첫번째 시작점은 0으로 한다.
	visitList[startNode - 1] = 0;

	return 0;
}