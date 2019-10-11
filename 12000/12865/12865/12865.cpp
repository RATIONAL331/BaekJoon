#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, K;

int dp[100][100'001];
int solve(vector<pair<int, int>>& vec, int start, int weight) {
	if (start >= N || weight > K) return 0;

	int& ret = dp[start][weight];
	if (ret != 0) return ret;

	// 포함하지 않는 경우
	ret = solve(vec, start + 1, weight);
	// 포함하는 경우
	if (weight + vec[start].first <= K) {
		ret = max(ret, solve(vec, start + 1, weight + vec[start].first) + vec[start].second);
	}
	return ret;
}

int main() {
	cin >> N >> K;
	vector<pair<int, int>> vec(N);

	int W, V;
	for (int i = 0; i < N; i++) {
		cin >> W >> V;
		vec[i] = { W, V };
	}
	cout << solve(vec, 0, 0);
	return 0;
}