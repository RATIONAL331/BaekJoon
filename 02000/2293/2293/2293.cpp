#include<iostream>
int main() {
	int n, k;
	std::cin >> n >> k;

	int coin;
	int * coinArr = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		std::cin >> coin;
		coinArr[i] = coin;
	}
	// dp생성 및 초기화
	int * dp = new int[k + 1];
	dp[0] = 1;
	for (int i = 1; i <= k; i++) { 
		if (i % coinArr[1] == 0) dp[i] = 1;
		else dp[i] = 0;
	}
	// 두번째 동전부터 시작
	for (int coinIdx = 2; coinIdx <= n; coinIdx++) {
		for (int dpIdx = 1; dpIdx <= k; dpIdx++) {
			// 현재 접근하고 있는 k가 coin보다 크면 
			if (dpIdx >= coinArr[coinIdx]) {
				dp[dpIdx] += dp[dpIdx - coinArr[coinIdx]];
			}
		}
	}
	std::cout << dp[k];
	// 동적 배열 제거
	delete[] dp;
	delete[] coinArr;
	return 0;
}