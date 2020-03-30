#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
vector<vector<int>> graph;

const int INF = 987654321;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	graph.resize(n);
	for (int i = 0; i < n; i++)
		graph[i].resize(n, INF);

	int from, to, cost;
	while (m--) {
		cin >> from >> to >> cost;
		graph[from - 1][to - 1] = min(graph[from - 1][to - 1], cost);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (graph[i][k] == INF || graph[k][j] == INF)
					continue;
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] != INF)
				cout << graph[i][j] << " ";
			else
				cout << 0 << " ";
		}
		cout << '\n';
	}

	return 0;
}