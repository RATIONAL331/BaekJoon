#include<iostream>
#include<vector>
using namespace std;

bool* visited;
int lastNode;
int length;
vector<vector<pair<int, int>>> tree;
void dfs(int node, int totalDist) {
	if (visited[node]) return;
	visited[node] = true;

	if (length < totalDist) {
		length = totalDist;
		lastNode = node;
	}
	for (const auto& elem : tree[node]) 
		dfs(elem.first, elem.second + totalDist);	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int V;
	cin >> V;

	tree.resize(V);

	int parent, child, dist;
	for (int i = 0; i < V; i++) {
		cin >> parent;
		while (true) {
			cin >> child;
			if (child == -1) break;

			cin >> dist;
			tree[parent - 1].push_back({ child - 1, dist });
		}
	}
	visited = new bool[V]();
	dfs(lastNode, 0);
	delete[] visited;

	length = 0;
	visited = new bool[V]();
	dfs(lastNode, 0);
	delete[] visited;

	cout << length;

	return 0;
}