#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool isPossible(vector<long long>& vec, long long M, long long K) {
	long long sum = 0;
	for (long long tree : vec) {
		if (tree - K <= 0) sum += 0;
		else sum += tree - K;
	}
	return sum >= M;
}
int main() {
	int N;
	long long M;
	cin >> N >> M;

	vector<long long> trees(N);
	long long right = 0;
	long long left = 0;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
		right = max(right, trees[i]);
	}

	long long ans = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (isPossible(trees, M, mid)) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	
	cout << ans;

	return 0;
}