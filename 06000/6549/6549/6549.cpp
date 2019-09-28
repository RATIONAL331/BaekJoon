#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long solve(vector<long long>& vec, int start, int end) {
	if (start > end) return 0;
	if (start == end) return vec[start];

	int mid = (start + end) / 2;
	long long maxVal = 0;
	// 왼쪽에서 가장 큰것
	maxVal = max(maxVal, solve(vec, start, mid));
	// 오른쪽에서 가장 큰것
	maxVal = max(maxVal, solve(vec, mid + 1, end));
	// 가운데에서 가장 큰것
	int left = mid, right = mid + 1;
	long long selectedHeight = min(vec[left], vec[right]);
	maxVal = max(maxVal, (selectedHeight * 2));

	while (left > start && right < end) {
		if (vec[left - 1] < vec[right + 1]) {
			right += 1;
			selectedHeight = min(selectedHeight, vec[right]);
		}
		else {
			left -= 1;
			selectedHeight = min(selectedHeight, vec[left]);
		}
		maxVal = max(maxVal, selectedHeight * ((long long)right - left + 1));
	}
	while (left > start) {
		left -= 1;
		selectedHeight = min(selectedHeight, vec[left]);
		maxVal = max(maxVal, selectedHeight * ((long long)right - left + 1));
	}
	while (right < end) {
		right += 1;
		selectedHeight = min(selectedHeight, vec[right]);
		maxVal = max(maxVal, selectedHeight * ((long long)right - left + 1));
	}

	/*while (left > start || right < end) {
		if (right < end && (left == start || vec[left - 1] < vec[right + 1])) {
			right += 1;
			selectedHeight = min(selectedHeight, vec[right]);
		}
		else {
			left -= 1;
			selectedHeight = min(selectedHeight, vec[left]);
		}
		maxVal = max(maxVal, selectedHeight * ((long long)right - left + 1));
	}*/

	return maxVal;
}

int main() {
	int N;
	while (true) {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		cin >> N;
		if (N == 0) return 0;
		
		vector<long long> vec(N);
		for (int i = 0; i < N; i++) {
			cin >> vec[i];
		}

		cout << solve(vec, 0, N - 1) << '\n';
	}
	return 0;
}