#include<iostream>
#include<vector>
using namespace std;

int N, R, Q;
vector<int> dp;
vector<vector<int>> tree;
int solve(int searchNode) {
	dp[searchNode] = 1;
	for (int nextNode : tree[searchNode]) {
		if (dp[nextNode] == 0)
			dp[searchNode] += solve(nextNode);
	}

	return dp[searchNode];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> R >> Q;
	tree.resize(N);
	dp.resize(N);

	int U, V;
	for (int i = 0; i < N - 1; i++) {
		cin >> U >> V;
		tree[U - 1].push_back(V - 1);
		tree[V - 1].push_back(U - 1);
	}
	solve(R - 1);

	int solveNode;
	for (int i = 0; i < Q; i++) {
		cin >> solveNode;
		cout << dp[solveNode - 1] << '\n';
	}

	return 0;
}