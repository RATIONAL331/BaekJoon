// 거리를 결정한 후 그 후에 공유기가 몇 개 설치되는지 본다.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool check(vector<int>& vec, int C, int dist) {
	int cnt = 1;
	int last = vec[0];
	for (int home : vec) {
		if (home - last >= dist) {
			cnt++;
			last = home;
		}
	}
	return cnt >= C;
}
int main() {
	int N, C;
	cin >> N >> C;

	vector<int> home(N);
	for (int i = 0; i < N; i++)
		cin >> home[i];
	sort(home.begin(), home.end());

	int left = 1;
	int right = home[N - 1] - home[0];

	int result = left;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(home, C, mid)) {
			if (result < mid)
				result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << result;

	return 0;
}