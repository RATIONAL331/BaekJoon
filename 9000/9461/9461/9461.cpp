#include<iostream>
long long calculate(int n, long long* dp) {
	if (dp[n] != 0) return dp[n];
	if (n == 0) return dp[0] = 1;
	if (n == 1) return dp[1] = 1;
	if (n == 2) return dp[2] = 1;
	return dp[n] = calculate(n - 3, dp) + calculate(n - 2, dp);
}
int main() {
	int T;
	std::cin >> T;
	// Input Phase
	int N;
	for (int i = 0; i < T; i++) {
		std::cin >> N;
		// Init DP
		long long * dp = new long long[N];
		for (int i = 0; i < N; i++) {
			dp[i] = 0;
		}
		// Calculate
		std::cout << calculate(N - 1, dp) << std::endl;
		// Delete Phase;
		delete[] dp;
	}
	return 0;
}