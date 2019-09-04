#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int dp[100001];

int solve(int N, int K) {
	int& ret = dp[N];
	if (ret != -1) return ret;

	if (N < 0) return 987654321;
	if (N > 100000) return 987654321;

	if (N == K) return ret = 0;
	if (N < K) {
		
	}
	else return ret = N - K;
}

int main() {
	int N, K;
	cin >> N >> K;

	fill(begin(dp), end(dp), -1);
	cout << solve(N, K);

	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//
//int n, k, d[100001];
//
//int main() {
//	scanf("%d %d", &n, &k);
//	if (n > k) {
//		printf("%d\n", n - k);
//		return 0;
//	}
//	d[n] = 0;
//	if (n == 0)
//		d[n + 1] = 1;
//	else
//		d[n - 1] = d[n + 1] = 1;
//
//	// Modified
//	int idx = n - 2, tmp = 2;
//	while (idx >= 0) {
//		d[idx] = tmp;
//		idx--;
//		tmp++;
//	}
//	// End
//
//	for (int i = n + 2; i <= k + 1; i++) {
//		if (i % 2 == 0) d[i] = min(d[i - 1] + 1, d[i / 2] + 1);
//		else d[i] = d[i - 1] + 1;
//		d[i - 1] = min(d[i - 1], d[i] + 1);
//	}
//	printf("%d", d[k]);
//	return 0;
//}

