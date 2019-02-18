#include<iostream>
#include<algorithm>
int getMax(int* arr, int n) {
	int max = arr[1];
	for (int i = 2; i <= n; i++) {
		max = std::max(max, arr[i]);
	}
	return max;
}
void calculate(int * numArr, int * dp, int A, int B) {
	for (int i = A; i <= B; i++) {
		if (dp[i - 1] < 0) dp[i] = numArr[i];
		else dp[i] = dp[i - 1] + numArr[i];
	}
}
 // 메모리 제한 해결하기
int main() {
	int n;
	std::cin >> n;
	// Input Phase;
	int num;
	int * numArr = new int[n + 1];
	for (int i = 1; i <= n; i++){
		std::cin >> num;
		numArr[i] = num;
	}
	// DP init
	int * dp = new int[n + 1];
	for (int col = 0; col < n + 1; col++) {
		dp[col] = INT32_MIN;
	}
	dp[0] = 0;
	// Calcualte
	calculate(numArr, dp, 1, n);
	std::cout << getMax(dp, n);
	// Delete Phase;
	delete[] dp;
	delete[] numArr;
	return 0;
}