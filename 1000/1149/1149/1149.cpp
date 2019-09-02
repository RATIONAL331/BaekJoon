#include<iostream>
#include<algorithm>
int main() {
	int N;
	std::cin >> N;
	// 집 보관 
	int ** home = new int*[N];
	for (int i = 0; i < N; i++) {
		home[i] = new int[3];
	}
	// 거리 보관
	int ** dp = new int*[N];
	for (int i = 0; i < N; i++) {
		dp[i] = new int[3];
	}
	// 입력받기
	int R, G, B;
	for (int i = 0; i < N; i++) {
		std::cin >> R >> G >> B;
		home[i][0] = R; home[i][1] = G; home[i][2] = B;
	}
	// dp초기설정
	dp[0][0] = home[0][0]; dp[0][1] = home[0][1]; dp[0][2] = home[0][2];
	// dp구하기
	for (int i = 1; i < N; i++) {
		dp[i][0] = home[i][0] + std::min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = home[i][1] + std::min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = home[i][2] + std::min(dp[i - 1][0], dp[i - 1][1]);
	}
	std::cout << std::min(std::min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
	// 동적 배열 제거하기
	for (int i = 0; i < N; i++) {
		delete[] dp[i];
	}
	delete[] dp;
	for (int i = 0; i < N; i++) {
		delete[] home[i];
	}
	delete[] home;
	return 0;
}