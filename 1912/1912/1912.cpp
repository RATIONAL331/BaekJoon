#include<iostream>
#include<algorithm>
int calculate(int * numArr, int* dp, int A, int B) {
	for (int i = A; i <= B; i++) {
		dp[i] = std::max(std::max(dp[i - 1] + numArr[i], dp[i - 1]), numArr[i]);
	}
	return dp[B];
}
 // 메모리 제한 해결하기
int main() {
	int n;
	std::cin >> n;

	int num;
	int * numArr = new int[n + 1];
	int * dp = new int[n + 1];
	for (int i = 1; i <= n; i++){
		std::cin >> num;
		numArr[i] = num;
	}
	for (int col = 0; col < n + 1; col++) {
		dp[col] = INT32_MIN;
	}
	dp[1] = numArr[1];
	std::cout<<calculate(numArr, dp, 2, n);
	delete[] dp;
	delete[] numArr;
	return 0;
}