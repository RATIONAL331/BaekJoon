#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[1001];

int solve(vector<int>& cards, int pos) {
	if (pos == 0) return 0;

	int& ret = dp[pos];
	if (ret != 0) return ret;

	for (int i = 1; i <= pos; i++) {
		ret = max(ret, solve(cards, pos - i) + cards[i]);
	}

	return dp[pos];
}

int main() {
	int N;
	cin >> N;

	vector<int> cards(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> cards[i];
	}

	cout << solve(cards, N);

	return 0;
}