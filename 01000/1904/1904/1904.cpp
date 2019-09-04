#include<iostream>
using namespace std;

int dp[1000001] = { 0, 1, 2 };

//int solve(int n) {
//	if (n == 0) return 0;
//	if (n == 1) return 1;
//	if (n == 2) return 2;
//	int& ret = dp[n];
//	if (ret != 0) return ret;
//
//	return ret = (solve(n - 1) + solve(n - 2)) % 15746;
//}

// ���� ���� �ٷ� �� ���� 1 �߰��� �Ͱ�
//			 ���� ���� 00�� �߰��� �Ͱ� ����.

int main() {
	int N;
	cin >> N;

	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;

	printf("%d", dp[N]);

	return 0;
}