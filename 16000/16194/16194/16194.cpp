#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int dp[1001];

int solve(vector<int>& cards, int pos) {
	if (pos == 0) return 0;

	int& ret = dp[pos];
	if (ret != -1) return ret;

	for (int i = pos; i >= 1; i--) {
		if (ret == -1) ret = solve(cards, pos - i) + cards[i];
		else ret = min(ret, solve(cards, pos - i) + cards[i]);
	}

	return ret;
}

int main() {
	int N;
	scanf("%d", &N);

	vector<int> cards(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &cards[i]);
	}

	for (int i = 0; i <= N; i++)
		dp[i] = -1;

	printf("%d", solve(cards, N));

	return 0;
}