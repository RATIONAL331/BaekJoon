#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
	if (visited[node]) return;
	visited[node] = true;
	for (int adj : graph[node]) {
		dfs(adj);
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	graph.resize(N);
	visited.resize(N);

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}
	
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}