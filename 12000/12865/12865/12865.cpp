#include<iostream>
#include<vector>
using namespace std;

int dp[101][101];

int main() {
	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> vec(N);

	int W, V;
	for (int i = 0; i < N; i++) {
		cin >> W >> V;
		vec[i] = { W, V };
	}

	// 1 2 3 4, 12, 13, 14, 23, 24, 34, 123, 124, 134, 1234

	return 0;
}