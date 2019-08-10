#include<iostream>
#include<algorithm>
using namespace std;
int N;
int arr[1000];
int dp[1000];
int dp_r[1000];
void lis(int pos) { // 0~pos까지 lis길이
	int& ret = dp[pos];

	ret = 1;
	for (int next = 0; next < pos; next++) {
		if (arr[pos] > arr[next] && ret < dp[next] + 1)
			ret++;
	}
}
void lis_r(int pos) { // N-1 ~ pos까지의 역lis길이
	int& ret = dp_r[pos];

	ret = 1;
	for (int next = N - 1; next >= 0; next--) {
		if (arr[pos] > arr[next] && ret < dp_r[next] + 1)
			ret++;
	}
}
int solve() {
	for (int begin = 0; begin < N; begin++)
		lis(begin);

	for (int rbegin = N - 1; rbegin >= 0; rbegin--)
		lis_r(rbegin);

	int maxVal = -987654321;
	for (int i = 0; i < N; i++)
		maxVal = max(maxVal, dp[i] + dp_r[i]);

	return maxVal - 1;
}
int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cout << solve();

	return 0;
}