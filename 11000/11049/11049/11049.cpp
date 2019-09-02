#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[501][501];

int solve(vector<pair<int, int>>& vec, int X, int Y) {
	if (X == Y) return 0;
	int& ret = dp[X][Y];

	if (ret != 0) return ret;

	int tmp = INT32_MAX;
	for (int k = X; k < Y; k++)
		tmp = min(tmp, solve(vec, X, k) + solve(vec, k + 1, Y)
			+ vec[X].first * vec[k].second * vec[Y].second);
	return ret = tmp;
}

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> vec(N);

	int row, col;
	for (int i = 0; i < N; i++) {
		cin >> row >> col;
		vec[i] = { row, col };
	}

	cout << solve(vec, 0, N - 1);
	return 0;
}