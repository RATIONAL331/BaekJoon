#include<iostream>
#include<vector>
using namespace std;

bool* visited;
int last;
int maxLength;

void dfs(const vector<vector<pair<int, int>>>& tree, int node, int totalLength) {
	if (visited[node]) return;
	visited[node] = true;

	if (maxLength < totalLength) {
		maxLength = totalLength;
		last = node;
	}

	for (const auto& elem : tree[node])
		dfs(tree, elem.first, elem.second + totalLength);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<pair<int, int>>> tree(n);
	int parent, child, weight;
	for (int i = 0; i < n - 1; i++) {
		cin >> parent >> child >> weight;
		tree[parent - 1].push_back({ child - 1, weight });
		tree[child - 1].push_back({ parent - 1, weight });
	}

	for (int i = 0; i < 2; i++) {
		visited = new bool[n]();
		dfs(tree, last, 0);
		delete[] visited;
	}

	cout << maxLength;

	return 0;
}