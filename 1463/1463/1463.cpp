#include<iostream>
#include<algorithm>
int main() {
	int n;
	std::cin >> n;

	int * dp = new int[n + 1];

	dp[0] = 0; dp[1] = 0;  dp[2] = 1; dp[3] = 1;
	for (int i = 4; i <= n; i++) {
		if (i % 3 == 0) dp[i] = 1 + std::min(dp[i / 3], dp[i - 1]);
		else if (i % 2 == 0) dp[i] = 1 + std::min(dp[i / 2], dp[i - 1]);
		else dp[i] = 1 + dp[i - 1];
	}
	std::cout << dp[n];

	delete[] dp;
	return 0;
}