//#include<iostream>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//
//int dp[50001];
//
//int solve(int n) {
//	int tmpValue = (int)sqrt(n);
//
//	if (n == 0) return 0;
//	if (tmpValue * tmpValue == n) return dp[n] = 1;
//
//	if (dp[n] != 0) return dp[n];
//
//	dp[n] = 987654321;
//	for (int i = tmpValue; i >= 1; i--)
//		dp[n] = min(dp[n], solve(n - i * i) + 1);
//
//	return dp[n];
//}
//
//int main() {
//	int N;
//	cin >> N;
//	cout << solve(N);
//	return 0;
//}

#include <iostream>
using namespace std;

int dp[50001];

int main()
{
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++)
			dp[i] = dp[i] > dp[i - j * j] + 1 ? dp[i - j * j] + 1 : dp[i];
	}
	cout << dp[n];
	return 0;
}