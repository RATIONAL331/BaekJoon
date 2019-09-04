#include<iostream>
#include<algorithm>
int max(int* list, int length) {
	int ret = list[0];
	for (int idx = 1; idx < length; idx++) {
		if (ret < list[idx]) ret = list[idx];
	}
	return ret;
}
int main() {
	int n;
	std::cin >> n;
	// 삼각형 담는 배열 생성
	int ** triangle = new int*[n];
	for (int i = 1; i <= n; i++) {
		triangle[i - 1] = new int[i];
	}
	// dp생성
	int ** dp = new int*[n];
	for (int i = 1; i <= n; i++) {
		dp[i - 1] = new int[i];
	}
	// 삼각형 넣기
	int num;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			std::cin >> num;
			triangle[i - 1][j - 1] = num;
		}
	}
	// dp초기화
	dp[0][0] = triangle[0][0];
	// dp계산
	for (int i = 1; i < n; i++) {
		// 줄의 첫번째 원소는 항상 전줄의 첫번째 값을 받는다.
		dp[i][0] = triangle[i][0] + dp[i - 1][0];
		// 줄의 중간 원소는 윗 줄의 두 값중 큰 값을 받는다.
		for (int j = 1; j <= i - 1; j++) {
			dp[i][j] = triangle[i][j] + std::max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
		// 줄의 마지막 원소는 항상 전 줄의 마지막 값을 받는다.
		dp[i][i] = triangle[i][i] + dp[i - 1][i - 1];
	}
	// 최대값 출력
	std::cout << max(dp[n - 1], n);

	// 동적배열 제거
	for (int i = 0; i < n; i++) {
		delete[] dp[i];
	}
	delete[] dp;
	for (int i = 0; i < n; i++) {
		delete[] triangle[i];
	}
	delete[] triangle;
	return 0;
}