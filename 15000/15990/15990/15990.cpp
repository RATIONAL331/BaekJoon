#include<iostream>
#include<algorithm>
using namespace std;
const long long mod = 1'000'000'009;

long long dp[100001][3];
long long solve(int n, int last) {
	if (n == 0) return 0;
	if (n == 1) {
		if (last == 1) return 1;
		else return 0;
	}
	if (n == 2) {
		if (last == 2) return 1;
		else return 0;
	}
	if (n == 3) {
		return 1;
	}
	long long& ret = dp[n][last - 1];
	if (ret != 0) return ret;

	switch (last) {
	case 1:
		ret = (solve(n - 1, 2) + solve(n - 1, 3)) % mod;
		break;
	case 2:
		ret = (solve(n - 2, 1) + solve(n - 2, 3)) % mod;
		break;
	case 3:
		ret = (solve(n - 3, 1) + solve(n - 3, 2)) % mod;
		break;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;

	int n;
	while (T--) {
		cin >> n;
		cout << ((solve(n, 1) + solve(n, 2)) % mod + solve(n, 3)) % mod << endl;
	}
	return 0;
}