#include<iostream>
using namespace std;

const int DIV = 1'000'000'009;

int dp[1'000'001];

int solve(int num) {
	if (num == 1) return 1;
	if (num == 2) return 2;
	if (num == 3) return 4;
	int& ret = dp[num];
	if (ret != 0) return ret;

	return ret = ((solve(num - 1) + solve(num - 2)) % DIV + solve(num - 3)) % DIV;

}

int main() {
	int T;
	cin >> T;

	int num;
	while (T--) {
		cin >> num;
		cout << solve(num) << endl;
	}
	return 0;
}