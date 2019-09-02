#include<iostream>
#include<algorithm>
const int INF = 987654321;
int tsp(int** graph, int** dp, int N, int current, int visit) {
	if (dp[current][visit] != INF) 
		return dp[current][visit];
	if (visit == (1 << N) - 1) {
		if (graph[current][0] != 0) 
			return graph[current][0];
		else
			return INF;
	}

	for (int i = 0; i < N; i++) {
		 //그래프가 현재 방문하고 있는 곳과 i번째와 연결 되어있는지
		 //그리고 그곳이 방문한 곳인지 확인 
		if (graph[current][i] != 0 && !(visit & (1 << i))) {
			//ret을 연결한 곳과 다음 방문할 곳을 더한 것과 비교
			dp[current][visit] = std::min(dp[current][visit], graph[current][i] + tsp(graph, dp, N, i, visit | (1 << i)));
		}
	}
	return dp[current][visit];
}
int main() {
	int N;
	std::cin >> N;

	int ** graph = new int*[N];
	for (int i = 0; i < N; i++) {
		graph[i] = new int[N];
	}
	
	int ** dp = new int*[N];
	for (int i = 0; i < N; i++) {
		dp[i] = new int[1 << N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (1 << N); j++) {
			dp[i][j] = INF;
		}
	}

	int distance;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> distance;
			graph[i][j] = distance;
		}
	}

	std::cout << tsp(graph, dp, N, 0, 1);

	for (int i = 0; i < N; i++) {
		delete[] dp[i];
	}
	delete[] dp;
	for (int i = 0; i < N; i++) {
		delete[] graph[i];
	}
	delete[] graph;
	return 0;
	
}