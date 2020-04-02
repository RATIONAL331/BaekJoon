#include<iostream>
#include<algorithm>
using namespace std;

int dp[1000001];
int backTrack[1000001];

int solve(int n) {
	if (n == 1)
		return 0;

	if (dp[n] != 0) return dp[n];

	int minValue = INT32_MAX;
	if (n % 3 == 0) {
		if (minValue > solve(n / 3) + 1) {
			minValue = solve(n / 3) + 1;
			backTrack[n] = n / 3;
		}
	}

	if (n % 2 == 0) {
		if (minValue > solve(n / 2) + 1) {
			minValue = solve(n / 2) + 1;
			backTrack[n] = n / 2;
		}
	}

	if (minValue > solve(n - 1) + 1) {
		minValue = solve(n - 1) + 1;
		backTrack[n] = n - 1;
	}

	return dp[n] = minValue;
}

int main() {
	int N;
	cin >> N;
	cout << solve(N) << '\n' << N << " ";

	int idx = N;
	while (idx != 1) {
		cout << backTrack[idx] << " ";
		idx = backTrack[idx];
	}
	return 0;
}