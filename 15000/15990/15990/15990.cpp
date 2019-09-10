#include<iostream>
#include<algorithm>
using namespace std;
const long long mod = 1'000'000'009;

long long dp[100001][4];
long long solve(int n, int last) {
	
}
int main() {
	int T;
	cin >> T;

	int n;
	while (T--) {
		cin >> n;
		cout << solve(n, 0) << endl;
	}
	return 0;
}