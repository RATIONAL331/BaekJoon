#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
vector<int> mem;
vector<int> cost;
vector<vector<int>> dp;

int maxMem(int idx, int sumVal) {
	if (idx >= N) return 0;

	int& ret = dp[idx][sumVal];
	if (ret != -1) return ret;

	ret = maxMem(idx + 1, sumVal);
	if (cost[idx] <= sumVal)
		ret = max(ret, mem[idx] + maxMem(idx + 1, sumVal - cost[idx]));

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	mem.resize(N);
	cost.resize(N);
	dp.resize(N);

	int sumCost = 0;
	for (int i = 0; i < N; i++)
		cin >> mem[i];
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		sumCost += cost[i];
	}
	for (int i = 0; i < N; i++)
		dp[i].resize(sumCost + 1, -1);

	int sumVal = 0;
	while (true) {
		if (maxMem(0, sumVal) >= M) {
			cout << sumVal;
			break;
		}
		sumVal++;
	}

	return 0;
}