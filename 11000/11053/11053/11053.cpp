#include<iostream>
#include<algorithm>
using namespace std;
int N;
int arr[1000];
int dp[1000];

int search(int pos) { // pos에서 시작해서 최대길이
	int& ret = dp[pos];
	if (ret != 0) return ret;

	ret = 1;
	for (int next = pos + 1; next < N; next++) {
		if (arr[pos] < arr[next])
			ret = max(ret, search(next) + 1);
	}

	return ret;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int maxVal = -987654321;
	for (int begin = 0; begin < N; begin++)
		maxVal = max(maxVal, search(begin));

	cout << maxVal;

	return 0;
}