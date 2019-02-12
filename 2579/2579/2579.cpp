#include<iostream>
#include<algorithm>
int main() {
	int n;
	std::cin >> n;
	// 배열 생성
	int * stair = new int[n];
	int * dp = new int[n];
	// 입력받기
	int num;
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		stair[i] = num;
	}
	// dp초기화
	dp[0] = stair[0];
	// dp 계산
	for (int i = 1; i < n; i++) {
		if (i < 3) {
			if (i == 2) {
				// 계단이 3개인 경우 3번째 1번째 계단을 밟는 경우, 또는 2번째 3번째 계단을 밟는 경우가 있다.
				dp[i] = std::max(stair[i] + stair[i-1], stair[i] + stair[i-2]);
			}
			else {
				// 계단이 2개인 경우 두 번째 계단은 그대로 더해준다.
				dp[i] = stair[i-1] + stair[i];
			}
		}
		else {
			// 계단이 4개 이상인 경우 일단 밟은 계단의 숫자 + (그 바로 전 단계의 숫자 + 3 전단계의 총 숫자의 합 ) 또는 (2전 단계의 합)의 최댓값을 구한다. 
			dp[i] = stair[i] + std::max(dp[i - 2], stair[i-1] + dp[i - 3]);
		}
	}
	std::cout << dp[n - 1];
	// 동적 배열 제거
	delete[] dp;
	delete[] stair;
	return 0;
}