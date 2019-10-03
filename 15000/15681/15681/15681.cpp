#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, R, Q;
int solve(vector<vector<int>>& tree, int node) {
	const vector<int>& treeRoot = tree[R - 1];

}
int main() {
	cin >> N >> R >> Q;
	vector<vector<int>> tree(N);

	int U, V;
	for (int i = 0; i < N - 1; i++) {
		cin >> U >> V;
		tree[U - 1].push_back(V - 1);
		tree[V - 1].push_back(U - 1);
	}

	int solveNode;
	for (int i = 0; i < Q; i++) {
		cin >> solveNode;
		cout << solve(tree, solveNode - 1);
	}

	return 0;
}